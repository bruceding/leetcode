#include<iostream>
#include<string>
using std::string;
class Solution {
public:
    int romanToInt(string s) {
        int ret = 0;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            if (s[i] == 'M') {
                ret += 1000;
                continue;
            }
            if (i +1 < len && s[i] == 'C' && s[i+1] == 'M') {
                ret += 900;
                i++;
                continue;
            }
            if (s[i] == 'D') {
                ret += 500;
                continue;
            }
            if (i +1 < len && s[i] == 'C' && s[i+1] == 'D') {
                ret += 400;
                i++;
                continue;
            }
            if (s[i] == 'C') {
                ret += 100;
                continue;
            }
            if (i +1 < len && s[i] == 'X' && s[i+1] == 'C') {
                ret += 90;
                i++;
                continue;
            }
            if (s[i] == 'L') {
                ret += 50;
                continue;
            }
            if (i +1 < len && s[i] == 'X' && s[i+1] == 'L') {
                ret += 40;
                i++;
                continue;
            }
            if (s[i] == 'X') {
                ret += 10;
                continue;
            }
            if (i +1 < len && s[i] == 'I' && s[i+1] == 'X') {
                ret += 9;
                i++;
                continue;
            }
            if (s[i] == 'V') {
                ret += 5;
                continue;
            }
            if (i +1 < len && s[i] == 'I' && s[i+1] == 'V') {
                ret += 4;
                i++;
                continue;
            }
            if (s[i] == 'I') {
                ret += 1;
                continue;
            }
        }

        return ret;
    }
};
int main() {
    string str = "III";
    Solution sol;
    int ret;
    ret = sol.romanToInt(str);
    std::cout << str << "\t" << ret << std::endl;

    str = "IV";
    ret = sol.romanToInt(str);
    std::cout << str << "\t" << ret << std::endl;

    str = "IX";
    ret = sol.romanToInt(str);
    std::cout << str << "\t" << ret << std::endl;

    str = "LVIII";
    ret = sol.romanToInt(str);
    std::cout << str << "\t" << ret << std::endl;

    str = "MCMXCIV";
    ret = sol.romanToInt(str);
    std::cout << str << "\t" << ret << std::endl;

    str = "MMMDCCCLXXVI";
    ret = sol.romanToInt(str);
    std::cout << str << "\t" << ret << std::endl;

    str = "CCXXV";
    ret = sol.romanToInt(str);
    std::cout << str << "\t" << ret << std::endl;

    str = "CC";
    ret = sol.romanToInt(str);
    std::cout << str << "\t" << ret << std::endl;
    return 0;
}
