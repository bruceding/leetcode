#include<string>
#include<iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (nums.size() < k) {
            return false;
        }

        int64_t total = 0;
        for (auto n : nums) {
            total += n;
        }

        if (total % k > 0) {
            return false;
        }
        int avg = total / k;

        std::sort(nums.begin(), nums.end());
        int row = nums.size() - 1;
        if (nums[row] > avg) {
            return false;
        }
        while(row >= 0 && nums[row] == avg) {
            --row;
            --k;
        }
        vector<int> groups(k, 0);
        return partitionHelper(groups, nums, row, avg);
    }

    bool partitionHelper(vector<int>& groups, vector<int>& num, int row, int avg) {
        if (row < 0 ) return true;
        int v = num[row--];
        for (int i = 0; i < groups.size(); i++) {
            if (groups[i] + v <= avg) {
                groups[i] += v;
                if (partitionHelper(groups, num, row, avg)) return true;
                groups[i] -= v;
            }

            if (groups[i] == 0) break;
        }
        return false;

    }
    void printVec(vector<int>& nums) {
        for (auto n : nums) {
            std::cout << n << " " ;
        }
        std::cout << std::endl;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {4, 1,1,1, 2, 3, 5, 2, 1};

    bool ret = sol.canPartitionKSubsets(nums, 4);
    std::cout << ret << std::endl;
    
    nums = {10,10,10,7,7,7,7,7,7,6,6,6};
    ret = sol.canPartitionKSubsets(nums, 3);
    std::cout << ret << std::endl;
    return 0;
}
