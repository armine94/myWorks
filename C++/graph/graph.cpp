#include <iostream>
#include <vector>
#include "graph.h"

#define MAX 1000000


Graph::Node::Node(const int val, const int weight): val(val), weight(weight){}

// Function to create new node of Adjacency List
Graph::Node* Graph::getAdjListNode(const int last, const int weight, Node* head) {
    Node* newNode = new Node(last, weight);
    newNode->next = head;

    return newNode;
}

// Constructor
Graph::Graph(const Edge edges[], const int n, const int m) {
    // allocate memory
    head = new Node*[m]();
    nodeNumber = m;

    // initialize head pointer for all vertices
    for (int i = 0; i < m; ++i) {
        head[i] = nullptr;
    }

    // add edges to the graph
    for (int i = 0; i < n; ++i) {
        int first = edges[i].first;
        int last = edges[i].last;
        int weight = edges[i].weight;
        Node* newNode = getAdjListNode(last, weight, head[first]);
        head[first] = newNode;
    }
}

// destructor
Graph::~Graph() {
    for (int i = 0; i < nodeNumber; ++i) {
        delete[] head[i];
    }

    delete[] head;
}

//print graph
void Graph::printList() {

    Node * tmp;

    for (int i = 0; i < nodeNumber; ++i) {
        tmp = head[i];
        while (tmp != nullptr) {
            std::cout << "(" << i << ", "
            << tmp->val << ", " << tmp->weight << ")";
            tmp = tmp->next;
            if(nullptr != tmp) {
                std::cout << " −> ";
            }
        }
        std::cout << std::endl;
    }
}

bool Graph::check(int &node, int &m) {
    if(m == node) {
        return false;
    }
    else if(m < node) {
        int tmp = node;
        node = m;
        m = tmp;
    }

    return true;
}

int Graph::minWay2(int node, int m, std::vector<std::pair<int, int>> &mVec) {
    int k = m;
    int way = 0;
    int indexes[nodeNumber] = {-1, -1, -1, -1, -1, -1, -1, -1,-1}; // array of nodes that passed
    int index = node;
    int prev = -1;
    int j = 0;

    while(k != node && index != m) {
    Node* tmp = head[index];
    int min = MAX;
    indexes[index] = index;
        while(tmp != nullptr) {
            if(min > tmp->weight && indexes[tmp->val] == -1) {
                min = tmp->weight;
                index = tmp->val;
            }
            tmp = tmp->next;
        }
        way = way + min;
        mVec[j].first = index;
        mVec[j].second = min;
        ++j;
        k++;
    }

    if(index == m && way != 0) {
        return way;
    } else {
        return MAX;
    }
}

int Graph::minWay(int node, int m) {
    //if node = m return 0
    if(!check(node, m)) {
        return 0;
    }

    //vector contain node from which came and way
    std::vector<std::pair<int, int>> vec;

    //in the first all node initialize -1 and all way initialize MAX
    for(int i = 0; i < nodeNumber; ++i) {
        vec.push_back({-1, MAX});
    }

    //where did the way begin
    vec[node].first = 0;
    vec[node].second = 0;

    int minWay = 0; //minimum way from node to m
    int i = node; //start
    int count = 0; //the number of nodes that passed
    int indexes[nodeNumber] = {-1, -1, -1, -1, -1, -1, -1, -1,-1}; // array of nodes that passed
    int prev = -1; //prevuse index of passed node

    //continues while all nodes do not passed
    int p = 0;
    int k = 0;
    while(count != nodeNumber) {
        k = p;
        p++;
        indexes[i] = i;
        Node* tmp = head[i];//first node of graph
        int minIndex = -1, min = MAX;
        //continues while all neighborhood nodes do not comparing
        while(tmp != nullptr) {
            //if node way greater of new way , then changes way
            if(vec[tmp->val].second > tmp->weight + vec[i].second) {
                vec[tmp->val].second = tmp->weight + vec[i].second;
                vec[tmp->val].first = i;
            }

            //find minium neighborhood node
            if(min > tmp->weight && indexes[tmp->val] == -1) {
                min = tmp->weight;
                minIndex = tmp->val;
            }
            tmp = tmp->next;
        }
        ++count;
        if(min != MAX && prev != i) {
            prev = i;    i = minIndex;//change current node
        } else if(prev == i) {
            for(int j = 0; j < vec.size(); ++j) {
                if(vec[j].first == prev) {
                    i = j; //change current node
                }
            }
            prev = i;
            continue;
        } else {
            prev = i;
            for(int j = 0; j < vec.size(); ++j) {
                if(vec[j].first == prev) {
                    i = j; //change current node
                }
            }
        }
    }

    int it = m;
    std::vector<std::pair<int, int>> mVec;
    std::vector<std::pair<int, int>> mVec1;
    mVec.resize(m-node+1);
    mVec1.resize(m-node + 1);
    int minway2 = minWay2(m, node, mVec);
    int j = 0;
    while (it!=node) {
        if(head[vec[it].first]->val == it) {
            mVec1[j].second =  head[vec[it].first]->weight;
            mVec1[j].first = vec[it].first;
            minWay += head[vec[it].first]->weight;
            it = vec[it].first;
            ++j;
        } else {
            head[vec[it].first] = head[vec[it].first]->next;
        }
    }

    std::cout << "\nStart from: " << std::endl;
    if(minWay <= minway2){
        for(int i = 0; i < mVec1.size(); ++i) {
            std::cout << "node: " << mVec1[i].first << " way: " << mVec1[i].second << std::endl;
        }
    } else {
        for(int i = 0; mVec[i].second != 0 && i < mVec.size(); ++i) {
            std::cout << "node: " << mVec[i].first << " way: " << mVec[i].second << std::endl;
        }
    }

    return minWay < minway2 ? minWay : minway2;
}
