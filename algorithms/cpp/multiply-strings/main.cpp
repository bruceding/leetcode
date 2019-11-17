#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
         reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int len1 = num1.size();
        int len2 = num2.size();
        int c = 0;
        int i = 0;
        int j = 0;
        string ret(len1 + len2 + 1, '0');

        for (i = 0; i < len1; i++)
        {
            c = 0;
            for (j = 0; j < len2; j++)
            {
                int num = (num1[i] - '0') * (num2[j] - '0') + c + (ret[i + j] - '0');

                ret[i + j] = num % 10 + '0';
                c = num / 10;
            }

            int k = i + j;
            while (c)
            {
                int num = c + ret[k] - '0';

                ret[k++] = num % 10 + '0';
                c = num / 10;
            }
        }

        string::iterator iter = ret.end() - 1;
        while (iter != ret.begin() && (*iter) == '0')
            iter--;

        iter++;
        ret.erase(iter, ret.end());
        reverse(ret.begin(), iter);

        return ret;
    }
};
int main() {
    Solution sol;
    string num1 = "1123";
    string num2 = "456";
    string ret = sol.multiply(num1, num2); 
    std::cout << ret << std::endl;

    num1 = "999";
    num2 = "999";
    ret = sol.multiply(num1, num2); 
    std::cout << ret << std::endl;

    num1 = "123";
    num2 = "456";
    ret = sol.multiply(num1, num2); 
    std::cout << ret << std::endl;
    return 0;
}
