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
        ranges::sort(nums);//关键
        int n=nums.size();
        vector<vector<int>> res;
        for(int i=0;i<n-3;i++){
            if(i&&x==nums[i-1]) continue;//i的去重

            long x=nums[i];//直接在这转换，后续计算自动提升
            if(x+nums[i+1]+nums[i+2]+nums[i+3]>target) break;//当前最小的组合了
            if(x+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;//x太小了

            for(int j=i+1;j<n-2;j++){
                if(j>i+1&&y==nums[j-1]) continue;//j的去重

                int y=nums[j];
                if(x+y+nums[j+1]+nums[j+2]>target) break;
                if(x+y+nums[n-2]+nums[n-1]<target) continue;//y太小了

                int lo=j+1,hi=n-1;
                while(lo<hi){
                    long sum=x+y+nums[lo]+nums[hi];
                    if(sum==target){
                        res.push_back({(int)x,y,nums[lo],nums[hi]});//x记得转换，因为res的元素类型是int
                        lo++;
                        while(lo<hi&&nums[lo]==nums[lo-1]) lo++;//lo去重
                        hi--;
                        while(lo<hi&&nums[hi]==nums[hi+1]) hi--;//hi去重
                    }else if(sum>target){//(long)可以不加
                        hi--;
                    }else{
                        lo++;
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

