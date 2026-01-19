/*
 * @lc app=leetcode.cn id=445 lang=cpp
 * @lcpr version=30204
 *
 * [445] 两数相加 II
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
/*使用反转链表的思路*/
    // ListNode* reverseList(ListNode*head){
    //     ListNode*cur = head;
    //     ListNode*prev = nullptr;
    //     while(cur){
    //         ListNode*tmp = cur->next;
    //         cur->next = prev;
    //         prev = cur;
    //         cur = tmp;
    //     }
    //     return prev;
    // }
    // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //     l1 = reverseList(l1);
    //     l2 = reverseList(l2);
    //     int carry = 0;
    //     ListNode*dummy = new ListNode(-1);
    //     ListNode*cur = dummy;
    //     while(l1||l2||carry){
    //         ListNode*t = new ListNode(0);
    //         t->val += carry;
    //         if(l1){
    //             t->val+=l1->val;
    //             l1 = l1->next;
    //         }
    //         if(l2){
    //             t->val+=l2->val;
    //             l2 = l2->next;
    //         }
    //         carry = t->val/10;
    //         t->val%=10;
    //         cur->next = t;
    //         cur = cur->next;
    //     }
    //     dummy->next = reverseList(dummy->next);
    //     return dummy->next;
    // }
/*using stack*/
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> st1;
        stack<ListNode*> st2;
        while(l1){
            st1.push(l1);
            l1 = l1->next;
        }
        while(l2){
            st2.push(l2);
            l2 = l2->next;
        }
        int carry = 0;
        // stack<ListNode*> res;
        ListNode*dummy = new ListNode(-1);
        while(!st1.empty()||!st2.empty()||carry){
            ListNode*tmp = new ListNode(0);
            tmp->val+=carry;
            if(!st1.empty()){
                tmp->val+=st1.top()->val;
                st1.pop();
            }
            if(!st2.empty()){
                tmp->val+=st2.top()->val;
                st2.pop();
            }
            carry = tmp->val/10;
            tmp->val%=10;
            // res.push(tmp);

            tmp->next = dummy->next;
            dummy->next = tmp;
        }
        
        // ListNode*cur = dummy;
        // while(!res.empty()){
        //     cur->next = res.top();
        //     res.pop();
        //     cur = cur->next;
        // }
        return dummy->next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [7,2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n
// @lcpr case=end

 */

