/*
 * @lc app=leetcode.cn id=1 lang=cpp
 * @lcpr version=30204
 *
 * [1] 两数之和
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
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> map;
        for(int i=0;i<nums.size();i++){
            map.push_back({nums[i],i});
        }
        ranges::sort(map);//默认先按pair.first排序
        int left=0,right=nums.size()-1;
        while(left<right){
            int sum=map[left].first+map[right].first;
            if(sum==target){
                break;
            }else if(sum>target){
                right--;
            }else{
                left++;
            }
        }
        return vector<int>{map[left].second,map[right].second};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [3,3]\n6\n
// @lcpr case=end

 */

