/*
 * @lc app=leetcode.cn id=28 lang=cpp
 * @lcpr version=30204
 *
 * [28] 找出字符串中第一个匹配项的下标
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
/*method1:双指针--bruce solution*/
    // int strStr(string haystack, string needle) {
    //     int m = haystack.length();
    //     int n = needle.length();
    //     if(n>m) return -1;
    //     for(int left = 0;left<=m-n;left++){
    //         int flag = 1;
    //         for(int right = 0;right<n;right++){
    //             if(haystack[left+right]!=needle[right]){
    //                 flag = 0;
    //                 break;
    //             }
    //         }
    //         if(flag) return left;
    //     }
    //     return -1;
    // }
/*method2:KMP*/
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        if(n>m) return -1;
        /*求解next数组*/
        vector<int> next(n);//next[i]表示子串need[0..i]的最长相等前后缀长度
        //子串长度为i+1,next[0]必为0(单个字母没有前后缀),所以从next[1]开始求
        //i指向后缀末尾，j指向前缀末尾 = 上一次最大成功匹配的位置 = 上一次匹配的最长长度
        for(int i=1,j=0;i<n;i++){
            while(j>=1 && needle[i]!=needle[j]){
                j = next[j-1];//前缀一直退，退到新前缀+needle[j]=上一轮后缀+needle[i]
            }
            if(needle[i]==needle[j]){
                j++;//匹配上了，前缀和后缀都往后移动一位
            }
            next[i] = j;//本次匹配的最长长度
        }
        /*使用next匹配子串*/
        vector<int> res;//记录needle在haystack出现的索引
        //i指向当前在haystack中的位置
        //j指向当前在needle中的位置
        for(int i=0,j=0;i<m;i++){
            while(j>=1&&haystack[i]!=needle[j]){
                //两者不相等说明当前匹配到的最大长度为j,即needle[0..j-1]和haystack[(i-j),..i-1]匹配上的
                j = next[j-1];//在needle中一直回退，直到满足新的小子串+needle[j]=haystack中的新小子串(两者一样)+haystack[i]
            }
            if(haystack[i]==needle[j]){
                j++;
            }
            if(j==n){//当最后一个字符needle[n-1]在上面被匹配成功后，j++后=n，表明needle被完全匹配
                res.push_back(i-n+1);
                j = next[j-1];//继续往后找
            }
        }
        if(!res.empty()){
            return res[0];
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "sadbutsad"\n"sad"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n"leeto"\n
// @lcpr case=end

// @lcpr case=start
// "sadbutsad"\n""\n
// @lcpr case=end
 */

