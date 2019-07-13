#include <iostream>
#include <string>
#include <unordered_map>
using std::unordered_map;
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }

        Node* newHead = nullptr;

        Node* p = head;
        Node* pre = nullptr;
        unordered_map<Node*, Node*> hash;
        while(p) {
           Node* current = new Node(p->val, nullptr, p->random);
           if (!pre) {
               pre = current;
           } else {
               pre->next = current;
               pre = pre->next;
           }

           if (!newHead) {
                newHead = pre;
           }

           hash[p] = current;
           p = p->next;
        }

        Node* p1 = newHead;
        while(p1) {
            if (p1->random) {
                p1->random = hash[p1->random];
            }
            p1 = p1->next;
        }

        return newHead;
    }
};
void print(Node* head) {
    Node* p = head;
    while(p) {
        std::cout << p << "\t" << p->next << "\t" <<p->random << "\t" <<  p->val << std::endl; 
        p = p->next;
    }
}
int main() {

    Solution sol;
    Node n1(1, nullptr, nullptr);
    Node n2(1, nullptr, nullptr);
    n1.next = &n2;
    n1.random = &n2;

    print(&n1);

    Node* ret = sol.copyRandomList(&n1);
    print(ret);


    print(&n2);
    ret = sol.copyRandomList(&n2);
    print(ret);
    return 0;
}
