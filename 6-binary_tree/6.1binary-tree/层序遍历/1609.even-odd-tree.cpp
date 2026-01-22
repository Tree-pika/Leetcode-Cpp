/*
 * @lc app=leetcode.cn id=1609 lang=cpp
 * @lcpr version=30204
 *
 * [1609] 奇偶树
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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> que;
        if(!root->val%2) return false;
        que.push(root);
        int level=0;
        while(!que.empty()){
            int size=que.size();
            TreeNode*prev=nullptr;
            for(int i=0;i<size;i++){
                TreeNode*cur=que.front();
                que.pop();
                if(level%2){//奇数层
                    if(cur->val%2) return false;
                    if(prev&&cur->val>=prev->val) return false;
                }else{//偶数层
                    // if(!cur->val%2) return false;
                    if(!(cur->val%2)) return false;
                    if(prev&&cur->val<=prev->val) return false;
                }
                prev = cur;
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
            level++;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,10,4,3,null,7,9,12,8,6,null,null,2]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,2,3,3,7]\n
// @lcpr case=end

// @lcpr case=start
// [5,9,1,3,5,7]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [11,8,6,1,3,9,11,30,20,18,16,12,10,4,2,17]\n
// @lcpr case=end

 */

