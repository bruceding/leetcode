#include "skip_list.h"

using namespace skiplist;
int main() {
    SkipList list;
    list.insert(10);
    list.insert(12);
    list.printAll();
    return 0;
}
