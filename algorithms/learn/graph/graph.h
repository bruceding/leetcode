#ifndef GRAPH_H_
#define GRAPH_H_

#include <list>
#include <iostream>
class Graph {
public:
    explicit Graph(int v):v_(v) {
        adj_ = (std::list<int>**)malloc(v * sizeof(std::list<int>*));

        for (int i = 0; i < v; i++) {
            adj_[i] = new std::list<int>();
        }
    }
    // 无向图
    void AddEdge(int s, int t) {
        adj_[s]->push_back(t);
        adj_[t]->push_back(s);
    }
    void Print() {
        for (int i = 0; i < v_; i++) {
            if(adj_[i]->size() != 0) {
                for (auto it : *(adj_[i])) {
                    std::cout << i << " - " << it << std::endl;
                }
            }
        }
    }
    // 广度优先搜索
    void Bfs(int s, int t);
    void print(int pre[], int s, int t) {
        if (pre[s] != -1 && s != t) {
            print(pre, s, pre[t]);
        }
        std::cout << t << " " ;
    }
private:
    int v_ ; // 顶点个数
    std::list<int>** adj_;
};
void Graph::Bfs(int s, int t) {
    if (s == t)  return;

    bool visited[v_];
    int pre[v_];

    for (int i = 0; i < v_; i++) {
        pre[i] = -1;
        visited[i] = false;
    }

    std::list<int> queue;
    queue.push_back(s);

    while(queue.size() != 0) {
        int w = queue.front();
        queue.pop_front();

        for (auto q : *(adj_[w])) {
            if (!visited[q]) {
                pre[q] = w;
                if (q == t) {
                    print(pre, s, t);
                    return;
                }
            }
            visited[q] = true;
            queue.push_back(q);
        }
    }
}
#endif
