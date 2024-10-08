// ChaCha20 Key Function;
static inline void ck(unsigned int *k,unsigned int *o,unsigned int z)
{
    unsigned int b0=*k,b1=*(k+1),b2=*(k+2),b3=*(k+3),b4=*(k+4),b5=*(k+5),b6=*(k+6),b7=*(k+7),b8=*(k+8),b9=*(k+9),b10=*(k+10),b11=*(k+11),b12=*(k+12),b13=*(k+13),b14=*(k+14),b15=*(k+15);
    
    do
    {
        b0+=b4;b12=(b12^b0)<<16|(b12^b0)>>16;b8+=b12;b4=(b4^b8)<<12|(b4^b8)>>20;b0+=b4;b12=(b12^b0)<<8|(b12^b0)>>24;b8+=b12;b4=(b4^b8)<<7|(b4^b8)>>25;
        b1+=b5;b13=(b13^b1)<<16|(b13^b1)>>16;b9+=b13;b5=(b5^b9)<<12|(b5^b9)>>20;b1+=b5;b13=(b13^b1)<<8|(b13^b1)>>24;b9+=b13;b5=(b5^b9)<<7|(b5^b9)>>25;
        b2+=b6;b14=(b14^b2)<<16|(b14^b2)>>16;b10+=b14;b6=(b6^b10)<<12|(b6^b10)>>20;b2+=b6;b14=(b14^b2)<<8|(b14^b2)>>24;b10+=b14;b6=(b6^b10)<<7|(b6^b10)>>25;
        b3+=b7;b15=(b15^b3)<<16|(b15^b3)>>16;b11+=b15;b7=(b7^b11)<<12|(b7^b11)>>20;b3+=b7;b15=(b15^b3)<<8|(b15^b3)>>24;b11+=b15;b7=(b7^b11)<<7|(b7^b11)>>25;
        b0+=b5;b15=(b15^b0)<<16|(b15^b0)>>16;b10+=b15;b5=(b5^b10)<<12|(b5^b10)>>20;b0+=b5;b15=(b15^b0)<<8|(b15^b0)>>24;b10+=b15;b5=(b5^b10)<<7|(b5^b10)>>25;
        b1+=b6;b12=(b12^b1)<<16|(b12^b1)>>16;b11+=b12;b6=(b6^b11)<<12|(b6^b11)>>20;b1+=b6;b12=(b12^b1)<<8|(b12^b1)>>24;b11+=b12;b6=(b6^b11)<<7|(b6^b11)>>25;
        b2+=b7;b13=(b13^b2)<<16|(b13^b2)>>16;b8+=b13;b7=(b7^b8)<<12|(b7^b8)>>20;b2+=b7;b13=(b13^b2)<<8|(b13^b2)>>24;b8+=b13;b7=(b7^b8)<<7|(b7^b8)>>25;
        b3+=b4;b14=(b14^b3)<<16|(b14^b3)>>16;b9+=b14;b4=(b4^b9)<<12|(b4^b9)>>20;b3+=b4;b14=(b14^b3)<<8|(b14^b3)>>24;b9+=b14;b4=(b4^b9)<<7|(b4^b9)>>25;

        z-=1;
    }
    while(z>0);

    *o=(b0+*k);*(o+1)=(b1+*(k+1));*(o+2)=(b2+*(k+2));*(o+3)=(b3+*(k+3));*(o+4)=(b4+*(k+4));*(o+5)=(b5+*(k+5));*(o+6)=(b6+*(k+6));*(o+7)=(b7+*(k+7));*(o+8)=(b8+*(k+8));*(o+9)=(b9+*(k+9));*(o+10)=(b10+*(k+10));*(o+11)=(b11+*(k+11));*(o+12)=(b12+*(k+12));*(o+13)=(b13+*(k+13));*(o+14)=(b14+*(k+14));*(o+15)=(b15+*(k+15));
};

// ChaCha20 Crypthography Function;
static inline void cc(unsigned int *k,unsigned char *o,unsigned char *l)
{
    unsigned int b0=*k,b1=*(k+1),b2=*(k+2),b3=*(k+3),b4=*(k+4),b5=*(k+5),b6=*(k+6),b7=*(k+7),b8=*(k+8),b9=*(k+9),b10=*(k+10),b11=*(k+11),b12=*(k+12),b13=*(k+13),b14=*(k+14),b15=*(k+15);

    while(o<l)
    {
        *(unsigned int*)o^=b0;*(unsigned int*)(o+4)^=b1;*(unsigned int*)(o+8)^=b2;*(unsigned int*)(o+12)^=b3;
        *(unsigned int*)(o+16)^=b4;*(unsigned int*)(o+20)^=b5;*(unsigned int*)(o+24)^=b6;*(unsigned int*)(o+28)^=b7;

        *(unsigned int*)(o+32)^=b8;*(unsigned int*)(o+36)^=b9;*(unsigned int*)(o+40)^=b10;*(unsigned int*)(o+44)^=b11;
        *(unsigned int*)(o+48)^=b12;*(unsigned int*)(o+52)^=b13;*(unsigned int*)(o+56)^=b14;*(unsigned int*)(o+60)^=b15;

        o+=64;
    };
};

// Memory-Safe ChaCha20 Crypthography Function;
static inline void cs(unsigned int *k,unsigned char *o,unsigned char *l)
{
    unsigned int b0=*k,b1=*(k+1),b2=*(k+2),b3=*(k+3),b4=*(k+4),b5=*(k+5),b6=*(k+6),b7=*(k+7),b8=*(k+8),b9=*(k+9),b10=*(k+10),b11=*(k+11),b12=*(k+12),b13=*(k+13),b14=*(k+14),b15=*(k+15);

    while(o+64<l)
    {
        *(unsigned int*)o^=b0;*(unsigned int*)(o+4)^=b1;*(unsigned int*)(o+8)^=b2;*(unsigned int*)(o+12)^=b3;
        *(unsigned int*)(o+16)^=b4;*(unsigned int*)(o+20)^=b5;*(unsigned int*)(o+24)^=b6;*(unsigned int*)(o+28)^=b7;

        *(unsigned int*)(o+32)^=b8;*(unsigned int*)(o+36)^=b9;*(unsigned int*)(o+40)^=b10;*(unsigned int*)(o+44)^=b11;
        *(unsigned int*)(o+48)^=b12;*(unsigned int*)(o+52)^=b13;*(unsigned int*)(o+56)^=b14;*(unsigned int*)(o+60)^=b15;

        o+=64;
    };

    unsigned char s[4];

    while(o<l)
    {
        *(unsigned int*)s=*(unsigned int*)o^*k;k+=1;

        if(o<l){*o=*s;if(o+1<l){*(o+1)=*(s+1);if(o+2<l){*(o+2)=*(s+2);if(o+3<l){*(o+3)=*(s+3);}}}}

        o+=4;
    };
};
