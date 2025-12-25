/*
 * @lc app=leetcode.cn id=82 lang=cpp
 * @lcpr version=30204
 *
 * [82] 删除排序链表中的重复元素 II
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
//using list-partition
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *duniq = new ListNode(-101);
        ListNode *ddup = new ListNode(-101);
        
        ListNode *p1 = duniq;
        ListNode *p2 = ddup;
        for(ListNode *cur = head;cur!=nullptr;){
            if((cur->next&&cur->val==cur->next->val)||cur->val==p2->val){
                p2->next = cur;
                p2 = p2->next;
            }else{
                p1->next = cur;
                p1 = p1->next;
            }
            //每次断开原链表中的每个节点的 next 指针
            ListNode *temp = cur->next;
            cur->next = nullptr;
            cur = temp;
        }
        return duniq->next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,3,4,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,2,3]\n
// @lcpr case=end

 */

