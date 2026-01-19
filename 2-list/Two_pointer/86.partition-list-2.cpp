// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=86 lang=cpp
 * @lcpr version=30204
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy1 = new ListNode(-1);
        ListNode *dummy2 = new ListNode(-1);
        ListNode *p1 = dummy1;
        ListNode *p2 = dummy2;
        for(ListNode* cur = head;cur!=nullptr;){
            if(cur->val<x){
                p1->next = cur;
                p1 = p1->next;
            }else{
                p2->next = cur;
                p2 = p2->next;
            }
            //每次断开原链表中的每个节点的 next 指针
            ListNode *temp = cur->next;
            cur->next = nullptr;
            cur = temp;
        }
        p1->next = dummy2->next;
        return dummy1->next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,4,3,2,5,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,1]\n2\n
// @lcpr case=end

 */

