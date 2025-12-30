# 总结
* 先学习
  * 二叉树的递归/层序遍历
  * 多叉树的递归/层序遍历 
  * 图结构的 DFS/BFS 遍历
* 分析本质
  * DFS/回溯算法的本质就是递归遍历一棵穷举树（多叉树），
    * 而多叉树的递归遍历又是从二叉树的递归遍历衍生出来的。所以我说 DFS/回溯算法的本质是二叉树的递归遍历。
  * BFS 算法的本质就是遍历一幅图
    * 图的遍历算法其实就是多叉树的遍历算法加了个 visited 数组防止死循环；
    * 多叉树的遍历算法又是从二叉树遍历算法衍生出来的。所以我说 BFS 算法的本质就是二叉树的层序遍历。
* 最短路径使用BFS
  * 最短路径，都可以类比成二叉树最小深度这类问题（寻找距离根节点最近的叶子节点）。
  * 递归遍历必须要遍历整棵树的所有节点才能找到目标节点，而层序遍历不需要遍历所有节点就能搞定，所以层序遍历适合解决这类最短路径问题。
* 总结
  * DFS/回溯/BFS 这类算法，都是暴力穷举算法
  * 本质上就是把具体的问题抽象成树结构，然后遍历这棵树进行暴力穷举，所以这些穷举算法的代码本质上就是树的遍历代码。
* 进阶提升
  * 对具体的算法问题进行抽象和转化：把具体的场景抽象成一个标准的图/树结构
  * 然后套用 BFS 算法框架进行求解。
* BFS的算法框架基于图的BFS遍历进行改造，图的BFS有三种写法，写法二(可以记录从src开始走到当前节点的步数)最常用，下面的BFS算法框架就是基于写法二改造：
```cpp
// 从 s 开始 BFS 遍历图的所有节点，且记录遍历的步数
// 当走到目标节点 target 时，返回步数
int bfs(const Graph& graph, int s, int target) {
    vector<bool> visited(graph.size(),false);
    queue<int> que;
    que.push(s);
    visited[s] = true;
    // 记录从 s 开始走到当前节点的步数
    int step = 0;
    while(!que.empty()){
        for(int i=que.size()-1;i>=0;i--){
            int cur = que.front();
            que.pop();
            cout << "visit " << cur << " at step " << step << endl;
            // 判断是否到达终点
            if (cur == target) {
                return step;
            }
            for(const Edge&e:graph[cur].neighbors){
                if(visited[e.to]){
                    continue;
                }
                que.push(e.to);
                visited[e.to] = true;
            }
        }
        step++;
    }
     // 如果走到这里，说明在图中没有找到目标节点
    return -1;
}
```
# 994腐烂的橘子
* 为什么可以用BFS解决：解决“最短路径”或“**逐层扩散**”类问题
* Off-by-one Error：`if(cnt>0) cnt--;`我们不仅要关注队列是否为空，还要关注是否有新的传染发生。更优雅的做法是：如果当前队列里还有这一轮待处理的源头，且处理完它们后还有下一轮受害者，时间才 +1。
  * 或者采取：统计新鲜橘子的数量。
  * 如果一开始 fresh_count 为 0，直接返回 0。
  * 每感染一个，fresh_count 减 1。
  * 当 fresh_count 变为 0 时，我们可以提前返回当前的 cnt，或者用来控制循环终止。