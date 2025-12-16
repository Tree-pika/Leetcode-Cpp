/*
 * @lc app=leetcode.cn id=94 lang=cpp
 * @lcpr version=30204
 *
 * [94] 二叉树的中序遍历
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
    //     vec.push_back(cur->val);
    //     traversal(cur->right,vec);
    // }
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     traversal(root,res);
    //     return res;
    // }
/*solution2:using iteration*/
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     stack<TreeNode *> st;
    //     TreeNode *cur = root;
    //     // 只要指针不为空（还有节点没探索），
    //     // 或者栈不为空（还有节点没打印），就继续循环
    //     while(cur!=nullptr||!st.empty()){
    //         //指针访问并压栈（寻找左路尽头）
    //         if(cur!=nullptr){
    //             st.push(cur);
    //             cur = cur->left;
    //         }else{
    //             //回溯并转向右路
    //             // curr == NULL 说明左路走到头了。
    //         // 此时栈顶元素就是要找的“最左”的节点
    //         // （或者是左子树已经处理完的根节点）。
    //             cur = st.top();
    //             st.pop();
    //             res.push_back(cur->val);
    //             // 中序遍历是 左->根->右。
    //         // 左边（NULL）处理完了，根（curr）打印完了，现在该去处理右边了。
    //             cur = cur->right;
    //         }
    //     }
    //     return res;
    // }
/*solution3:using Morris*/
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *cur = root;
        while(cur){
            //1、没有左孩子，直接处理当前节点，并转向右边
            if(cur->left==nullptr){
                res.push_back(cur->val);
                cur = cur->right;
            }else{
            //2、如果有左孩子，先找到左子树的最右节点 (前驱)
                TreeNode *rightMost = cur->left;
                while(rightMost->right && rightMost->right!=cur){
                    rightMost = rightMost->right;
                }
                //2.1 还没建立线索 (第一次访问前驱)
                if(rightMost->right==nullptr){
                    rightMost->right = cur;// 建立线索: 前驱指向当
                    cur = cur->left;// 继续向左遍历
                }else{
                //2.2 线索已存在 (第二次访问，说明左子树都跑完了)
                    rightMost->right = nullptr;// 剪断线索: 恢复树结构
                    res.push_back(cur->val);//回到根了，记录数值
                    cur = cur->right;// 左边搞定，根搞定，转向右边
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
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

