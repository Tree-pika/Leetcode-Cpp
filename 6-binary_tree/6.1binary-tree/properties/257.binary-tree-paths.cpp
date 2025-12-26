/*
 * @lc app=leetcode.cn id=257 lang=cpp
 * @lcpr version=30204
 *
 * [257] 二叉树的所有路径
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
    // void traversal(TreeNode *node,vector<int>&path,vector<string>&res){
    //     path.push_back(node->val);//leaf node或者是middle node都是root，最先处理
    //     //终止条件：函数弹栈开始时
    //     if(!node->left&&!node->right){
    //         string tmp;
    //         for(int i=0;i<path.size()-1;i++){
    //             tmp+=to_string(path[i]);
    //             tmp+="->";
    //         }
    //         tmp+=to_string(path.back());
    //         res.push_back(tmp);
    //         return;
    //     }
    //     //普通的单层递归逻辑
    //     if(node->left){//left
    //         traversal(node->left,path,res);
    //         path.pop_back();//单层实际添加到路径中的就一个middle node，所以递归回来只需要pop一次即可
    //     }
    //     if(node->right){//right
    //         traversal(node->right,path,res);
    //         path.pop_back();
    //     }
    //     path.pop_back();
    // }
    // vector<string> binaryTreePaths(TreeNode* root) {
    //     vector<int> path;
    //     vector<string> res;
    //     traversal(root,path,res);
    //     return res;
    // }
/*solution1-2:类比797，统一在本层回溯*/
    // void traversal(TreeNode *node,vector<int>&path,vector<string>&res){
    //     path.push_back(node->val);//leaf node或者是middle node都是root，最先处理
    //     //终止条件：函数弹栈开始时
    //     if(!node->left&&!node->right){
    //         string tmp;
    //         for(int i=0;i<path.size()-1;i++){
    //             tmp+=to_string(path[i]);
    //             tmp+="->";
    //         }
    //         tmp+=to_string(path.back());
    //         res.push_back(tmp);
    //     }
    //     //普通的单层递归逻辑
    //     if(node->left){//left
    //         traversal(node->left,path,res);
    //     }
    //     if(node->right){//right
    //         traversal(node->right,path,res);
    //     }
    //     path.pop_back();//前后呼应，回撤的是本层添加的root node
    // }
    // vector<string> binaryTreePaths(TreeNode* root) {
    //     vector<int> path;
    //     vector<string> res;
    //     traversal(root,path,res);
    //     return res;
    // }
    /*solution2:pass by value and hide the backtrace in calling function*/
    // vector<string> binaryTreePaths(TreeNode* root) {
    //     vector<string> res;
    //     auto dfs = [&](this auto &&dfs,TreeNode*node,string path)->void{
    //         path+=to_string(node->val);
            
    //         if(!node->left&&!node->right){
    //             res.push_back(path);
    //             return;
    //         }
    //         path+="->";
    //         if(node->left) dfs(node->left,path);
    //         if(node->right) dfs(node->right,path);
    //     };

    //     dfs(root,"");//题目保证root非空
    //     return res;
    // }
/*solution2-2:利用系统栈+值传递实现隐式回溯*/
    void traversal(TreeNode *node,string path,vector<string>&res){
        path+=to_string(node->val);
        if(!node->left&&!node->right){
            res.push_back(path);
        }
        if(node->left) traversal(node->left,path+"->",res);
        if(node->right) traversal(node->right,path+"->",res);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string path;
        traversal(root,path,res);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,null,5]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

