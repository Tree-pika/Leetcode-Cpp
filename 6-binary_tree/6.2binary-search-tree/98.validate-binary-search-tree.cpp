/*
 * @lc app=leetcode.cn id=98 lang=cpp
 * @lcpr version=30204
 *
 * [98] 验证二叉搜索树
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
/*使用辅助函数，增加函数参数列表，在参数中携带额外信息，把 root 的约束传递给左右子树:
该函数返回 以root 为根的子树的所有节点是否满足 max->val > root->val > min->val(一路向上判断)
*/  
    bool isValidHelper(TreeNode* root,TreeNode* min,TreeNode*max){
        if(root==nullptr) return true;
        if((min&&min->val>=root->val)||(max&&max->val<=root->val)){
            return false;
        }
        //根据定义，限定左子树的最大值是 root->val，右子树的最小值是 root->val
        return isValidHelper(root->left,min,root)&&isValidHelper(root->right,root,max);
    }
    bool isValidBST(TreeNode* root) {
        return isValidHelper(root,nullptr,nullptr);//对于root来说，无祖先，所以大小没有限制
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,4,null,null,3,6]\n
// @lcpr case=end

 */

