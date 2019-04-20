#include<iostream>
#include<vector>
#include<stack>
using std::vector;
using std::string;
using std::stack;
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> vec;
        split_string(path, vec, "/");
        stack<string> st;

        for (auto v: vec) {
            if (v.empty()) {
                continue;
            }
            
            if (v == "..") {
               if (st.empty()) {
                    continue;
               } else {
                    st.pop();
               } 
            } else if (v == ".") {
                continue;
            } else {
                st.push(v);
            }
        }
        if (st.empty()) {
            return "/";
        }

        string ret;

        while(!st.empty()) {
            ret = "/" + st.top() + ret;
            st.pop();
        }
        return ret;
    }

    void split_string(const std::string& s, std::vector<std::string>& v, const std::string& c)
    {
      std::string::size_type pos1, pos2;
      pos2 = s.find(c);
      pos1 = 0;
      while(std::string::npos != pos2)
      {
        v.push_back(s.substr(pos1, pos2-pos1));

        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
      }
      if(pos1 != s.length())
        v.push_back(s.substr(pos1));
    }

};

int main() {
    Solution sol;
    string str;
    string ret;
    str = "/home/";
    ret = sol.simplifyPath(str);
    std::cout << str << "\t" << ret << std::endl;
    str = "/.././";
    ret = sol.simplifyPath(str);
    std::cout << str << "\t" << ret << std::endl;

    str = "/home//foo/";
    ret = sol.simplifyPath(str);
    std::cout << str << "\t" << ret << std::endl;

    str = "/a/./b/../../c/";
    ret = sol.simplifyPath(str);
    std::cout << str << "\t" << ret << std::endl;

    str = "/a/../../b/../c//.//";
    ret = sol.simplifyPath(str);
    std::cout << str << "\t" << ret << std::endl;

    str = "/a//b////c/d//././/..";
    ret = sol.simplifyPath(str);
    std::cout << str << "\t" << ret << std::endl;

    return 0;
}
