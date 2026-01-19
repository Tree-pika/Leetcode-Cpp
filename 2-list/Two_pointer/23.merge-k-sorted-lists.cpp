/*
 * @lc app=leetcode.cn id=23 lang=cpp
 * @lcpr version=30204
 *
 * [23] 合并 K 个升序链表
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
#include <queue>//
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
    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     int n = lists.size();
    //     auto cmp = [](ListNode*&lhs,ListNode*&rhs){return lhs->val>rhs->val;};
    //     priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)> pq(cmp);
    //     for(int i=0;i<n;i++){
    //         if(lists[i]) pq.push(lists[i]);
    //     }
    //     ListNode *dummy = new ListNode(0);
    //     ListNode*cur = dummy;
    //     while(!pq.empty()){
    //         ListNode* head = pq.top();
    //         pq.pop();
    //         cur->next = head;
    //         head = head->next;
    //         if(head) pq.push(head);//nullptr就不入队了
    //         cur = cur->next;
    //     }
    //     return dummy->next;
    // }






    ListNode* mergeKLists(vector<ListNode*>& lists){
        //返回为true时rhs拥有更高的优先级
        auto cmp = [](ListNode*&lhs,ListNode*&rhs){return lhs->val>rhs->val;};
        priority_queue <ListNode*,vector<ListNode*>,decltype(cmp)> pq(cmp);
        ListNode *dummy = new ListNode(0);
        ListNode*cur = dummy;
        for(auto node:lists){
            if(node) pq.push(node);
        }
        while(!pq.empty()){
            ListNode*tmp = pq.top();
            pq.pop();
            cur->next = tmp;
            cur = cur->next;
            if(tmp->next) pq.push(tmp->next);//空节点不放进去，否则while跳出循环慢，且会UB
        }
        return dummy->next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,4,5],[1,3,4],[2,6]]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [[]]\n
// @lcpr case=end

 */

