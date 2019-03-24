#include<string>
#include<iostream>
#include<stack>
using std::string;
class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 0) {
            return true;
        }
        if (s.size() % 2 != 0) {
            return false; 
        }
        std::stack<char> list;
        list.push(s[0]);
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                list.push(s[i]);
            } else {
                if (list.empty()) {
                    return false;
                }
                if(s[i] == ')' && list.top() == '(') {
                    list.pop();
                    continue;
                }
                if(s[i] == ']' && list.top() == '[') {
                    list.pop();
                    continue;
                }
                if(s[i] == '}' && list.top() == '{') {
                    list.pop();
                    continue;
                }
            }
        }
        return list.empty();   
    }
};
int main() {
    string s = "";
    Solution sol;
    bool ret;
    ret = sol.isValid(s);
    std::cout << s << "\t" << ret << std::endl;
    s = "()";
    ret = sol.isValid(s);
    std::cout << s << "\t" << ret << std::endl;

    s = "()[]{}";
    ret = sol.isValid(s);
    std::cout << s << "\t" << ret << std::endl;

    s = "(]";
    ret = sol.isValid(s);
    std::cout << s << "\t" << ret << std::endl;

    s = "([)]";
    ret = sol.isValid(s);
    std::cout << s << "\t" << ret << std::endl;

    s = "{[]}";
    ret = sol.isValid(s);
    std::cout << s << "\t" << ret << std::endl;

    s = "(()])}[}[}[]][}}[}{})][[(]({])])}}(])){)((){";
    ret = sol.isValid(s);
    std::cout << s << "\t" << ret << std::endl;
    return 0;
}
