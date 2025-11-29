//Circular Linked List
struct CircularListNode{
    int val;//数据域
    CircularListNode *next;

    CircularListNode(int x):val(x),next(nullptr){}
    // 注意：在实际构建循环链表时，尾节点的 next 会指向头节点，而不是 NULL。
}
/*对于循环链表，
通常使用一个 tail 指针指向尾节点，
这样头节点就是 tail->next。*/

/*尾插*/
void insertCircularTail(CircularListNode*&tail,int new_val){
    CircularListNode* new_node = new CircularListNode(new_val);

    if(tail==nullptr){
        // 链表为空，新节点既是头节点也是尾节点
        tail = new_node;
        new_node->next = new_node;
    }else {
        new_node->next = tail->next; // 1. 新节点指向原来的头节点 (tail->next)
        tail->next = new_node;       // 2. 原尾节点指向新节点
        tail = new_node;             // 3. 尾指针更新为新节点
    }
}
/*删除头节点*/
bool deleteCircularHead(CircularListNode*&tail){
    if(tail==nullptr){
        //list is empty
        return false;
    }
    CircularListNode* head = tail->next;
    if (head == tail) { 
        // 链表中只有一个节点
        delete head;
        tail = nullptr;
        return true;
    }

    // 1. 尾节点的 next 指向新的头节点 (原头节点的 next)
    tail->next = head->next;
    // 2. 释放原头节点
    delete head;
    return true;
}