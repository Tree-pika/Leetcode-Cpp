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
/*explict loop with 循环不变量*/
    // vector<int> spiralOrder(vector<vector<int>>& matrix) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();
    //     vector<int> res(m*n,0);
    //     int idx = 0;//res的index
    //     int loop = min(m/2,n/2);
    //     int startx = 0;
    //     int starty = 0;
    //     int offset = 1;
    //     int i,j;//遍历matrix的index
    //     while(loop--){
    //         i = startx++;
    //         j = starty++;
    //         for(j;j<n-offset;j++){
    //             res[idx++] = matrix[i][j];
    //         }
    //         for(i;i<m-offset;i++){
    //             res[idx++] = matrix[i][j];
    //         }
    //         for(j;j>offset-1;j--){
    //             res[idx++] = matrix[i][j];
    //         }
    //         for(i;i>offset-1;i--){
    //             res[idx++] = matrix[i][j];
    //         }
    //         offset++;
    //     }
    //     /*当最小边是奇数时，会剩下芯*/
    //     if(min(m,n)%2 ){
    //         i = startx;
    //         j = starty;
    //         offset--;
    //         if(m<=n){
    //             for(j;j<n-offset;j++){
    //                 res[idx++] = matrix[i][j];
    //             }
    //         }
    //         else{
    //             for(;i<m-offset;i++){
    //                 res[idx++] = matrix[i][j];
    //             }
    //         }
    //     }
    //     return res;
    // }
    /*method2:四边界收缩法*/
    vector<int> spiralOrder(vector<vector<int>>& matrix){
        vector<int> ans;
        int top = 0,bot = matrix.size()-1;
        int left = 0,right = matrix[0].size()-1;
        int i;
        while(true){
            //left to right
            for(i=left;i<=right;i++) ans.push_back(matrix[top][i]);
            if(++top>bot) break;
            //top to bottom
            for(i=top;i<=bot;i++) ans.push_back(matrix[i][right]);
            if(--right<left) break;
            //right to left
            for(i=right;i>=left;i--) ans.push_back(matrix[bot][i]);
            if(--bot<top) break;
            //bottom to top
            for(i=bot;i>=top;i--) ans.push_back(matrix[i][left]);
            if(++left>right) break;
        }
        return ans;
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

