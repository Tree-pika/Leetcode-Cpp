> Minimum Spanning Tree, MST 最小生成树
# basic
* 生成树：给定一个无向连通图G，其生成树是 G 的一个子图，它包含G 中的所有顶点，并且是一棵树（即无环连通图）。
* 生成树具有以下特性：
  * 含原图中的所有顶点。
  * 边的数量为顶点数减一（V-1条边）。
  * 连通且无环。
* 生成树 = 含有图所有顶点的「无环连通子图」，最小生成树是权重和最小的生成树。
* 算法：有两种经典的算法用于求解最小生成树问题：Kruskal 算法和 Prim 算法。它们都基于贪心思想，但实现方式不同。
  * Kruskal 算法：先对图中的所有边按照权重排序，然后借助Union-Find判断是否成环
  * Prim 算法可以由 Dijkstra 算法 拓展而来，借助优先级队列 动态排序的特性，逐步构造最小生成树。

# Kruskal
* 先来看如何借助Union-Find判断是否成环
  * 在树中加入一条边：
    * 对于添加的这条边，如果该边的两个节点本来就在同一连通分量里，那么添加这条边会产生环；
    * 反之，如果该边的两个节点不在同一连通分量里，则添加这条边不会产生环。
```cpp
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // 初始化 0...n-1 共 n 个节点
        UF uf(n);
        // 遍历所有边，将组成边的两个节点进行连接
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            // 若两个节点已经在同一连通分量中，会产生环
            if (uf.connected(u, v)) {
                return false;
            }
            // 这条边不会产生环，可以是树的一部分
            uf.unionNodes(u, v);
        }
        // 要保证最后只形成了一棵树，即只有一个连通分量
        return uf.getCount() == 1;
    }
private:
    class UF{
    public:
        // 连通分量个数
        int count;
        // 存储一棵树
        vector<int> parent;
        // 记录树的「重量」
        vector<int> size;

        // n 为图中节点的个数
        UF(int n) : count(n), parent(n), size(n, 1) {
            for (int i = 0; i < n; ++i) {
                parent[i] = i;
            }
        }
        //
        void unionNodes(int p, int q) {};
        bool connected(int p, int q) {};
        int getCount() const {};
        int find(int x) {};        
    };
};
```
* 总的思路
  * 将所有边按照权重从小到大排序，从权重最小的边开始遍历，
  * 如果这条边和 mst 中的其它边不会形成环，则这条边是最小生成树的一部分，将它加入 mst 集合；
  * 否则，这条边不是最小生成树的一部分，不要把它加入 mst 集合。
