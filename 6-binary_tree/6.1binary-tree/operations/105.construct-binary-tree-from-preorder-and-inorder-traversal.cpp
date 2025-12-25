/*
 * @lc app=leetcode.cn id=105 lang=cpp
 * @lcpr version=30204
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
//返回构造好的子树的根节点，传来构造的数组元素为左闭右闭[Start,End]
    TreeNode* build(vector<int>&preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd){
        //base case
        if(preStart>preEnd) return nullptr;
        int root_val = preorder[preStart];
        TreeNode *root = new TreeNode(root_val);

        //找到root node在inorder中的index
        // int root_idx = -1;
        // for(int i=inStart;i<=inEnd;i++){
        //     if(inorder[i]==root_val){
        //         root_idx = i;
        //         break;
        //     }
        // }
        int root_idx = valToIndex[root_val];

        int leftSize = root_idx-inStart;
        root->left = build(preorder,preStart+1,preStart+leftSize,inorder,inStart,root_idx-1);
        root->right = build(preorder,preStart+leftSize+1,preEnd,inorder,root_idx+1,inEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            valToIndex[inorder[i]] = i;
        }
        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
private:
    unordered_map<int,int> valToIndex;
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,15,7]\n[9,3,15,20,7]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */

