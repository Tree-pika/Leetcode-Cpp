/*
 * @lc app=leetcode.cn id=15 lang=cpp
 * @lcpr version=30204
 *
 * [15] 三数之和
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        ranges::sort(nums);
        int n=nums.size();
        vector<vector<int>> res;
        for(int i=0;i<n-2;i++){
            int x=nums[i];
            if(i>0&&x==nums[i-1]) continue;//对i去重
            if(x+nums[i+1]+nums[i+2]>0) break;//当前最小的组合
            if(x+nums[n-2]+nums[n-1]<0) continue;//x太小了，直接砍掉
            int j=i+1,k=n-1;
            //nums[i]固定下来了，转变为2Sum
            while(j<k){
                int sum=x+nums[j]+nums[k];
                if(sum==0){
                    res.push_back({x,nums[j],nums[k]});
                    j++;
                    while(j<k&&nums[j]==nums[j-1]) j++;//j的去重
                    k--;
                    while(j<k&&nums[k]==nums[k+1]) k--;//k的去重
                }else if(sum<0){
                    j++;//也可以跳过所有重复元素，但没必要，判断很快
                }else{
                    k--;
                }
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-1,0,1,2,-1,-4]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0]\n
// @lcpr case=end

 */

