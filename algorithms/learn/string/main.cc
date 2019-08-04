#include "rabin_karp.h"
#include "boyer_moore.h"

#include <iostream>
#include <string>
#include <map>

using namespace std;
int main() {

    std::map<string, string> maps {
        {"263", "3.1415926345"},
        {"abbcabc", "abcacabcbcbacabc"},
        {"cbacabc", "abcacabcbcbacabc"}
    };

    for (auto m : maps) {
        RabinKarp rk(m.first);
        BoyerMoore bm(m.first);

        auto ret1 = rk.search(m.second);
        auto ret2 = bm.search(m.second);

        std::cout << ret1 << "\t" << ret2  << std::endl;
    }



    return 0;
}
