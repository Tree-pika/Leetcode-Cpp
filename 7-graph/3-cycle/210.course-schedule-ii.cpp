/*
 * @lc app=leetcode.cn id=210 lang=cpp
 * @lcpr version=30204
 *
 * [210] 课程表 II
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
// class Solution {
// private:
//     vector<vector<int>> graph;
//     vector<bool> onPath;//检测环
//     bool hasCycle = false;
//     vector<bool> visited;//剪枝

//     vector<int> postOrder;//记录遍历结果
// public:
//     //以节点src为起点，开始遍历
//     void dfs(int src){
//         //1.环检测
//         if(onPath[src]){
//             hasCycle = true;
//             return;
//         }
//         //2.
//         if(hasCycle||visited[src]){
//             return;
//         }
//         //3.标记当前递归层的状态
//         visited[src] = true;
//         onPath[src] = true;
//         for(int neighbors:graph[src]){
//             dfs(neighbors);
//         }
//         postOrder.push_back(src);
//         onPath[src] = false;
//     }
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         build(numCourses,prerequisites);
//         onPath = vector<bool>(numCourses,false);
//         visited = vector<bool>(numCourses,false);

//         for(int i=0;i<numCourses;i++){
//             dfs(i);
//             if(hasCycle){
//                 return vector<int>();
//             }
//         }
//         reverse(postOrder.begin(),postOrder.end());
//         return postOrder;
//     }
// private:
//     void build(int numCourses, vector<vector<int>>& prerequisites){
//         graph = vector<vector<int>>(numCourses);
//         for(vector<int>&e:prerequisites){
//             int from=e[1],to=e[0];
//             graph[from].push_back(to);
//         }
//     }
// };
/*soluiton2:BFS*/
class Solution {
private:
    vector<vector<int>> graph;
    vector<int> indegree;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        build(numCourses,prerequisites);
        vector<int> res;
        queue<int> que;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                que.push(i);
            }
        }
        int count = 0;
        while(!que.empty()){
            int cur = que.front();
            que.pop();
            res.push_back(cur);
            count++;
            for(int neighbors:graph[cur]){
                if(--indegree[neighbors]==0){
                    que.push(neighbors);
                }
            }
        }
        return count==numCourses?res:vector<int>{};
    }
private:
    void build(int numCourses, vector<vector<int>>& prerequisites){
        graph = vector<vector<int>>(numCourses);
        indegree = vector<int>(numCourses,0);
        for(vector<int>&e:prerequisites){
            int from=e[1],to=e[0];
            graph[from].push_back(to);
            indegree[to]++;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n[[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[1,0],[2,0],[3,1],[3,2]]\n
// @lcpr case=end

// @lcpr case=start
// 1\n[]\n
// @lcpr case=end

 */

