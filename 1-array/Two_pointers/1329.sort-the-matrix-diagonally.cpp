/*
 * @lc app=leetcode.cn id=1329 lang=cpp
 * @lcpr version=30204
 *
 * [1329] 将矩阵按对角线排序
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>//greater
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
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int,vector<int>> map;
        int m = mat.size(),n=mat[0].size();
        // 存储所有对角线的元素列表
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int key = i-j;
                map[key].push_back(mat[i][j]);
            }
        }
        // for(auto &diagonal:map){
        //     ranges::sort(diagonal.second,greater<int>());
        // }
        for(auto&[k,v]:map){
            ranges::sort(v,greater<int>());
        }
        // 把排序结果回填二维矩阵
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mat[i][j]=map[i-j].back();
                map[i-j].pop_back();//从后面删除元素更快
            }
        }
        return mat;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[3,3,1,1],[2,2,1,2],[1,1,1,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]\n
// @lcpr case=end

 */

