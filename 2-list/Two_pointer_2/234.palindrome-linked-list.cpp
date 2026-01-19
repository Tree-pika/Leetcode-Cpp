/*
 * @lc app=leetcode.cn id=234 lang=cpp
 * @lcpr version=30204
 *
 * [234] 回文链表
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
    // bool isPalindrome(ListNode* head) {
    //     vector<ListNode*> vec;
    //     ListNode*cur = head;
    //     while(cur){
    //         vec.push_back(cur);
    //         cur = cur->next;
    //     }
    //     int left = 0,right = vec.size()-1;
    //     while(left<right){
    //         if(vec[left]->val!=vec[right]->val){
    //             return false;
    //         }
    //         left++;
    //         right--;
    //     }
    //     return true;
    // }
    //2.反转链表
    // bool isPalindrome(ListNode* head) {
    //     ListNode*p = new ListNode(head->val,nullptr);
    //     ListNode*cur = head->next;
    //     while(cur){
    //         ListNode*newNode = new ListNode(cur->val);
    //         newNode->next = p;
    //         p = newNode;
    //         cur = cur->next;
    //     }
    //     //p指向新链表的头
    //     while(p){
    //         if(p->val!=head->val){
    //             return false;
    //         }
    //         p = p->next;
    //         head = head->next;
    //     }
    //     return true;
    // }
    //3.后序遍历
    // ListNode* left;
    // ListNode*right;
    // bool res = true;
    
    // void traverse(ListNode*right){
    //     if(right==nullptr) return;
    //     traverse(right->next);
    //     // 后序遍历位置，此时的 right 指针指向链表右侧尾部
    //     if(left->val!=right->val){
    //         res = false;
    //     }
    //     left = left->next;
    // }
    // bool isPalindrome(ListNode* head) {
    //     left = head;
    //     traverse(head);
    //     return res;
    // }
    //4. O(1) 空间复杂度
    ListNode* midList(ListNode*head){
        ListNode*slow = head,*fast = head;
        while(fast&&fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head){
        ListNode*cur = head,*prev = nullptr;
        while(cur){
            ListNode*tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* midNode = midList(head);
        ListNode*head2 = reverseList(midNode);
        while(head2){
            if(head->val!=head2->val){
                return false;
            }
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */

