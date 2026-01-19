/*
 * @lc app=leetcode.cn id=707 lang=cpp
 * @lcpr version=30204
 *
 * [707] 设计链表
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
class MyLinkedList {
public:
    struct ListNode{
        int val;
        ListNode*next;
        ListNode(int x):val(x),next(nullptr){}
    };
private:
    ListNode*dummy;
    int size;//节点个数
public:
    MyLinkedList() {
        dummy = new ListNode(-1);
        size = 0;
    }
    
    int get(int index) {
        if(index<0||index>=size){
            return -1;
        }
        ListNode*cur = dummy->next;
        while(index--){
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        return addAtIndex(0,val);
    }
    
    void addAtTail(int val) {
        return addAtIndex(size,val);
    }
    
    void addAtIndex(int index, int val) {
        if(index<0||index>size){
            return;
        }
        ListNode*cur = dummy;
        while(index--){
            cur = cur->next;
        }
        ListNode* new_node = new ListNode(val);
        new_node->next = cur->next;
        cur->next = new_node;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index<0||index>=size){
            return;
        }
        ListNode*cur = dummy;
        while(index--){
            cur = cur->next;
        }
        ListNode*to_delete = cur->next;
        cur->next = to_delete->next;
        delete to_delete;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end



