/*
 * @lc app=leetcode.cn id=160 lang=cpp
 * @lcpr version=30204
 *
 * [160] 相交链表
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
/*关键点：相交点处指针即地址值相同，其后两个链表的结点完全重合，即地址、值、数目一致*/
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     ListNode* curA = headA;
    //     ListNode* curB = headB;
    //     int lenA = 0;
    //     int lenB = 0;
    //     while(curA){
    //         curA=  curA->next;
    //         lenA++;
    //     }
    //     while(curB){
    //         curB = curB->next;
    //         lenB++;
    //     }
    //     //重置
    //     curA = headA;
    //     curB = headB;
        
    //     if(lenA<lenB){
    //         swap(lenA,lenB);
    //         swap(curA,curB);
    //     }
    //     int gap = lenA-lenB;
    //     //将指向长链表初始结点的指针往右移动，以对齐两个链表的长度
    //     // 长链表(前面)的多余结点不可能是相交结点
    //     while(gap--){
    //         curA = curA->next;
    //     }
    //     while(curA){
    //         if(curA==curB){
    //             return curA;
    //         }
    //         curA = curA->next;
    //         curB = curB->next;
    //     }

    //     return nullptr;
    // }
/*method2：双指针法*/
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        while(curA!=curB){
            curA = curA?curA->next:headB;
            curB = curB?curB->next:headA;
        }
        return curA;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 8\n[4,1,8,4,5]\n[5,6,1,8,4,5]\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// 2\n[1,9,1,2,4]\n[3,2,4]\n3\n1\n
// @lcpr case=end

// @lcpr case=start
// 0\n[2,6,4]\n[1,5]\n3\n2\n
// @lcpr case=end

 */

