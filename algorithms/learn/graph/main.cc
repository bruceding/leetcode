#include "graph.h"
int main() {
    Graph graph(8);
    graph.AddEdge(0, 1);
    graph.AddEdge(0, 3);
    graph.AddEdge(1, 2);
    graph.AddEdge(3, 4);
    graph.AddEdge(5, 4);
    graph.AddEdge(6, 4);
    graph.AddEdge(6, 7);
    graph.AddEdge(5, 7);

//    graph.Print();
    std::cout << "bfs search" << std::endl;
    graph.Bfs(0, 7);
    std::cout << "\ndfs search" << std::endl;
    graph.Dfs(0, 7);
    return 0;
}
