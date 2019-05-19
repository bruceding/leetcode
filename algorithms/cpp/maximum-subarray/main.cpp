/*
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

 * Example:

 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max) {
                max = nums[i];
            }
            int sum = nums[i];
            for (int j = i+1; j< nums.size(); j++) {
                if (nums[j] < 0 && sum+nums[j] < 0) {
                    break;
                }
              sum += nums[j];
              if (sum > max) {
                  max = sum;
              }
            }
        }

        return max;
    }
};

// 更优雅的解法如下：
//
public int maxSubArray(int[] nums) {
             if (nums == null || nums.length == 0) return 0;
             int max = nums[0], tempSum = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (tempSum <= 0)
                tempSum = nums[i];
            else
                tempSum += nums[i];
            if (tempSum > max) max = tempSum;
        }
        return max;
}
