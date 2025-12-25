/*
 * @lc app=leetcode.cn id=538 lang=cpp
 * @lcpr version=30204
 *
 * [538] 把二叉搜索树转换为累加树
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
/*先想到BST中序遍历可以得到升序数组，但是本题需要计算所有大于等于自己的值
也就是计算升序数组中所有位于自己右边的值（并不是从数组头开始，不好计算），于是想到可以右->根->左遍历，
得到降序数组，这样就是从头开始加，加到自己这就行*/
    void dfs(TreeNode *node){
        if(node==nullptr) return;
        dfs(node->right);
        //中序位置
        sum+=node->val;
        node->val = sum;

        dfs(node->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }
private:
    int sum = 0;//全局变量，每次调用不断变化
};
// @lc code=end



/*
// @lcpr case=start
// [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]\n
// @lcpr case=end

// @lcpr case=start
// [0,null,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4,1]\n
// @lcpr case=end

 */

