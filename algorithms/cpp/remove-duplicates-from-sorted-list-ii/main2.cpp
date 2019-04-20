// 使用哨兵节点
#include<iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL) {}
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
//        if (!head) {
//            return head;
//        }
        ListNode guard(0);
        guard.next = head;
        head = &guard;

       ListNode* p1 = head; 
       ListNode* p2 = head->next; 
       while(p2) {
           bool flag = false;
           while (p2->next && p2->next->val == p2->val) {
                p2 = p2->next;
                flag = true;
           } 
           if (flag) {
                p2 = p2->next;
                p1->next = p2;
           } else {
                p1= p2;
                p2= p2->next;
           }
       }

        return head->next;

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
    ListNode h2(1);
    ListNode h3(1);
    ListNode h4(2);
    ListNode h5(3);
    ListNode h6(3);
    ListNode h7(3);
    head->next = &h2;
    h2.next = &h3; 
    h3.next = &h4; 
    h4.next = &h5;
    h5.next = &h6;
    h6.next = &h7;
    printNode(head);
    Solution sol;
    ListNode *ret;
    ret = sol.deleteDuplicates(head);
    printNode(ret);
    return 0;
}
