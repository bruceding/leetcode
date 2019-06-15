#include<iostream>
#include<vector>
#include <map>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int len = nums.size();
        for (int i = 1 ; i < len ; i++) {
            for (int j = i; j-1 >=0; j--) {
                if (nums[j] < nums[j-1]) {
                    int tmp = nums[j];
                    nums[j] = nums[j-1];
                    nums[j-1] = tmp;
                }
            }
        }
    }
};
void printVector(const vector<int> &vec) {
    for (auto v : vec) {
        std::cout << v << "\t";
    }
    std::cout << std::endl; 
}
int main() {
    Solution sol;
    vector<int> v1{0,1,2,0};
    sol.sortColors(v1);
    printVector(v1);

    vector<int> v2{2,0,2,1,1,0};
    sol.sortColors(v2);
    printVector(v2);
    return 0;
}
