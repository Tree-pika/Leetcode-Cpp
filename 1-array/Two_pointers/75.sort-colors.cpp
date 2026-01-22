/*
 * @lc app=leetcode.cn id=75 lang=cpp
 * @lcpr version=30204
 *
 * [75] 颜色分类
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
    void sortColors(vector<int>& nums) {
        int left=0,right=nums.size()-1;//0的边界和2的边界(下一个放0/2的位置)
        int cur=0;//当前位置
        //[0,left-1]是0，[right+1,num.size()-1]是2,[left,cur-1]=1
        //[cur,right] = 待处理
        while(cur<=right){
            if(nums[cur]==0){
                swap(nums,cur,left);
                left++;
                cur++;//换过来的nums[left]=1，不用管
            }else if(nums[cur]==2){
                swap(nums,cur,right);
                right--;//换过来的nums[right]不确定，需要继续检测
            }else{
                cur++;
            }
        }
    }
private:
    void swap(vector<int>&nums,int i,int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,0,2,1,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [2,0,1]\n
// @lcpr case=end

 */

