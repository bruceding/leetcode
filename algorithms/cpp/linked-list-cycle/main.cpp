#include<iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *p1 = head, *p2 = head;

        while(p1) {
            p1 = p1->next;
            p2 = p2->next;
            if (!p2) {
                break;
            }
            p2 = p2->next;
            if (!p2) {
                break;
            }
            if (p1 == p2) {
                return true;
            }
        }
        return false;

    }
};
void printNode(ListNode *head) {
    ListNode *p = head;
    while(p) {
        std::cout << p->val << "\t";
        p = p->next;
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
//    h2.next = head;

    h2.next = &h3; 
    h3.next = &h4; 
    h4.next = &h5;
    h5.next = &h2;
//    printNode(head);
    Solution sol;
    auto ret = sol.hasCycle(head);
    std::cout << ret << std::endl;
    return 0;
}
