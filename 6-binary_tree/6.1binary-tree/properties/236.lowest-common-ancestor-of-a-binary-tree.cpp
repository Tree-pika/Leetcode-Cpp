/*
 * @lc app=leetcode.cn id=236 lang=cpp
 * @lcpr version=30204
 *
 * [236] 二叉树的最近公共祖先
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
//查找当前以node为根的子树是否都包含p和q
    TreeNode* find(TreeNode *node,int val1,int val2){
        //base case;
        if(node==nullptr) return nullptr;
        if(node->val==val1||node->val==val2){
            return node;
        }

        TreeNode* left = find(node->left,val1,val2);
        TreeNode *right = find(node->right,val1,val2);
        //题目规定所有 Node->val 互不相同
        if(left&&right){
            //说明左右子树各找到一个
            return node;
        }
        //若不是分别在左右子树中找到，说明都在一边子树中
        return left==nullptr?right:left;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return find(root,p->val,q->val);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n1\n
// @lcpr case=end

// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n4\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n2\n
// @lcpr case=end

 */

