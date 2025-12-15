/*
 * @lc app=leetcode.cn id=347 lang=cpp
 * @lcpr version=30204
 *
 * [347] 前 K 个高频元素
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
/*solution 1:bruce-solution*/
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     unordered_map<int,int> cnt;
    //     for(int a:nums){
    //         cnt[a]++;
    //     }
    //     int max_key;
    //     vector<int> res;
    //     for(int i=0;i<k;i++){
    //         max_key = cnt.begin()->first;
    //         for(auto it1=cnt.begin();it1!=cnt.end();it1++){
    //             if(it1->second>cnt[max_key])
    //                 max_key = it1->first;
    //         }
    //         res.push_back(max_key);
    //         cnt.erase(max_key);
    //     }
    //     return res;
    // }
/*solution2:using min heap*/
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     unordered_map<int,int> cnt;
    //     for(int a:nums){
    //         cnt[a]++;
    //     }
    //     // auto cmp = [](const pair<int,int>& lhs,const pair<int,int>&rhs){//true代表lhs<rhs(priority)
    //     // return lhs.second>rhs.second;//根据频率大小进行比较
    //     // };
    //     // priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
    //     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    //     for(auto [key,val]:cnt){
    //         pq.push({val,key});//交换存储顺序，pair默认先比较第一个元素
    //         if(pq.size()>k){
    //             pq.pop();
    //         }
    //     }
    //     vector<int> res;
    //     while(!pq.empty()){
    //         res.push_back(pq.top().second);
    //         pq.pop();
    //     }
    //     return res;
    // }
/*solution3：using bucket sorting*/
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> cnt;
        //统计数频
        int max_cnt = 0;
        for(int a:nums){
            cnt[a]++;
            max_cnt = max(max_cnt,cnt[a]);
        }
            
        //桶排序：以元素的频率作为索引下标，每个索引/桶中存放
        vector<vector<int>> bucket(max_cnt+1);
        for(auto [key,val]:cnt){
            bucket[val].push_back(key);
        }
        vector<int> res;
        for(auto rit = bucket.rbegin();rit!=bucket.rend();rit++){
            for(int a:*rit){
                res.push_back(a);
            }
            if(res.size()==k){
                return res;
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1,2,2,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1,2,1,2,3,1,3,2]\n2\n
// @lcpr case=end

 */

