/*
 * =====================================================================================
 *
 *       Filename:  twosum.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016/10/22 08时50分10秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<stdlib.h>
int* twoSum(int* nums, int numsSize, int target) {

    int i = 0;
    int k ;
    int count = 0;

    int *ret = (int*)malloc(sizeof(int) * 2);
    

    for (i = 0; i< numsSize; i++) {
       for (k = i+1; k < numsSize; k++) {
           if (nums[i] + nums[k] == target) {
               if (count > 1) {
                   continue;
               }

               ret[count++] = i;
               ret[count++] = k;
           }
            
       } 
    } 
        
    return ret;
}

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}
/* 
 * 这个方法不对，缺少之前的顺序索引 
 * 需要再构建个数组，对应之前的索引下标
 */
int* twoSum1(int* nums, int numsSize, int target) {

    int i = 0;
    int j = numsSize - 1;

    int *ret = (int*)malloc(sizeof(int) * 2);
    
    qsort(nums, numsSize, sizeof(int), cmp);
   
    while (nums[i] + nums[j] != target) {
        if (nums[i] + nums[j] > target) {
            --j;
        } else if (nums[i] + nums[j] < target) {
            ++i;
        } else {
            break;
        }
    }

    ret[0] = i;
    ret[1] = j;

    return ret;
}

int* twoSum2(int* nums, int numsSize, int target, int* returnSize) {

    int i = 0;
    int j = numsSize - 1;

    int *ret = (int*)malloc(sizeof(int) * *returnSize);
    
    while (nums[i] + nums[j] != target) {
        if (nums[i] + nums[j] > target) {
            --j;
        } else if (nums[i] + nums[j] < target) {
            ++i;
        } else {
            break;
        }
    }

    ret[0] = i + 1;
    ret[1] = j + 1;

    return ret;
}

int main(int argc, char** argv) {
    
    int nums[3] = {2,3,4};

    int i = 0;
    int returnSize = 2;
//    int *ret = (int*)malloc(sizeof(int) * 2);
//    ret[0] = 1;
//    ret[1] = 2;
//    for(i = 0; i < 2; i++) {
//        printf("%d\n", ret[i]);
//    }

    int* ret;
    ret = twoSum2(nums, 3, 6, &returnSize);
    for(i = 0; i < 2; i++) {
        printf("%d\n", ret[i]);
    }
    return 0;
}



