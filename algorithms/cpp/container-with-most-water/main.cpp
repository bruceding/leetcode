#include<iostream>
#include<vector>
using std::vector;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        bool flag = false;
        int index = 0;
        int hi = 0;

        int s = height.size();
        for (int i = 0; i < s ; i++) {
            if (!flag || (height[i] - height[index] > 0)) {
                for (int j= s-1; j >=0; j--) {
                    int len = j - i;
                    hi = min(height[i], height[j]);
                    if (len * hi > area) {
                        area = len * hi;
                        flag = true;
                        index = i;
                    }
                }
            }
        }

        return area;
    }
    int min(int a, int b) {
        return a < b ? a : b;
    }
};
int main() {
    Solution sol;
    vector<int> height {1,8,6,2,5,4,8,3,7};
    int ret;
    ret = sol.maxArea(height);
    std::cout << ret << std::endl;
    height = {8,6};
    ret = sol.maxArea(height);
    std::cout << ret << std::endl;
    height = {8,6, 9};
    ret = sol.maxArea(height);
    std::cout << ret << std::endl;
    return 0;
}
/** 
 * java 版本， 两个指针移动
public class Solution {
    public int maxArea(int[] height) {
        int maxarea = 0, l = 0, r = height.length - 1;
        while (l < r) {
            maxarea = Math.max(maxarea, Math.min(height[l], height[r]) * (r - l));
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return maxarea;
    }
}
**/
