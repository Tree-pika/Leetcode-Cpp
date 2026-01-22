/*
 * @lc app=leetcode.cn id=1302 lang=cpp
 * @lcpr version=30204
 *
 * [1302] 层数最深叶子节点的和
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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> que;
        if(root) que.push(root);
        int sum=0;
        while(!que.empty()){
            int size=que.size();
            sum=0;
            for(int i=0;i<size;i++){
                TreeNode*cur=que.front();
                que.pop();
                sum+=cur->val;
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
        }
        return sum;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5,null,6,7,null,null,null,null,8]\n
// @lcpr case=end

// @lcpr case=start
// [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]\n
// @lcpr case=end

 */

