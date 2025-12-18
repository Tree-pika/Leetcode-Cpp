/*
 * @lc app=leetcode.cn id=104 lang=cpp
 * @lcpr version=30204
 *
 * [104] 二叉树的最大深度
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
    // int maxDepth(TreeNode* root) {
    //     queue<TreeNode*> que;
    //     if(!root) return 0; 
    //     que.push(root);
    //     int level = 0;
    //     while(!que.empty()){
    //         for(int i=que.size()-1;i>=0;i--){
    //             TreeNode* root = que.front();
    //             que.pop();
    //             if(root->left) que.push(root->left);
    //             if(root->right) que.push(root->right);
    //         }
    //         level++;
    //     }
    //     return level;
    // }
    /*solution2:using recursion with postorder searching height*/
    // int getDepth(TreeNode* node){
    //     if(node==nullptr) return 0;
    //     int leftDepth = getDepth(node->left);//left
    //     int rightDepth = getDepth(node->right);//right
    //     int maxDepth = max(leftDepth,rightDepth)+1;//root
    //     return maxDepth;
    // }
    // int maxDepth(TreeNode* root) {
    //     if(root==nullptr) return 0;
    //     return getDepth(root);
    // }
    /*solution2-2:using recursion*/
    // int maxDepth(TreeNode* root) {
    //     if(root==nullptr) return 0;
    //     return 1+max(maxDepth(root->left),maxDepth(root->right));
    // }
    /*solution3:using recursion with preorder searching for depth*/

};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2]\n
// @lcpr case=end

 */

