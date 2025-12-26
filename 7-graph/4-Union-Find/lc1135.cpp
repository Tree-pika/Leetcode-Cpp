/*
想象一下你是个城市基建规划者，地图上有 n 座城市，它们按以 1 到 n 的次序编号。

给你整数 n 和一个数组 conections，其中 connections[i] = [xi, yi, costi] 表示将城市 xi 和城市 yi 连接所要的costi（连接是双向的）。

返回连接所有城市的最低成本，每对城市之间至少有一条路径。如果无法连接所有 n 个城市，返回 -1

该 最小成本 应该是所用全部连接成本的总和。

*/

class Solution{
public:
    int minimumCost(int n, vector<vector<int>>& connections){
        // 城市编号为 1...n，所以初始化大小为 n + 1
        UF uf(n+1);
        int mst = 0;
        sort(connections.begin(),connections.end(),[](const vector<int>& a1,const vector<int>& a2){
            return a1[2]<a2[2];
        });
        for(auto& edge:connections){
            int u=edge[0],v=edge[1];
            int weight = edge[2];
            // 若这条边会产生环，则不能加入 mst
            if(uf.connected(u,v)){
                continue;
            }
            // 若这条边不会产生环，则属于最小生成树
            uf.unionNodes(u,v);
            mst+=weight;
        }
        // 保证所有节点都被连通：存在图本来就不连通的情况
        // 但因为节点 0 没有被使用，所以 0 会额外占用一个连通分量
        return uf.getCount()==2?mst:-1;
    }
private:
    class UF {
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

        // 将节点 p 和节点 q 连通
        void unionNodes(int p, int q) {
            int rootP = find(p);
            int rootQ = find(q);
            if (rootP == rootQ)
                return;

            // 小树接到大树下面，较平衡
            if (size[rootP] > size[rootQ]) {
                parent[rootQ] = rootP;
                size[rootP] += size[rootQ];
            } else {
                parent[rootP] = rootQ;
                size[rootQ] += size[rootP];
            }
            // 两个连通分量合并成一个连通分量
            count--;
        }

        // 判断节点 p 和节点 q 是否连通
        bool connected(int p, int q) {
            return find(p) == find(q);
        }

        // 返回节点 x 的连通分量根节点
        int find(int x) {
            while (parent[x] != x) {
                // 进行路径压缩
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        }

        // 返回图中的连通分量个数
        int getCount() {
            return count;
        }
    };
};