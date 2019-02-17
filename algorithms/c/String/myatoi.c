/*
 * =====================================================================================
 *
 *       Filename:  myatoi.c
 *
 *    Description:  Implement atoi to convert a string to an integer.
 *    
 *
 *        Version:  1.0
 *        Created:  2016/10/23 23时03分30秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include<stdio.h>
#include <stdlib.h>
#define INT_MAX 2147483647
#define INT_MIN (- INT_MAX - 1)
#define NULL 0

int myAtoi(char* str) {

    if (!str) {
        return NULL;
    }

    int i = 1;
    int ret = 0;
    char *p = str;

    while(*p == ' ' && ++p);

    if (*p == '-') {
        i = -1;
        p++;
    } else if (*p == '+') {
        p++;
    }

    while(*p) {

        // 中间有非法字符
        if (*p < '0'  ||  *p > '9') {
            break;
        }
       
        // 主要考虑如何判断大于INT_MAX 以及 小于 INT_MIN
        if (i > 0 && (ret > INT_MAX/10 || ( ret == INT_MAX/10 && (*p - '0') > INT_MAX%10))) {
            ret = INT_MAX;
            break;
        }

        if (i < 0 && (ret >(unsigned)INT_MIN/10 || (ret == (unsigned)INT_MIN/10 && (*p - '0') > (unsigned)INT_MIN % 10))) {
            ret = INT_MIN;
            break;
        }

        ret = ret * 10 + (*p - '0');
        p++;
    }

    ret = i * ret;

    return ret;
}
int main(int argc, char** argv) {

    char* str = "-2147483649";
        
    int ret = myAtoi(str);

    printf("%s\n", str);
    printf("%d\n", ret);

    return 0;
}


