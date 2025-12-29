/*
 * @lc app=leetcode.cn id=695 lang=cpp
 * @lcpr version=30204
 *
 * [695] 岛屿的最大面积
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
/*solution1:using DFS with recursion*/
// private:
//     int m,n;
//     /*返回当前连通块的陆地单元格数量*/
//     int dfs(vector<vector<int>>& grid,int i,int j){
//         if(i<0||i>=m||j<0||j>=n){
//             return 0;
//         }
//         if(grid[i][j]==0){
//             return 0;
//         }
//         grid[i][j] = 0;
//         int area = 1;
//         area+=dfs(grid,i-1,j);
//         area+=dfs(grid,i+1,j);
//         area+=dfs(grid,i,j-1);
//         area+=dfs(grid,i,j+1);

//         return area;
//     }
// public:
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();
//         int maxArea = 0;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(grid[i][j]==1){
//                     maxArea = max(maxArea,dfs(grid,i,j));
//                 }
//             }
//         }
//         return maxArea;
//     }
/*solution2:using UF*/
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        UF uf(grid);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    if(i+1<m&&grid[i+1][j]==1){
                        uf.unite(i*n+j,(i+1)*n+j);
                    }
                    if(j+1<n&&grid[i][j+1]==1){
                        uf.unite(i*n+j,i*n+j+1);
                    }
                }
            }
        }
        return uf.getMaxSize();
    }
private:
    class UF{
        private:
            vector<int> parent;
            vector<int> size;//uinon by size
            int m,n;
            int maxArea;
        public:
            UF(vector<vector<int>>&grid){
                m = grid.size();
                n = grid[0].size();
                maxArea = 0;
                parent.resize(m*n);
                size.resize(m*n,0);
                for(int i=0;i<m;i++){
                    for(int j=0;j<n;j++){
                        if(grid[i][j]==1){
                            parent[i*n+j] = i*n+j;
                            size[i*n+j] = 1;
                            maxArea = 1;
                        }
                    }
                }
            }
            int find(int i){
                if(i!=parent[i]){
                    parent[i] = find(parent[i]);
                }
                return parent[i];
            }
            // bool isConnected(int x,int y){
            //     return find(x)==find(y);
            // }
            void unite(int x,int y){
                int rootx = find(x);
                int rooty = find(y);
                if(rootx!=rooty){
                    if(size[rootx]>size[rooty]){
                        parent[rooty] = rootx;
                        size[rootx]+=size[rooty];
                        maxArea = max(maxArea,size[rootx]);
                    }else{
                        parent[rootx] = rooty;
                        size[rooty]+=size[rootx];
                        maxArea = max(maxArea,size[rooty]);
                    }
                }
            }
            int getMaxSize(){
                return maxArea;
            }
    };
};
// @lc code=end



/*
// @lcpr case=start
// [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,0,0,0,0,0,0]]\n
// @lcpr case=end

 */

