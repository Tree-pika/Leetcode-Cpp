/*
 * @lc app=leetcode.cn id=704 lang=cpp
 * @lcpr version=30204
 *
 * [704] 二分查找
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
    /*区间的定义就是不变量，在循环中坚持根据查找区间的定义来做边界处理：循环不变量规则。*/
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;//时刻提醒自己array index从0开始！
        int mid;
        /*这里定义target在左闭右闭的区间里：[left,right]*/
        while(left <= right){
            mid = (left+right)/2;
            /*better one:mid = left+(right-left)/2;*/
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                left = mid+1;
            else
                right = mid-1;
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-1,0,3,5,9,12]\n9\n
// @lcpr case=end

// @lcpr case=start
// [-1,0,3,5,9,12]\n2\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n2\n
// @lcpr case=end

 */

