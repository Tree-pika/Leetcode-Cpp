/*undirected weighted graph:无向加权图
等同于双向的有向加权图*/

class WeightedUndigraph {
private:
    WeightedDigraph graph;

public:
    WeightedUndigraph(int n) : graph(n) {}

    // 增，添加一条带权重的无向边
    void addEdge(int from, int to, int weight) {
        graph.addEdge(from,to,weight);
        graph.addEdge(to,from,weight);
    }

    // 删，删除一条无向边
    void removeEdge(int from, int to) {
        graph.removeEdge(from,to);
        graph.removeEdge(to,from);
    }

    // 查，判断两个节点是否相邻
    bool hasEdge(int from, int to) {
        return graph.hasEdge(from,to);
    }

    // 查，返回一条边的权重
    int weight(int from, int to) {
       return graph.weigh(from,to);
    }

    // 查，返回某个节点的所有邻居节点
    const vector<WeightedDigraph::Edge>& neighbors(int v) const {
        return graph.neighbors(v);
    }
};
