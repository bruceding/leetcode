#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();

        int i = size -1;
        int num = 1; // add number
        int tmp = 0;
        int total =0;
        do {
            total = digits[i] + tmp + num;
            if (total < 10) {
                digits[i] = total;
                tmp = 0; // 进位清0
                break;
            }
            tmp = total / 10;
            digits[i] = total - tmp * 10;
            num = 0; // when add plus one, set zero

        } while(--i>=0 && tmp !=0);

        if (tmp != 0) {
            digits.insert(digits.begin(), tmp);
        }

        return digits;

    }
};
void printVector(const vector<vector<int>> &vec) {
    for (auto v : vec) {
        for (auto i : v) {
            std::cout << i << "\t";
        }
        std::cout << std::endl; 
    }
    std::cout << std::endl; 
}
int main() {
    Solution sol;
    return 0;
}
