#include<string>
#include<iostream>
#include<vector>
#include<unordered_map>
using std::string;
using std::vector;
using std::unordered_map;
typedef unordered_map<char, vector<string> > PhoneMap; 
class Solution {
public:
    Solution() {
        _map['2'] = {"a", "b", "c"};
        _map['3'] = {"d", "e", "f"};
        _map['4'] = {"g", "h", "i"};
        _map['5'] = {"j", "k", "l"};
        _map['6'] = {"m", "n", "o"};
        _map['7'] = {"p", "q", "r", "s"};
        _map['8'] = {"t", "u", "v"};
        _map['9'] = {"w", "x", "y", "z"};
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        vector<string> tmp;
        for (int i = 0; i < digits.size(); i++) {
            if (i == 0) {
                ret = _map[digits[i]];
            } else {
                tmp = _map[digits[i]];
                vector<string> next;
                for (int j=0; j < ret.size(); j++) {
                    for (int k=0; k < tmp.size(); k++) {
                        next.push_back(ret[j] + tmp[k]);
                    }
                }
                ret = next;
            }
        }
        return ret;
    }
    void toString(const vector<string> &ret)  const {
       for (auto s : ret) {
          std::cout << s << "\t" ;
       } 
       std::cout << std::endl;
    }
private:
    PhoneMap _map;
};
int main() {
    Solution sol;
    string digits = "2";
    vector<string> ret;
    ret = sol.letterCombinations(digits);
    std::cout << digits << "\t" << ret.size() << std::endl;
    sol.toString(ret);

    digits = "236";
    ret = sol.letterCombinations(digits);
    std::cout << digits << "\t" << ret.size() << std::endl;
    sol.toString(ret);
    return 0;
}
