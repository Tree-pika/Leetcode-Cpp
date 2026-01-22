/*
 * @lc app=leetcode.cn id=14 lang=cpp
 * @lcpr version=30204
 *
 * [14] 最长公共前缀
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
    string longestCommonPrefix(vector<string>& strs) {
        //以第一行串为基准
        int n=strs[0].size();
        for(int j=0;j<n;j++){
            for(string&s:strs){
                if(j==s.size()||s[j]!=strs[0][j]){//与第一串的字符不匹配或字符不够了
                    //pos,len
                    return strs[0].substr(0,j);
                }
            }
        }
        return strs[0];
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["flower","flow","flight"]\n
// @lcpr case=end

// @lcpr case=start
// ["dog","racecar","car"]\n
// @lcpr case=end

 */

