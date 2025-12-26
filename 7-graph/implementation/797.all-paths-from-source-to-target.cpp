/*
 * @lc app=leetcode.cn id=797 lang=cpp
 * @lcpr version=30204
 *
 * [797] 所有可能的路径
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
/*similar to 257*/
private:
    vector<vector<int>> res;
    vector<int> path;
public:
    void dfs(vector<vector<int>>& graph,int src,int dest){
        
        path.push_back(src);//先添加本节点到路径中；1. 进门

        //终止条件：若路径最后一个节点等于dest目标节点，说明路径找到了；2a. 结算
        if(src==dest){
            res.push_back(path);
            path.pop_back();//回溯
            return;
        }else{//2b.找邻居
            for(int s:graph[src]){
                dfs(graph,s,dest);
            }
        }

        path.pop_back();//回溯：撤销掉本层递归节点，继续找别的路；3.出门
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph,0,graph.size()-1);
        return res;
    }
/*soluiton2:using BFS*/
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2],[3],[3],[]]\n
// @lcpr case=end

// @lcpr case=start
// [[4,3,1],[3,2,4],[3],[4],[]]\n
// @lcpr case=end

 */

