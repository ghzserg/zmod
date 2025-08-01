#!/bin/sh

export PATH=/opt/openssl-1.0.2d/bin:$PATH
export OPENSSL_DIR=/opt/openssl-1.0.2d
export OPENSSL_CONF=/opt/openssl-1.0.2d/openssl.cnf
export LD_LIBRARY_PATH=$OPENSSL_DIR/lib:$LD_LIBRARY_PATH

KEYDIR="$1"
KEYPAIR=${KEYDIR}private.pem
PUBLICKEY=${KEYDIR}key.pub
PRIVATEKEY=${KEYDIR}key.priv
PASSWORD=abcd

rm -rf ${KEYPAIR} ${PUBLICKEY} ${PRIVATEKEY}

# Generate the key pair
openssl genrsa -des3 -passout pass:${PASSWORD} -out ${KEYPAIR} 2048

# Save the RSA public key in the file key.pub
openssl rsa -in ${KEYPAIR} -passin pass:${PASSWORD} -outform PEM -pubout -out ${PUBLICKEY}

# Save the RSA private key in the file key.priv
openssl rsa -in ${KEYPAIR} -passin pass:${PASSWORD} -out ${PRIVATEKEY} -outform PEM
