/*
 * @lc app=leetcode.cn id=19 lang=cpp
 * @lcpr version=30204
 *
 * [19] 删除链表的倒数第 N 个结点
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
    //     int size = 0;
    //     ListNode* dummuy = new ListNode(-1,head);
    //     ListNode* prev = dummuy;
    //     while(prev->next){
    //         prev = prev->next;
    //         size++;
    //     }
    //     int index = size-n;//倒数第2个，正数第(size-n)个，index从0开始
    //     prev = dummuy;
    //     ListNode* cur = head;
    //     /*最终是希望cur指向被删除的点，prev指向被删除结点的前一个
    //     又因为一开始cur指向的是head，所以结点索引可以认为从0开始*/
    //     while(index--){
    //         prev = cur;
    //         cur = cur->next;
    //     }
    //     ListNode* to_delete = cur;
    //     prev->next = to_delete->next;
    //     delete to_delete;
    //     head = dummuy->next;//crucial，单结点时head在上面会被删掉
    //     delete dummuy;
    //     return head;
    // }
    /*双指针法*/
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1,head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        n++;
        while(n--){
            fast = fast->next;
        }
        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* to_delete = slow->next;
        slow->next = to_delete->next;
        delete to_delete;
        head = dummy->next;
        delete dummy;
        return head;
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

