/*
 * =====================================================================================
 *
 *       Filename:  count_say.c
 *
 *    Description:  
 * Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 *        Version:  1.0
 *        Created:  2016/10/22 18时25分32秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include<stdio.h>
#include <limits.h>
#include <stdlib.h>
int reverse(int x) {
    if (x == INT_MAX || x == INT_MIN) {
        return 0;
    }

    int flag = 1;
    if (x < 0) {
        flag = -1;
        x = x * (-1);
    }

    int ret = 0;
    int k = 0;

    while (x) {
        k = x % 10;

        if (ret > (INT_MAX/10) ) {
            return 0;
        }

        ret = 10 * ret + k;
        x /= 10;
    }

    return flag * ret; 
}
int main(int argc, char** argv) {

    int x = atoi( argv[1] );

    int i = reverse(x);

    printf("%d\n", i);
    return 0;
}
