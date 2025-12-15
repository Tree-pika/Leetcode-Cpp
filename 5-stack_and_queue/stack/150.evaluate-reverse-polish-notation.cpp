/*
 * @lc app=leetcode.cn id=150 lang=cpp
 * @lcpr version=30204
 *
 * [150] 逆波兰表达式求值
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
    int evalRPN(vector<string>& tokens) {
        stack<long long> cal;
        for(auto str:tokens){
            if(str=="+"||str=="-"||str=="*"||str=="/"){
                long long num2 = cal.top();
                cal.pop();
                long long num1 = cal.top();
                cal.pop();
                long long res;
                if(str=="+") res = num1+num2;
                else if(str=="-") res = num1-num2;
                else if(str=="*") res = num1*num2;
                else res = num1/num2;
                cal.push(res);
            }else{
                long long num = stoll(str);
                cal.push(num);
            }
        }
        long long ans = cal.top();
        cal.pop();
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["2","1","+","3","*"]\n
// @lcpr case=end

// @lcpr case=start
// ["4","13","5","/","+"]\n
// @lcpr case=end

// @lcpr case=start
// ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]\n
// @lcpr case=end

 */

