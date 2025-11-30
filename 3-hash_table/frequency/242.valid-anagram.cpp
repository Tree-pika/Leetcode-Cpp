/*
 * @lc app=leetcode.cn id=242 lang=cpp
 * @lcpr version=30204
 *
 * [242] 有效的字母异位词
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
/*method1:using hash table*/
    // bool isAnagram(string s, string t) {
    //     /*长度不一致肯定不是*/
    //     if(s.size()!=t.size()) return false;
    //     unordered_map<char,int> maps;
    //     // int i=0;
    //     // while(s[i]!='\0'){
    //     //     maps[s[i]]++;
    //     //     i++;
    //     // }
    //     // i = 0;
    //     // while(t[i]!='\0'){
    //     //     if(maps.count(t[i])){
    //     //         maps[t[i]]--;
    //     //         if(maps[t[i]]==0)
    //     //             maps.erase(t[i]);
    //     //     }else 
    //     //         return false;
    //     //     i++;
    //     // }
    //     for(char c:s) maps[c]++;
    //     for(char c:t){
    //         if(--maps[c]<0)//若不是异位词，对于特定字符，t中数量肯定有多余s的（也有少于s的）
    //             return false;
    //     }
    //     return true;
    // }
/*method2:using array*/
    bool isAnagram(string s, string t) {
        int freq[26]={0};//仅包含小写字母
        for(char c:s)
            freq[c-'a']++;
        for(char c:t)
            freq[c-'a']--;
        for(int a:freq)
            if(a!=0)
                return false;
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "anagram"\n"nagaram"\n
// @lcpr case=end

// @lcpr case=start
// "rat"\n"car"\n
// @lcpr case=end

 */

