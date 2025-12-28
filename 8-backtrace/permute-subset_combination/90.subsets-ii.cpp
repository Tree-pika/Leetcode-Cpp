/*
 * @lc app=leetcode.cn id=90 lang=cpp
 * @lcpr version=30204
 *
 * [90] 子集 II
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
    vector<int> track;//记录递归路径
    /*元素可重不可复选*/
    void backtrack(vector<int>& nums,int start){
        res.push_back(track);
        for(int i=start;i<nums.size();i++){
            //每一层的第一根树枝都是start，是必要的
            if(i>start&&nums[i]==nums[i-1]){
                continue;//对于本层(同一层)的相同树枝，除了第一个要，其余的都剪掉
            }
            track.push_back(nums[i]);
            backtrack(nums,i+1);//本层选择的是i，下一层要从索引i+1开始选
            track.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ranges::sort(nums);
        backtrack(nums,0);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

