/*
 * @lc app=leetcode.cn id=48 lang=cpp
 * @lcpr version=30204
 *
 * [48] 旋转图像
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
//先按对角线对称，再逐行reverse
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //对角线[i][j]<->[j][i]
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        //逐行：利用左右对撞双指针
        for(int i=0;i<n;i++){
            int left=0,right = n-1;
            while(left<right){
                int tmp=matrix[i][left];
                matrix[i][left] = matrix[i][right];
                matrix[i][right] = tmp;
                left++;
                right--;
            }
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]\n
// @lcpr case=end

 */

