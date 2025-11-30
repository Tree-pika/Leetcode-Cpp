//Doubly Linked List
struct DoublyListNode{
    int val;//数据域
    DoublyListNode *prev;
    DoublyListNode *next;

    DoublyListNode(int x):val(x),prev(nullptr),next(nullptr){}
}

/*尾插法*/
void insertAtTail(DoublyListNode*&head,int new_val){
    DoublyListNode* new_node = new DoublyListNode(new_val);
    if(head==nullptr){
        head = new_node;
        return;
    }
    // 找到尾节点
    DoublyListNode* current = head;
    while(current->next){
        current = current->next;
    }
    // 1. 新节点的 prev 指向原尾节点
    new_node->prev = current; 
    // 2. 原尾节点的 next 指向新节点
    current->next = new_node;
}

/*删除尾部的节点*/
bool deleteTail(DoublyListNode*&head){
    if(head==nullptr){
        return false;
    }
    // 只有一个节点的情况
    //如果不单独处理，后续会出现nullptr->next = nullptr;非法
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return true;
    }

    // 找到尾节点
    DoublyListNode* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    
    // current 现在是尾节点
    DoublyListNode* new_tail = current->prev; // 新的尾节点
    
    // 1. 新尾节点的 next 设为 nullptr
    new_tail->next = nullptr;
    // 2. 释放原尾节点
    delete current; 
    return true;
}

/*顺序插入 (保持升序)*/
void sortedInsertDoubly(DoublyListNode*&head,int new_val){
    DoublyListNode* new_node = new DoublyListNode(new_val);
    // 1. 如果链表为空，执行头插
    if(head==nullptr){
        head = new_node;
        return;
    }
    // 情况2: 插入头部 (新值小于头节点)
    if(new_val<head->val){
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        return;
    }
    // 情况3: 插入中间或尾部
    DoublyListNode* current = head;
    DoublyListNode* previous = nullptr;
    while(current&&current->val<new_val){
        previous = current;
        current = current->next;
    }
    // 此时，new_node 应该插入到 previous 和 current 之间
    previous->next = new_node;
    new_node->prev = previous;
    // 连接 new_node <-> current
    if (current != nullptr) {
        new_node->next = current;
        current->prev = new_node;
    }
}

void deleteByValDoubly(DoublyListNode*&head,int target_val){
    bool deleted = false;
    if(head==nullptr) return deleted;
    DoublyListNode* current = head;
    while(current){
        if(current->val==target_val){
            DoublyListNode* to_delete = current;

            if(current->prev){
                current->prev->next = current->next;
            }else{
                // 如果没有前驱，说明删除的是头节点
                head = current->next;
            }
            if(current->next){
                //头节点也可以适配，此时current->prev = nullptr
                current->next->prev = current->prev;
            }

            current = current->next;
            delete to_delete;
            deleted = true;
        }else{
            current = current->next;
        }
    }
    return deleted;
    
}