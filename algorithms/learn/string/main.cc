#include "rabin_karp.h"

#include <iostream>
#include <string>

using namespace std;
int main() {

    RabinKarp rk("1224");

    auto ret = rk.search("3.1415926345");

    std::cout << ret << std::endl;
    return 0;
}
