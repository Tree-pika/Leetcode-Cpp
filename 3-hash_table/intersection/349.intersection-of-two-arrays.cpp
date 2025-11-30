/*
 * @lc app=leetcode.cn id=349 lang=cpp
 * @lcpr version=30204
 *
 * [349] 两个数组的交集
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
#include <set>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
/*method1:using hash set*/
    // vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    //     // unordered_set<int> s1(nums1.begin(),nums1.end()),s2(nums2.begin(),nums2.end());
    //     // vector<int> res;
    //     // for(int a:s2){
    //     //     if(s1.count(a))
    //     //         res.emplace_back(a);
    //     // }
    //     // return res;
    //     unordered_set<int> s1(nums1.begin(),nums1.end()),res;
    //     for(int a:nums2){
    //         if(s1.count(a))
    //         // if(s1.find(a)!=s1.end())
    //             res.insert(a);
    //     }
    //     vector<int> ans(res.begin(),res.end());
    //     return ans;
    // }
/*method2:using array*/
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        array<int,1001> a1={0};
        vector<int> res;
        for(int a:nums1)
            // a1[a]++;
            a1[a]=1;
        for(int a:nums2)
            if(a1[a]){
                res.emplace_back(a);
                a1[a] = 0;
            }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2,1]\n[2,2]\n
// @lcpr case=end

// @lcpr case=start
// [4,9,5]\n[9,4,9,8,4]\n
// @lcpr case=end

 */

