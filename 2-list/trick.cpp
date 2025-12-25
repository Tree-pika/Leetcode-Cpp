struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};

ListNode* createLinkedList(std::vector<int> arr) {
    if(arr.empty()) return nullptr;//访问数组前要判断下标是否有效

    ListNode *head = new ListNode(arr[0]);
    ListNode *cur = head;
    for(int i=0;i<arr.size();i++){
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    return head;
}

class DoublyListNode{
public:
    int val;
    DoublyListNode *prev;
    DoublyListNode *next;
    DoublyListNode(int x):val(x),prev(nullptr),next(nullptr){}
};