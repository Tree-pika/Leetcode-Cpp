/*
 * @lc app=leetcode.cn id=559 lang=cpp
 * @lcpr version=30204
 *
 * [559] N 叉树的最大深度
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
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    // int depth(Node* root) {
    //     queue<Node*> que;
    //     if(root) que.push(root);
    //     int level = 0;
    //     while(!que.empty()){
    //         for(int i = que.size()-1;i>=0;i--){
    //             Node *cur = que.front();
    //             que.pop();
    //             for(int j=0;j<cur->children.size();j++)
    //                 que.push(cur->children[j]);//根据实例可知孩子中没有null，否则可以加一个if(cur->children[j])
    //         }
    //         level++;
    //     }
    //     return level;
    // }
    /*solution2:using recursion with postorder*/
    // int getDepth(Node *node){
    //     if(node==nullptr) return 0;
    //     int depth = 0;
    //     for(int i=0;i<node->children.size();i++){
    //         depth = max(depth,getDepth(node->children[i]));
    //     }
    //     return depth+1;
    // }
    // int maxdepth(Node* root) {
    //     if(root==nullptr) return 0;
    //     return getDepth(root);
    // }
    /*solution2-2:using recursion with postorder*/
    int maxDepth(Node* root) {
        if(root==nullptr) return 0;
        int depth = 0;
        for(int i=0;i<root->children.size();i++){
            depth = max(depth,maxDepth(root->children[i]));
        }
        return depth+1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,null,3,2,4,null,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]\n
// @lcpr case=end

 */

