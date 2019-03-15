#include<string>
#include<iostream>
using std::string;
class Solution {
public:
    string convert(string s, int numRows) {
       int len = s.size(); 
       string ret;
       if (numRows <= 1) {
            ret = s;
            return ret;
       }
       int off = numRows -2 + numRows;
       for (int i = 1; i <= numRows; i++) {
           int index = i; 
           while(index <= len) {
               if (index == i) {
                    ret += s[index -1];
                    index += off;
                    continue;
               }
               if (i == 1 || i == numRows) {
                    ret += s[index -1];
                    index += off;
                    continue;
               }

               int pre = index - (i-1) * 2;
               ret += s[pre-1];
               ret += s[index-1];
               index += off;
           }
           if (i !=1 && i != numRows) {
                int pre = index - (i-1) * 2;
                if (pre <= len && pre > 0) {
                    ret += s[pre-1];
                }
           }
       }
       return ret;
    }
};
int main() {
    string str="PAYPALISHIRING";
    Solution sol;
    string ret;
    ret = sol.convert(str, 3);
    std::cout << ret << std::endl;
    ret = sol.convert(str, 4);
    std::cout << ret << std::endl;
    ret = sol.convert(str, 5);
    std::cout << ret << std::endl;
    str = "PAY";
    ret = sol.convert(str, 10);
    std::cout << ret << std::endl;
    str = "A";
    ret = sol.convert(str, 1);
    std::cout << ret << std::endl;
    str = "ABCDEFGH";
    ret = sol.convert(str, 2);
    std::cout << ret << std::endl;
    return 0;
}
