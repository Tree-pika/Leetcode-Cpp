/*
 * @lc app=leetcode.cn id=200 lang=cpp
 * @lcpr version=30204
 *
 * [200] 岛屿数量
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
// @lcpr-template-end
// @lc code=start
class Solution {
// private:
//     int m,n;
//     void dfs(vector<vector<char>>&grid,int i,int j){
//         //base case
//         if(i<0||i>=m||j<0||j>=n){
//             return;
//         }
//         if(grid[i][j]=='0'){
//             return;//只找与陆地相邻的陆地，避免淹没多了，导致漏解
//         }
//         grid[i][j] = '0';
//         dfs(grid,i-1,j);
//         dfs(grid,i+1,j);
//         dfs(grid,i,j-1);
//         dfs(grid,i,j+1);
//     }
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         m = grid.size();
//         n = grid[0].size();
//         int ans = 0;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(grid[i][j]=='1'){
//                     ans++;
//                     dfs(grid,i,j);
//                 }
//             }
//         }
//         return ans;
//     }
/*solution2:using std::stack*/
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int m = grid.size(),n = grid[0].size();
//         stack<pair<int,int>> st;
//         int ans = 0;
//         //上下左右offset
//         int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(grid[i][j]=='1'){
//                     ans++;
//                     st.push({i,j});
//                     grid[i][j] = '0';
//                     while(!st.empty()){
//                         auto [r,c] = st.top();//为了拿到每个出栈元素的索引，选择压栈坐标对，而不是元素本身
//                         st.pop();
//                         for(int k=0;k<4;k++){
//                             int next_i = r+dirs[k][0];
//                             int next_j = c+dirs[k][1];
//                             if(next_i>=0&&next_i<m&&next_j>=0&&next_j<n&&
//                                 grid[next_i][next_j]=='1'){
//                                 st.push({next_i,next_j});
//                                 grid[next_i][next_j] = '0';
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
/*solution3:UF*/
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n = grid[0].size();
        UF uf(grid);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    //只需向右和向下查询合并
                    if(i+1<m&&grid[i+1][j]=='1'){
                        uf.unite(i*n+j,(i+1)*n+j);
                    }
                    if(j+1<n&&grid[i][j+1]=='1'){
                        uf.unite(i*n+j,i*n+j+1);
                    }
                }
            }
        }
        return uf.getCount();
    }
private:
    class UF{
        private:
            int count;
            //存放父亲的索引
            vector<int> parent;
            vector<int> rank;//union by rank/height
        public:
            //构造+初始化
            UF(vector<vector<char>>&grid){
                int m=grid.size(),n=grid[0].size();
                count = 0;
                parent.resize(m*n);
                rank.resize(m*n,0);
                for(int i=0;i<m;i++){
                    for(int j=0;j<n;j++){
                        if(grid[i][j]=='1'){
                            count++;
                            //节点统一编号为i*n+j
                            parent[i*n+j] = i*n+j;
                        }
                    }
                }
            }
            //判断两个节点是否连通
            bool isConnected(int x,int y){
                return find(x)==find(y);
            }
            //查找节点i的根节点
            int find(int i) {
                //完全路径压缩
                // if(i!=parent[i]){
                //     parent[i] = find(parent[i]);
                // }
                // return parent[i];
                while(i!=parent[i]){
                    //隔代路径压缩
                    parent[i] = parent[parent[i]];
                }
                return i;
            }
            // 合并两个节点
            void unite(int x, int y) {
                int rootx = find(x);
                int rooty = find(y);
                if(rootx!=rooty){
                    if(rank[rootx]>rank[rooty]){
                        parent[rooty] = rootx;
                    }else if(rank[rootx]<rank[rooty]){
                        parent[rootx] = rooty;
                    }else{
                        parent[rootx] = rooty;
                        rank[rooty]+=1;
                    }
                    count--;
                }
            }
            //获取连通量数目
            int getCount(){
                return count;
            }
            
    };
};
// @lc code=end



/*
// @lcpr case=start
// [['1','1','1','1','0'],['1','1','0','1','0'],['1','1','0','0','0'],['0','0','0','0','0']]\n
// @lcpr case=end

// @lcpr case=start
// [['1','1','0','0','0'],['1','1','0','0','0'],['0','0','1','0','0'],['0','0','0','1','1']]\n
// @lcpr case=end

 */

