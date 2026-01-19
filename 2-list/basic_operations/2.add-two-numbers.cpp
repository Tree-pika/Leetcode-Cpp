/*
 * @lc app=leetcode.cn id=2 lang=cpp
 * @lcpr version=30204
 *
 * [2] 两数相加
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
    // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //     bool flag = false;//进位标志
    //     ListNode*dummy = new ListNode(10);
    //     ListNode*cur = dummy;
    //     while(l1&&l2){
    //         ListNode*tmp = new ListNode(0);
    //         tmp->val = l1->val+l2->val;
    //         if(flag){
    //             tmp->val++;
    //             flag = false;
    //         }
    //         if(tmp->val>=10){
    //             flag = true;
    //             tmp->val%=10;
    //         }
    //         cur->next = tmp;
    //         cur = cur->next;
    //         //
    //         l1 = l1->next;
    //         l2 = l2->next;
    //     }
    //     while(l1){
    //         ListNode*tmp = new ListNode(0);
    //         tmp->val = l1->val;
    //         if(flag){
    //             tmp->val++;
    //             flag = false;
    //         }
    //         if(tmp->val>=10){
    //             flag = true;
    //             tmp->val%=10;
    //         }
    //         cur->next = tmp;
    //         cur = cur->next;
    //         //
    //         l1 = l1->next;
    //     }
    //     while(l2){
    //         ListNode*tmp = new ListNode(0);
    //         tmp->val = l2->val;
    //         if(flag){
    //             tmp->val++;
    //             flag = false;
    //         }
    //         if(tmp->val>=10){
    //             flag = true;
    //             tmp->val%=10;
    //         }
    //         cur->next = tmp;
    //         cur = cur->next;
    //         //
    //         l2 = l2->next;
    //     }
    //     if(flag){
    //         ListNode*tmp = new ListNode(1);
    //         cur->next = tmp;
    //     }
    //     return dummy->next;
    // }
/*将情况总结成一种：充分利用carry与加法器的思想*/
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode(10);
        ListNode* cur = dummy;
        while(l1||l2||carry){
            ListNode*tmp = new ListNode(0);
            tmp->val+=carry;
            if(l1){
                tmp->val+=l1->val;
                l1 = l1->next;
            }
            if(l2){
                tmp->val+=l2->val;
                l2 = l2->next;
            }
            carry = tmp->val/10;
            tmp->val%=10;
            cur->next = tmp;
            cur = cur->next;
        }
        return dummy->next;
    }

};
// @lc code=end



/*
// @lcpr case=start
// [2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n
// @lcpr case=end

// @lcpr case=start
// [9,9,9,9,9,9,9]\n[9,9,9,9]\n
// @lcpr case=end

 */

