#include <stdio.h>
#include <sys/socket.h>

// ChaCha20 Crypthography Function.
unsigned int b0,b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15;

static inline void cb()
{
    b0+=b4;b12=(b12^b0)<<16|(b12^b0)>>16;b8+=b12;b4=(b4^b8)<<12|(b4^b8)>>20;b0+=b4;b12=(b12^b0)<<8|(b12^b0)>>24;b8+=b12;b4=(b4^b8)<<7|(b4^b8)>>25;
    b1+=b5;b13=(b13^b1)<<16|(b13^b1)>>16;b9+=b13;b5=(b5^b9)<<12|(b5^b9)>>20;b1+=b5;b13=(b13^b1)<<8|(b13^b1)>>24;b9+=b13;b5=(b5^b9)<<7|(b5^b9)>>25;
    b2+=b6;b14=(b14^b2)<<16|(b14^b2)>>16;b10+=b14;b6=(b6^b10)<<12|(b6^b10)>>20;b2+=b6;b14=(b14^b2)<<8|(b14^b2)>>24;b10+=b14;b6=(b6^b10)<<7|(b6^b10)>>25;
    b3+=b7;b15=(b15^b3)<<16|(b15^b3)>>16;b11+=b15;b7=(b7^b11)<<12|(b7^b11)>>20;b3+=b7;b15=(b15^b3)<<8|(b15^b3)>>24;b11+=b15;b7=(b7^b11)<<7|(b7^b11)>>25;
    b0+=b5;b15=(b15^b0)<<16|(b15^b0)>>16;b10+=b15;b5=(b5^b10)<<12|(b5^b10)>>20;b0+=b5;b15=(b15^b0)<<8|(b15^b0)>>24;b10+=b15;b5=(b5^b10)<<7|(b5^b10)>>25;
    b1+=b6;b12=(b12^b1)<<16|(b12^b1)>>16;b11+=b12;b6=(b6^b11)<<12|(b6^b11)>>20;b1+=b6;b12=(b12^b1)<<8|(b12^b1)>>24;b11+=b12;b6=(b6^b11)<<7|(b6^b11)>>25;
    b2+=b7;b13=(b13^b2)<<16|(b13^b2)>>16;b8+=b13;b7=(b7^b8)<<12|(b7^b8)>>20;b2+=b7;b13=(b13^b2)<<8|(b13^b2)>>24;b8+=b13;b7=(b7^b8)<<7|(b7^b8)>>25;
    b3+=b4;b14=(b14^b3)<<16|(b14^b3)>>16;b9+=b14;b4=(b4^b9)<<12|(b4^b9)>>20;b3+=b4;b14=(b14^b3)<<8|(b14^b3)>>24;b9+=b14;b4=(b4^b9)<<7|(b4^b9)>>25;
};

static inline void cc(unsigned int k[],unsigned char o[],unsigned char *l)
{
    do
    {
        b0=*k,b1=*(k+1),b2=*(k+2),b3=*(k+3),b4=*(k+4),b5=*(k+5),b6=*(k+6),b7=*(k+7),b8=*(k+8),b9=*(k+9),b10=*(k+10),b11=*(k+11),b12=*(k+12),b13=*(k+13),b14=*(k+14),b15=*(k+15);

        cb();cb();cb();cb();cb();cb();cb();cb();cb();cb();

        *(unsigned int*)o^=(b0+*k);*(unsigned int*)(o+4)^=(b1+*(k+1));*(unsigned int*)(o+8)^=(b2+*(k+2));*(unsigned int*)(o+12)^=(b3+*(k+3));
        *(unsigned int*)(o+16)^=(b4+*(k+4));*(unsigned int*)(o+20)^=(b5+*(k+5));*(unsigned int*)(o+24)^=(b6+*(k+6));*(unsigned int*)(o+28)^=(b7+*(k+7));

        *(unsigned int*)(o+32)^=(b8+*(k+8));*(unsigned int*)(o+36)^=(b9+*(k+9));*(unsigned int*)(o+40)^=(b10+*(k+10));*(unsigned int*)(o+44)^=(b11+*(k+11));
        *(unsigned int*)(o+48)^=(b12+*(k+12));*(unsigned int*)(o+52)^=(b13+*(k+13));*(unsigned int*)(o+56)^=(b14+*(k+14));*(unsigned int*)(o+60)^=(b15+*(k+15));

        o+=64;
    }
    while(o<l);
};

// Shared Encryption Key;
unsigned int h[16]={21937359,56958583,70814153,111055359,149495678,151167677,216656255,217880042,249600224,261823012,305832524,312157109,316316977,336098390,398699812,424274577};

// Message Buffer & Pointers;
unsigned char g[65336],*i,*w;

// Main Logic;
int main()
{
    // Configures Socket To Use Port 9010, IPv6 (1-1-4-1);
    unsigned int s=socket(10,2050,17),q[7],t[7],l=28,y;*q=9010<<16|10;bind(s,(struct sockaddr*)&q,l);

    // Listen Indefinitly For Incoming Data;
    while(1)
    {
        y=recvfrom(s,&g,65536,0,(struct sockaddr*)&t,&l);

        if(y>>31==0)
        {
            // Decrypt Received Message & Print It;
            cc(h,g,g+y);i=g,w=g+y;do{printf("%c",*i);i+=1;}while(i<w);printf(" (%u.%u.%u.%u:%u).\n",*(t+2),*(t+3),*(t+4),*(t+5),*t>>16);

            // Send Newly Encrypted Message Back;
            unsigned char b[16]="Hello, Client 1!",*z=g;i=b;w=b+16;do{*z=*i;z+=1;i+=1;}while(i<w);cc(h,g,g+16);sendto(s,&g,16,0,(struct sockaddr*)&t,l);
        };
    };
};