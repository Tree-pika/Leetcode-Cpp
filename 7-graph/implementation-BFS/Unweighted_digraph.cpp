/*directed unweighted graph:有向无权图*/
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;
/*邻接表实现*/
class UnweightedDigraph {
public:
    // 存储相邻节点及边的权重
    struct Edge {
        int to;
        int weight;

        Edge(int to, int weight) {
            this->to = to;
            this->weight = weight;
        }
    };

private:
    // 邻接表，graph[v] 存储节点 v 的所有邻居节点及对应权重
    vector<vector<Edge>> graph;

public:
    WeightedDigraph(int n) {
        // 我们这里简单起见，建图时要传入节点总数，这其实可以优化
        // 比如把 graph 设置为 Map<Integer, List<Edge>>，就可以动态添加新节点了
        graph = vector<vector<Edge>>(n);
    }

    // 增，添加一条带权重的有向边，复杂度 O(1)
    // 如果调用时不传 weight，则默认为 1（无权边）
    // 如果传了 weight，则为加权边
    void addEdge(int from, int to, int weight = 1) {
        graph[from].emplace_back(to, weight);
        // graph[from].push_back({to,weight});
    }

    // 删，删除一条有向边，复杂度 O(V)
    void removeEdge(int from, int to) {
        for (auto it = graph[from].begin(); it != graph[from].end(); ++it) {
            if (it->to == to) {
                graph[from].erase(it);
                break;
            }
        }
    }

    // 查，判断两个节点是否相邻，复杂度 O(V)
    bool hasEdge(int from, int to) {
        for (const auto& e : graph[from]) {
            if (e.to == to) {
                return true;
            }
        }
        return false;
    }

    // 查，返回一条边的权重，复杂度 O(V)
    // 对于无权图，这个方法依然返回 1
    int weight(int from, int to) {
        for (const auto& e : graph[from]) {
            if (e.to == to) {
                return e.weight;
            }
        }
        throw invalid_argument("No such edge");
    }

    // 查，返回某个节点的所有邻居节点，复杂度 O(1)
    const vector<Edge>& neighbors(int v) {
        return graph[v];
    }
};

/*邻接矩阵实现*/
class WeightedDigraph {
public:
    // 存储相邻节点及边的权重
    struct Edge {
        int to;
        int weight;

        Edge(int to, int weight):to(to),weight(weight) {}
    };

private:
    // 邻接矩阵，matrix[from][to] 存储从节点 from 到节点 to 的边的权重
    // 0 表示没有连接
    vector<vector<int>> matrix;

public:
    WeightedDigraph(int n) {
        matrix = vector<vector<int>>(n, vector<int>(n, 0));
    }

    // 增，添加一条带权重的有向边，复杂度 O(1)
    void addEdge(int from, int to, int weight=1) {
        matrix[from][to] = weight;
    }

    // 删，删除一条有向边，复杂度 O(1)
    void removeEdge(int from, int to) {
        matrix[from][to] = 0;
    }

    // 查，判断两个节点是否相邻，复杂度 O(1)
    bool hasEdge(int from, int to) {
        return matrix[from][to] != 0;
    }

    // 查，返回一条边的权重，复杂度 O(1)
    int weight(int from, int to) {
        return matrix[from][to];
    }

    // 查，返回某个节点的所有邻居节点，复杂度 O(V)
    vector<Edge> neighbors(int v) {
        vector<Edge> res;
        for (int i = 0; i < matrix[v].size(); i++) {
            if (matrix[v][i] != 0) {
                res.emplace_back(i, matrix[v][i]);
            }
        }
        return res;
    }
};