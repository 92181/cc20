#include <stdio.h>
#include <sys/socket.h>
#include "../../cc20.h"

// Shared Encryption Key;
unsigned int j[16],h[16]={21937359,56958583,70814153,111055359,149495678,151167677,216656255,217880042,249600224,261823012,305832524,312157109,316316977,336098390,398699812,424274577};

// Message Buffer & Pointers;
unsigned char g[65336],*i,*w;

// Main Logic;
int main()
{
    // Configures Socket To Use Port 9010, IPv6 (1-1-4-1);
    unsigned int s=socket(10,2050,17),q[7],t[7],l=28,y;*q=9010<<16|10;bind(s,(struct sockaddr*)&q,l);ck(h,j,10);

    // Listen Indefinitly For Incoming Data;
    while(1)
    {
        y=recvfrom(s,&g,65536,0,(struct sockaddr*)&t,&l);

        if(y>>31==0)
        {
            // Decrypt Received Message & Print It;
            cc(j,g,g+y);i=g,w=g+y;do{printf("%c",*i);i+=1;}while(i<w);printf(" (%u.%u.%u.%u:%u).\n",*(t+2),*(t+3),*(t+4),*(t+5),*t>>16);

            // Send Newly Encrypted Message Back;
            unsigned char b[16]="Hello, Client 1!",*z=g;i=b;w=b+16;do{*z=*i;z+=1;i+=1;}while(i<w);cc(j,g,g+16);sendto(s,&g,16,0,(struct sockaddr*)&t,l);
        };
    };
};
