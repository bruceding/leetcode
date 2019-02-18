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
    string strWithout3a3b(int A, int B) {
        string result;
        if (A > (B+1) *2 || B > (A+1) * 2) {
            return result;
        }
        string last;
        while(A > 0  ||  B>0) {
           if (A -B >= 2 && last != "a") {
                result += "aa";
                A -=2;
                last ="a";
           } else if (B -A >= 2 && last != "b") {
                result += "bb";
                B -=2;
                last = "b";
           } else if (A >0 && last != "a") {
                result += "a";
                A -=1;
                last ="a";
           } else if (B > 0 && last != "b") {
                result += "b";
                B -=1;
                last ="b";
           } 
        } 
        return result;
        
    }
};
int main() {
    Solution sol;
    string result;
    result = sol.strWithout3a3b(1, 2);
    std::cout << result << std::endl;

    result = sol.strWithout3a3b(4, 1);
    std::cout << result << std::endl;
    result = sol.strWithout3a3b(8, 3);
    std::cout << result << std::endl;
    result = sol.strWithout3a3b(10, 3);
    std::cout << result << std::endl;
    return 0;
}
