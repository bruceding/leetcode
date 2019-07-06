#include "skip_list.h"

using namespace skiplist;
int main() {
    SkipList list;
    list.insert(10);
    list.insert(12);
    list.printAll();
    Node* p = list.find(10);
    if (p == nullptr) {
        std::cout << "not find" << std::endl;
    } else {
        std::cout << p->data() << std::endl;
    }
    p = list.find(12);
    if (p == nullptr) {
        std::cout << "not find" << std::endl;
    } else {
        std::cout << p->data() << std::endl;
    }
    p = list.find(2);
    if (p == nullptr) {
        std::cout << "not find" << std::endl;
    } else {
        std::cout << p->data() << std::endl;
    }
    p = list.find(20);
    if (p == nullptr) {
        std::cout << "not find" << std::endl;
    } else {
        std::cout << p->data() << std::endl;
    }

    list.insert(13);
    list.insert(14);
    list.insert(15);
    list.printAll();

    list.del(12);
    list.printAll();
    list.del(14);
    list.printAll();

    p = list.find(14);
    if (p == nullptr) {
        std::cout << "not find" << std::endl;
    } else {
        std::cout << p->data() << std::endl;
    }
    return 0;
}
