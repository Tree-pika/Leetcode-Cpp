#include<iostream>
using namespace std;
/*defintion*/
//Singly Linked List
struct ListNode{
    int val;//数据域
    ListNode *next;//指针域
    ListNode(int x):val(x),next(nullptr){}//自定义的node的ctor
}
//通过自己定义构造函数初始化节点：
ListNode* head = new ListNode(5);
//使用默认构造函数初始化节点：
ListNode* head = new ListNode;
head->val = 5;

/*头插法*/
//head 是一个引用，它引用的是 ListNode*。
void insertAtHead(ListNode*&head,int new_val){
    ListNode* new_node = new ListNode(new_val);
    new_node->next = head;
    head = new_node;
}

/*删除头节点*/
bool delete(ListNode*&head){
    if(head == nullptr){
        cout << "链表为空，无法删除。" << endl;
        return false;
    }
    ListNode* to_delete = head;
    head = head->next;
    delete to_delete;
    return true;
}

/*遍历链表*/
void traverseSinglyList(ListNode* head){
    ListNode* current = head;
    while(current!=nullptr){
        cout<<current->val;
        if(current->next!=nullptr){
            cout<<"->";
        }
        current = current->next;
    }
    cout<<"->nullptr"<<endl;
}

/*顺序插入 (保持升序)*/
void sortedInsertSingly(ListNode*&head,int new_val){
    ListNode* new_node = new ListNode(new_val);
    // 1. 如果链表为空，或者新值小于头节点值，执行头插
    if(head==nullptr || new_val<head->val){
        insertAtHead(head,new_val);
        return ;
    }
    // 2. 找到插入位置：找到第一个 `current->next` 的值大于 `new_val` 的节点
    ListNode* current = head;
    while(current->next!=nullptr && current->next->val<new_val){
        current = current->next;
    }
    // 3. 执行插入操作
    new_node->next = current->next;
    current->next = new_node;

}

/*删除指定 val 的节点*/
bool deleteByValSingly(ListNode*&head,int target_val){
    bool deleted = false;//是否至少删了一个
    while(head&&head->val == target_val){
        ListNode* to_delete = head;
        head = head->next;
        delete to_delete;
        deleted = true;
    }
    if(head==nullptr) return deleted;

    ListNode* current = head;
    while(current->next){
        if(current-next->val == target_val){
            ListNode* to_delete = current->next;
            current->next = to_delete->next;
            delete to_delete;
            deleted = true;
        }
        else{
            current = current->next;
        }
    }
    return deleted;
}

/*dummy head*/
ListNode* removeElements(ListNode*head,int val){
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* current = dummy;
    while(current->next){
        if(current->next->val==val){
            ListNode* to_delete = current->next;
            current->next = to_delete->next;
            delete to_delete;
        }else{
            current = current->next;
        }
    }
    head = dummy->next;
    delete dummy;
    return head;
}