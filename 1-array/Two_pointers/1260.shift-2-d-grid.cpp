/*
 * @lc app=leetcode.cn id=1260 lang=cpp
 * @lcpr version=30204
 *
 * [1260] 二维网格迁移
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
public:
//序列化+右旋转
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n = grid[0].size();
        vector<int> res;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res.push_back(grid[i][j]);
            }
        }
        k = k%(m*n);//防止数组访问越界
        reverseArray(res,0,m*n-1);
        reverseArray(res,0,k-1);
        reverseArray(res,k,m*n-1);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                grid[i][j] = res[i*n+j];
            }
        }
        return grid;
    }
private:
    void reverseArray(vector<int>&res,int start,int end){
        while(start<end){
            int tmp=res[start];
            res[start] = res[end];
            res[end] = tmp;
            start++;
            end--;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n1\n
// @lcpr case=end

// @lcpr case=start
// [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]]\n4\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n9\n
// @lcpr case=end

 */

