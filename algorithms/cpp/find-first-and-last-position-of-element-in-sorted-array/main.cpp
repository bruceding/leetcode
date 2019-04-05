/* *
 * 二分法变相使用
 *
 * */
#include<vector>
#include<iostream>
using std::vector;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result{-1, -1};
        int l = 0;
        int r = nums.size() - 1;
        int mid = (l+r)/2;
        bool found = false;
        while (l <= r) {
           if (target > nums[mid]) {
                l = mid + 1;
           } else if (target < nums[mid]) {
                r = mid -1;
           } else {
                found = true;
                break;
           } 

           mid = (l + r) /2;
        }
        if (!found) {
            return result;
        }

        int start = mid, end = mid;

        while(true) {
            
            if (start -1 >=0 && nums[start-1] == nums[mid]) {
                start--;
            } else {
                break;
            }
        }

        while(true) {
            
            if (end +1  <= nums.size()-1 && nums[end+1] == nums[mid]) {
                end++;
           } else {
                break;
            }
        }

        result[0] = start;
        result[1] = end;

        return result;

    }
};
void printV(vector<int>& nums) {
    for (auto v: nums) {
        std::cout << v << "\t" ;
    }
    std::cout << std::endl;
}
int main() {
    vector<int> A;
    vector<int> ret;
    Solution sol;
    ret = sol.searchRange(A, 2);
    printV(ret);

    A = {5, 6, 7, 8, 9};
    ret = sol.searchRange(A, 2);
    printV(ret);

    ret = sol.searchRange(A, 5);
    printV(ret);

    ret = sol.searchRange(A, 9);
    printV(ret);

    ret = sol.searchRange(A, 8);
    printV(ret);

    A = {5, 7, 7, 8, 8, 10};
    ret = sol.searchRange(A, 8);
    printV(ret);
    A = {7, 7, 7, 7, 7, 7};
    ret = sol.searchRange(A, 7);
    printV(ret);
    return 0;
}
