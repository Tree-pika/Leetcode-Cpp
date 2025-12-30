/*
 * @lc app=leetcode.cn id=79 lang=cpp
 * @lcpr version=30204
 *
 * [79] 单词搜索
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
private:
    int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};//choice offsets
    int m,n;
    // 从 (r,c) 开始向四周搜索，试图匹配 word[index..]，返回word是否匹配成功
    bool backtrack(vector<vector<char>>&board,const string&word,int r,int c,int index){
        //base case1:越界/当前字母不匹配
        if(r<0||r>=m||c<0||c>=n||board[r][c]!=word[index]){
            return false;
        }
        //base case2：结束条件
        if(index==word.length()-1){
            // 最后一个字符刚被匹配完，说明word全部匹配成功
            return true;
        }
        //做选择：进行标记
        char tmp = board[r][c];
        board[r][c] = '#';
        
        //word[p] 被 board[r][c] 匹配，开始向四周搜索 word[index+1..]
        for(int k=0;k<4;k++){
            //如果某一个方向找到了，立刻返回 true，不再试其他方向
            if(backtrack(board,word,r+dirs[k][0],c+dirs[k][1],index+1)){
                return true;
            }
        }
        //撤销选择
        board[r][c] = tmp;

        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                //剪枝:只有当起点字符匹配时，才开始回溯
                if(board[i][j]==word[0]){
                    if(backtrack(board, word,i, j, 0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']]\n"ABCCED"\n
// @lcpr case=end

// @lcpr case=start
// [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']]\n"SEE"\n
// @lcpr case=end

// @lcpr case=start
// [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']]\n"ABCB"\n
// @lcpr case=end

 */

