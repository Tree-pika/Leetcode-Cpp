/*
 * @lc app=leetcode.cn id=222 lang=cpp
 * @lcpr version=30204
 *
 * [222] 完全二叉树的节点个数
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
    /*solution1:using levelorder with iteration*/
    // int countNodes(TreeNode* root) {
    //     int count = 0;
    //     queue<TreeNode*> que;
    //     if(root) que.push(root);
    //     while(!que.empty()){
            //这里实际不需要统计当前层数，只要保证每个节点都有且仅有一次被访问到即可
    //         TreeNode* node = que.front();
    //         que.pop();
    //         count++;
    //         if(node->left) que.push(node->left);
    //         if(node->right) que.push(node->right);
    //     }
    //     return count;
    // }
    /*solution2:using recusion with post order*/
    // int getNodes(TreeNode* node){
    //     if(node==nullptr) return 0;
    //     int leftNode = getNodes(node->left);
    //     int rightNode = getNodes(node->right);
    //     return leftNode+rightNode+1;
    // }
    // int countNodes(TreeNode* root) {
    //     if(root==nullptr) return 0;
    //     return getNodes(root);
    // }
    /*solution2-2:using recusion with post order*/
    // int countNodes(TreeNode* root){
    //     if(root==nullptr) return 0;
    //     return 1+countNodes(root->left)+countNodes(root->right);
    // }
    /*solution3:make use of complete binary tree*/
    // int getNodes(TreeNode *node){
    //     if(node==nullptr) return 0;
    //     TreeNode *left = node->left;
    //     TreeNode *right = node->right;
    //     int leftDepth = 1,rightDepth = 1;
    //     while(left){
    //         left = left->left;
    //         leftDepth++;
    //     }
    //     while(right){
    //         right = right->right;
    //         rightDepth++;
    //     }
    //     if(leftDepth==rightDepth){
    //         return pow(2,leftDepth)-1;
    //     }
    //     //如果以本节点为根的树不是perfect的(即向左遍历深度!=向右遍历深度)
    //     //则告诉计算机去帮我们计算--使用递归
    //     int leftNode = getNodes(node->left);
    //     int rightNode = getNodes(node->right);
    //     return leftNode+rightNode+1;
    // }
    // int countNodes(TreeNode* root){
    //     return getNodes(root);
    // }
    /*solution3-2:using bit operation and shorten*/
    int countNodes(TreeNode *root){
        if(root==nullptr) return 0;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        int leftDepth = 0,rightDepth = 0;
        while(left){
            leftDepth++;
            left = left->left;
        } 
        while(right){
            rightDepth++;
            right = right->right;
        }
        if(leftDepth==rightDepth)
            return (2<<leftDepth)-1;
        int leftNode = countNodes(root->left);
        int rightNode = countNodes(root->right);
        return leftNode+rightNode+1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5,6]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

