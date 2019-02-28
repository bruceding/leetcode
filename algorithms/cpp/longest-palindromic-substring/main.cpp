/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2019/02/18 08时46分02秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include<string>
#include<iostream>
using std::string;
class Solution {
public:
    string longestPalindrome(string s) {
        string result ;
        if (s.empty()) {
            return result; 
        }
        if (s.size() == 1) {
            return s; 
        }
        int max = 0;
        int j = s.size() - 1;
        // i < j - max
        for (int i = 0; i < j ; i++) {
            for(int k = j; k >= i; k-- ) {
               if((s[i] == s[k]) && (k-i + 1 > max)) {
                   if (isPalindrome(s, i , k)) {
                        max = k-i + 1;
                        result = s.substr(i, max);
                   }
               } 
            }
        }
        return result;
    }
    bool isPalindrome(const string& s, int i, int j) {
        while ( i <= j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else {
                return false;
            }
        }
        return true; 
    }
};
int main() {
    Solution sol;
    string a;
    a = "babad";
    std::cout << sol.longestPalindrome(a) << std::endl;
    a = "aa";
    std::cout << sol.longestPalindrome(a) << std::endl;
    a = "a";
    std::cout << sol.longestPalindrome(a) << std::endl;
    a = "cbbd";
    std::cout << sol.longestPalindrome(a) << std::endl;
    a = "cbbdabcdedcba";
    std::cout << sol.longestPalindrome(a) << std::endl;
    a = "ac";
    std::cout << sol.longestPalindrome(a) << std::endl;
    a = "abb";
    std::cout << sol.longestPalindrome(a) << std::endl;
    return 0;
}
