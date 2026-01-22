/*
 * @lc app=leetcode.cn id=59 lang=cpp
 * @lcpr version=30204
 *
 * [59] 螺旋矩阵 II
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
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n,0));
        int num=1;
        int left=0,right=n-1;
        int up = 0,down = n-1;
        while(num<=n*n){
            if(up<=down){
                for(int j=left;j<=right;j++)
                    matrix[up][j] = num++;
                up++;
            }
            if(left<=right){
                for(int i=up;i<=down;i++)
                    matrix[i][right] = num++;
                right--;
            }
            if(up<=down){
                for(int j=right;j>=left;j--)
                    matrix[down][j] = num++;
                down--;
            }
            if(left<=right){
                for(int i=down;i>=up;i--)
                    matrix[i][left] = num++;
                left++;
            }
        }
        return matrix;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

