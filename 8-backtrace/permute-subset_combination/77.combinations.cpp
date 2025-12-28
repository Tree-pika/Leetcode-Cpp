/*
 * @lc app=leetcode.cn id=77 lang=cpp
 * @lcpr version=30204
 *
 * [77] 组合
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
    // vector<int> nums;
    vector<vector<int>> res;
    vector<int> track;//记录递归路径
    /*元素无重不可复选*/
    void backtrack(int n,int k,int start){
        //base case
        if(track.size()==k){
            res.push_back(track);
            return;
        }
        for(int i=start;i<=n;++i){
            // track.push_back(nums[i]);
            track.push_back(i);
            backtrack(n,k,i+1);
            track.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        // nums.reserve(n);
        // for(int i=1;i<=n;i++){
        //     nums.push_back(i);
        // }
        // backtrack(n,k,0);
        backtrack(n,k,1);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n2\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

 */

