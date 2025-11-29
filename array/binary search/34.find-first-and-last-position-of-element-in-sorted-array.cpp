/*
 * @lc app=leetcode.cn id=34 lang=cpp
 * @lcpr version=30204
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
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
    /*time spent = O(N)*/
    // vector<int> searchRange(vector<int>& nums, int target) {
    //     int min = -1;
    //     int max = -1;
    //     for(int i=0;i<nums.size();i++){
    //         if(target==nums[i]){
    //             if(min==-1)
    //                 min = i;
    //             if(max==-1)
    //                 max = i;
    //             max = i;
    //         }

    //     }
    //     vector<int> v = {min,max};
    //     return v;
    // }
private:
    vector<int> searchRange(vector<int>& nums,int target){
        int leftBorder = getLeftBorder(nums,target);
        int rightBorder = getRightBorder(nums,target);
        //case 3:超出数组范围
        if(leftBorder==-2||rightBorder==-2) return {-1,-1};
        //case 1
        if((rightBorder-leftBorder)>=2) return {leftBorder+1,rightBorder-1};
        //case 2:没有这个元素
        return {-1,-1};
    }
    /*遇到肯定不能作为右边界的元素（即 <= target），
    就让左指针 left 往右跳(忽略不可能的元素)，并顺手标记当前位置；
    后续如果还能往右跳，就覆盖标记。*/
    /*找到大于最后一个target的第一个元素*/
    int getRightBorder(vector<int>& nums,int target){
        int left = 0;
        int right = nums.size()-1;
        int rightBorder = -2;
        while(left<=right){
            int mid = left+(right-left)/2;
            /*if是继续往右找的情况，符合找右边界的目的*/
            if(nums[mid]<=target){
                left = mid+1;//左边界最小的位置
                rightBorder = left;
            }else{
                /*在这里更新border的话，后续继续往左找，
                右边界会被越更新越左，不合题意*/
                right = mid-1;
            }
        }
        return rightBorder;
    }
    /*找到小于第一个target的最后一个元素*/
    int getLeftBorder(vector<int>& nums,int target){
        int left = 0;
        int right = nums.size()-1;
        int leftBorder = -2;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(nums[mid]>=target){
                right = mid-1;//左边界最大的位置
                leftBorder = right;
            }else{
                left = mid+1;
            }
        }
        return leftBorder;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,7,7,8,8,10]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,7,7,8,8,10]\n6\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */

