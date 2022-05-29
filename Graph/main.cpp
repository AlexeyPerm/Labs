#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "Graph.h"


int main() {

    //������� ��������� �����
    Graph g({{0,   INF, INF, 26,  9,   INF, INF},
             {INF, 0,   INF, 17,  INF, INF, 23},
             {INF, INF, 0,   INF, 13,  5,   INF},
             {26,  17,  INF, 0,   INF, 42,  INF},
             {9,   INF, 13,  INF, 0,   INF, 30},
             {INF, INF, 5,   42,  INF, 0,   19},
             {INF, 23,  INF, INF, 30,  19,  0}});

    g.printResult();
    g.printPath(7);

    return 0;
}