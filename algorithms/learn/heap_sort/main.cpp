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
void sink(int arrs[], int k , int n) {
    while(2*k <= n ) {
       int j = 2 * k;
       if (j < n && less(arrs[j], arrs[j+1])) 
           j++;
       if (!less(arrs[k], arrs[j])) 
           break;
       exch(arrs, k, j);
       k = j;
    }
}
void sort(int arrs[], int size) {
    int N = size;
    for (int k = N/2; k >= 1; k--) {
        sink(arrs, k, N);
    }
    while(N > 1) {
       exch(arrs, 1, N--);
       sink(arrs, 1, N);
    }
}
#define SIZE 11
int main() {
    int arrs[SIZE];
    arrs[0] = -1;

    for (int i = 1; i < SIZE; i++) {
        arrs[i] = 10 - i;
    }
    for (int i = 0; i < SIZE; i++) {
        std::cout << arrs[i] << std::endl; 
    }
    sort(arrs, SIZE - 1);
    for (int i = 0; i < SIZE; i++) {
        std::cout << arrs[i] << std::endl; 
    }
    return 0;
}
