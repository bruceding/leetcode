#include<iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL) {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || head->next == nullptr) {
            return head;
        }

        // 循环减少次数
        int size = 0;
        ListNode *p = head;
        while(p) {
            size++;
            p = p->next;
        }
        k = k % size;
        while (k-- > 0) {
            
            ListNode *last = head, *pre ;

            while(last->next != nullptr) {
                pre = last;
                last = last->next;
            }
            pre->next = nullptr;
            last->next = head;
            head = last;
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
    ListNode *head = new ListNode(0);
    ListNode h2(1);
    ListNode h3(2);
    ListNode h4(4);
    ListNode h5(5);
    head->next = &h2;
    h2.next = &h3; 
//    h3.next = &h4; 
//    h4.next = &h5;
    printNode(head);
    Solution sol;
    ListNode *ret;
    ret = sol.rotateRight(head, 2);
    printNode(ret);
    return 0;
}
