/*
 * =====================================================================================
 *
 *       Filename:  strStr.c
 *
 *    Description:  
 * Implement strStr().
 *
 * Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 *
 *        Version:  1.0
 *        Created:  2017/05/21 22时07分07秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strStr(char* haystack, char* needle) {
    if (!haystack || !needle ) {
        return -1;
    }

    if (*needle == '\0') {
        return 0;
    }

    char* find = haystack;
    char* str = needle;
    char* p;

    int length  = strlen(needle);

    while(*find) {
        if (*find == *needle) {
           str = needle; 
           p = find;

           while (*p == *str && *str != '\0' && *p != '\0') {
               p++;
               str++;
           } 
           if (p - find == length) {
               return find - haystack;
           }
        } 

        find++;
    }

    return -1;
}

int strStr1(char* haystack, char* needle) {
    int i,j;
    int hlen = strlen(haystack);
    int nlen = strlen(needle);

    if (nlen == 0)
        return 0;

    for (i = 0 ; i <= hlen - nlen; i ++) {
        for (j = 0 ; j < nlen; j ++ ) {
            if (haystack[i+j] != needle[j])
                break;
        }
        if (j == nlen)
            return i;
    }
    return -1;
}

int main(int argc, char** argv) {
    char* haystack = argv[1];
    char* needle = argv[2];
//    char* haystack = "";
//    char* needle = "";

    int i = strStr(haystack, needle);

    printf("%d\n", i);
    return 0;
}
