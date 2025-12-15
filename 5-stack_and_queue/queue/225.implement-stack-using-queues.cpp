/*
 * @lc app=leetcode.cn id=225 lang=cpp
 * @lcpr version=30204
 *
 * [225] 用队列实现栈
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
// class MyStack {
// public:
//     MyStack() {
        
//     }
    
//     void push(int x) {
//         q1.push(x);
//     }
    
//     int pop() {
//         while(q1.size()>=2){
//             q2.push(q1.front());
//             q1.pop();
//         }
//         int topVal = q1.front();
//         q1.pop();
//         while(q2.size()>=1){
//             q1.push(q2.front());
//             q2.pop();
//         }
//         // q1 = q2;
//         // while(!q2.empty()){
//         //     q2.pop();
//         // }
//         return topVal;
//     }
    
//     int top() {
//         int topVal = this->pop();
//         this->push(topVal);
//         return topVal;
//     }
    
//     bool empty() {
//         return q1.empty();
//     }
// private:
//     queue<int> q1;
//     queue<int> q2;
// };
/*method2:using one queue to implement*/
class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int cnt = q.size();
        while(cnt-->=2){
            q.push(q.front());
            q.pop();
        }
        int topVal = q.front();
        q.pop();
        return topVal;
    }
    
    int top() {
        int topVal = this->pop();
        this->push(topVal);
        return topVal;
    }
    
    bool empty() {
        return q.empty();
    }
private:
    queue<int> q;
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end



/*
// @lcpr case=start
// ["MyStack", "push", "push", "top", "pop", "empty"][[], [1], [2], [], [], []]\n
// @lcpr case=end

 */

