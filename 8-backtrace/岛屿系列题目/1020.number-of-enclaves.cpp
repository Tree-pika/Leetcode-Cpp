/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 * @lcpr version=30204
 *
 * [1020] 飞地的数量
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
/*solution1:遍历的思路*/
// private:
//     int m,n;
//     int cnt;
//     void dfs(vector<vector<int>>&grid,int x,int y,bool flag){
//         if(x<0||x>=m||y<0||y>=n){
//             return;
//         }
//         if(grid[x][y]==0){
//             return;
//         }
//         grid[x][y]=0;
//         if(flag) cnt++;
//         dfs(grid,x-1,y,flag);
//         dfs(grid,x+1,y,flag);
//         dfs(grid,x,y-1,flag);
//         dfs(grid,x,y+1,flag);
//     }
// public:
//     int numEnclaves(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();
//         cnt=0;
//         //pre-processing
//         for(int i=0;i<m;i++){
//             dfs(grid,i,0,false);
//             dfs(grid,i,n-1,false);
//         }
//         for(int j=0;j<n;j++){
//             dfs(grid,0,j,false);
//             dfs(grid,m-1,j,false);
//         }
//         //
//         for(int i=1;i<m-1;i++){
//             for(int j=1;j<n-1;j++){
//                 if(grid[i][j]==1){
//                     dfs(grid,i,j,true);
//                 }
//             }
//         }
//         return cnt;
//     }
/*分解问题的思路*/
private:
    int m,n;
    /*返回当前连通块的陆地单元格数量*/
    int dfs(vector<vector<int>>&grid,int i,int j){
        if(i<0||i>=m||j<0||j>=n){
            return 0;
        }
        if(grid[i][j]==0){
            return 0;
        }
        grid[i][j] = 0;
        int area = 1;
        area+=dfs(grid,i-1,j);
        area+=dfs(grid,i+1,j);
        area+=dfs(grid,i,j-1);
        area+=dfs(grid,i,j+1);
        return area;
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int totalEnclaves = 0;
        //pre-processing
        for(int i=0;i<m;i++){
            dfs(grid,i,0);
            dfs(grid,i,n-1);
        }
        for(int j=0;j<n;j++){
            dfs(grid,0,j);
            dfs(grid,m-1,j);
        }
        //
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(grid[i][j]==1){
                    totalEnclaves+=dfs(grid,i,j);
                }
            }
        }
        return totalEnclaves;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]\n
// @lcpr case=end

 */

