/*
 * @lc app=leetcode.cn id=LCR 021 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 021] 删除链表的倒数第 N 个结点
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
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     ListNode*fast = head,*slow = head;
    //     while(n--){
    //         fast = fast->next;
    //     }
    //     if(fast){
    //         fast = fast->next;//多走一步，使得slow指向被删除节点的前一个
    //         while(fast){
    //             fast = fast->next;
    //             slow = slow->next;
    //         }
    //         ListNode *to_delete = slow->next;
    //         slow->next = to_delete->next;
    //         delete to_delete;
    //     }
    //     else{//若移动n步后fast为空，说明slow现在指向的已经是待删除的节点 = head
    //         head = head->next;
    //     }
    //     return head;
    // }
    /*使用dummy减少后续讨论：将删除头节点与删除后续节点统一处理*/
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* fast = dummy,*slow = dummy;
        while(n--){
            fast = fast->next;
        }
        fast = fast->next;
        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode*to_delete = slow->next;
        slow->next = to_delete->next;
        delete to_delete;
        return dummy->next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n
// @lcpr case=end

 */

