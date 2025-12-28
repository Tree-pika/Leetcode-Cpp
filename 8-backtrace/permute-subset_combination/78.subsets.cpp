/*
 * @lc app=leetcode.cn id=78 lang=cpp
 * @lcpr version=30204
 *
 * [78] 子集
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
    vector<int> track;//递归的路径
    /*通过start来控制结果中元素的相对顺序*/
    void backtrack(vector<int>&nums,int start){
        res.push_back(track);
        for(int i=start;i<nums.size();++i){
            track.push_back(nums[i]);
            backtrack(nums,i+1);//i已经在本层选过了，下一层要从我后面选
            track.pop_back();
        }
    }
public:
/*元素无重不可复选*/
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums,0);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

