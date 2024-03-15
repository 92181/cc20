#include <stdio.h>
#include "../../cc20.h"

unsigned char *i;

int main()
{
    // Constant Value, Key, Counter & Nonce (4-8-1-3);
    unsigned int k[16]={255147747,473982973,594997402,362904909,739702246,1052196548,842639248,1181193411,2127264408,377828058,1509332996,1422761110,1,3828058,739753246,378289958};

    // Plain Input (125);
    unsigned char e[128]="ChaCha20 Is A Stream Cipher Known For It's Good Diffusion & Simplicity. This Implementation Focusses On Absolute Performance.";

    // Encryption;
    cc(k,e,e+125);printf("Encrypted... \n");i=e;while(i<e+125){printf("%u ",*i);i+=1;};printf("\n\n");

    // Decryption;
    cc(k,e,e+125);printf("Decrypted... \n");i=e;while(i<e+125){printf("%c",*i);i+=1;};printf("\n");
};