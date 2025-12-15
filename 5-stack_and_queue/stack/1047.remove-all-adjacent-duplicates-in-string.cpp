/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 * @lcpr version=30204
 *
 * [1047] 删除字符串中的所有相邻重复项
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
    // string removeDuplicates(string s) {
    //     stack<char> res;
    //     for(char c:s){
    //         if(!res.empty()&&c==res.top())
    //             res.pop();
    //         else
    //             res.push(c);
    //     }
    //     string ans;
    //     while(!res.empty()){
    //         ans+=res.top();
    //         res.pop();
    //     }
    //     reverse(ans.begin(),ans.end());
    //     return ans;
    // }

    /*method2:using string as a stack*/
    string removeDuplicates(string s) {
        string ans;
        for(char c:s){
            if(!ans.empty()&&c==ans.back()){
                ans.pop_back();
            }else
                ans.push_back(c);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abbaca"\n
// @lcpr case=end

 */

