/*
 * @lc app=leetcode.cn id=459 lang=cpp
 * @lcpr version=30204
 *
 * [459] 重复的子字符串
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
/*method1：移动匹配,利用库函数contains/find*/
    // bool repeatedSubstringPattern(string s) {
    //     string t = s+s;
    //     //erase(pos,len)
    //     t.erase(0,1);
    //     //erase([begin,end))
    //     t.erase(t.end()-1);
    //     bool flag = t.contains(s);
    //     return flag;
    //     // if(t.find(s)!=string::npos) return true;
    //     // return false;
    // }
/*method2：KMP-bad thinking*/
    // bool repeatedSubstringPattern(string s) {
    //     string t = s+s;
    //     t.erase(t.begin());
    //     t.erase(t.end()-1);
    //     int n = s.length();
    //     vector<int> next(n,0);
    //     /*i指向后缀末尾，j指向前缀末尾
    //     next[0]=0*/
    //     for(int i=1,j=0;i<n;i++){
    //         while(j>=1&&s[i]!=s[j]){
    //             j = next[j-1];
    //         }
    //         if(s[i]==s[j]){
    //             j++;
    //         }
    //         next[i] = j;
    //     }
    //     /*t中查找是否存在子串s
    //     i指向t中字符，j指向s中字符*/
    //     for(int i=0,j=0;i<t.length();i++){
    //         if(j>=1&&t[i]!=s[j]){
    //             j = next[j-1];
    //         }
    //         if(t[i]==s[j]){
    //             j++;
    //         }
    //         if(j==n){
    //             return true;
    //         }
    //     }
    //     return false;
    // }
/*method2：KMP-good thinking*/
bool repeatedSubstringPattern(string s) {
    /*计算s的最长相等前后缀*/
    int n = s.length();
    vector<int> next(n,0);
    for(int i=1,j=0;i<n;i++){
        while(j>=1&&s[i]!=s[j]){
            j = next[j-1];
        }
        if(s[i]==s[j]){
            j++;
        }
        next[i] = j;
    }
    int len = n-next[n-1];
    return next[n-1]&&(n%len==0);
}
};
// @lc code=end



/*
// @lcpr case=start
// "abab"\n
// @lcpr case=end

// @lcpr case=start
// "aba"\n
// @lcpr case=end

// @lcpr case=start
// "abcabcabcabc"\n
// @lcpr case=end

 */

