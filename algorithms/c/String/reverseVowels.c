/*
 * =====================================================================================
 *
 *       Filename:  reverseVowels.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016/10/22 11时46分32秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include<stdio.h>
// 英语元音交换
char* reverseVowels(char* s) {

    int size = strlen(s);

    int i = 0;
    int j = size - 1;
    char tmp;

    for (i = 0; i < j ; i++) {
        if (s[i] == 'a' || s[i] == 'i' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'I' || s[i] == 'E' || s[i] == 'O' || s[i] == 'U') {
            while (i < j && s[j] != 'a' && s[j] != 'i' &&  s[j] != 'e' &&  s[j] != 'o' && s[j] != 'u' && s[j] != 'A' && s[j] != 'I' && s[j] != 'E' && s[j] != 'O' && s[j] != 'U') {
               j--; 
            }

            if (i < j) {
                tmp = s[i];
                s[i] = s[j];
                s[j] = tmp; 
                // 找到往前推进
                j--;
            }
        }
    }
    return s;
}
int main(int argc, char** argv) {

    char str[] = "leetcode";

    char* dest = reverseVowels(str);

    printf("%s\n", dest);
    printf("%d\n", sizeof(char));
    return 0;
}

