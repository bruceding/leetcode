/*
 * =====================================================================================
 *
 *       Filename:  threeSum.c
 *
 *    Description:  
 *     3Sum
 *
 *        Version:  1.0
 *        Created:  2017/05/21 21时53分05秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#define SORT_VALUE 16

int exists(int **ret, int size, int i, int j, int k) {
    
    int p;
    for (p = 0; p < size; p++) {
        if (ret[p][0] == i && ret[p][1] == j && ret[p][2] == k) {
            return 0;
        }
    }

    return 1;
}
void swap(int* i, int* j) {
    int tmp = *i;
    *i = *j;
    *j = tmp;
}
/**
 * 插入排序
*/
void insert_sort(int* nums, int numsSize) {
    int i,j,tmp = 0;

    for (i = 1; i < numsSize; i++) {
       for (j = i; j > 0 && nums[j] < nums[j-1]; j--) {
            swap(&nums[j], &nums[j-1]); 
       } 
    }
} 
int partition(int* nums, int lo, int hi) {
    int i = lo, j = hi + 1;
    int k = nums[lo];

    while(1) {
        while( (nums[++i]) < k) if (i == hi) break;
        while ( (nums[--j]) > k) if (j == lo) break;
        if (i >=j) break;
        swap(&nums[i], &nums[j]);
    }

    swap(&nums[lo], &nums[j]);
    return j;
}
/**
 * 快排
*/
void quick_sort(int* nums, int lo, int hi) {
    if (hi <= lo) return;
    int j = partition(nums, lo, hi);

    quick_sort(nums, lo, j-1);
    quick_sort(nums, j+1, hi);
}
void sort(int* nums, int numsSize) {
    if (numsSize < SORT_VALUE) {
        insert_sort(nums, numsSize);    
    } else {
        quick_sort(nums, 0, numsSize-1);    
    }

}

/**
 * 二分查找
*/
int binary_search(int *nums, int numsSize, int key, int index) {

    int lo = (index > numsSize -1 ? numsSize -1: index);

    if (nums[lo] == key) {
        return lo;
    }
    int hi = numsSize - 1;
    int mid;

    while (lo <= hi) {
        mid = lo + (hi - lo)/2;

        if (key < nums[mid]) {
            hi = mid - 1;
        } else if (key > nums[mid]) {
            lo = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;

}
int** threeSum(int* nums, int numsSize, int* returnSize) {
    if (numsSize < 3) {
        return NULL;
    }

    sort(nums, numsSize);
    
    int **ret;
    ret = (int**)malloc(sizeof(int*) * 100000) ;

    int i, j, k = 0, size=0,  tmp = 0;

    for (i = 0; i < numsSize && nums[i] <= 0; i++) {
        for (j = i + 1; j < numsSize && (nums[i] + nums[j] <=0); j++) {
            tmp = 0 - (nums[i] + nums[j]);
            
            k = binary_search(nums, numsSize, tmp, j+1);

            if (k != -1 && k> j) {
               int *p = malloc(sizeof(int) * 3);                     
               p[0] = nums[i];
               if (nums[j] > nums[k]) {
                   p[1] = nums[k];
                   p[2] = nums[j];
               } else {
                   p[1] = nums[j];
                   p[2] = nums[k];
               }

               if (exists(ret, size, p[0], p[1], p[2])) {
                    ret[size++] = p;
               } else {
                    free(p);
               }
                
            }
        }
    }

    *returnSize = size;
    return ret;
}

int main(int argc, char** argv) {

    int** ret;


    int p[27] = {-7,-4,-6,6,4,-6,-9,-10,-7,5,3,-1,-5,8,-1,-2,-8,-1,5,-3,-5,4,2,-5,-4,4,7};
//    int p[6] = {-1, 0, 1, 2, -1, -4};
//    int p[3] = {0,0,0};

    int i = 0 ;
    ret = threeSum(p, 27, &i);

    printf("%d\n", i);
    int k;
    for (k = 0; k <i ; k++) {
        printf("%d %d %d\n", ret[k][0], ret[k][1], ret[k][2]);
    }
    return 0;
}


