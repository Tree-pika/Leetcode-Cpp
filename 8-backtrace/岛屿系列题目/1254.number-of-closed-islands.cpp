/*
 * @lc app=leetcode.cn id=1254 lang=cpp
 * @lcpr version=30204
 *
 * [1254] 统计封闭岛屿的数目
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
//     // 从 (x, y) 开始，将与之相邻的陆地都变成海水
//     void dfs(vector<vector<int>>&grid,int x,int y){
//         if(x<0||x>=m||y<0||y>=n){
//             return;
//         }
//         if(grid[x][y]==1){
//             return;
//         }
//         grid[x][y] = 1;
//         dfs(grid,x-1,y);
//         dfs(grid,x+1,y);
//         dfs(grid,x,y-1);
//         dfs(grid,x,y+1);
//     }
// public:
//     int closedIsland(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();
//         int cnt = 0;
//         /*先将接触到边缘的所有陆地全部淹没(非封闭岛屿)*/
//         for(int i=0;i<m;i++){
//             dfs(grid,i,0);
//             dfs(grid,i,n-1);
//         }
//         for(int j=0;j<n;j++){
//             dfs(grid,0,j);
//             dfs(grid,m-1,j);
//         }
//         /*然后再在中间区域进行陆地搜索*/
//         for(int i=1;i<m-1;i++){
//             for(int j=1;j<n-1;j++){
//                 if(grid[i][j]==0){
//                     cnt++;
//                     dfs(grid,i,j);
//                 }
//             }
//         }
//         return cnt;
//     }
/*solution2:Boolean DFS*/
private:
    int m,n;
    /*sink the neighbor land and return whether is closed*/
    bool dfs(vector<vector<int>>&grid,int i,int j){
        //边界检查
        if(i<0||i>=m||j<0||j>=n){
            return false;
        }
        if(grid[i][j]==1){
            return true;
        }
        grid[i][j] = 1;
        bool up = dfs(grid,i-1,j);
        bool down = dfs(grid,i+1,j);
        bool left = dfs(grid,i,j-1);
        bool right = dfs(grid,i,j+1);
        return up&&down&&left&&right;//左右都是水才是封闭的
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    if(dfs(grid,i,j)){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,1,1,1,1,1],[1,0,0,0,0,0,1],[1,0,1,1,1,0,1],[1,0,1,0,1,0,1],[1,0,1,1,1,0,1],[1,0,0,0,0,0,1],[1,1,1,1,1,1,1]]\n
// @lcpr case=end

 */

