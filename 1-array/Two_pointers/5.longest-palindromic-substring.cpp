/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=30204
 *
 * [5] 最长回文子串
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
    string longestPalindrome(string s) {
        string res = "";
        for(int i=0;i<s.length();i++){
            string s1 = expand(s,i,i);
            string s2 = expand(s,i,i+1);
            res = res.length()>s1.length()?res:s1;
            res = res.length()>s2.length()?res:s2;
        }
        return res;
    }
    /*以left和right为中心进行扩散，寻找最长回文*/
    string expand(string&s,int left,int right){
        while(left>=0&&right<s.length()&&s[left]==s[right]){
            left--;
            right++;
        }
        //s[left+1...right-1]
        return s.substr(left+1,right-left-1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */

