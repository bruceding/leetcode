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
void sort(int arrs[], int size) {
    int N = size;
    int h = 1;
    while(h < N/3) h = h*3 + 1;

    while(h >= 1) {
        for (int i = h; i < N; i++) {
            for (int j = i; j >=h && less(arrs[j], arrs[j-h]); j-=h) {
                exch(arrs, j, j-h);
            }
        }
        h = h /3;
    }
}
#define SIZE 10
int main() {
    int arrs[SIZE];

    for (int i = 0; i < SIZE; i++) {
        arrs[i] = 10 - i;
    }
    for (int i = 0; i < SIZE; i++) {
        std::cout << arrs[i] << std::endl; 
    }
    sort(arrs, SIZE);
    for (int i = 0; i < SIZE; i++) {
        std::cout << arrs[i] << std::endl; 
    }
    return 0;
}
