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
/*method1:using 双指针*/
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     ranges::sort(nums);//先排序，方便跳过重复数字
    //     vector<vector<int>> ans;
    //     int n = nums.size();
    //     for(int k=0;k<n-2;k++){
    //         if(nums[k]>0) break;
    //         if(k>=1&&nums[k]==nums[k-1]) 
    //             continue;//所有组合已在nums[k-1]找完
    //         if(nums[k]+nums[n-2]+nums[n-1]<0)
    //             continue;//当前的固定值nums[k]太小了
    //         int i = k+1,j = n-1;
    //         while(i<j){
    //             int sum = nums[k]+nums[i]+nums[j];
    //             if(sum==0){
    //                 // ans.push_back({nums[k],nums[i],nums[j]});
    //                 ans.emplace_back(vector<int>{nums[k], nums[i], nums[j]});
    //                 while(i<j&&nums[i]==nums[++i]);//前置自增，确保至少右移一次
    //                 while(i<j&&nums[j]==nums[--j]);
    //             }else if(sum>0){
    //                 //右指针j左移
    //                 while(i<j&&nums[j]==nums[--j]);
    //             }else{
    //                 //左指针i右移
    //                 while(i<j&&nums[i]==nums[++i]);
    //             }
    //         }
    //     }
    //     return ans;
    // }
/*method2：hash table*/
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     unordered_map<int,int> freq;
    //     // vector<vector<int>> ans;
    //     // unordered_set<vector<int>> tmp;//hash set不接受容器类型的元素
    //     set<vector<int>> tmp;
    //     for(int k:nums) freq[k]++;
    //     //遍历数字种类的所有可能组合
    //     for(auto it1=freq.begin();it1!=freq.end();it1++){
    //         int a = it1->first;;
    //         int countA = it1->second;
    //         for(auto it2=it1;it2!=freq.end();it2++){
    //             int b = it2->first;
    //             int countB = it2->second;
    //             int c = -a-b;
    //             if(!freq.count(c)) continue;
    //             //存在这样的数字种类组合，看是否有足够的数字
    //             //countA和countB至少为1
    //             //三者相等
    //             if(a==b&&b==c&&countA<3) continue;
    //             //两两相等
    //             if(a==b&&countA<2) continue;
    //             if(a==c&&countA<2) continue;
    //             if(b==c&&countB<2) continue;
    //             vector<int> res = {a,b,c};
    //             ranges::sort(res);
    //             tmp.insert(res);
    //         }
    //     }
    //     // ans.assign(tmp.begin(),tmp.end());
    //     return vector<vector<int>>(tmp.begin(),tmp.end());
    // }
/*method3:improved hash--using 2Sum's mind*/
    vector<vector<int>> threeSum(vector<int>& nums) {
        ranges::sort(nums);
        int n = nums.size();
        vector<vector<int>> res;
        for(int i=0;i<n-2;i++){
            if(nums[i]>0) break;
            if(i>=1&&nums[i]==nums[i-1]) continue;
            int target = -nums[i];
            //下面就是两数之和的哈希逻辑
            unordered_set<int> seen;
            for(int j=i+1;j<n;j++){
                int need = target - nums[j];
                if(seen.count(need)){
                    res.push_back({nums[i],nums[j],need});
                    //跳过重复数字，res不去重，所以要手动去重
                    while(j<n-1&&nums[j]==nums[j+1]) 
                        j++;
                    // while(j<n-1&&nums[j]==nums[++j])//这种写法在这里不对，因为这是不管三七二十一先加一次，但是可能一次都不需要跳过，会导致跳多元素
                }
                seen.insert(nums[j]);
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

