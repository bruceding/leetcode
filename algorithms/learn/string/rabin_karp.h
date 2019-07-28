#ifndef RABIN_KARP_H
#define RABIN_KARP_H

#include <string>

class RabinKarp {
public:
    RabinKarp(const std::string& pattern): pattern_(pattern) {
        patternLen_ = pattern.length();
        RM = 1;
        for (int i = 1; i <= pattern.length()-1; i++) {
            RM = R *RM;
        }
        patHash_ = hash(pattern, pattern.length());
    }
    int search(const std::string& str);
private:
    int64_t hash(const std::string& str, int m) {
       int64_t h = 0; 
       for (int i = 0; i < m; i++) {
            h = h * R + str[i];
       }
       return h;
    }
    bool check(const std::string& str, int i) {
        for (int j = 0; j < patternLen_ ; j++) {
            if (str[j+i] != pattern_[j]) {
                return false;
            }
        }

        return true;
    }
    int R = 256 ; // 进制大小
    int64_t RM ;
    int64_t patHash_ ; // 模式hash
    std::string pattern_;
    int patternLen_;
};

// if not found ,return -1
int RabinKarp::search(const std::string &str) {
   if (str.length() < patternLen_) {
        return -1;
   }
   auto textHash = hash(str, patternLen_); 

   if ((textHash == patHash_) && check(str, 0)) {
        return 0;
   }

   int m = patternLen_;
   int n = str.length();
   for (int i = 1; i < n - m +1; i++) {
       textHash = (textHash - str[i-1] * RM) * R + str[i+patternLen_-1]; 
       if (textHash == patHash_ && check(str, i)) {
            return i;
       } 
   }
   return -1;
}
#endif


