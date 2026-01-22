/*
 * @lc app=leetcode.cn id=92 lang=cpp
 * @lcpr version=30204
 *
 * [92] 反转链表 II
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
    //纯迭代
    // ListNode* reverseN(ListNode*head,int n){
    //     ListNode*cur = head,*prev = nullptr;
    //     while(n--){
    //         ListNode*tmp = cur->next;
    //         cur->next = prev;
    //         prev = cur;
    //         cur = tmp;
    //     }
    //     // 此时的 cur 是第 n + 1 个节点，head 是反转后的尾结点
    //     head->next = cur;
    //     return prev;
    // }
    // ListNode* reverseBetween(ListNode* head, int left, int right) {
    //     ListNode dummy(501,head);
    //     ListNode*cur = &dummy;//统一left=1，确保cur指向待反转node的prev
    //     int step = left;
    //     while(--step){
    //         cur = cur->next;
    //     }
    //     //从第left个node开始反转(right-left+1)=n个节点
    //     cur->next = reverseN(cur->next,right-left+1);
    //     return dummy.next;
    // }
    //纯递归
    ListNode* succ = nullptr;
    //返回反转后的头节点
    ListNode* reverseN(ListNode*head,int n){
        //base case
        if(n==1){
            succ = head->next;
            return head;
        }
        ListNode*last = reverseN(head->next,n-1);
        head->next->next = head;
        head->next = succ;
        return last;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //base case
        if(left==1) return reverseN(head,right);
        // 对于 head->next 来说，反转区间就是从 left - 1 到 right - 1
        head->next = reverseBetween(head->next,left-1,right-1);
        return head;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n4\n
// @lcpr case=end

// @lcpr case=start
// [5]\n1\n1\n
// @lcpr case=end

 */

