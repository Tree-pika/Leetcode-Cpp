/*
 * @lc app=leetcode.cn id=867 lang=cpp
 * @lcpr version=30204
 *
 * [867] 转置矩阵
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
    // vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    //     int m=matrix.size(),n=matrix[0].size();
    //     vector<vector<int>> res;
    //     for(int j=0;j<n;j++){
    //         vector<int> tmp;
    //        for(int i=0;i<m;i++){
    //             tmp.push_back(matrix[i][j]);
    //        }
    //        res.push_back(tmp);
    //     }
    //     return res;
    // }
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> res(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res[j][i]=matrix[i][j];
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[4,5,6]]\n
// @lcpr case=end

 */

