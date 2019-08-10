#ifndef KMP_H
#define KMP_H

#include <string>
#include <vector>
#include <iostream>

class KMP {
public:
    KMP(const std::string& pat):pattern_(pat) {
        pattern_len_ = pat.length();
        next_ = new int[pattern_len_];

        for (int i = 0; i < pattern_len_; i++) {
            next_[i] = -1;
        }
        generateNext();
    }
    ~KMP() {
        if (next_ != nullptr) {
            delete  next_;
            // next_ = nullptr;
        }
    }
    int search(const std::string& str);
private:
    void generateNext();
    std::string pattern_;
    int *next_;
    int pattern_len_;
};

// bad rule search
int KMP::search(const std::string &str) {

    int j = 0;
    for (int i = 0; i < str.length(); i++) {
        while (j > 0 && pattern_[j] != str[i]) {
            j = next_[j-1] +1;
        }

        if (pattern_[j] == str[i]) {
            ++j;
        }

        if (j == pattern_len_) {
            return i - pattern_len_ +1;
        }
    }
    return -1;
}
void KMP::generateNext() {
    int k = -1;
    for (int i = 1; i < pattern_len_; i++) {
        while(k != -1 && pattern_[k+1] != pattern_[i]) {
            k = next_[k];
        }

        if (pattern_[k+1] == pattern_[i]) {
            ++k;
        }

        next_[i] = k;
    }
}
#endif
