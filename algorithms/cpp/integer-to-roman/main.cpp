#include<iostream>
#include<string>
#include<unordered_map>
using std::string;
using std::unordered_map;
class Solution {
public:
    Solution() {
        _mappings.insert(
             {
                {1, "I"},
                {2, "II"},
                {3, "III"},
                {4, "IV"},
                {5, "V"},
                {6, "VI"},
                {7, "VII"},
                {8, "VIII"},
                {9, "IX"}
//                {10, "X"},
//                {40, "XL"},
//                {50, "L"},
//                {90, "XC"},
//                {100, "C"},
//                {400, "CD"},
//                {500, "D"},
//                {900, "CM"},
//                {1000, "M"}
             }         
        );
    }
    string intToRoman(int num) {
        string ret;
        int tmp = num;
        int n = 0;
        while (tmp) {
           if (tmp >= 1000) {
                n = tmp /1000;
                for (int i = 0; i < n; i++) {
                    ret += "M";
                }
                tmp -= n * 1000;
                continue;
           }
           if (tmp >= 900) {
                ret += "CM";
                tmp -= 900;
                continue;
           }
           if (tmp >= 500) {
                ret += "D";
                tmp -= 500;
                continue;
           }
           if (tmp >= 400) {
                ret += "CD";
                tmp -= 400;
                continue;
           }
           if (tmp >= 100) {
                n = tmp /100;
                for (int i = 0; i < n; i++) {
                    ret += "C";
                }
                tmp -= n * 100;
                continue;
           }
           if (tmp >= 90) {
                ret += "XC";
                tmp -= 90;
                continue;
           }
           if (tmp >= 50) {
                ret += "L";
                tmp -= 50;
                continue;
           }
           if (tmp >= 40) {
                ret += "XL";
                tmp -= 40;
                continue;
           }
           if (tmp >= 10) {
                n = tmp /10;
                for (int i = 0; i < n; i++) {
                    ret += "X";
                }
                tmp -= n * 10;
                continue;
           }
           if (tmp < 10) {
               ret += _mappings[tmp];
               tmp = 0;
               continue;
           }
        }
        return ret;
    }
private:
    unordered_map<int, string> _mappings;
};
int main() {
    int num = 3;
    Solution sol;
    string ret;
    ret = sol.intToRoman(num);
    std::cout << num << "\t" << ret << std::endl;

    num = 4;
    ret = sol.intToRoman(num);
    std::cout << num << "\t" << ret << std::endl;

    num = 9;
    ret = sol.intToRoman(num);
    std::cout << num << "\t" << ret << std::endl;

    num = 58;
    ret = sol.intToRoman(num);
    std::cout << num << "\t" << ret << std::endl;

    num = 1994;
    ret = sol.intToRoman(num);
    std::cout << num << "\t" << ret << std::endl;

    num = 200;
    ret = sol.intToRoman(num);
    std::cout << num << "\t" << ret << std::endl;

    num = 225;
    ret = sol.intToRoman(num);
    std::cout << num << "\t" << ret << std::endl;

    num = 3876;
    ret = sol.intToRoman(num);
    std::cout << num << "\t" << ret << std::endl;
    return 0;
}
