/*
 * @lc app=leetcode.cn id=80 lang=cpp
 * @lcpr version=30204
 *
 * [80] 删除有序数组中的重复项 II
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
    // int removeDuplicates(vector<int>& nums) {
    //     int slow=0,fast=1;
    //     while(fast<nums.size()){
    //         if(nums[fast]!=nums[slow]){
    //             slow++;
    //             nums[slow] = nums[fast];
    //             fast++;
    //         }else{//给的第二次机会，此时已经是第二次出现的元素了(slow和fast指向的元素值一样)
    //             slow++;
    //             nums[slow] = nums[fast];
    //             fast++;
    //             while(fast<nums.size()&&nums[fast]==nums[slow]){
    //                 fast++;
    //             }
    //         }
    //     }
    //     return slow+1;
    // }
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2) return nums.size();
        int slow=2,fast=2;
        for(;fast<nums.size();fast++){
            if(nums[fast]!=nums[slow-2]){
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1,2,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,1,1,2,3,3]\n
// @lcpr case=end

 */

