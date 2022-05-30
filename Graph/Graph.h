#pragma once

#include <vector>
#include <string>

static constexpr int INF = 9999999;
constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 600;

class Graph {
    static constexpr int SIZE_ARRAY = 10;       //Размер матрицы, где хранятся вершины.
    std::vector<std::vector<int>> graph;
    //Массив, где хранятся вершины графов для построения пути
    int nextVertex[SIZE_ARRAY][SIZE_ARRAY]{};
    void floyd();       //Реализация алгоритма

public:
    explicit Graph(std::vector<std::vector<int>> g);
    ~Graph() = default;
    void printResult();     //Печать матрицы цены пути.
    void printPath(int start);  //Печать пути и его цены.
    std::vector<int> path(int start, int end);  //Выполнение построения с указанной вершины.
    void initWindow(int argc, char** argv);
};

