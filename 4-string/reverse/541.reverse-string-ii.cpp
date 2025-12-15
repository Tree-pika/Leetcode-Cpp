/*
 * @lc app=leetcode.cn id=541 lang=cpp
 * @lcpr version=30204
 *
 * [541] 反转字符串 II
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
    string reverseStr(string s, int k) {
        int n = s.size();
        int cnt=0;//偏移量
        while(n>k){
            //反转2k中的前k个字符
            reverse(s.begin()+cnt,s.begin()+cnt+k);//reverse翻转[begin,end)
            cnt+=2*k;
            n-=2*k;
        }
        if(n>0) reverse(s.begin()+cnt,s.end());//剩余字符少于k个
        return s;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcdefg"\n2\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n2\n
// @lcpr case=end

 */

