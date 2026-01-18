/*
 * @lc app=leetcode.cn id=438 lang=cpp
 * @lcpr version=30204
 *
 * [438] 找到字符串中所有字母异位词
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
/*bruce solution：TLE*/
    // vector<int> findAnagrams(string s, string p) {
    //     int s2 = p.size();
    //     int s1 = s.size();
    //     if(s2>s1||s2==0) return {};
    //     vector<int> ans;
    //     ranges::sort(p);
    //     //在 s1 < s2 时产生 超大无符号数，循环继续执行，访问越界
    //     for(int i=0;i<s1-s2+1;i++){
    //         string t=s.substr(i,s2);
    //         /*每次 substr 都拷贝一段长度为 s2 的字符串，
    //         再对整个段 ranges::sort，总复杂度 O(|s|·|p|·log|p|)
    //         会TLE*/
    //         ranges::sort(t);
    //         if(p==t) ans.emplace_back(i);
    //     }
    //     return ans;
    // }
/*定长滑动窗口+hash using array*/
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans,cnt(26,0);
        int s1 = s.size(),s2 = p.size();
        if(s2>s1) return {};

        for(char &c:p) cnt[c-'a']--;//需求
        for(int i=0;i<s2;i++) cnt[s[i]-'a']++;//初始窗口
        int match = 0;
        for(int &a:cnt) 
            if(a==0) match++;
        if(match==26) //如果cnt中每个值都为0，说明子串是同位词，此时match=26
            ans.emplace_back(0);
        int left = 0;
        /*left和right同时往右滑动一格，直到right滑到字符串结尾*/
        for(int right = s2;right<s1;right++){
            //右边进
            cnt[s[right]-'a']++;
            if(cnt[s[right]-'a']==0) match++;
            else if(cnt[s[right]-'a']==1) match--;//说明之前是0(是符合条件的)，+1后变为1
            //左边出
            cnt[s[left]-'a']--;
            if(cnt[s[left]-'a']==0) match++;
            else if(cnt[s[left]-'a']==-1) match--;//说明之前是0，-1后变为-1
            left++;
            if(match==26)
                ans.emplace_back(left);
        }
        return ans;
       
    }
/*定长滑动窗口*/
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        /*不用每次去检查26个字母是否都一致(之前开一个数组只能这样)，
        最后直接比较整个数组是否相等即可*/
        array<int,26> cnt_p;//p中字符映射的数量数组
        array<int,26> cnt_s;//子串组成的字符映射的数量数组
        for(char c:p) cnt_p[c-'a']++;
        for(int right = 0;right<s.size();right++){
            cnt_s[s[right]-'a']++;
            int  left = right-p.size()+1;
            if(left<0)
                continue;
            if(cnt_p==cnt_s)
                ans.emplace_back(left);
            cnt_s[s[left]-'a']--;
        }
        return ans;
    }
/*不定长滑窗*/
};
// @lc code=end



/*
// @lcpr case=start
// "cbaebabacd"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abab"\n"ab"\n
// @lcpr case=end

 */

