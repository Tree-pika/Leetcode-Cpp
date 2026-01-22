/*
 * @lc app=leetcode.cn id=103 lang=cpp
 * @lcpr version=30204
 *
 * [103] 二叉树的锯齿形层序遍历
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
    //遍历
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> que;
        if(root) que.push(root);
        int depth=0;
        while(!que.empty()){
            int size=que.size();
            vector<int> tmp;
            for(int i=0;i<size;i++){
                TreeNode*t = que.front();
                que.pop();
                tmp.push_back(t->val);
                if(t->left) que.push(t->left);
                if(t->right) que.push(t->right);
            }
            if(depth%2) reverse(tmp.begin(),tmp.end());
            res.push_back(tmp);
            depth++;
        }
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

