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
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) {
            return false;
        }
        if (A.size() < 2) {
            return false;
        }
        if (A == B) {
           for (int i = 0; i < A.size() -1; i++) {
               for (int j=i+1; j < A.size(); j++) {
                    if (A[i] == A[j]) {
                        return true;
                    } 
               }
           }
        }

        int buddy  = 0;
        for (int i = 0; i < A.size() -1; i++ ) {
            if (A[i] != B[i]) {
                for (int j = i+1; j < B.size(); j++) {
                   if (A[j] != B[j] && A[i] == B[j] && A[j] == B[i]) {
                       buddy++;     
                   } 
                }
            }    
            if (buddy > 1) {
                return false;
            }
        }
        return buddy == 1;
    }
};
int main() {
    Solution sol;
    string a, b;
    a = "", b="aa";
    std::cout << a << "\t" << b << "\t" << sol.buddyStrings(a, b) << std::endl;
    a = "ab", b="ba";
    std::cout << a << "\t" << b << "\t" << sol.buddyStrings(a, b) << std::endl;
    a = "ab", b="ab";
    std::cout << a << "\t" << b << "\t" << sol.buddyStrings(a, b) << std::endl;
    a = "aa", b="aa";
    std::cout << a << "\t" << b << "\t" << sol.buddyStrings(a, b) << std::endl;
    a = "a", b="a";
    std::cout << a << "\t" << b << "\t" << sol.buddyStrings(a, b) << std::endl;
    a = "aaaaaaabc", b="aaaaaaacb";
    std::cout << a << "\t" << b << "\t" << sol.buddyStrings(a, b) << std::endl;
    a = "abcd", b="badc";
    std::cout << a << "\t" << b << "\t" << sol.buddyStrings(a, b) << std::endl;
    a = "abab", b="abab";
    std::cout << a << "\t" << b << "\t" << sol.buddyStrings(a, b) << std::endl;
    a = "abcd", b="dbca";
    std::cout << a << "\t" << b << "\t" << sol.buddyStrings(a, b) << std::endl;
    return 0;
}
