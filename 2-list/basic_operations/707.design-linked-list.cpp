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
// class MyLinkedList {
// public:
//     struct ListNode{
//         int val;
//         ListNode* next;
//         ListNode(int val):val(val),next(nullptr){}
//     };
// private:
//     int size;
//     ListNode* dummy;
// public:
//     MyLinkedList() {
//         size = 0;
//         dummy = new ListNode(-1);
//     }
//     ~MyLinkedList(){
//         ListNode* current = dummy;
//         while(current){
//             ListNode* to_delete = current;
//             current = current->next;
//             delete to_delete;
//         }
//     }
//     int get(int index) {
//         if(index>size-1||index<0){
//             return -1;
//         }
//         ListNode* current = dummy->next;
//         while(index--){
//             current = current->next;
//         }
//         return current->val;
//     }
    
//     // void addAtHead(int val) {
//     //     size++;
//     //     ListNode* head = dummy->next;
//     //     ListNode* new_node = new ListNode(val);
//     //     new_node->next = head;
//     //     dummy->next = new_node;
//     // }
//     void addAtHead(int val){
//         addAtIndex(0,val);
//     }
    
//     // void addAtTail(int val) {
//     //     size++;
//     //     // ListNode* current = dummy->next;//若链表为空，后续就会出现nullptr->next,造成段错误
//     //     ListNode* current = dummy;
//     //     while(current->next){
//     //         current = current->next;
//     //     }
//     //     ListNode* new_node = new ListNode(val);
//     //     current->next = new_node;
//     // }
//     void addAtTail(int val){
//         addAtIndex(size,val);
//     }
    
//     void addAtIndex(int index, int val) {
//         ListNode* previous = dummy;
//         if(index>size) return;
//         while(index--){
//             previous = previous->next;
//         }
//         ListNode* new_node = new ListNode(val);
//         new_node->next = previous->next;
//         previous->next = new_node;
//         size++;
//     }
    
//     void deleteAtIndex(int index) {
//         if(index>size-1||index<0) return;
//         ListNode* previous = dummy;
//         while(index--){
//             previous = previous->next;
//         }
//         ListNode* to_delete = previous->next;
//         previous->next = to_delete->next;
//         delete to_delete;//new出来的需要手动释放！
//         to_delete = nullptr;
//         size--;
//     }
// };
/*method2:DoublyList*/
// class MyLinkedList {
// public:
//     struct DListNode{
//         int val;
//         DListNode* prev;
//         DListNode* next;
//         DListNode(int val):val(val),prev(nullptr),next(nullptr){}
//     };
// private:
//     int size;
//     DListNode* dummy;
// public:
//     MyLinkedList() {
//         size = 0;
//         dummy = new DListNode(-1);
//     }
//     ~MyLinkedList(){
//         DListNode*current = dummy;
//         while(current){
//             DListNode* to_delete = current;
//             current = current->next;
//             delete to_delete;
//             to_delete = nullptr;
//         }
//     }
//     int get(int index) {
//         if(index>=size||index<0) return -1;
//         DListNode*current = dummy->next;
//         while(index--){
//             current = current->next;
//         }
//         return current->val;
//     }
    
//     void addAtHead(int val) {
//         addAtIndex(0,val);
//     }
    
//     void addAtTail(int val) {
//         addAtIndex(size,val);
//     }
    
//     void addAtIndex(int index, int val) {
//         if(index>size) return ;
//         DListNode* previous = dummy;
//         while(index--){
//             previous = previous->next;
//         }
//         DListNode* new_node = new DListNode(val);
//         new_node->next = previous->next;
//         new_node->prev = previous;
//         if(previous->next)//crucial！确保不是空指针，nullptr->prev会造成段错误
//             previous->next->prev = new_node;
//         previous->next = new_node;

//         size++;
//     }
    
//     void deleteAtIndex(int index) {
//         if(index>=size||index<0) return ;
//         DListNode* previous = dummy;
//         while(index--){
//             previous = previous->next;
//         }
//         DListNode* to_delete = previous->next;
//         previous->next = to_delete->next;
//         if(to_delete->next)//确保不是空指针，nullptr->prev会造成段错误
//             to_delete->next->prev = previous;
//         delete to_delete;
//         to_delete = nullptr;
//         size--;
//     }
// };
/*method3:using double sentinels*/
class MyLinkedList {
public:
    struct DListNode{
        int val;
        DListNode* prev;
        DListNode* next;
        DListNode(int val):val(val),prev(nullptr),next(nullptr){}
    };
private:
    int size;
    DListNode* dummyhead;
    DListNode* dummytail;
public:
    MyLinkedList() {
        size = 0;
        dummyhead = new DListNode(0);
        dummytail = new DListNode(0);
        dummyhead->next = dummytail;
        dummytail->prev = dummyhead;
    }
    ~MyLinkedList(){
        DListNode*current = dummyhead;
        while(current){
            DListNode* to_delete = current;
            current = current->next;
            delete to_delete;
            // to_delete = nullptr;
        }
    }
    int get(int index) {
        if(index>=size||index<0) return -1;
        DListNode*current;
        if(index<size/2){
            current = dummyhead->next;
            while(index--)
                current = current->next;
        }
        else{
            current = dummytail->prev;
            index = size-1-index;
            while(index--){
                current = current->prev;
            }
        }
        return current->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0,val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size,val);
    }
    
    void addAtIndex(int index, int val) {
        if(index>size) return ;
        DListNode* succ;//后继结点successor
        if(index<size/2){
            succ = dummyhead->next;
            while(index--)
                succ = succ->next;
        }else{
            // succ = dummytail->prev;
            // index = size-1-index;//index = size时不对，新index=-1，while非0就会进入循环，解引用空指针
            succ = dummytail;//原因在于新插入的结点最右可以到dummytail的左边，上面写的是最右到tail的左边
            index = size-index;
            while(index--)
                succ = succ->prev;
        }
        DListNode* pred = succ->prev;//前驱结点predecessor
        DListNode* new_node = new DListNode(val);
        
        //四步连接
        new_node->next = succ;
        new_node->prev = pred;
        succ->prev = new_node;
        pred->next = new_node;

        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index>=size||index<0) return ;
        DListNode* to_delete;
        if(index<size/2){
            to_delete = dummyhead->next;
            while(index--)
                to_delete = to_delete->next;
        }else{
            to_delete = dummytail->prev;
            index = size-1-index;
            while(index--)
                to_delete = to_delete->prev;
        }
        DListNode* pred = to_delete->prev;
        DListNode* succ = to_delete->next;
        pred->next = succ;
        succ->prev = pred;
        delete to_delete;
        // to_delete = nullptr;
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



