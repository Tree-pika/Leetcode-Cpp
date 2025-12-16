/*
 * @lc app=leetcode.cn id=102 lang=cpp
 * @lcpr version=30204
 *
 * [102] 二叉树的层序遍历
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
    // vector<vector<int>> levelOrder(TreeNode* root) {
    //     vector<vector<int>> res;
    //     queue<TreeNode*> que;
    //     if(root) que.push(root);
    //     while(!que.empty()){
    //         //提前获取本层的大小，因为后期遍历本层时需要将下一层的子节点push到queue中
    //         //即queue的大小后期会变化
    //         //或者int i = que.size();i--也可以
    //         int size = que.size();
    //         vector<int> tmp;
    //         for(int i=0;i<size;i++){
    //             TreeNode *root = que.front();
    //             tmp.push_back(root->val);
    //             if(root->left) que.push(root->left);
    //             if(root->right) que.push(root->right);
    //             que.pop();
    //         }
    //         res.push_back(tmp);
    //     }
    //     return res;
    // }
    /*solution2:using DFS*/
    void dfs(TreeNode *node,vector<vector<int>>& res,int level){
        if(node==nullptr) return;
        //第一次到达本层
        if(level==res.size()){
            res.push_back(vector<int>());
        }
        res[level].push_back(node->val);
        dfs(node->left,res,level+1);
        dfs(node->right,res,level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root,res,0);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

