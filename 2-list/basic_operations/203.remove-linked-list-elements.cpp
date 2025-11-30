/*
 * @lc app=leetcode.cn id=203 lang=cpp
 * @lcpr version=30204
 *
 * [203] 移除链表元素
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
/*using dynamic allocation：heap variable*/
    // ListNode* removeElements(ListNode* head, int val) {
    //     ListNode* dummy = new ListNode(-1,head);
    //     ListNode* current = dummy;
    //     while(current->next){
    //         if(current->next->val == val){
    //             ListNode* to_delete = current->next;
    //             current->next = to_delete->next;
    //             delete to_delete;
    //         }
    //         else{
    //             current = current->next;
    //         }
    //     }
    //     head = dummy->next;
    //     delete dummy;
    //     return head;
    // }
    /*using object：stack variable*/
    // ListNode* removeElements(ListNode* head,int val){
    //     ListNode dummy(-1,head);
    //     ListNode* current = &dummy;//取地址
    //     /*引用：ListNode& current = dummy;*/
    //     while(current->next){
    //         if(current->next->val==val){
    //             ListNode* to_delete = current->next;
    //             current->next = to_delete->next;
    //             delete to_delete;
    //         }else{
    //             current = current->next;
    //         }
    //     }
    //     return dummy.next;
    // }
    /*method2:recursion*/
    ListNode* removeElements(ListNode* head,int val){
        if(head==nullptr){
            return nullptr;
        }
        if(head->val==val){
            ListNode* newHead = removeElements(head->next,val);
            delete head;
            return newHead;
        }else{
            head->next = removeElements(head->next,val);
            return head;
        }
    }

};
// @lc code=end



/*
// @lcpr case=start
// [1,2,6,3,4,5,6]\n6\n
// @lcpr case=end

// @lcpr case=start
// []\n1\n
// @lcpr case=end

// @lcpr case=start
// [7,7,7,7]\n7\n
// @lcpr case=end

 */

