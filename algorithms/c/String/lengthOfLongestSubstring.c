/*
 * =====================================================================================
 *
 *       Filename:  lengthOfLongestSubstring.c
 *
 *    Description:  
 * Given a string, find the length of the longest substring without repeating characters.
 *
 * Examples:
 *
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 *
 * Given "bbbbb", the answer is "b", with the length of 1.
 *
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 *
 *        Version:  1.0
 *        Created:  2017/05/17 21时51分56秒
 *       Compiler:  gcc
 *
 *         Author:  bruce ding , dingjingdjdj@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>

int countLength(char* s, char* p) {
    if (!(*p) || !(*s)) {
        return 0;
    }

    char* tmp = s;
    int i = 1;
    int max = 1;
    p++;
    while (*p) {
        i = 1;
        tmp = s;
        while (*tmp && tmp != p) {
            if (*p != *tmp++) {
                i++;
            } else {
                if (i > max) {
                    max = i;
                }
                return max; 
            }
        }

        if (i > max) {
            max = i;
        }
        p++;
    }

    return  max;
}

int lengthOfLongestSubstring(char* s) {
    int max = 0;
    int i = 0;
    char* p;
    char* tmp;

    while (*s) {
       p = s; 
       i = 0;

       i = countLength(s, p);

//       printf("%d\n", i);
       if (i > max) {
           max = i;
       }

       s++;

    }

    return max;
}

// 充分利用空间概念
int lengthOfLongestSubstring1(char* s)
{
    int len=0;
    char *end=s,*temp;
    char* addressTable[128]={NULL};
    while(*end){
        temp = addressTable[*end];
        addressTable[*end]=end;
        if(temp>=s){
        len=end-s>len?end-s:len;
        s = temp+1;
        }end++;
    }
    len=end-s>len?end-s:len;
    return len;
}

int main(int argc, char** argv) {

    char *s = "c";

    int i = lengthOfLongestSubstring(s);

    printf("%s %d\n", s, i);

    return 0;
}


