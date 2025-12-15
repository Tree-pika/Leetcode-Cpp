/*
 * @lc app=leetcode.cn id=239 lang=cpp
 * @lcpr version=30204
 *
 * [239] 滑动窗口最大值
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
    /*solution1:use deque to implement a monotonic queue*/
    class Myqueue{
        public:
        void pop(int val){
            if(!que.empty()&&val==que.front()){
                que.pop_front();
            }
        }
        void push(int val){
            while(!que.empty()&&val>que.back()){
                //注意这里写>=不对，因为pop传入窗口最左边元素的形式是值，
                // 所以如果将等于的值也在这里pop走的话，会导致后续pop时，
                // 将本次添加的最大值当作之前加入的最大值pop走
                //corner case：nums{-7, -8, 7, 5, 7, 1, 6, 0}
                que.pop_back();
            }
            que.push_back(val);
        }
        int front(){
            return que.front();
        }
        private:
            deque<int> que;
    };
public:
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     Myqueue ans;
    //     int n = nums.size();
    //     vector<int> res;
    //     for(int i=0;i<k;i++){
    //         ans.push(nums[i]);
    //     }
    //     res.push_back(ans.front());
    //     for(int i=k;i<n;i++){
    //         ans.pop(nums[i-k]);
    //         ans.push(nums[i]);
    //         res.push_back(ans.front());
    //     }
    //     return res;
    // }
/*solution2：using multiset as a monotonic queue*/
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> ms;//默认升序
        vector<int> res;
        for(int i=0;i<k;i++){
            ms.insert(nums[i]);
        }
        res.push_back(*ms.rbegin());
        for(int i=k;i<nums.size();i++){
            ms.erase(ms.find(nums[i-k]));
            ms.insert(nums[i]);
            res.push_back(*ms.rbegin());
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,-1,-3,5,3,6,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

