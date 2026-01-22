/*
 * @lc app=leetcode.cn id=25 lang=cpp
 * @lcpr version=30204
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseN(ListNode*head,int n){
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt = 0;
        ListNode*cur = head;
        while(cur){
            cnt++;
            cur = cur->next;
        }
        ListNode dummy(-1,head);
        cur = &dummy;//始终指向待反转链表的前驱node
        for(int i=0;i+k<=cnt;i+=k){
            ListNode*tmp = reverseN(cur->next,k);//反转后的头节点
            ListNode*tail = cur->next;//反转后的尾结点
            cur->next = tmp;
            cur = tail;//下一组的前驱node
        }
        return dummy.next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n3\n
// @lcpr case=end

 */

