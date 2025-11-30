/*
 * @lc app=leetcode.cn id=904 lang=cpp
 * @lcpr version=30204
 *
 * [904] 水果成篮
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
/*method1：using hash table*/
    // int totalFruit(vector<int>& fruits) {
    //     int left = 0;
    //     int right = 0;
    //     unordered_map<int,int> cnt;
    //     int len = 0;
    //     for(;right<fruits.size();right++){
    //         cnt[fruits[right]]++;
    //         while(cnt.size()>2){
    //             // int num = fruits[left];
    //             // cnt[num]--;
    //             // if(cnt[num]==0){
    //             //     cnt.erase(num);
    //             // }
    //             // left++;
    //             auto it = cnt.find(fruits[left]);
    //             it->second--;
    //             if(it->second==0){
    //                 cnt.erase(it);
    //             }
    //             left++;
    //         }
    //         len = max(len,right-left+1);
    //     }
    //     return len;
    // }

    /*method2：using array--faster*/
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int right = 0;
        vector<int> cnt(100000,0);
        int n = fruits.size();
        int distinct = 0;
        int len = 0;
        for(;right<n;right++){
            if(cnt[fruits[right]]==0){
                distinct++;
            }
            cnt[fruits[right]]++;
            while(distinct>2){
                int num = fruits[left];
                cnt[num]--;
                if(cnt[num]==0){
                    distinct--;
                }
                left++;
            }
            len = max(len,right-left+1);
        }
        return len;
    }

};
// @lc code=end



/*
// @lcpr case=start
// [1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,3,3,1,2,1,1,2,3,3,4]\n
// @lcpr case=end

 */

