/*
 * @lc app=leetcode.cn id=40 lang=cpp
 * @lcpr version=30204
 *
 * [40] 组合总和 II
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
    vector<int> track;//记录递归路径

    int sum;//记录track中元素之和
    /*元素可重不可复选*/
    void backtrack(vector<int>& candidates,int target,int start){
        // base case，达到目标和，找到符合条件的组合
        if(sum==target){
            res.push_back(track);
            return;
        }
        /*base case,超过目标和，直接结束--剪枝1：基础版
        剪纵向：只阻止了向更深处搜索，后序更大的兄弟分支没有剪掉*/
        // if(sum>target){
        //     return;
        // }
        for(int i=start;i<candidates.size();i++){
            /*剪枝2:优化版
            横向 + 纵向：阻止了当前深搜，且斩断了本层后续所有横向遍历*/
            if(sum+candidates[i]>target) 
                break;
            
            //去重，本层的其他相同树枝不要了
            if(i>start&&candidates[i]==candidates[i-1]){
                continue;
            }
            //选择
            track.push_back(candidates[i]);
            sum+=candidates[i];
            //
            backtrack(candidates,target,i+1);
            //撤销选择
            track.pop_back();
            sum-=candidates[i];
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ranges::sort(candidates);
        sum = 0;
        backtrack(candidates,target,0);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,1,2,7,6,1,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2,5,2,1,2]\n5\n
// @lcpr case=end

 */

