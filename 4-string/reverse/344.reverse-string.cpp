/*
 * @lc app=leetcode.cn id=344 lang=cpp
 * @lcpr version=30204
 *
 * [344] 反转字符串
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
    // void reverseString(vector<char>& s) {
    //     int n = s.size();
    //     for(int i=0;i<n/2;i++){
    //         // char tmp = s[i];
    //         // s[i] = s[n-1-i];
    //         // s[n-1-i] = tmp;
    //         /*2*/
    //         swap(s[i],s[n-1-i]);
    //     }
    // }
    /*method2:double pointers*/
    void reverseString(vector<char>& s) {
        int n=s.size();
        for(int i=0,j=n-1;i<j;i++,j--){
            swap(s[i],s[j]);
        }
    }

};
// @lc code=end



/*
// @lcpr case=start
// ["h","e","l","l","o"]\n
// @lcpr case=end

// @lcpr case=start
// ["H","a","n","n","a","h"]\n
// @lcpr case=end

 */

