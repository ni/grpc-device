openssl genrsa -passout pass:1111 -des3 -out ca.key 2048

openssl req -passin pass:1111 -new -x509 -days 3650 -key ca.key -out ca.crt -subj "/C=US/ST=Texas/L=Austin/O=NI/OU=R&D/CN=localhost"
 
openssl genrsa -passout pass:1111 -des3 -out server_privatekey.pem 2048
 
openssl req -passin pass:1111 -new -key server_privatekey.pem -out server_csr.pem -subj "/C=US/ST=Texas/L=Austin/O=NI/OU=R&D/CN=localhost"
 
openssl x509 -req -passin pass:1111 -days 3650 -in server_csr.pem -CA ca.crt -CAkey ca.key -CAcreateserial -out server_self_signed_crt.pem
 
openssl rsa -passin pass:1111 -in server_privatekey.pem -out server_privatekey.pem