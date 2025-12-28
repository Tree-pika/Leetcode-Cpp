/*
 * @lc app=leetcode.cn id=46 lang=cpp
 * @lcpr version=30204
 *
 * [46] 全排列
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
    //记录递归路径
    vector<int> path;
    //path中的元素会被标记为 true
    vector<bool> used;

    void backtrack(vector<int>& nums){
        // base case，到达叶子节点
        if(path.size()==nums.size()){
            res.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();++i){
            // 已经存在 track 中的元素，不能重复选择
            if(used[i]){
                continue;
            }
            //做选择
            used[i] = true;
            path.push_back(nums[i]);
            // 进入下一层回溯树
            backtrack(nums);
            //撤销选择
            path.pop_back();
            used[i] = false;
        }
    }
public:
/*元素无重不可复选*/
    vector<vector<int>> permute(vector<int>& nums) {
        used = vector<bool>(nums.size(),false);
        path.reserve(nums.size());
        backtrack(nums);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

