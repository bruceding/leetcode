/*
 * =====================================================================================
 *
 *       Filename:  count_say.c
 *
 *    Description:  
 *    1 is read off as "one 1" or 11.
 *    11 is read off as "two 1s" or 21.
 *    21 is read off as "one 2, then one 1" or 1211.
 *
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
#include <stdlib.h>
char* countAndSay(int n) {
   if (n == 1) {
       return "1";
   } 
   char dest[100];
   char str[100];
   char *ret = dest;
   int i;
   int j;
   int k;
   sprintf(str, "%d", n);
   int len = strlen(str); 

   for ( i = 0; i < len ; i++) {
       for(j = i; str[j] == str[i] && j < len; j++);

       dest[k++] = (j-i) + '0';
       dest[k++] = str[i];
       i = j-1;
   }


   dest[k] = '\0';
   return ret;
}
int main(int argc, char** argv) {
    
    int i = 2;
    char* ret = countAndSay(i);
    printf("%d\n", i);
    printf("%s\n", ret);
    return 0;
}

