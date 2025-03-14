# -*- coding: utf-8 -*-
'''
Implement the base key object for other keys to inherit convenience functions
'''
# Import libnacl libs
import libnacl.encode

# Import python libs
import os
import stat

class BaseKey(object):
    '''
    Include methods for key management convenience
    '''
    def hex_sk(self):
        if hasattr(self, 'sk'):
            return libnacl.encode.hex_encode(self.sk)
        else:
            return ''

    def hex_pk(self):
        if hasattr(self, 'pk'):
            return libnacl.encode.hex_encode(self.pk)

    def hex_vk(self):
        if hasattr(self, 'vk'):
            return libnacl.encode.hex_encode(self.vk)

    def hex_seed(self):
        if hasattr(self, 'seed'):
            return libnacl.encode.hex_encode(self.seed)

    def for_json(self):
        '''
        Return a dictionary of the secret values we need to store.
        '''
        pre = {}
        sk = self.hex_sk()
        pk = self.hex_pk()
        vk = self.hex_vk()
        seed = self.hex_seed()
        if sk:
            pre['priv'] = sk.decode('utf-8')
        if pk:
            pre['pub'] = pk.decode('utf-8')
        if vk:
            pre['verify'] = vk.decode('utf-8')
        if seed:
            pre['sign'] = seed.decode('utf-8')

        return pre

    def save(self, path, serial='json'):
        '''
        Safely save keys with perms of 0400
        '''
        pre = self.for_json()

        if serial == 'msgpack':
            import msgpack
            packaged = msgpack.dumps(pre)
        elif serial == 'json':
            import json
            packaged = json.dumps(pre)

        perm_other = stat.S_IROTH | stat.S_IWOTH | stat.S_IXOTH
        perm_group = stat.S_IRGRP | stat.S_IWGRP | stat.S_IXGRP

        cumask = os.umask(perm_other | perm_group)
        with open(path, 'w+') as fp_:
            fp_.write(packaged)
        os.umask(cumask)
