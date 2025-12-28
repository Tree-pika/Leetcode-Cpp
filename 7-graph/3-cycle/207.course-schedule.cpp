/*
 * @lc app=leetcode.cn id=207 lang=cpp
 * @lcpr version=30204
 *
 * [207] 课程表
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
//     vector<bool> onPath;
//     vector<bool> visited;
//     bool hasCycle = false;
// public:
//     //检测以src为起点，是否有环
//     void dfs(int src){
//         // 1. 优先检查正在遍历的路径中是否有环:当前递归路径中再次遇到相同节点，说明图中存在环
//         if (onPath[src]) {
//             hasCycle = true;
//             return;
//         }
        
//         // 2. 其次检查是否已经安全访问过（剪枝）
//         // 如果节点之前已经访问过，且当时没有发现环（否则早就在上面return了或hasCycle为true了），
//         // 说明从这个节点出发的所有路径都是安全的，无需再次遍历。
//         if (visited[src] || hasCycle) {
//             return;
//         }

//         // 3. 标记状态
//         visited[src] = true;
//         onPath[src] = true;

//         for(int neighbors:graph[src]){
//             dfs(neighbors);
//         }
//         // 4. 回溯：离开当前节点，将其从当前路径移除
//         onPath[src] = false;
//     }
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         visited = vector<bool>(numCourses,false);
//         onPath = vector<bool>(numCourses,false);
//         build(numCourses,prerequisites);
//         for(int i=0;i<numCourses;i++){
//             dfs(i);
//             if(hasCycle) return false;
//         }
//         return true;
//     }
// private:
//     void build(int numCourses,vector<vector<int>>& prerequisites){
//         graph = vector<vector<int>>(numCourses);
//         for(vector<int>&e:prerequisites){
//             int from = e[1],to = e[0];
//             //先修from，才能修to
//             graph[from].push_back(to);
//         }
//     }
// };
/*solution2:BFS*/
class Solution {
private:
    vector<vector<int>> graph;
    vector<int> indegree; 
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        build(numCourses,prerequisites);
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
            count++;//出队的时候，统一记录访问过的元素
            for(int neighbors:graph[cur]){
                indegree[neighbors]--;
                if(indegree[neighbors]==0){
                    que.push(neighbors);
                }
            }
        }
        return count==numCourses;
    }
private:
    void build(int numCourses,vector<vector<int>>& prerequisites){
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
// 2\n[[1,0],[0,1]]\n
// @lcpr case=end

 */

