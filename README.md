# Performance C - ChaCha20
Performance based ChaCha20 implementation with various real-world use case examples. Written in pure C it has no dependencies and can be compiled standalone.
This implementation is written to have the ability to be used with various systems independent of their hardware capabilities. It is also fairly compact if compiled, uncompiled it is around 2.3 KB big.
This implementation does not contain any unneccesary error checking or bloat.

Various examples are provided such as...
* Basic encryption and decryption of a data array using a shared key.
* Networking example using IPv6, a key is shared between the client & server, the connection is henceforth encrypted.
* A Psuedorandom number generator (PRNG), uses a fixed private key to generate an almost limitless amount of psuedo random keys.

# Basic Usage
This is a basic example on how to use it correctly. It is recommended to always make sure that the array size can be subdivided by 64.

```c
// Constant Value, Key, Counter & Nonce (4-8-1-3);
unsigned int k[16]={255147747,473982973,594997402,362904909,739702246,1052196548,842639248,1181193411,2127264408,377828058,1509332996,1422761110,1,3828058,739753246,378289958};

// Plain Input (125);
unsigned char e[128]="ChaCha20 Is A Stream Cipher Known For It's Good Diffusion & Simplicity. This Implementation Focusses On Absolute Performance.";

// Generate CC20 Key;
ck(k,j,10);

// Encryption;
cc(k,e,e+125);printf("Encrypted... \n");i=e;while(i<e+125){printf("%u ",*i);i+=1;};printf("\n\n");

// Decryption;
cc(k,e,e+125);printf("Decrypted... \n");i=e;while(i<e+125){printf("%c",*i);i+=1;};printf("\n");
```


# License
This project is part of the public domain, feel free to use it in whatever form you want.
