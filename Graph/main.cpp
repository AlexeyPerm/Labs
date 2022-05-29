#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

//constexpr int SIZE_ARRAY = 7;       //Размер
constexpr int INF = 9999999;

void printResult(const std::vector<std::vector<int>>& graph);
void floyd(std::vector<std::vector<int>>& graph);

void floyd(std::vector<std::vector<int>>& graph) {
    int vertexCount = static_cast<int> (graph.size());
    int i{};        //Номер вершины
    int j{};        //Номер вершины
    int k{};        //Число вершин в графе

    for (k = 0; k < vertexCount; k++) {
        for (i = 0; i < vertexCount; i++) {      //Вершина i
            for (j = 0; j < vertexCount; j++) {  //Вершина j
                //Если вершина k на кротчайшем пути от i до j, то обновляем значение graph[i][j]
                if (graph[i][j] > (graph[i][k] + graph[k][j]) && (graph[k][j] != INF && graph[i][k] != INF))
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }
    printResult(graph);
}


void printResult(const std::vector<std::vector<int>>& graph) {
    int vertexCount = static_cast<int> (graph.size());
    std::string z(vertexCount * 5 + 5, '-');
    std::cout << z << std::endl << "X |   ";
    for (int i = 1; i <= vertexCount; ++i) {
        std::cout << i << "  | ";
    }
    std::cout << std::endl << z << std::endl;

    for (int i = 0; i < vertexCount; i++) {
        std::cout << i + 1 << " |";
        for (int j = 0; j < vertexCount; j++) {
            std::cout << std::setw(5);
            if (graph[i][j] == INF) {
                std::cout << "INF";
            } else {
                std::cout << graph[i][j];
            }
        }
        std::cout << " |" << std::endl << z << std::endl;;
    }
}

int main() {

    std::vector<std::vector<int>> graph{        //Матрица смежности графа
            {0,   INF, INF, 26,  9,   INF, INF},
            {INF, 0,   INF, 17,  INF, INF, 23},
            {INF, INF, 0,   INF, 13,  5,   INF},
            {26,  17,  INF, 0,   INF, 42,  INF},
            {9,   INF, 13,  INF, 0,   INF, 30},
            {INF, INF, 5,   42,  INF, 0,   19},
            {INF, 23,  INF, INF, 30,  19,  0}
    };
    floyd(graph);
    return 0;
}
