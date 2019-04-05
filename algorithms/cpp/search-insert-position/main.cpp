/* *
 * 二分法变相使用
 *
 * */
#include<vector>
#include<iostream>
using std::vector;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() -1;
        unsigned int mid = (l+r)/2;
        while(l <= r) {
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                r = mid -1;
            } else {
                l = mid + 1; 
            }
            mid = (l+r) /2;
        }

        return l;
    }
};
void printV(vector<int>& nums) {
    for (auto v: nums) {
        std::cout << v << "\t" ;
    }
    std::cout << std::endl;
}
int main() {
    vector<int> A{1,3, 8, 9};
    int ret;
    Solution sol;
    ret = sol.searchInsert(A, 10); 
    std::cout << ret << std::endl;
    return 0;
}
