/*
 * @lc app=leetcode.cn id=226 lang=cpp
 * @lcpr version=30204
 *
 * [226] 翻转二叉树
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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /*solution1:using level order with BFS*/
    // TreeNode* invertTree(TreeNode* root) {
    //     queue<TreeNode*> que;
    //     if(root) que.push(root);
    //     while(!que.empty()){
    //         TreeNode* cur = que.front();
    //         que.pop();
    //         swap(cur->left,cur->right);
    //         if(cur->left) que.push(cur->left);
    //         if(cur->right) que.push(cur->right);
    //     }
    //     return root;
    // }
    /*solution2:using preorder with DFS and recursion*/
    // TreeNode* invertTree(TreeNode* root) {
    //     if(root==nullptr) return root;//函数开始弹栈出口
    //     swap(root->left,root->right);//中
    //     invertTree(root->left);//左(此时的 left 其实是原本的 right，但这不影响递归逻辑)
    //     invertTree(root->right);//右
    //     return root;//最终左子树和右子树全部调用返回后，返回最终的根节点
    // }
    /*solution3：using preorder with DFS and iteration*/
    // TreeNode* invertTree(TreeNode* root) {
    //     stack<TreeNode*> st;
    //     if(root) st.push(root);
    //     while(!st.empty()){
    //         TreeNode *cur = st.top();
    //         st.pop();
    //         swap(cur->left,cur->right);
    //         if(cur->right) st.push(cur->right);
    //         if(cur->left) st.push(cur->left);
    //     }
    //     return root;
    // }
    /*solution4:using post order with DFS and recursion*/
    // TreeNode* invertTree(TreeNode* root) {
    //     if(root==nullptr) return root;
    //     invertTree(root->left);
    //     invertTree(root->right);
    //     swap(root->left,root->right);
    //     return root;
    // }
    /*solution5:using inorder with DFS and recurion*/
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr) return root;
        invertTree(root->left);
        swap(root->left,root->right);
        invertTree(root->left);//其实就是原根节点的右子树
        return root;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,7,1,3,6,9]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

