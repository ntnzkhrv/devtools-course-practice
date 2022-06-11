// Copyright 2022 Khlyustov Ilya

#ifndef MODULES_KHLYUSTOV_ILYA_KRUSKAL_ALGORITHM_INCLUDE_KRUSKAL_H_
#define MODULES_KHLYUSTOV_ILYA_KRUSKAL_ALGORITHM_INCLUDE_KRUSKAL_H_

#include <vector>
#include <numeric>
#include <stdexcept>

struct Edge {
    Edge(size_t src_, size_t dst_, int weight_);

    bool operator <(const Edge& rhs) const;

    bool operator ==(const Edge& rhs) const;

    size_t src, dst;
    int weight;
};

class Graph {
 public:
    explicit Graph(size_t nodesCount);

    Graph(size_t nodesCount, std::vector<Edge> edges);

    std::vector<Edge> getMST();

    size_t getNodesCount();

    size_t getEdgesCount();

    void addEdge(const Edge& newEdge);

 private:
    size_t _nodesCount;
    std::vector<size_t> _parent, _rank;
    std::vector<Edge> _edges;

    bool unite(size_t a, size_t b);

    size_t getRepresentativeParent(size_t src);
};


#endif  //  MODULES_KHLYUSTOV_ILYA_KRUSKAL_ALGORITHM_INCLUDE_KRUSKAL_H_
