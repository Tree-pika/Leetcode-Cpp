/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=30204
 *
 * [20] 有效的括号
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
    // bool isEqual(char c1,char c2){
    //     if(c1=='('&&c2==')') return true;
    //     else if(c1=='{'&&c2=='}') return true;
    //     else if(c1=='['&&c2==']') return  true;
    //     else return false;
    // }
    // bool isValid(string s) {
    //     int n = s.length();
    //     if (n % 2 != 0) return false;//剪枝，奇数肯定不能匹配
    //     stack<char> ans;
    //     for(int i=0;i<n;i++){
    //         if(s[i]=='('||s[i]=='{'||s[i]=='['){
    //             ans.push(s[i]);
    //         }else{
    //             if(ans.empty())
    //                 return false;
    //             if(!isEqual(ans.top(),s[i]))
    //                 return false;
    //             ans.pop();
    //         }
    //     }
    //     // if(ans.empty()){
    //     //     return true;
    //     // }
    //     // return false;
    //     return ans.empty();
    // }
/*method2:使用技巧转化判断匹配为判断相等*/
    bool isValid(string s) {
        int n = s.length();
        if(n%2!=0) return false;
        stack<char> ans;
        for(auto c:s){
            if(c=='(') ans.push(')');
            else if(c=='[') ans.push(']');
            else if(c=='{') ans.push('}');
            else if(ans.empty()||ans.top()!=c) return false;
            else ans.pop();
        }
        return ans.empty();
    }

};
// @lc code=end



/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

// @lcpr case=start
// "([])"\n
// @lcpr case=end

// @lcpr case=start
// "([)]"\n
// @lcpr case=end

 */

