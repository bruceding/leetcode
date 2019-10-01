#include "string"
#include "iostream"

using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        
        int min = a.size() > b.size() ? b.size() : a.size();
        
        string ret ;
        
        int d = 0;
        int i = 0;
        while (i < min) {
            int j = a[a.size()-i-1] - '0';
            int k = b[b.size() -i -1] - '0';
            if (j + k == 0){
                 ret = std::to_string(d) + ret;
                d = 0;
            } else if (j + k == 1) {
                if (d == 0) {
                    ret = std::to_string(1) + ret;
                    d = 0;
                } else {
                    ret = std::to_string(0) + ret;
                    d = 1;
                }
            } else if (j + k == 2) {
                if (d == 0) {
                     ret = std::to_string(0) + ret;
                     d = 1;
                } else {
                    ret = std::to_string(1) + ret;
                     d = 1;
                }
            }
            i++;
        }
       
        if (a.size() > min) {
            for (int i = a.size() - min -1; i >= 0; i--) {
                int j = a[i] - '0';
                if (j + d == 0) {
                     ret = std::to_string(0) + ret;
                     d = 0;
                } else if (j + d == 1) {
                     ret = std::to_string(1) + ret;
                     d = 0;
                } else {
                     ret = std::to_string(0) + ret;
                     d = 1;
                } 
            }                  
        } else if (b.size() > min) {
            for (int i = b.size() - min -1; i >= 0; i--) {
                int j = b[i] - '0';
                if (j + d == 0) {
                     ret = std::to_string(0) + ret;
                     d = 0;
                } else if (j + d == 1) {
                     ret = std::to_string(1) + ret;
                     d = 0;
                } else {
                     ret = std::to_string(0) + ret;
                     d = 1;
                } 
            }                  

        }
        if (d > 0) {
            ret = "1" + ret;
        }
        return ret;
    }
};
int main() {
    Solution sol;
    string ret = sol.addBinary("11", "01");
    std::cout << ret << std::endl;

    ret = sol.addBinary("1010", "1011");
    std::cout << ret << std::endl;

    ret = sol.addBinary("111", "111");
    std::cout << ret << std::endl;

    ret = sol.addBinary("11", "1");
    std::cout << ret << std::endl;

    ret = sol.addBinary("100", "110010");
    std::cout << ret << std::endl;
    return 0;
}
