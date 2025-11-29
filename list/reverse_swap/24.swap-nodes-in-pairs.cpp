/*
 * @lc app=leetcode.cn id=24 lang=cpp
 * @lcpr version=30204
 *
 * [24] 两两交换链表中的节点
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
    // ListNode* swapPairs(ListNode* head) {
    //     //空链表或者只有一个结点的情况
    //     if(!head||!head->next) return head;
    //     //至少两个结点
    //     ListNode* dummy = new ListNode(0,head);
    //     ListNode* prev = dummy;
    //     ListNode* cur = prev->next;
    //     ListNode* tmp = cur->next;
    //     while(cur&&tmp&&prev){
    //         prev->next = tmp;
    //         cur->next = tmp->next;
    //         tmp->next = cur;
    //         prev = prev->next->next;
    //         if(prev)
    //             cur = prev->next;
    //         if(cur)
    //             tmp = cur->next;

    //     }
    //     head = dummy->next;
    //     delete dummy;
    //     // dummy = nullptr;
    //     return head;
    // }
    /*method2:优雅的写法，不用加上很多判断来限制UB*/
    // ListNode* swapPairs(ListNode* head) {
    //     ListNode* dummy = new ListNode(0,head);
    //     ListNode* node0 = dummy;
    //     ListNode* node1 = head;
    //     //若node0=nullptr，直接跳出while循环了
    //     // 后续的node1->next不会计算，也就不会发生空指针解引用
    //     while(node1&&node1->next){
    //         //进入循环说明node1和node2都不是nullptr
    //         ListNode* node2 = node1->next;
    //         ListNode* node3 = node2->next;//不会发生空指针解引用

    //         node0->next = node2;
    //         node2->next = node1;
    //         node1->next = node3;

    //         node0 = node1;
    //         node1 = node3;
    //     }
    //     head = dummy->next;
    //     delete dummy;
    //     return head;
    // }
    /*method3：recursion*/
    ListNode* swapPairs(ListNode* head) {
        //return/base cases
        if(!head||!head->next)
            return head;
        ListNode* node1 = head;
        ListNode* node2 = node1->next;
        ListNode* node3 = node2->next;
        node1->next = swapPairs(node3);
        node2->next = node1;

        return node2;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

