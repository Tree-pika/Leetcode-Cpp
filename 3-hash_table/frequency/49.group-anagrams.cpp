/*
 * @lc app=leetcode.cn id=49 lang=cpp
 * @lcpr version=30204
 *
 * [49] 字母异位词分组
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
/*Bruce solution：TLE*/
    // bool isAnagram(string s, string t) {
    //     int freq[26]={0};//仅包含小写字母
    //     for(char c:s)
    //         freq[c-'a']++;
    //     for(char c:t)
    //         freq[c-'a']--;
    //     for(int a:freq)
    //         if(a!=0)
    //             return false;
    //     return true;
    // }
    // vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //     vector<vector<string>> res;
    //     while(!strs.empty()){
    //         string t = strs[0];
    //         vector<string> group;
    //         /*从后往前遍历，确保下标不会在擦除的过程中失效*/
    //         for(int j = strs.size()-1;j>=0;j--){
    //             if(isAnagram(t,strs[j])){
    //                 group.push_back(strs[j]);
    //                 strs.erase(strs.begin()+j);//原地擦除
    //             }
    //         }
    //         res.push_back(group);
    //     }
    //     return res;
    // }
    /*method2:using sort and hash table*/
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> maps;
        for(string &s:strs){
            string key = s;
            // sort(key.begin(),key.end());
            ranges::sort(key);
            maps[key].emplace_back(s);
        }
        vector<vector<string>> res;
        // for(auto &[first,second]:maps){//C++17
        //     res.emplace_back(second);
        // }
        res.reserve(maps.size());//关键性能提升
        for(auto it=maps.begin();it!=maps.end();it++){
            res.emplace_back(it->second);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["eat", "tea", "tan", "ate", "nat", "bat"]\n
// @lcpr case=end

// @lcpr case=start
// [""]\n
// @lcpr case=end

// @lcpr case=start
// ["a"]\n
// @lcpr case=end

 */

