/*
 * @lc app=leetcode.cn id=88 lang=cpp
 * @lcpr version=30204
 *
 * [88] 合并两个有序数组
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
    // void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //     vector<int> res;
    //     res.resize(m+n);
    //     int p1=0,p2=0;
    //     int p=0;
    //     while(p1<m&&p2<n){
    //         if(nums1[p1]<nums2[p2]){
    //             res[p++]=nums1[p1++];
    //         }else{
    //             res[p++]=nums2[p2++];
    //         }
    //     }
    //     while(p1<m){
    //         res[p++]=nums1[p1++];
    //     }
    //     while(p2<n){
    //         res[p++]=nums2[p2++];
    //     }
    //     for(int i=0;i<m+n;i++){
    //         nums1[i]=res[i];
    //     }
    // }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1=m-1,p2=n-1;
        int c=m+n-1;
        while(p1>=0&&p2>=0){
            if(nums1[p1]<=nums2[p2]){
                nums1[c--]=nums2[p2--];
            }else{
                nums1[c--]=nums1[p1--];
            }
        }
        //p1的剩余元素不用管，因为nums1就是result
        while(p2>=0){
            nums1[c--]=nums2[p2--];
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,0,0,0]\n3\n[2,5,6]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n[]\n0\n
// @lcpr case=end

// @lcpr case=start
// [0]\n0\n[1]\n1\n
// @lcpr case=end

 */

