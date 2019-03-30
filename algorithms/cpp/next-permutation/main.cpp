#include<vector>
#include<iostream>
using std::vector;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        if (size <=1 ) {
            return;
        }
        int i = 0;
        // 从尾部查找，发现第一个降序的位置
        for (i = size-1; i>0; i--) {
           if(nums[i] > nums[i-1]) {
                i--;
                break;
           } 
        }
        int start = i;
        int j ;
        // 从尾部查找，第一个大于降序的位置，两者互换，有种情况查找不到，说明是本身是最大的数
        for (j = size-1; j>i;j--) {
           if (nums[j] > nums[i]) {
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                start = i+1;
                break;
           } 
        }

        int l = start, r = size-1;
        // 反向倒转
        while (l < r) {
           int tmp = nums[l];
           nums[l] = nums[r];
           nums[r] = tmp;
           l++;
           r--;
        }

    }
};
void printV(vector<int>& nums) {
    for (auto v: nums) {
        std::cout << v << "\t" ;
    }
    std::cout << std::endl;
}
int main() {
    vector<int> A{1,2,3,4};
    Solution sol;
    printV(A);
    sol.nextPermutation(A);
    printV(A);
    A = {6,6,4, 5, 3};
    printV(A);
    sol.nextPermutation(A);
    printV(A);

    A = {1,5,8,4,7,6,5,3,1};
    printV(A);
    sol.nextPermutation(A);
    printV(A);

    A = {6,6,5, 4, 3};
    printV(A);
    sol.nextPermutation(A);
    printV(A);
    return 0;
}
