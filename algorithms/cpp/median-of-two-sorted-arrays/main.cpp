/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2019/02/18 08时46分02秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include<vector>
#include<iostream>
using std::vector;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0) {
            return medianArrays(nums2);
        }
        if(nums2.size() == 0) {
            return medianArrays(nums1);
        }

        vector<int> nums;
        int i =0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            while((i < nums1.size()) && (nums1[i] <= nums2[j])) {
                    nums.push_back(nums1[i]);
                    i++;
                
            }
            if (i >= nums1.size()) {
                break;
            }
            while((j < nums2.size()) && (nums2[j] <= nums1[i])) {
                    nums.push_back(nums2[j]);
                    j++;
            }
        }
        if (i >= nums1.size()) {
            for(int tmp = j; tmp < nums2.size(); tmp++) {
                    nums.push_back(nums2[tmp]);
            }
        }
        if (j >= nums2.size()) {
            for(int tmp = i; tmp < nums1.size(); tmp++) {
                    nums.push_back(nums1[tmp]);
            }
        }

        for (auto v : nums) {
            std::cout << v << "\t";
        }
        std::cout << std::endl;
        return medianArrays(nums);
    }

    double medianArrays(vector<int>& num) {
        if (num.size() % 2 == 0) {
            int m = num.size() / 2;
            return (double)((num[m-1] + num[m]) / 2.0); 
        } else {
           return (double)(num[num.size()/2.0]); 
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums1{1,3};
    vector<int> nums2{2};

    std::cout << sol.findMedianSortedArrays(nums1,nums2) << std::endl;
    std::cout << sol.findMedianSortedArrays(nums2,nums1) << std::endl;
    nums1 = {1,2};
    nums2 = {3,4};
    std::cout << sol.findMedianSortedArrays(nums1,nums2) << std::endl;
    std::cout << sol.findMedianSortedArrays(nums2,nums1) << std::endl;
    nums1 = {1,2,5};
    nums2 = {3,4,9,10,11};
    std::cout << sol.findMedianSortedArrays(nums1,nums2) << std::endl;
    std::cout << sol.findMedianSortedArrays(nums2,nums1) << std::endl;
    return 0;
}
