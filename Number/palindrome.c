/*
 * =====================================================================================
 *
 *       Filename:  palindrome.c
 *
 *    Description:  
 * Determine whether an integer is a palindrome. Do this without extra space.
 *
 *        Version:  1.0
 *        Created:  2017/05/18 22时40分36秒
 *       Compiler:  gcc
 *
 *         Author:  bruce ding , dingjingdjdj@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool isPalindrome(int x) {

    if (x < 0) {
        return false;
    }

    if (x < 10 ) {
        return true;
    }

    int i=0, j=0;

    int k;
    while (x) {
       k = x%10; 

       if (j == 0 && k == 0) {
          return false;
       }

       j = 10 * j + k;

       i = x/10;

       if (i == j || j == x) {
           return true;
       }
       if (i < j) {
           return false;
       }

       x = i;

    }

    return false;
}

int main(int argc, char** argv) {

    int x = atoi( argv[1] );
    bool i = isPalindrome(x);

    printf("%d", i);
    return 0;
}
