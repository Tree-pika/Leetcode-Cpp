/*
 * @lc app=leetcode.cn id=654 lang=cpp
 * @lcpr version=30204
 *
 * [654] 最大二叉树
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
//利用数组元素[l,r)构造子树,返回构造好的子树的根节点
    TreeNode* build(const vector<int>&nums,int l,int r){
        //base case
        if(l>=r) return nullptr;//这样确保后续找到的max_val一定是有效的，则构造的root才是有意义的

        int max_val = nums[l];
        int max_idx = l;
        for(int i=l;i<r;i++){
            if(nums[i]>max_val){
                max_idx = i;
                max_val = nums[i];
            }
        }
        TreeNode *root = new TreeNode(max_val);
        root->left = build(nums,l,max_idx);
        root->right = build(nums,max_idx+1,r);

        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums,0,nums.size());
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,1,6,0,5]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1]\n
// @lcpr case=end

 */

