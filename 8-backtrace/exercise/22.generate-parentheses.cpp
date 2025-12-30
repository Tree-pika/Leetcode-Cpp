/*
 * @lc app=leetcode.cn id=22 lang=cpp
 * @lcpr version=30204
 *
 * [22] 括号生成
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
class Solution {
// private:
//     string track;
//     vector<string> res;
//     /*目前用了left个左括号，right个右括号*/
//     void backtrack(int left,int right,int n){
//         if(track.size()==n*2){
//             res.push_back(track);
//             return;
//         }
//         /*相当于以(和)分别为root生成了一棵决策树*/
//         if(left<n){
//             track.push_back('(');
//             backtrack(left+1,right,n);
//             track.pop_back();
//         }
//         if(right<left){
//             track.push_back(')');
//             backtrack(left,right+1,n);
//             track.pop_back();
//         }

//     }
// public:
//     vector<string> generateParenthesis(int n) {
//         backtrack(0,0,n);
//         return res;
//     }
/*solution2:using dfs 框架*/
private:
    string track;
    vector<string> res;
    char choice[2]={'(',')'};//选择列表
    /*目前用了left个左括号，right个右括号*/
    void backtrack(int left,int right,int n){
        //base case
        if(track.length()==2*n){
            res.push_back(track);
            return;
        }
        /*每一层都可以选择加入左括号或者右括号*/
        for(auto c:choice){
            /*先判断选择是否合法：剪枝*/
            if(c=='('&&left>=n) continue;
            if(c==')'&&left<=right) continue;
            
            //做选择
            track.push_back(c);
            //进入下一层决策
            if(c=='('){
                backtrack(left+1,right,n);
            }
            else{
                backtrack(left,right+1,n);
            }
            //撤销选择
            track.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        backtrack(0,0,n);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

