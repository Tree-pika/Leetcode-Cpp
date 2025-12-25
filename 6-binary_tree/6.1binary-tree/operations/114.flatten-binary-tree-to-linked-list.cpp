/*
 * @lc app=leetcode.cn id=114 lang=cpp
 * @lcpr version=30204
 *
 * [114] 二叉树展开为链表
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
//分解问题的思路：展开左边，展开右边，再连接根-左-右
//返回：子树展平后的根节点
    // TreeNode *flatSubtree(TreeNode *node){
    //     if(!node) return nullptr;
    //     TreeNode *left = nullptr,*right = nullptr;

    //     if(node->left)  left= flatSubtree(node->left);
    //     if(node->right) right = flatSubtree(node->right);

    //     node->left = nullptr;
    //     node->right = left;
    //     TreeNode *tail = node;
    //     while(tail->right){
    //         tail = tail->right;//移动到左链的最后一个节点
    //     }
    //     tail->right = right;
        
    //     return node;
    // }
    // void flatten(TreeNode* root) {
    //     flatSubtree(root);
    // }
    /*solution2*/
    //返回：子树展平后的尾节点
    TreeNode *flatSubtree(TreeNode *node){
        if(!node) return nullptr;
        if(!node->left && !node->right) return node;//叶子节点自己就是尾巴
        
        TreeNode *left = nullptr,*right = nullptr;

        if(node->left)  left= flatSubtree(node->left);
        if(node->right) right = flatSubtree(node->right);
        
        //如果左子树非空，才做拼接
        if(left){
            left->right = node->right;
            node->right = node->left;
            node->left = nullptr;
        }//左子树为空，直接维持原来的连接状态即可
        
        if(right) return right;
        return left;
    }
    void flatten(TreeNode* root) {
        flatSubtree(root);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,5,3,4,null,6]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

