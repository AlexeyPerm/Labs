#pragma once
#include <vector>
#include <string>

static constexpr int INF = 9999999;

class Graph {
private:
    std::vector<std::vector<int>> graph;
    static constexpr int SIZE_ARRAY    = 10;    //Размер матрицы, где хранятся вершины.
    static constexpr int WINDOW_WIDTH  = 800;
    static constexpr int WINDOW_HEIGHT = 600;
    int nextVertex[SIZE_ARRAY][SIZE_ARRAY]{};   //Массив, где хранятся вершины графов для построения пути
    void floyd();       //Реализация алгоритма
    std::vector<int> path(int start, int end);  //Выполнение построения с указанной вершины.

public:
    explicit Graph(std::vector<std::vector<int>> g);
    ~Graph() = default;
    void printResult();         //Печать матрицы цены пути.
    void printPath(int start);  //Печать пути и его цены.
    static void initWindow(int argc, char** argv);
};

