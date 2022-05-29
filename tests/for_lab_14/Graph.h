#pragma once

#include <vector>
#include <string>

static constexpr int INF = 9999999;

class Graph {
    static constexpr int SIZE_ARRAY = 10;
    std::vector<std::vector<int>> graph;
    int nextVertex[SIZE_ARRAY][SIZE_ARRAY]{};
    void floyd();
public:
    explicit Graph(std::vector<std::vector<int>> g);
    ~Graph() = default;
    void printResult();
    void printPath(int start);
    std::vector<int> path(int start, int end);  //Выполнение построения с указанной вершины.

};