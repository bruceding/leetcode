#ifndef BOYER_MOORE_H
#define BOYER_MOORE_H

#include <string>
#include <vector>
#include <iostream>

class BoyerMoore {
public:
    BoyerMoore(const std::string& pat):pattern_(pat) {
        pattern_len_ = pat.length();
        right_ = new int[pattern_len_];
        suffix_ = new int[pattern_len_];
        prefix_ = new bool[pattern_len_];

        int R = 256; // 字符范围大小

        for (int i = 0; i < R; i++) {
            right_[i] = -1;
            suffix_[i] = -1;
            prefix_[i] = false;
        }

        for (int i = 0; i < pattern_len_; i++) {
            right_[(int)pattern_[i]] = i;
        }
        generateGS();
    }
    ~BoyerMoore() {
        if (right_ != nullptr) {
            delete  right_;
        }
    }
    int search(const std::string& str);
private:
    void generateGS();
    int moveByGS(int j);
    std::string pattern_;
    int *right_;
    int *suffix_;
    bool *prefix_;
    int pattern_len_;
};

// bad rule search
int BoyerMoore::search(const std::string &str) {

    int len = str.length();
    int skip = 0;
    int j;
    int gsSkip = 0;
    for (int i = 0; i <= len - pattern_len_; i += skip) {
        skip = 0;
        gsSkip = 0;

        for (j = pattern_len_-1; j >=0; j--) {
            if (str[i+j] != pattern_[j]) {
                skip = j - right_[(int)str[i+j]];
                if (j < pattern_len_ -1) {
                    // if have good suffix
                    gsSkip = moveByGS(j);
                }
                skip = skip >= gsSkip ? skip : gsSkip;
                if (skip < 1) {
                    skip = 1;
                }
                break;
            }
        }

        if (skip == 0) {
            return i;
        }

    }
    return -1;
}
// good rule 
// generate suffix and prefix array
void BoyerMoore::generateGS() {
    int j;
    int k;
    for (int i = 0; i < pattern_len_-1; i++) {
       j = i;
       k = 0;
       while(j >=0 && pattern_[j] == pattern_[pattern_len_ -1 -k]) {
           --j;
           ++k;
           suffix_[k] = j+1;
       }
       if (j == -1) {
           prefix_[k] = true;
       }
    }
}
int BoyerMoore::moveByGS(int j) {
    int k = pattern_len_ - j - 1;
    if (suffix_[k] != -1) {
        return j - suffix_[k] + 1;
    }
    for (int r = j+1; r <= pattern_len_ -1 ; r++) {
        // true
        if (prefix_[pattern_len_ -r]) {
            return r;
        }
    }
    return pattern_len_;
}
#endif


