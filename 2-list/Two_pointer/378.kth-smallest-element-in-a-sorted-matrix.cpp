/*
 * @lc app=leetcode.cn id=378 lang=cpp
 * @lcpr version=30204
 *
 * [378] 有序矩阵中第 K 小的元素
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
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //存索引位置,使用&捕获前面的参数matrix
        auto cmp = [&](auto &lhs,auto&rhs){return matrix[lhs.first][lhs.second]>matrix[rhs.first][rhs.second];};
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
        int n = matrix.size();
        for(int i=0;i<n;i++){
            pq.push({i,0});
        }
        int cnt = 0,res=INT_MAX;
        while(!pq.empty()){
            auto [r,c]=pq.top();
            pq.pop();
            cnt++;
            if(cnt==k){
                res = matrix[r][c];
                break;
            }
            if(c<n-1) pq.push({r,c+1});
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,5,9],[10,11,13],[12,13,15]]\n8\n
// @lcpr case=end

// @lcpr case=start
// [[-5]]\n1\n
// @lcpr case=end

 */

