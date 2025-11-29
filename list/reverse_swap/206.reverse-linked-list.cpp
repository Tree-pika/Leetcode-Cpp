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
/*双指针法:from head to tail*/
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* prev = nullptr;
    //     ListNode* cur = head;
    //     while(cur){
    //         ListNode* tmp = cur->next;
    //         cur->next = prev;
    //         prev = cur;
    //         cur = tmp;
    //     }
    //     return prev;
    // }
/*recursion:from tail to head*/
    // ListNode* reverseList(ListNode* head) {
    //     //1. 终止条件：链表为空或只有一个节点，直接返回当前节点
    //     if(head==nullptr||head->next==nullptr)
    //         return head;
    //     // 2. 递归调用：先反转 head 后面的链表
    //     // 这里的 newHead 将会是整条链表反转后的新头节点（即原链表的最后一个节点）
    //     ListNode* newHead = reverseList(head->next);

    //     // 3. 内部逻辑：将当前节点 head 接到“已反转部分的末尾”
    //     // 此时 head->next 其实就是“已反转部分”的尾节点
    //     head->next->next = head;
        
    //     // 断开原来的连接，防止形成环
    //     head->next = nullptr;

    //     // 返回新的头节点（这个 newHead 会一直传回最顶层）
    //     return newHead;
    // }

/*tail recursion:from head to tail*/
    // ListNode* reverse(ListNode*prev,ListNode* cur){
    //     // 1. 终止条件：相当于迭代法里的 while(cur) 结束了
    //     // 如果 cur 为空，说明链表走到了尽头，prev 指向的就是新的头节点
    //     if(cur==nullptr) return prev;
    //     // 2. 核心逻辑：先保存下一步，再反转当前指向
    //     ListNode* tmp = cur->next;
    //     cur->next = prev;
    //     // prev = cur;
    //     // cur = tmp;
    //     // 3. 递归调用：相当于迭代法里的 prev = cur; cur = tmp;
    //     // 把当前的 cur 变成下一次的 prev
    //     // 把当前的 tmp 变成下一次的 cur
    //     return reverse(cur,tmp);
    // }   
    // ListNode* reverseList(ListNode* head) {
    //     // 初始状态：prev 是 nullptr，cur 是 head
    //     return reverse(nullptr,head);
    // }
/*insertAtHead*/
ListNode* reverseList(ListNode* head) {
    //dummy固定不懂，指向next随着翻转过程一直在变，
    // 每次切换到指向当前已翻转好的链表的头部
    ListNode* dummy = new ListNode(-1);
    ListNode* cur = head;//记录当前需要翻转的结点，一直迭代到tail节点
    while(cur){
        ListNode* tmp = cur->next;
        cur->next = dummy->next;//将未翻转的部分接到当前已翻转好的链表的头部
        dummy->next = cur;//当前已翻转好的链表的头部往后移一位
        cur = tmp;//未翻转的部分也往后移一位
    }
    return dummy->next;
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

