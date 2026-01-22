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
    // vector<vector<int>> generateMatrix(int n) {
    //     vector<vector<int>> matrix(n,vector<int>(n,0));
    //     int num = 1;
    //     int i = 0,j = 0;
    //     /*右下左上为一圈，每次都使用左闭右开区间*/
    //     int cnt = n;
    //     while(num<=n*n){
    //         if(i==j&&j<cnt-1) {
    //             for(;j<cnt-1;)
    //                 matrix[i][j++] = num++;
    //         }
    //         if((i+j)==n-1&&i<cnt-1){
    //             for(;i<cnt-1;)
    //                 matrix[i++][j] = num++;
    //         }
    //         if(i==j&&j>n-cnt){
    //             for(;j>n-cnt;)
    //                 matrix[i][j--] = num++;
    //         }
    //         if((i+j)==n-1&&i>n-cnt){
    //             for(;i>n-cnt;)
    //                 matrix[i--][j] = num++;
    //         }
    //         cnt--;
    //         /*每一圈转完，会回到本圈的起点，需要调节到下一圈的起点*/
	// 			if (num > 1) {
    //                 //只有当跑了一圈(num值增大时)才会进入下一圈
    //                 //为了适配n=1的特殊情况
	// 				i++;
	// 				j++;
	// 			}

	// 			/*转到奇数矩阵的最后一圈时*/
	// 			if ((n + 1) % 2 == 0 && i == n / 2) {
	// 				matrix[n / 2][n / 2] = num++;
	// 			}
    //     }
    //     return matrix;
    // }
/*method2:explict loop*/
    // vector<vector<int>> generateMatrix(int n) {
    //     vector<vector<int>> matrix(n,vector<int>(n,0));
    //     int loop = n/2;//走的（常规）圈数
    //     //定义每圈开始的起点
    //     int startx = 0;
    //     int starty = 0;
    //     //约束每段区间的右端点
    //     // int offset = 1;
    //     int num = 1;//装载进矩阵的数字
    //     int i = 0,j = 0;
    //     while(loop--){
    //         //每一圈的开始，将行列索引赋值为圈的起点
    //         i = startx;
    //         j = starty;
    //         for(j;j<n-1-starty;j++){//j<n-offset
    //             matrix[i][j] = num++;
    //         }
    //         for(i;i<n-1-startx;i++){//i<n-offset
    //             matrix[i][j] = num++;
    //         }
    //         for(j;j>starty;j--){
    //             matrix[i][j] = num++;
    //         }
    //         for(i;i>startx;i--){
    //             matrix[i][j] = num++;
    //         }
    //         // offset++;
    //         startx++;
    //         starty++;
    //     }
    //     if(n%2){
    //         matrix[n/2][n/2] = num;
    //     }
    //     return matrix;
    // }
/*method3:四边界收缩法*/
    vector<vector<int>> generateMatrix(int n){
        vector<vector<int>> matrix(n,vector<int>(n,0));
        int num = 1;
        int target = n*n;
        //定义四个边界
        int top = 0,bot = n-1,left = 0,right = n-1;
        int i,j;
        // while(num<=target){
        while(left<=right&&top<=bot){//当边界交叉时，说明所有格子都被填过

            /*每次把没剥完的一层全部填完，
            四个边界越过的地方代表已经填充过*/
            //left to right
            for(j=left;j<=right;j++) matrix[top][j] = num++;
            top++;
            //top to bottom
            for(i=top;i<=bot;i++) matrix[i][right] = num++;
            right--;
            //right to left
            for(j=right;j>=left;j--) matrix[bot][j] = num++;
            bot--;
            //bottom to top
            for(i=bot;i>=top;i--) matrix[i][left] = num++;
            left++;
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

