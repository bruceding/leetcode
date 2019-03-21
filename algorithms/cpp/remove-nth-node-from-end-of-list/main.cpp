#include<iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) {
            return nullptr;
        }
        if (n == 0) {
            return head;
        }
//        // 节点为 1 
//        if (n == 1 && head->next == nullptr) {
//            return nullptr;
//        }
        ListNode *pre = head, *p2 = head, *p3 =p2;
        for (int i =0; i < n; i++) {
           pre = pre->next; 
        }
        while(pre) {
            pre =pre ->next;
            p3 = p2;
            p2 = p2->next;
        }

        if (p3 == p2) {
            head = head->next;
        } else {
            p3->next = p2->next;
            p2->next = nullptr;
        }

        return head;
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
//    h2.next = &h3; 
//    h3.next = &h4; 
//    h4.next = &h5;
    printNode(head);
    Solution sol;
    ListNode *ret;
    ret = sol.removeNthFromEnd(head, 2);
    printNode(ret);
    return 0;
}
