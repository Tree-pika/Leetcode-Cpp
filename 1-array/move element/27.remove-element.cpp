/*
 * @lc app=leetcode.cn id=27 lang=cpp
 * @lcpr version=30204
 *
 * [27] 移除元素
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
/*method1：Bruce solution
两层for循环，一个for循环遍历数组元素 ，第二个for循环更新数组。*/
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        int l = nums.size();
        // int cnt = 0;
        /*method2：双指针法（快慢指针法）*/
        int slow_idx = 0;
        for(;i<l;i++){
            if(nums[i]==val) {
                // cnt++;
                continue;
            }
            nums[slow_idx] = nums[i];
            slow_idx++;
        }
        return slow_idx;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,2,3]\n3\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2,2,3,0,4,2]\n2\n
// @lcpr case=end

 */

