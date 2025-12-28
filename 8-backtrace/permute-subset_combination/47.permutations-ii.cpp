/*
 * @lc app=leetcode.cn id=47 lang=cpp
 * @lcpr version=30204
 *
 * [47] 全排列 II
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
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> used;
    /*元素可重不可复选*/
    // void backtrack(vector<int>&nums){
    //     if(path.size()==nums.size()){
    //         res.push_back(path);
    //         return;
    //     }
    //     int preNum=-11;//对于每一层，第二次及更后出现的相同枝干剪掉
    //     for(int i=0;i<nums.size();i++){
    //         if(used[i]){
    //             continue;
    //         }
    //         // 去重：如果当前数字和本层上一次尝试的数字一样，跳过
    //         // 优化树层去重
    //         if(nums[i]==preNum){
    //             continue;
    //         }
    //         path.push_back(nums[i]);
    //         used[i] = true;
    //         preNum = nums[i];
    //         backtrack(nums);
    //         path.pop_back();
    //         used[i] = false;
    //     }
    // }
    /*solution2:*/
    void backtrack(vector<int>&nums){
        if(path.size()==nums.size()){
            res.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]){
                continue;
            }
            //used[i-1] = true说明是我的父亲用的，就不算树层重复了，可以使用
            //=false说明是兄弟用过的，就不能再选nums[i]了
            if(i>0&&nums[i]==nums[i-1]&&!used[i-1]){
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backtrack(nums);
            path.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        path.reserve(nums.size());
        ranges::sort(nums);
        used = vector<bool>(nums.size(),false);
        backtrack(nums);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */

