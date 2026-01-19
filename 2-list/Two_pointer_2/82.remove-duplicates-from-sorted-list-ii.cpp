/*
 * @lc app=leetcode.cn id=82 lang=cpp
 * @lcpr version=30204
 *
 * [82] 删除排序链表中的重复元素 II
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
    /*solution2:快慢指针法*/
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(101);
        ListNode*cur = head;//向前探测是否有重复节点(快指针)
        ListNode*prev = &dummy;//始终指向最后一个不重复的节点(慢指针)
        while(cur){
            if(cur->next&&cur->val==cur->next->val){
                // 发现重复节点，跳过这些重复节点
                while(cur->next&&cur->val==cur->next->val){
                    cur = cur->next;
                }
                //无论后面是 null 还是新节点，立刻把 prev 的路铺好(实时更新)
                prev->next = cur->next;//但是不移动prev，因为next不一定符合条件，prev指向的都是符合条件的node
            }else{
                // 不是重复节点，直接接到prev后面
                prev->next = cur;
                prev = prev->next;
            }
            cur = cur->next;
        }
        return dummy.next;
    }
    /*solution3:分解链表的思路*/
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*pUniq = new ListNode(101),*pDup = new ListNode(101);
        ListNode*cur = head,*p = pUniq;
        while(cur){
            if((cur->next&&cur->val==cur->next->val)||cur->val==pDup->val){
                pDup->next = cur;
                pDup = pDup->next;
            }else{
                pUniq->next = cur;
                pUniq = pUniq->next;
            }
            cur = cur->next;
        }
        pUniq->next = nullptr;//断开与原链表的连接
        pDup->next = nullptr;
        return p->next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,3,4,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,2,3]\n
// @lcpr case=end

 */

