/*
 * @lc app=leetcode.cn id=145 lang=cpp
 * @lcpr version=30204
 *
 * [145] 二叉树的后序遍历
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
    //     traversal(cur->left,vec);
    //     traversal(cur->right,vec);
    //     vec.push_back(cur->val);
    // }
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     traversal(root,res);
    //     return res;
    // }
/*solution2:using iteration*/
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     stack<TreeNode *> st;
    //     if(root==nullptr) return res;
    //     st.push(root);
    //     while(!st.empty()){
    //         TreeNode *cur = st.top();
    //         st.pop();
    //         res.push_back(cur->val);
    //         if(cur->left) st.push(cur->left);
    //         if(cur->right) st.push(cur->right);
    //     }//root->right->left
    //     reverse(res.begin(),res.end());
    //     return res;
    // }
/*solution3:Morris*/
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *cur = root;
        while(cur){
            //1.没有右孩子，直接保存当前节点，并访问左孩子
            if(cur->right==nullptr){
                res.push_back(cur->val);
                cur = cur->left;
            }else{
            //2.有右孩子
                //先找右子树的最左节点,本节点需要连接的前驱节点
                TreeNode *mostLeft = cur->right;
                while(mostLeft->left&&mostLeft->left!=cur){
                    mostLeft = mostLeft->left;
                }
                //2.1说明此时还没有建立线索，右子树还没遍历
                //先打印root即cur
                if(mostLeft->left==nullptr){
                    mostLeft->left = cur;
                    res.push_back(cur->val);
                    cur = cur->right;//开始遍历右子树
                }else{
                    //2.2线索已经建立，此时代表右子树已经处理完毕
                //拆桥，然后转向处理左子树
                    mostLeft->left = nullptr;
                    cur = cur->left;
                }
            }
        }
        reverse(res.begin(),res.end());
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

