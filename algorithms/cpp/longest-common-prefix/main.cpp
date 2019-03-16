#include<string>
#include<iostream>
#include<vector>
using std::string;
using std::vector;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string ret = "";
        if (strs.size() == 0) {
            return ret;
        }
        auto first_str = strs[0];
        for (int i = 0; i < first_str.size(); i++) {
            bool flag = true;
            for (auto &str : strs) {
               if (i >= str.size()) {
                    flag = false;
                    break;
               } 
               if(first_str[i] != str[i]) {
                    flag = false; 
                    break;
               } 
            }
            if (flag) {
                ret += first_str[i];
            } else {
                break;
            }
        }
        return ret;
    }
};
int main() {
    vector<string> strs {"flower","flow","flight"};
    Solution sol;
    string ret;
    ret = sol.longestCommonPrefix(strs);
    std::cout << ret << std::endl;
    strs = {"dog","racecar","car"};
    ret = sol.longestCommonPrefix(strs);
    std::cout << ret << std::endl;
    strs = {"dog"};
    ret = sol.longestCommonPrefix(strs);
    std::cout << ret << std::endl;
    strs = { "dogdogdog", "dog"};
    ret = sol.longestCommonPrefix(strs);
    std::cout << ret << std::endl;
    return 0;
}
