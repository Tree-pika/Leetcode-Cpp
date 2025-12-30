/*
 * @lc app=leetcode.cn id=994 lang=cpp
 * @lcpr version=30204
 *
 * [994] 腐烂的橘子
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
private:
    int m,n;
public:
    // int orangesRotting(vector<vector<int>>& grid) {
    //     m = grid.size();
    //     n = grid[0].size();
    //     int cnt = 0;
    //     queue<pair<int,int>> que;
    //     for(int i=0;i<m;i++){
    //         for(int j=0;j<n;j++){
    //             if(grid[i][j]==2){
    //                 que.push({i,j});
    //             }
    //         }
    //     }
    //     while(!que.empty()){
    //         for(int k=que.size()-1;k>=0;k--){
    //             auto [r,c] = que.front();
    //             que.pop();
    //             if(r+1<m&&grid[r+1][c]==1){
    //                 que.push({r+1,c});
    //                 grid[r+1][c]=2;
    //             }
    //             if(r-1>=0&&grid[r-1][c]==1){
    //                 que.push({r-1,c});
    //                 grid[r-1][c]=2;
    //             }
    //             if(c+1<n&&grid[r][c+1]==1){
    //                 que.push({r,c+1});
    //                 grid[r][c+1]=2;
    //             }
    //             if(c-1>=0&&grid[r][c-1]==1){
    //                 que.push({r,c-1});
    //                 grid[r][c-1]=2;
    //             }
    //         }
    //         cnt++;
    //     }
    //     if(cnt>0) cnt--;//最后一轮没有感染新的橘子，只是处理上一轮留下的烂橘子，所以cnt多加了1
    //     for(int i=0;i<m;i++){
    //         for(int j=0;j<n;j++){
    //             if(grid[i][j]==1){
    //                 cnt = -1;
    //                 break;
    //             }
    //         }
    //     }
    //     return cnt;
    // }
/*solution2：improvement*/
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int fresh_count=0;//避免最后的扫描，检验可达性
        queue<pair<int,int>> que;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    que.push({i,j});
                }else if(grid[i][j]==1){
                    fresh_count++;
                }
            }
        }
        int cnt = 0;//计时
        bool rotted_orange = false;//辅助更新cnt
        const int dirs[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
        while(!que.empty()){
            rotted_orange = false;
            for(int i=que.size()-1;i>=0;i--){
                auto [r,c]=que.front();
                que.pop();
                for(auto [dr,dc]:dirs){
                    int nr = r+dr;
                    int nc = c+dc;
                    if(nr>=0&&nr<m&&nc>=0&&nc<n&&grid[nr][nc]==1){
                        grid[nr][nc]=2;// 标记为腐烂，避免重复访问
                        fresh_count--;
                        que.push({nr,nc});
                        rotted_orange = true;
                    }
                }
            }
            if(rotted_orange) cnt++;
        }
        return fresh_count==0?cnt:-1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[2,1,1],[1,1,0],[0,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[2,1,1],[0,1,1],[1,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,2]]\n
// @lcpr case=end

 */

