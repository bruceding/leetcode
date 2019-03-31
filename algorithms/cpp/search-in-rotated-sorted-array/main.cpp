/* *
 * 二分法变相使用
 *
 * */
#include<vector>
#include<iostream>
using std::vector;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        int l = 0, r = 0 ;
        int len = nums.size();
        if (nums[len-1] >= nums[0]) {
            l = 0, r = len-1;
        } else {
            for(int j = len-2; j>=0; j--) {
                if(nums[j] >= nums[0]) {
                   if (target > nums[j] ) {
                       return -1; 
                   } else if (target >= nums[0]) {
                        l = 0; 
                        r = j;
                        break;
                   } else if (target > nums[len-1]) {
                        return -1;
                   } else if (target >= nums[j+1]) {
                        l = j+1;
                        r = len-1;
                        break;
                   } 
                }
            }    
        }
        int mid = (l + r) /2;
        while (l <= r) {
            if (target > nums[mid]) {
               l = mid+1; 
            } else if (target < nums[mid]) {
                r = mid -1;
            } else {
                return mid;
            }

            mid = (l + r) / 2;
        }
        return -1;

    }
};
void printV(vector<int>& nums) {
    for (auto v: nums) {
        std::cout << v << "\t" ;
    }
    std::cout << std::endl;
}
int main() {
    vector<int> A{1};
    int ret;
    Solution sol;
    ret = sol.search(A, 1);
    std::cout << ret << std::endl;
    ret = sol.search(A, 0);
    std::cout << ret << std::endl;
    ret = sol.search(A, 2);
    std::cout << ret << std::endl;

    A = {1, 2};
    ret = sol.search(A, 2);
    std::cout << ret << std::endl;
    ret = sol.search(A, 1);
    std::cout << ret << std::endl;
    ret = sol.search(A, 0);
    std::cout << ret << std::endl;
    ret = sol.search(A, 3);
    std::cout << ret << std::endl;

    A = {4,5,6,7,0,1,2};
    ret = sol.search(A, 3);
    std::cout << ret << std::endl;
    ret = sol.search(A, 0);
    std::cout << ret << std::endl;
    ret = sol.search(A, 6);
    std::cout << ret << std::endl;
    ret = sol.search(A, 9);
    std::cout << ret << std::endl;
    
    A = {3, 1, 2};
    ret = sol.search(A, 1);
    std::cout << ret << std::endl;
    return 0;
}
