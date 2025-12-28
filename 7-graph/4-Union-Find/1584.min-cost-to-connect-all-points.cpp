/*
 * @lc app=leetcode.cn id=1584 lang=cpp
 * @lcpr version=30204
 *
 * [1584] 连接所有点的最小费用
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <cmath>
// @lcpr-template-end
// @lc code=start
class Solution {
/*solution1*/
// private:
//     //distance-->{i,j}i,j为表示两个点的索引
//     multimap<int,vector<int>> costMap;
// public:
//     int minCostConnectPoints(vector<vector<int>>& points) {
//         buildCost(points);
//         int minCost = 0;
//         int n = points.size();
//         UF uf(n);
//         for(auto &[k,v]:costMap){
//             int p1=v[0],p2=v[1];
//             if(uf.connected(p1,p2)){
//                 continue;
//             }
//             uf.union_(p1,p2);
//             minCost+=k;
//         }
//         return minCost;//所有点都是可连的，直接返回即可
//     }
// private:
//     void buildCost(vector<vector<int>>& points){
//         int distance=0;
//         for(int i=0;i<points.size();i++){
//             for(int j=i+1;j<points.size();j++){
//                 int x1=points[i][0],y1=points[i][1];
//                 int x2=points[j][0],y2=points[j][1];
//                 distance = abs(x1-x2)+abs(y1-y2);
//                 costMap.insert({distance,vector<int>{i,j}});
//             }
//         }
//     }
/*solution2:similar to 1135*/
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> connections;
        connections.reserve(n * (n - 1) / 2);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int xi = points[i][0], yi = points[i][1];
                int xj = points[j][0], yj = points[j][1];
                connections.push_back({i,j,abs(xi-xj)+abs(yi-yj)});
            }
        }
        sort(connections.begin(),connections.end(),[](vector<int>&a1,vector<int>&a2){
            return a1[2]<a2[2];
        });
        int minCost = 0;
        int cnt = 0;//记录已经连接的边数
        UF uf(n);
        for(vector<int>&e:connections){
            if(uf.connected(e[0],e[1])){
                continue;
            }
            uf.unionNodes(e[0],e[1]);
            cnt++;
            minCost+=e[2];
            if(cnt==n-1) break;//已经全部连上了，没有找下去的必要了
        }
        return minCost;
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
            if (rootP == rootQ) return;

            // 小树接到大树下面，较平衡
            if (size[rootP] > size[rootQ]) {
                parent[rootQ] = rootP;
                size[rootP] += size[rootQ];
            } else {
                parent[rootP] = rootQ;
                size[rootQ] += size[rootP];
            }
            // 两个连通分量合并成一个连通分量
            --count;
        }

        // 判断节点 p 和节点 q 是否连通
        bool connected(int p, int q) {
            return find(p) == find(q);
        }

        // 返回节点 x 的连通分量根节点
        int find(int x) {
            // 根节点的 parent[x] == x
            while (parent[x] != x)
                x = parent[x];
            return x;
        }

        // 返回图中的连通分量个数
        int countComponents() {
            return count;
        }
    };
};
// @lc code=end



/*
// @lcpr case=start
// [[0,0],[2,2],[3,10],[5,2],[7,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,12],[-2,5],[-4,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0],[1,1],[1,0],[-1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[-1000000,-1000000],[1000000,1000000]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0]]\n
// @lcpr case=end

 */

