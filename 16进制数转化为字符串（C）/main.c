//
//  main.c
//  16进制数转化为字符串（C）
//
//  Created by 范云飞 on 2017/6/28.
//  Copyright © 2017年 范云飞. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

char a2x(char ch)
{
    switch(ch)
    {
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        case 'A':
        case 'a':
            return 10;
        case 'B':
        case 'b':
            return 11;
        case 'C':
        case 'c':
            return 12;
        case 'D':
        case 'd':
            return 13;
        case 'E':
        case 'e':
            return 14;
        case 'F':
        case 'f':
            return 15;
        default:
            break;;
    }
    
    return 0;
}

int hexstringtobyte(char *in, unsigned char *out);
int hexstringtobyte(char *in, unsigned char *out) {
    int len = (int)strlen(in);
    char *str = (char *)malloc(len);
    memset(str, 0, len);
    memcpy(str, in, len);
    for (int i = 0; i < len; i+=2) {
        //小写转大写
        if(str[i] >= 'a' && str[i] <= 'f') str[i] = str[i] & ~0x20;
        if(str[i+1] >= 'a' && str[i] <= 'f') str[i+1] = str[i+1] & ~0x20;
        //处理第前4位
        if(str[i] >= 'A' && str[i] <= 'F')
            out[i/2] = (str[i]-'A'+10)<<4;
        else
            out[i/2] = (str[i] & ~0x30)<<4;
        //处理后4位, 并组合起来
        if(str[i+1] >= 'A' && str[i+1] <= 'F')
            out[i/2] |= (str[i+1]-'A'+10);
        else
            out[i/2] |= (str[i+1] & ~0x30);
    }
    free(str);
    return 0;
}

int main(int argc, const char * argv[]) {
    
#pragma mark - 16进制转文本字符串
    char str1[] = "6E6973742E746563686D6F62696C65206B65793932303030303032000000000000000000000000000000000000000000000000010001000101000000050200010000000105000000D40000809E000000000000000000000000000000000000084E495354303030320000000000000000000000000000000000000000000000000000000000000000000000000000";
    char str2[1024*150];
    int i;
    
    i = 0;
    while(str1[i])
    {
        str2[i >> 1] = (a2x(str1[i]) << 4) | a2x(str1[i + 1]);
        i += 2;
    }
    str2[i >> 1] = '\0';
    
    printf("%s\n", str2);
    
#pragma mark - 16进制转 unsigned char []
    char *str = "fa32333435363738393a3b3c3d3e3f40";
    unsigned char temp[16] = {0};
    hexstringtobyte(str, temp);
    for (int i = 0; i < 16; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");
    
#pragma mark - 16进制字符串转 int
    char s[50] = "000000D4";
    scanf("%s",s);
    int t;
    long sum=0;
    for(int i=0;s[i];i++){
        if(s[i]<='9')
            t=s[i]-'0';
        else
            t=s[i]-'A'+10;
        sum=sum*16+t;
    }
    printf("%ld\n",sum);
    return 0;
}




