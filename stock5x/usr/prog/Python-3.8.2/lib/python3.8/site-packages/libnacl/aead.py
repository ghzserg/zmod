# -*- coding: utf-8 -*-
'''
Utilities to make secret box encryption simple
'''
# Import libnacl
import libnacl
import libnacl.utils
import libnacl.base


class AEAD(libnacl.base.BaseKey):
    '''
    Manage AEAD encryption using the IETF ChaCha20-Poly1305(default) or AES-GCM algorithm
    '''

    def __init__(self, key=None):
        if key is None:
            key = libnacl.utils.aead_key()
        if len(key) != libnacl.crypto_aead_chacha20poly1305_ietf_KEYBYTES:  # same size for both
            raise ValueError('Invalid key')
        self.sk = key
        self.usingAES = False

    def useAESGCM(self):
        self.usingAES = True
        return self

    def encrypt(self, msg, aad, nonce=None, pack_nonce_aad=True):
        '''
        Encrypt the given message. If a nonce is not given it will be
        generated via the rand_nonce function
        '''
        if nonce is None:
            nonce = libnacl.utils.rand_aead_nonce()
        if len(nonce) != libnacl.crypto_aead_aes256gcm_NPUBBYTES:
            raise ValueError('Invalid nonce')
        if self.usingAES:
            ctxt = libnacl.crypto_aead_aes256gcm_encrypt(msg, aad, nonce, self.sk)
        else:
            ctxt = libnacl.crypto_aead_chacha20poly1305_ietf_encrypt(msg, aad, nonce, self.sk)

        if pack_nonce_aad:
            return aad + nonce + ctxt
        else:
            return aad, nonce, ctxt

    def decrypt(self, ctxt, aadLen):
        '''
        Decrypt the given message, if no nonce or aad are given they will be
        extracted from the message
        '''
        aad = ctxt[:aadLen]
        nonce = ctxt[aadLen:aadLen+libnacl.crypto_aead_aes256gcm_NPUBBYTES]
        ctxt = ctxt[aadLen+libnacl.crypto_aead_aes256gcm_NPUBBYTES:]
        if len(nonce) != libnacl.crypto_aead_aes256gcm_NPUBBYTES:
            raise ValueError('Invalid nonce')
        if self.usingAES:
            return libnacl.crypto_aead_aes256gcm_decrypt(ctxt, aad, nonce, self.sk)
        return libnacl.crypto_aead_chacha20poly1305_ietf_decrypt(ctxt, aad, nonce, self.sk)

    def decrypt_unpacked(self, aad, nonce, ctxt):
        '''
        Decrypt the given message, if no nonce or aad are given they will be
        extracted from the message
        '''
        if len(nonce) != libnacl.crypto_aead_aes256gcm_NPUBBYTES:
            raise ValueError('Invalid nonce')
        if self.usingAES:
            return libnacl.crypto_aead_aes256gcm_decrypt(ctxt, aad, nonce, self.sk)
        return libnacl.crypto_aead_chacha20poly1305_ietf_decrypt(ctxt, aad, nonce, self.sk)
