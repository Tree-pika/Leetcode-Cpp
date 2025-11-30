/*
 * @lc app=leetcode.cn id=209 lang=cpp
 * @lcpr version=30204
 *
 * [209] 长度最小的子数组
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
#include <climits> // 为了使用 INT_MAX
// @lcpr-template-end
// @lc code=start
class Solution {
public:
/*method1:bruce solution*/

    // int minSubArrayLen(int target, vector<int>& nums) {
    //     int i=0,j;
    //     int minlen = nums.size()+1;
    //     /*有解时，minlen的最大值为nums.size(),
    //     所以如果有解，minlen一定会被更新。
    //     所以这里也可以设置为INT_MAX*/
    //     // int flag;
    //     for(;i<nums.size();i++){
    //         int sum = 0;/*子序列之和*/
    //         // int cnt = 0;/*子序列长度*/
    //         // flag = 0;
    //         for(j=i;j<nums.size();j++){
    //             sum+=nums[j];
    //             // cnt++;
    //             if(sum>=target){
    //                 // flag = 1;
    //                 int currentlen = j-i+1;
    //                 if(currentlen<minlen)
    //                     minlen = currentlen;
    //                 break;
    //             }
    //         }
    //         // if(cnt<minlen&&flag){
    //         //     minlen = cnt;
    //         // }
    //     }
    //     return minlen>nums.size()?0:minlen;
    // }
    int minSubArrayLen(int target,vector<int>& nums){
        int left = 0;
        int right = 0;
        int minlen = INT_MAX;
        int sum = 0;
        for(;right<nums.size();right++){
            sum+=nums[right];
            while(sum>=target){
                int currentlen = right-left+1;
                if(currentlen<minlen)
                    minlen = currentlen;
                sum-=nums[left];
                left++;
            }
        }
        return minlen==INT_MAX?0:minlen;
    }
    
};
// @lc code=end



/*
// @lcpr case=start
// 7\n[2,3,1,2,4,3]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[1,4,4]\n
// @lcpr case=end

// @lcpr case=start
// 11\n[1,1,1,1,1,1,1,1]\n
// @lcpr case=end

 */

