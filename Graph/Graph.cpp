#include "Graph.h"
#include "GL/glut.h"
#include <string>
#include <iostream>
#include <iomanip>
#include "draw.h"

Graph::Graph(std::vector<std::vector<int>> g) {     //Конструктор
    graph = std::move(g);
    for (int i = 0; i < graph.size(); ++i) {
        for (int j = 0; j < graph.size(); ++j) {
            if (graph[i][j] == INF) {
                nextVertex[i][j] = -1;
            } else {
                nextVertex[i][j] = j;
            }
        }
    }
    floyd();
}

void Graph::printResult() {
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
        std::cout << " |" << std::endl << z << std::endl;
    }
}

void Graph::floyd() {
    int vertexCount = static_cast<int> (graph.size());
    int i{};        //Номер вершины
    int j{};        //Номер вершины
    int k{};        //Число вершин в графе

    for (k = 0; k < vertexCount; k++) {
        for (i = 0; i < vertexCount; i++) {      //Вершина i
            for (j = 0; j < vertexCount; j++) {  //Вершина j
                if (graph[i][k] == INF || graph[k][j] == INF)
                    continue;
                //Если вершина k на кротчайшем пути от i до j, то обновляем значение graph[i][j]
                if (graph[i][j] > (graph[i][k] + graph[k][j])) {
                    graph[i][j] =  graph[i][k] + graph[k][j];
                    nextVertex[i][j] = k;
                }
            }
        }
    }
}

std::vector<int> Graph::path(int start, int end) {
    std::vector<int> path = {start};
    while (start != end) {
        start = nextVertex[start][end];
        path.emplace_back(start);
    }
    return path;
}

void Graph::printPath(int start) {
    std::string z(40, '-');
    std::cout << z;
    for (int k = 1; k <= graph.size(); ++k) {
        std::vector<int> p = this->path(start - 1, k - 1);
        int n = static_cast<int> (p.size());
        std::cout << std::endl;
        for (int i = 0; i < n - 1; i++) {
            std::cout << p[i] + 1 << " -> ";
        }
        std::cout << p[n - 1] + 1 << "\n" << "cost = " << graph[start - 1][k - 1] << std::endl;
        std::cout << z;
    }
}

void Graph::initWindow(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("My Graph");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
}
