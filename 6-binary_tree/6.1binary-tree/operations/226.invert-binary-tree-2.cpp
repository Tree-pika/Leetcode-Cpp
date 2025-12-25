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
/*利用遍历的思路*/
    // TreeNode* invertTree(TreeNode* root) {
    //     if(!root) return nullptr;
    //     swap(root->left,root->right);
    //     if(root->right) invertTree(root->right);
    //     if(root->left) invertTree(root->left);
    //     return root;
    // }
/*利用分解的思路：拿到子树的返回结果*/
 // 定义：将以 root 为根的这棵二叉树翻转，返回翻转后的二叉树的根节点
    TreeNode* invertTree(TreeNode* root) {
        if(root){
            TreeNode *left = invertTree(root->left);
            TreeNode *right = invertTree(root->right);

            //注意，最终是对树上的root进行操作：将交换后的左子树根节点接到root的右孩子处
            root->left = right;
            root->right = left;
        }
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

