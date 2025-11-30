/*
 * @lc app=leetcode.cn id=350 lang=cpp
 * @lcpr version=30204
 *
 * [350] 两个数组的交集 II
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
/*method1：using array*/
    // vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    //     array<int,1001> a1={0};
    //     vector<int> res;
    //     for(int a:nums1)
    //         a1[a]++;
    //     for(int a:nums2){
    //         if(a1[a]>=1){
    //             res.emplace_back(a);
    //             a1[a]--;
    //         }
    //     }
    //     return res;
    // }
/*method2：using hash table*/
    // vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    //     unordered_map<int,int> maps;
    //     vector<int> ans;
    //     for(int a:nums1){
    //         maps[a]++;
    //     }
    //     for(int a:nums2){
    //         if(maps[a]>=1){
    //             ans.emplace_back(a);
    //             maps[a]--;
    //         }
    //     }
    //     return ans;
    // }
/*method3：sort+双指针*/
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        ranges::sort(nums1);
        ranges::sort(nums2);
        int p1=0,p2=0;
        int s1 = nums1.size(),s2=nums2.size();
        vector<int> ans;
        while(p1<s1&&p2<s2){
            if(nums1[p1]==nums2[p2]){
                ans.push_back(nums1[p1]);
                p1++;
                p2++;
            }else if(nums1[p1]<nums2[p2]){
                p1++;
            }else{
                p2++;
            }
        }
        return ans;
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

