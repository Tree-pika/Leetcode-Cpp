/*
 * @lc app=leetcode.cn id=543 lang=cpp
 * @lcpr version=30204
 *
 * [543] 二叉树的直径
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
private:
    int diameter=0;
public:
    //分解问题；返回以root为根的最大深度
    //新开函数是因为需要利用depth这个返回值，而不是diameter这个返回值(不具备子问题结构)
    int maxDepth(TreeNode* root){
        if(!root) return 0;
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        diameter = max(diameter,left+right);

        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);//返回的不是diameter，所以不需要接收这个返回值，将其当作纯遍历的函数调用
        return diameter;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */

