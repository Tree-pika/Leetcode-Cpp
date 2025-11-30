/*
 * @lc app=leetcode.cn id=283 lang=cpp
 * @lcpr version=30204
 *
 * [283] 移动零
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
    void moveZeroes(vector<int>& nums) {
        int fast_idx = 0;
        int slow_idx = 0;
        for(;fast_idx<nums.size();fast_idx++){
            if(nums[fast_idx]!=0){
                nums[slow_idx++] = nums[fast_idx];
            }
        }
        for(;slow_idx<nums.size();slow_idx++){
            nums[slow_idx] = 0;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,0,3,12]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

