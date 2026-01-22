/*
 * @lc app=leetcode.cn id=206 lang=cpp
 * @lcpr version=30204
 *
 * [206] 反转链表
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
    // ListNode* reverseList(ListNode* head) {
    //     ListNode*cur = head,*prev = nullptr;
    //     while(cur){
    //         ListNode*tmp = cur->next;
    //         cur->next = prev;
    //         prev = cur;
    //         cur = tmp;
    //     }
    //     return prev;
    // }
    //recursion:返回反转后的链表的头指针
    ListNode* reverseList(ListNode* head) {
        //base case
        if(!head||!head->next) return head;
        ListNode*last = reverseList(head->next);
        //head->next 仍然指向子链表反转后的尾部。
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
    // 将链表的前 n 个节点反转（n <= 链表长度）
    //iteration
    ListNode* reverseN(ListNode* head, int n){
        ListNode*cur = head,*prev = nullptr;
        while(n--){
            ListNode*tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        head->next = cur;
        return prev;
    }
    //recursion
    ListNode*succ = nullptr;
    ListNode* reverseN(ListNode* head, int n){
        if(n==1) {//base case:n步走完了就停，当前 head 就是第 n 个节点
            succ = head->next;// 记录第 n + 1 个节点，后面要接上
            return head;
        }
        ListNode*last = reverseN(head->next,n-1);
        head->next->next = head;
        head->next = succ;//
        return last;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

