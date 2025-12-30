/*
 * @lc app=leetcode.cn id=131 lang=cpp
 * @lcpr version=30204
 *
 * [131] 分割回文串
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
private:
    vector<string> track;
    vector<vector<string>> res;
    void backtrack(string s,int start){
        if(start==s.length()){
            res.push_back(track);
            return;
        }
        //选择列表：从start开始到s末尾都可以切
        for(int end=start;end<s.length();end++){
            /*isPalindrome*/
            // string temp(s,start,end-start+1);//(str,pos,len)
            // string t(temp);
            // reverse(t.begin(),t.end());
            // if(temp!=t){
            //     continue;
            // }
            string temp(s,start,end-start+1);
            if(!isPalindrome(temp)){
                continue;
            }
            //做选择，把 s[start..end] 放入路径列表中
            track.push_back(temp);
            // 进入回溯树的下一层，继续切分 s[end+1..]
            backtrack(s,end+1);
            // 撤销选择
            track.pop_back();
        }
    }
    bool isPalindrome(const string&temp){
        int l = 0,r=temp.length()-1;
        while(l<r){
            if(temp[l]!=temp[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        backtrack(s,0);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aab"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n
// @lcpr case=end

 */

