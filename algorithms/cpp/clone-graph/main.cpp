#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;
using std::unordered_map;
// Definition for a Node.
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
    void Neighbors(vector<Node*> _neighbors) {
        neighbors =_neighbors;
    }
    void Print() {
        std::cout << val << ",neighbors:";
        for (auto n : neighbors) {
            std::cout << n << "," << n->val << "\t";
        }
        std::cout << std::endl;
    }
};
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }
        std::queue<Node*> queue; 
        std::unordered_map<Node*, Node*> maps;

        queue.push(node);

        while(!queue.empty()) {
            Node* p = queue.front();
            queue.pop();
            if (maps.find(p) == maps.end()) {
                Node *newP = new Node(p->val, p->neighbors);
                maps[p] = newP;
                for (auto n : p->neighbors) {
                    queue.push(n);
                } 
            } 
        }

        std::cout << maps.size() << "\t" << queue.size() << std::endl;
        Node *newNode = maps[node];
        queue.push(newNode); 
        std::unordered_map<Node*, bool> visited;
        while(!queue.empty()) {
            Node* p = queue.front();
            queue.pop();
            if (visited.find(p) == visited.end()) {
                std::vector<Node*> vec;
                for (auto n : p->neighbors) {
                    vec.push_back(maps[n]);
                    queue.push(maps[n]);
                }
                p->neighbors = vec;
                visited[p] = true;
            }
        }

        return newNode;
    }
};
void print(Node* node) {
    std::unordered_map<Node*, bool> visited;

    std::queue<Node*> queue; 

    queue.push(node);
    while(!queue.empty()) {
        Node* p = queue.front();
        queue.pop();
        // not visited
        if (visited.find(p) == visited.end()) {
            p->Print();
            for (auto n : p->neighbors) {
                queue.push(n);
            } 
            visited[p] = true;
        } 
    }
}
int main() {

    Solution sol;
    Node n1(1, vector<Node*>{});
    Node n2(2, vector<Node*>{});
    Node n3(3, vector<Node*>{});
    Node n4(4, vector<Node*>{});
    n1.Neighbors(std::vector<Node*>{&n2, &n4});
    n4.Neighbors(vector<Node*>{&n1, &n3});
    n2.Neighbors(vector<Node*>{&n1, &n3});
    n3.Neighbors(vector<Node*>{&n2, &n4});
    print(&n1);

    std::cout << std::endl; 
    Node* ret = sol.cloneGraph(&n1);
    print(ret);
    return 0;
}
