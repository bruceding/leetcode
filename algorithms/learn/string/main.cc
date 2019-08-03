#include "rabin_karp.h"
#include "boyer_moore.h"

#include <iostream>
#include <string>

using namespace std;
int main() {

    std::string pat = "263";
    RabinKarp rk(pat);
    BoyerMoore bm(pat);


    auto ret1 = rk.search("3.1415926345");
    auto ret2 = bm.search("3.1415926345");

    std::cout << ret1 << "\t" << ret2  << std::endl;
    return 0;
}
