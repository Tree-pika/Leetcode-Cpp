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
    // ListNode* partition(ListNode* head, int x) {
    //     // ListNode*dum1 = new ListNode(-1);
    //     // ListNode*dum2 = new ListNode(-1);
    //     // ListNode*cur1 = dum1,*cur2 = dum2;
    //     ListNode dum1 = ListNode(-1);
    //     ListNode dum2 = ListNode(-1);
    //     ListNode*cur1 = &dum1,*cur2 = &dum2;
    //     while(head){
    //         if(head->val<x){
    //             cur1->next = head;
    //             cur1 = cur1->next;
    //             head = head->next;//先把原链移到下一个位置，否则原链本身也断了
    //             cur1->next = nullptr;//与原链断开
    //         }else{
    //             cur2->next = head;
    //             cur2 = cur2->next;
    //             head = head->next;
    //             cur2->next = nullptr;//与原链断开
    //         }
    //     }
    //     cur1->next = dum2.next;
    //     // delete dum2;
    //     return dum1.next;
    // }
/*review:
* 目前的写法中，head = head->next 和 cur->next = nullptr 在 if 和 else 里重复出现。
* need:减少分支预测（Branch Prediction）失败的代价，尽量合并公共逻辑。
* solution2
*/
    // ListNode* partition(ListNode* head, int x) {
    //     ListNode dum1 = ListNode(-1);
    //     ListNode dum2 = ListNode(-1);
    //     ListNode*cur1 = &dum1,*cur2 = &dum2;
    //     while(head){
    //         if(head->val<x){
    //             cur1->next = head;
    //             cur1 = cur1->next;
    //         }else{
    //             cur2->next = head;
    //             cur2 = cur2->next;
    //         }
    //         head = head->next;
    //     }
    //     cur2->next = nullptr;//只需要最后一个断开即可
    //     cur1->next = dum2.next;
    //     return dum1.next;
    // }



    ListNode* partition(ListNode* head, int x){
        ListNode* dum1 = new ListNode(-1);
        ListNode *dum2 = new ListNode(-1);
        ListNode*cur1 = dum1,*cur2 = dum2;
        while(head){
            if(head->val<x){
                cur1->next = head;
                cur1 = cur1->next;
            }else{
                cur2->next = head;
                cur2 = cur2->next;
            }
            head = head->next;
        }
        cur2->next = nullptr;//防止成环
        cur1->next = dum2->next;
        return dum1->next;
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

