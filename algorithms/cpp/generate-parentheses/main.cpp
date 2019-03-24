#include<string>
#include<vector>
#include<iostream>
using std::string;
using std::vector;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;

        backtrack(ret, "", 0, 0, n);
        return ret;
    }
    void backtrack(vector<string> &ret, string cur, int open, int close, int max) {
        if(cur.size() == max*2) {
            ret.push_back(cur);
            return;
        }
        if (open < max) {
            backtrack(ret, cur+"(", open+1, close, max);
        }
        if (close < open) {
            backtrack(ret, cur+")", open, close+1, max);
        }
    }
    void toString(const vector<string> &ret)  const {
       for (auto s : ret) {
          std::cout << s << "\t" ;
       } 
       std::cout << std::endl;
    }
};
int main() {
    int n = 1;
    Solution sol;
    vector<string> ret;
    ret = sol.generateParenthesis(n);
    sol.toString(ret);
    
    n = 2;
    ret = sol.generateParenthesis(n);
    sol.toString(ret);

    n = 3;
    ret = sol.generateParenthesis(n);
    sol.toString(ret);

    n = 4;
    ret = sol.generateParenthesis(n);
    sol.toString(ret);
    return 0;
}
