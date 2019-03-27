#include<iostream>
#include<unordered_map>
using std::unordered_map;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        ListNode *p = head;
        unordered_map<ListNode*, bool> map;
        while(p) {
            if(map.find(p) != map.end()) {
                return p;
            } 

            map[p] = true;
            p = p->next;
        }

        return nullptr;
    }
};
void printNode(ListNode *head) {
    ListNode *p = head;
    while(p) {
        std::cout << p->val << "\t";
        break;
    }

    std::cout << std::endl;
}

int main() {
    ListNode *head = new ListNode(1);
    ListNode h2(2);
    ListNode h3(3);
    ListNode h4(4);
    ListNode h5(5);
    head->next = &h2;
    h2.next = head;

//    h2.next = &h3; 
//    h3.next = &h4; 
//    h4.next = &h5;
//    h5.next = &h2;
//    printNode(head);
    Solution sol;
    ListNode *ret;
    ret = sol.detectCycle(head);
    printNode(ret);
    return 0;
}
