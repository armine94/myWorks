#include <iostream>
#include "graph.h"

int main() {
    const Edge edges[] = {
        // pair (x, y)
        { 0, 1, 4 }, { 0, 7, 8 }, { 1, 0, 4 }, { 1, 7, 11 }, { 1, 2, 8 },
        { 2, 1, 8 }, { 2, 3, 7 }, { 2, 8, 2 }, { 3, 2, 7 }, { 3, 4, 9 },
        { 3, 5, 14 }, { 4, 3, 9 }, { 4, 5, 10 }, { 5, 4, 10 }, { 5, 3, 14 },
        { 6, 5, 2 }, { 6, 8, 6 }, { 6, 7, 1 }, { 7, 6, 1 },
        { 7, 0, 8 }, { 7, 8, 7 }, { 7, 1, 11 }, { 8, 2, 2 }, { 8, 7, 7 }, { 8, 6, 6 }
    };

    // Number of vertices in the graph
    const int N = 9;

    // calculate number of edges
    const int n = sizeof(edges)/sizeof(edges[0]);

    // // construct graph
    Graph graph(edges, n, N);

    //print graph
    graph.printList();

    //calculate minimum way
    int minWay = graph.minWay(1, 4);
    std::cout << "Min way from 1 to 4: " << minWay << std::endl;

    return 0;
}