/*
 * @lc app=leetcode.cn id=367 lang=cpp
 * @lcpr version=30204
 *
 * [367] 有效的完全平方数
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
    bool isPerfectSquare(int num) {
        int q = Mysqrt(num);
        if(q*q==num){
            return true;
        }
        else 
            return false;
    }
    int Mysqrt(int num){
        /*为了防止后面xi*xi溢出，这里xi得设置为大数据类型*/
        long long xi = num;
        while(xi*xi>num){
            xi = (xi+num/xi)>>1;
        }
        return xi;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 16\n
// @lcpr case=end

// @lcpr case=start
// 14\n
// @lcpr case=end

 */

