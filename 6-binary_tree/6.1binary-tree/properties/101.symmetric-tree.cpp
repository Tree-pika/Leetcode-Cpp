/*
 * @lc app=leetcode.cn id=101 lang=cpp
 * @lcpr version=30204
 *
 * [101] 对称二叉树
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
    //比较节点的左子树和右子树是否对称：left->left == right->right
    bool compare(TreeNode *left,TreeNode *right){
        //final condition：遍历过程中遇到不满足条件的直接提前终止下面的判断，返回false
        if(!left&&!right) return true;
        else if(!left&&right) return false;
        else if(left&&!right) return false;
        else if(left->val!=right->val) return false;//比较左右子树的值是否相等
        
        //下面是基于本层的校验通过(left->val=right->val)的情形：
        //指派计算机去比较root的左右子树在下层的内外侧是否对称
        bool inside = compare(left->right,right->left);
        bool outside = compare(left->left,right->right);
        return inside&&outside;//只有左右子树的内外侧都对称才返回true
    }
    bool isSymmetric(TreeNode* root) {
        // if(root==nullptr) return true;
        return compare(root->left,root->right);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2,3,4,4,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,null,3,null,3]\n
// @lcpr case=end

 */

