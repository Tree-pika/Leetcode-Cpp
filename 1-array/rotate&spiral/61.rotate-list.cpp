/*
 * @lc app=leetcode.cn id=61 lang=cpp
 * @lcpr version=30204
 *
 * [61] 旋转链表
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
    //返回反转后的链表头指针
    ListNode* reverseN(ListNode*head,int n){
        ListNode*cur = head,*prev = nullptr;
        while(n--){
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        head->next = cur;//连上后序的list
        return prev;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!head->next||k==0) return head;
        //计算list长度
        ListNode*cur = head;
        int n = 0;
        while(cur){
            n++;
            cur = cur->next;
        }
        k = k%n;
        if(k==0) return head;
        //三次反转
        head = reverseN(head,n);
        head = reverseN(head,k);
        cur = head;
        for(int i=0;i<k-1;i++){
            cur = cur->next;
        }
        cur->next = reverseN(cur->next,n-k);
        return head;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2]\n4\n
// @lcpr case=end

 */

