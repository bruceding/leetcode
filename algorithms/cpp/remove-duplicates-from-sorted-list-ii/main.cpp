#include<iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL) {}
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return head;
        }

       ListNode* p1 = head; 
       while (p1->next) {
           if (p1->next->val == p1->val) {
               head = deleteDuplicatesHelper(head, p1->val);
               if (!head) {
                    break;
               }
               p1 = head;
           } else {
                p1 = p1->next;
           }
       }


        return head;

    }

    ListNode* deleteDuplicatesHelper(ListNode* head, int val) {
        while(head && head->val == val) {
            head = head->next;
        }
        if (!head) {
            return head;
        }
        
        ListNode* p1 = head; 
        ListNode* p2 = head->next;

        while(p2) {
            if (p2->val == val) {
                p1->next = p2->next;
                p2 = p1->next;
            } else {
                p1 = p2;
                p2 = p2->next;
            }
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
    ListNode h2(1);
    ListNode h3(1);
    ListNode h4(2);
    ListNode h5(3);
    ListNode h6(4);
    ListNode h7(5);
    head->next = &h2;
    h2.next = &h3; 
//    h3.next = &h4; 
    h4.next = &h5;
//    h5.next = &h6;
//    h6.next = &h7;
    printNode(head);
    Solution sol;
    ListNode *ret;
    ret = sol.deleteDuplicates(head);
    printNode(ret);
    return 0;
}
