/*
 * @lc app=leetcode.cn id=373 lang=cpp
 * @lcpr version=30204
 *
 * [373] 查找和最小的 K 对数字
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
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        //存{sum,r,c}
        auto cmp = [](const vector<int>&lhs,const vector<int>&rhs){return lhs[0]>rhs[0];};
        priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)> pq(cmp);
        int m = nums1.size(),n = nums2.size();
        for(int i=0;i<m;i++){
            pq.push({nums1[i]+nums2[0],i,0});
        }
        int cnt = 0;
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            int r = cur[1],c = cur[2];
            res.push_back({nums1[r],nums2[c]});
            cnt++;
            if(cnt==k) break;
            if(c<n-1) pq.push({nums1[r]+nums2[c+1],r,c+1});
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,7,11]\n[2,4,6]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2]\n[1,2,3]\n2\n
// @lcpr case=end

 */

