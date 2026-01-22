/*
 * @lc app=leetcode.cn id=662 lang=cpp
 * @lcpr version=30204
 *
 * [662] 二叉树最大宽度
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
class State{
    public:
        TreeNode* node;
        unsigned long long id;//ULL防止overflow
        State(TreeNode*node,unsigned long long id):node(node),id(id){}
};
public:
    //遍历，二叉树的问题不方便用递归就想想迭代BFS;
    //BFS写法三
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long maxWidth=0;
        queue<State> que;
        if(root) que.push(State(root,1));
        while(!que.empty()){
            int size=que.size();
            unsigned long long start=0,end=0;
            unsigned long long base=que.front().id;//
            for(int i=0;i<size;i++){
                State tmp=que.front();
                que.pop();
                TreeNode* cur=tmp.node;
                unsigned long long curId=tmp.id-base;//
                if(cur->left) que.push(State(cur->left,curId*2));
                if(cur->right) que.push(State(cur->right,curId*2+1));
                if(i==0) start=curId;
                if(i==size-1) end = curId;
            }
            maxWidth = max(maxWidth,end-start+1);
        }
        return maxWidth;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,2,5,3,null,9]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,2,5,null,null,9,6,null,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,2,5]\n
// @lcpr case=end

 */

