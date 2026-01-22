/*
 * @lc app=leetcode.cn id=54 lang=cpp
 * @lcpr version=30204
 *
 * [54] 螺旋矩阵
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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(),n = matrix[0].size();
        int up = 0,down = m-1;
        int left = 0,right = n-1;
        vector<int> res;
        while(res.size()<m*n){
            if(up<=down){
                for(int j=left;j<=right;j++)
                    res.push_back(matrix[up][j]);
                up++;
            }
            if(left<=right){
                for(int i=up;i<=down;i++)
                    res.push_back(matrix[i][right]);
                right--;
            }
            if(up<=down){
                for(int j=right;j>=left;j--)
                    res.push_back(matrix[down][j]);
                down--;
            }
            if(left<=right){
                for(int i=down;i>=up;i--)
                    res.push_back(matrix[i][left]);
                left++;
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
// [[1,2,3,4],[5,6,7,8],[9,10,11,12]]\n
// @lcpr case=end

 */

