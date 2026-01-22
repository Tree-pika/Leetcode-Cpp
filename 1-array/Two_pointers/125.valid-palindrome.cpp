/*
 * @lc app=leetcode.cn id=125 lang=cpp
 * @lcpr version=30204
 *
 * [125] 验证回文串
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
    bool isPalindrome(string s) {
        int slow=0,fast=0;
        while(fast<s.length()){
            if(s[fast]>='A'&&s[fast]<='Z'){
                s[slow] = s[fast]-'A'+'a';
                slow++;
            }else if((s[fast]>='a'&&s[fast]<='z')||(s[fast]>='0'&&s[fast]<='9')){
                s[slow] = s[fast];
                slow++;
            }
            fast++;
        }
        s.resize(slow);
        bool flag = true;
        int left=0,right = slow-1;
        while(left<right){
            if(s[left]!=s[right]){
                flag = false;
                break;
            }
            left++;
            right--;
        }
        return flag;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "A man, a plan, a canal: Panama"\n
// @lcpr case=end

// @lcpr case=start
// "race a car"\n
// @lcpr case=end

// @lcpr case=start
// " "\n
// @lcpr case=end

 */

