/*
 * @lc app=leetcode.cn id=144 lang=cpp
 * @lcpr version=30204
 *
 * [144] 二叉树的前序遍历
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
    // void traversal(TreeNode *cur,vector<int>& vec){
    //     if(cur==nullptr) return;
    //     vec.push_back(cur->val);
    //     traversal(cur->left,vec);
    //     traversal(cur->right,vec);
    // }
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     traversal(root,res);
    //     return res;
    // }
/*solution2：using iteration*/
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     stack<TreeNode*> st;
    //     if(root==nullptr) return res;
    //     st.push(root);
    //     while(!st.empty()){
    //         TreeNode *cur = st.top();
    //         st.pop();
    //         res.push_back(cur->val);
    //         if(cur->right) st.push(cur->right);
    //         if(cur->left) st.push(cur->left);
    //     }
    //     return res;
    // }
/*solution3:Morris*/
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *cur = root;
        while(cur){
            //1.没有左孩子，直接保存当前节点，并访问右孩子
            if(cur->left==nullptr){
                res.push_back(cur->val);
                cur = cur->right;
            }else{
            //2.有左孩子
                //先找到本节点的前驱节点
                TreeNode *mostRight = cur->left;
                while(mostRight->right&&mostRight->right!=cur){
                    mostRight = mostRight->right;
                }
                //2.1说明此时还没有建立线索，左子树还没遍历
                //先打印root即cur
                if(mostRight->right==nullptr){
                    mostRight->right = cur;
                    res.push_back(cur->val);
                    cur = cur->left;
                }else{
                //2.2线索已经建立，此时代表左子树已经处理完毕
                //拆桥，然后转向处理右子树
                    mostRight->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,null,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,null,8,null,null,6,7,9]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

