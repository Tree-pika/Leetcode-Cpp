/*
 * @lc app=leetcode.cn id=1 lang=cpp
 * @lcpr version=30204
 *
 * [1] 两数之和
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
// #include <multiset>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     unordered_map<int,vector<int>> maps;
    //     maps.reserve(nums.size());
    //     for(int i=0;int v:nums){
    //         maps[v].push_back(i);
    //         i++;
    //     }
    //     for(auto&[k,idxs]:maps){
    //         int need = target-k;
    //         if(maps.count(need)){
    //             if(k==need){
    //                 if(idxs.size()>=2)
    //                     return {idxs[0],idxs[1]};
    //                     //因为题目说只存在一个有效答案，所以找到一个直接return
    //                     //也就避免了同一个组合找两次的结果(即返回[0,1]和[1，0])
    //             }else{
    //                 return {idxs[0],maps[need][0]};
    //             }
    //         }
    //     }
    //     return {};
    // }
    /*thinking2*/
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> maps;
        int i=0;
        for(int a:nums){
            int need = target-a;
            if(maps.count(need)){
                return {i,maps[need]};
            }
            // maps.insert(pair<int,int>(a,i));
            maps.insert({a,i});
            i++;//计算下一轮的index
        }
        return {};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [3,3]\n6\n
// @lcpr case=end

 */

