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

        int R = 256; // 字符范围大小

        for (int i = 0; i < R; i++) {
            right_[i] = -1;
        }

        for (int i = 0; i < pattern_len_; i++) {
            right_[(int)pattern_[i]] = i;
        }
    }
    int search(const std::string& str);
private:
    std::string pattern_;
    int *right_;
    int pattern_len_;
};

// bad rule search
int BoyerMoore::search(const std::string &str) {

    int len = str.length();
    int skip = 0;
    int j;
    for (int i = 0; i <= len - pattern_len_; i += skip) {
        skip = 0;

        for (j = pattern_len_-1; j >=0; j--) {
            if (str[i+j] != pattern_[j]) {
                skip = j - right_[(int)str[i+j]];
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
#endif


