/*
 * @lc app=leetcode.cn id=124 lang=cpp
 * @lcpr version=30204
 *
 * [124] 二叉树中的最大路径和
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
    int maxPathSum(TreeNode* root) {
        maxSum = root->val;//root->val可能<0，初始化 = 0不对
        getSubtreeSum(root);
        return maxSum;
    }
private:
    int maxSum;
    // 函数含义：计算以 node 为根的子树，向父节点提供的最大单侧路径和
    int getSubtreeSum(TreeNode *node){
        if(node==nullptr) return 0;
        int leftSum = max(0,getSubtreeSum(node->left));
        int rightSum = max(0,getSubtreeSum(node->right));
        /*更新结果时，可以计算“左 + 根 + 右”这种倒 V 形路径
        （因为它不需要再向上延伸了）。*/
        maxSum = max(maxSum,node->val+leftSum+rightSum);
        return node->val+max(leftSum,rightSum);//返回给父节点时,路径要想继续向上延伸，只能选一条腿走。
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [-10,9,20,null,null,15,7]\n
// @lcpr case=end

 */

