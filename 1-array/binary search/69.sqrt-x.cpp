/*
 * @lc app=leetcode.cn id=69 lang=cpp
 * @lcpr version=30204
 *
 * [69] x 的平方根 
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
/*method 1:袖珍计算器算法
用指数函数 exp 和对数函数 ln 代替平方根函数的方法。*/
    // int mySqrt(int x) {
    //     if(x==0) return 0;
    //     int q;
    //     q = exp(0.5*log(x));
    //     /*浮点数精度误差*/
    //     if((long long)(q+1)*(q+1)<=x){
    //         return q+1;
    //     }
    //     return q;
    // }
/*method-2:binary search
二分查找的本质不是一定要在区间范围内找到最终的结果ans
我们要找到的值只要与ans有恒定的数学关系即可。
*/
//     int mySqrt(int x) {
//        int left = 0;
//        int right = x;
//        /*规定要找的平方根位于左闭右闭区间[left,right]*/
//        while(left<=right){
//         long long mid = left+(right-left)/2;
//         if(mid*mid==x){
//             return mid;
//         }
//         else if(mid*mid<x){
//             left = mid+1;
//         }
//         else{
//             right = mid-1;
//         }
//        }
//        return right;
//     }

/*method-3:Newton's method*/
    int mySqrt(int x){
        if(x==0) return 0;
        long long xi = x;
        // int y = xi*xi-x;
        // int dy = 2*xi;
        while(xi*xi>x){
            // xi = 0.5*(xi+x/xi);
            /*x/xi会发生整除，为了和 0.5 相乘，整数被转成 double
            赋值给xi时，又被强制转为double，索性都用整数位移更快*/
            xi = (xi+x/xi)>>1;
            // y = xi*xi-x;
            // dy = 2*xi;
            /*自己直接将最终的迭代式计算并简化出来，
            重复算中间值很耗时*/
        }
        return xi;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 8\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

