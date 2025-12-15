/*
 * @lc app=leetcode.cn id=18 lang=cpp
 * @lcpr version=30204
 *
 * [18] 四数之和
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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        ranges::sort(nums);
        int n = nums.size();
        vector<vector<int>> res;
        for(int i=0;i<n-3;i++){
            int a = nums[i];
            if(a>target&&a>=0) break;//剪枝优化一,a非负是确保sum>=a(否则如果后面sum可能小于a的话，a>target也有可能出结果)
            if(i>=1&&nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n-2;j++){
                int b = nums[j];
                if(a+b>target&&b>=0) break;//剪枝优化二,b非负是确保sum>=a+b
                if(j>=i+2&&nums[j]==nums[j-1]) continue;
                int left = j+1,right = n-1;
                while(left<right){
                    long long sum = static_cast<long long>(a)+
                                static_cast<long long>(b)+
                                static_cast<long long>(nums[left])+
                                static_cast<long long>(nums[right]);
                    if(sum==static_cast<long long>(target)){
                        res.push_back({a,b,nums[left],nums[right]});
                        //左指针右移
                        while(left<right&&nums[left]==nums[++left]);
                        //右指针左移
                        while(left<right&&nums[right]==nums[--right]);
                    }else if(sum>target){
                        //右指针左移
                        while(left<right&&nums[right]==nums[--right]);
                    }else{
                        //左指针右移
                        while(left<right&&nums[left]==nums[++left]);
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,0,-1,0,-2,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n8\n
// @lcpr case=end

 */

