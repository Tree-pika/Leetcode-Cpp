/*
 * @lc app=leetcode.cn id=977 lang=cpp
 * @lcpr version=30204
 *
 * [977] 有序数组的平方
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
/*method1:bruce solution*/
    // vector<int> sortedSquares(vector<int>& nums) {
    //     for(auto & a:nums){
    //         a = a*a;
    //     }
    //     sort(nums.begin(),nums.end());
    //     return nums;
    // }
/*method2:双指针法*/
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        int k = nums.size()-1;
        vector<int> n(k+1);
        /*这里只要想清楚：最后新数组的元素数量必和原来一样，
        用这个作为循环条件最简单*/
        while(k>=0){
            if(nums[l]*nums[l]<=nums[r]*nums[r]){
                n[k--] = nums[r]*nums[r];
                r--;
            }
            else{
                n[k--] = nums[l]*nums[l];
                l++;
            }
        }
        // for(auto & a:n){
        //     a*=a;
        // }
        return n;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-4,-1,0,3,10]\n
// @lcpr case=end

// @lcpr case=start
// [-7,-3,2,3,11]\n
// @lcpr case=end

 */

