/*
 * @lc app=leetcode.cn id=39 lang=cpp
 * @lcpr version=30204
 *
 * [39] 组合总和
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
private:
    vector<vector<int>> res;
    vector<int> track;
    
    int sum;
    /*元素无重可复选*/
    void backtrack(vector<int>&candidates,int target,int start){
        //base case
        if(sum==target){
            res.push_back(track);
            return;
        }

        for(int i=start;i<candidates.size();i++){
            //优化不必要的查找
            if(sum+candidates[i]>target){
                break;
            }
            track.push_back(candidates[i]);
            sum+=candidates[i];
            // 当前元素可重复使用,所以下一层参数传i
            //实现去重：i之前的元素不可再使用
            backtrack(candidates,target,i);
            track.pop_back();
            sum-=candidates[i];
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sum = 0;
        ranges::sort(candidates);//排序是为了中间的优化
        backtrack(candidates,target,0);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,6,7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */

