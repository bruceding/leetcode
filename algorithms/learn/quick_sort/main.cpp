/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2019/02/23 22时00分15秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
bool less (int j, int k) {
    return j < k;
}
void exch(int arrs[], int i, int j) {
    int temp = arrs[i];
    arrs[i] = arrs[j];
    arrs[j] = temp;
}
int partion(int arrs[], int lo, int hi) {
    int v = arrs[lo];
    int j = hi + 1;
    int i = lo;
    while (true) {
       while(less(arrs[++i], v)) if (i == hi) break; 
       while(less(v, arrs[--j])) if (j == lo) break; 
       if (i >= j) break;
       exch(arrs, i ,j );
    }
    exch(arrs, lo, j);

    return j;
}
void doSort(int arrs[], int lo, int hi) {
    if (hi <= lo) return;
    int j = partion(arrs, lo, hi);
    doSort(arrs, lo, j-1);
    doSort(arrs, j+1, hi);
}
void sort(int arrs[], int size) {
   doSort(arrs, 0, size -1); 
}
int main() {
    int arrs[10];

    for (int i = 0; i < 10; i++) {
        arrs[i] = 10 - i;
    }
    for (int i = 0; i < 10; i++) {
        std::cout << arrs[i] << std::endl; 
    }
    sort(arrs, 10);
    for (int i = 0; i < 10; i++) {
        std::cout << arrs[i] << std::endl; 
    }
    return 0;
}
