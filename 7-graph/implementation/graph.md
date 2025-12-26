# 表示方法
* 一幅图是由节点 (Vertex) 和边 (Edge) 构成的，逻辑结构如下：
  * ![alt text](0.jpg)
* 「逻辑结构」和「具体实现」分开
* 「**有向无权图**」的逻辑结构就是用下面的类来表示节点，以及它连接的边
  ```cpp
  // 图节点的逻辑结构
    class Vertex {
    public:
        int id;
        std::vector<Vertex*> neighbors;
    };
  ```
* 「具体实现」用邻接表和邻接矩阵的存储方式分别如下：
  * ![alt text](2.jpg)
  * 有 V 个节点，E 条边的图
  * 邻接表很直观，我把每个节点 x 的邻居都存到一个列表里，然后把 x 和这个列表映射起来，这样就可以通过一个节点 x 找到它的所有相邻节点。
    * 空间复杂度是 O(V+E)
  * 邻接矩阵则是一个二维布尔数组，我们权且称为 matrix，如果节点 x 和 y 是相连的，那么就把 matrix[x][y] 设为 true（上图中绿色的方格代表 true）。如果想找节点 x 的邻居，去扫一圈 matrix[x][..] 就行了。
    * 空间复杂度是O($V^2$)。
* 实际问题中，图节点可能是其他类型，比如字符串、自定义类等
  * 再额外使用一个哈希表，把实际节点和整数 id 映射起来，然后就可以用邻接表和邻接矩阵存储整数 id 了。
* 对比
  * 如果一幅图的 E 远小于 $V^2$（稀疏图），那么邻接表会比邻接矩阵节省空间，反之，如果 E 接近 $V^2$（稠密图），二者就差不多了。

# 代码实现

```cpp
    /*有向无权图*/
    // 邻接表
    // graph[x] 存储 x 的所有邻居节点
    vector<vector<int>> graph;

    // 邻接矩阵
    // matrix[x][y] 记录 x 是否有一条指向 y 的边
    vector<vector<bool>> matrix;

    /*有向加权图*/
    // 邻接表
    // graph[x] 存储 x 的所有邻居节点Edge.to以及对应的权重
    struct Edge {
        int to;
        int weight;
    };

    vector<vector<Edge>> graph;

    // 邻接矩阵
    // matrix[x][y] 记录 x 指向 y 的边的权重，0 表示不相邻
    vector<vector<int>> matrix;
```

* 无向图：等同于「双向」
  * 如果连接无向图中的节点 x 和 y，把 matrix[x][y] 和 matrix[y][x] 都变成 true；
  * 邻接表也是类似的操作，在 x 的邻居列表里添加 y，同时在 y 的邻居列表里添加 x。

# 遍历方式
* 就是多叉树遍历 的延伸，主要遍历方式还是深度优先搜索（DFS）和广度优先搜索（BFS）。
* 树结构中不存在环，而图结构中可能存在环，所以我们需要标记遍历过的节点，避免遍历函数在环中死循环。
* 可以细分为遍历图的「节点」、「边」和「路径」三种场景
  * 遍历图的「节点」和「边」时，需要 visited 数组在前序位置做标记，避免重复遍历；
  * 遍历图的「路径」时，需要 onPath 数组在前序位置标记节点，在后序位置撤销标记。

## DFS
### 遍历所有节点(visited)
* 假设节点的值从0开始，升序增加
* s代表第s个节点(下标从0开始)
* visited 数组，用来记录被遍历过的节点，避免遇到环时陷入死循环。
```cpp
// 遍历图的所有节点
void traverse(const Graph& graph, int s, std::vector<bool>& visited) {
    // base case
    if (s < 0 || s >= graph.size()) {
        return;
    }
    if (visited[s]) {
        // 防止死循环
        return;
    }
    // 前序位置
    visited[s] = true;
    std::cout << "visit " << s << std::endl;
    for (const Graph::Edge& e : graph.neighbors(s)) {
        traverse(graph, e.to, visited);
    }
    // 后序位置
}
```
* 由于 visited 数组的剪枝作用，这个遍历函数会遍历一次图中的所有节点，并尝试遍历一次所有边，所以算法的时间复杂度是 O(E+V)，其中 E 是边的总数，V 是节点的总数。
* 注意这里前序位置的相关代码在 for 循环外部，因为遍历节点只需要一个节点就能记录了
  * 后续遍历所有边的时候：由于一条边由两个节点构成，所以我们需要把前序位置的相关代码放到 for 循环内部。

### 遍历所有边(二维visited)
> 此场景不常见
* 用一个二维的 visited 数组来记录遍历过的边（visited[u][v] 表示边 u->v 已经被遍历过），从而确保每条边只被遍历一次。

```cpp
// 从起点 s 开始遍历图的所有边
void traverseEdges(const Graph& graph, int s, std::vector<std::vector<bool>>& visited) {
    // base case
    if (s < 0 || s >= graph.size()) {
        return;
    }
    for (const Graph::Edge& e : graph.neighbors(s)) {
      // 如果边已经被遍历过，则跳过
      if (visited[s][e.to]) {
        continue;
      }
      // 标记并访问边
      visited[s][e.to] = true;
      std::cout << "visit edge: " << s << " -> " << e.to << std::endl;
      traverseEdges(graph, e.to, visited);
    }
}
```
* 因为需要创建二维 visited 数组，这个算法的
  * 时间复杂度是O(E+$V^2$)
    * 边只遍历一次
    * 但是边的顶点会被遍历多次
  * 空间复杂度是O($V^2$)
    * visited数组需要存每条边的两个顶点
  * 其中E 是边的数量，V 是节点的数量。
### 遍历所有路径(onPath)

 ```cpp
  // 下面的算法代码可以遍历图的所有路径，寻找从 src 到 dest 的所有路径

  // onPath 和 path 记录当前递归路径上的节点
  vector<bool> onPath(graph.size());
  list<int> path;

  void traverse(Graph& graph, int src, int dest) {
      // base case
      if (src < 0 || src >= graph.size()) {
          return;
      }
      if (onPath[src]) {
          // 防止死循环（成环）
          return;
      }
      if (src == dest) {
          // 找到目标节点
          cout << "find path: ";
          for (auto it = path.begin(); it != path.end(); it++) {
              cout << *it << "->";
          }
          cout << dest << endl;
          return;
      }

      // 前序位置
      onPath[src] = true;
      path.push_back(src);
      for (const Edge& e : graph.neighbors(src)) {
          traverse(graph, e.to, dest);
      }
      // 后序位置
      path.pop_back();
      onPath[src] = false;
  }
```
* 由起点 src 到目标节点 dest 的路径可能不止一条。我们需要一个 onPath 数组，在进入节点时（前序位置）标记为正在访问，退出节点时（后序位置）撤销标记，这样才能遍历图中的所有路径，从而找到 src 到 dest 的所有路径
  * path记录结果路径中的节点，所以当在后序位置时，说明经过此节点无法达到最终目标，就将其pop出来

## BFS
* BFS 算法一般只用来寻找最短路径，不会用来求所有路径。
  * 用DFS求所有路径
* 求最短路径的话，只需要遍历「节点」就可以了，因为按照 BFS 算法一层一层向四周扩散的逻辑，第一次遇到目标节点，必然就是最短路径。
* 图结构的广度优先搜索其实就是多叉树的层序遍历，无非就是加了一个 visited 数组来避免重复遍历节点。
* 写法一：不记录遍历步数
* 
  ```cpp
  // 图结构的 BFS 遍历，从节点 s 开始进行 BFS
  void bfs(const Graph& graph, int s) {
    vector<bool> visited(graph.size(),false);
    queue<int> que;
    que.push(s);
    visited[s] = true;

    while(!que.empty()){
      int cur = que.front();
      que.pop();
      std::cout << "visit " << cur << std::endl;

      for(const Edge& e:graph.neighbors(cur)){
        if(visited[e.io]){
          continue;
        }
        visited[e.to] = true;
        que.push(e.to);
      }
    }
  }
  ```
* 再访问本节点的边，从而访问邻居节点的时候，确保邻居节点之前没有被访问过，再加入到队列中
* 然后加入节点进入队列后，立马给其visited设为true，所以队列中都是可以访问但是已经访问标记已经被设置为已访问的节点
* 写法二：记录遍历步数
* 
  ```cpp
  // 从 s 开始 BFS 遍历图的所有节点，且记录遍历的步数
  void bfs(const Graph& graph, int s) {
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
        visited[cur] = true;
        for(const Edge&e:graph.neighbors(cur)){
          if(visited[e.to]){
            continue;
          }
          que.push(e.to);
          visited[e.to] = true;
        }
      }
      step++;
    }
  }
  ```
  * step 变量记录了从起点 s 开始的遍历步数，对于无权图来说，相当于每条边的权重都是 1，这个变量就可以辅助我们判断最短路径。
* 写法三：适配不同权重边的写法。
* 
  ```cpp
  // 图结构的 BFS 遍历，从节点 s 开始进行 BFS，且记录遍历步数（从起点 s 到当前节点的边的条数）
  // 每个节点自行维护 State 类，记录从 s 走来的遍历步数
  class State {
  public:
      // 当前节点 ID
      int node;
      // 从起点 s 到当前节点的遍历步数
      int step;

      State(int node, int step) : node(node), step(step) {}
  };

  void bfs(const Graph& graph, int s) {
    vector<bool> visited(graph.size(),false);
    queue<State> que;
    que.push(State(s,0));
    visited[s]=true;
    while(!que.empty()){
      State cur = que.front();
      que.pop();
      int id = cur.node;
      int step = cur.step;
      cout << "visit " << id << " with step " << step << endl;
      for(const Edge&e:graph.neighbors(id)){
        if(visited[e.to]){
          continue;
        }
        que.push(State(e.to,step+1));
        visited[e.to] = true;
      }
    }
  }
* State.step 变量记录了从起点 s 到当前节点的最少步数（边的条数）。
* 加权图来说，每条边可以有不同的权重，题目一般会让我们计算从 src 到 dest 的权重和最小的路径。
  * 需要修改上面的代码，将步数换为对应的权重

## 总结DFS
1. **遍历所有节点 (Traverse Nodes)：**
   - **核心思想：** “地毯式搜索”。
   - **目的：** 确保图中的每一个节点都被访问一次，且仅被访问一次。
   - **类比：** 就像你去游乐园，你想玩遍所有的项目，玩过的项目盖个章（`visited`），下次看到盖过章的就不进去了。
2. **遍历所有边 (Traverse Edges)：**
   - **核心思想：** “穷举连线”。
   - **目的：** 确保每条连接线都被走过。注意，一个节点可能会被经过多次（因为它连接了多条边），但每条边只能走一次。
   - **类比：** 就像邮递员送信，他可能多次经过同一个十字路口（节点），但他必须走过每一条街道（边）来投递信件。
3. **遍历所有路径 (Traverse Paths)：**
   - **核心思想：** “回溯搜索（Backtracking）”。
   - **目的：** 寻找从 A 到 B 的所有可能走法。
   - **关键点：** 这不再是简单的“路过”，而是“尝试”。如果不通，或者找到一条路后，我们需要**撤销**刚才的选择，退回到上一步，去尝试别的路。这就是为什么会有“后序位置”撤销操作的原因。

------
#### 1. `visited` 数组

- **作用：** 记录**全局**历史。
- **含义：** “这个节点在**整个程序运行期间**，是否曾经被访问过？”
- **生命周期：** 一旦变为 `true`，通常永远不会变回 `false`（除非在多连通分量遍历的外部重置，但在单次 DFS 中不重置）。
- **为什么需要它：** 主要用于**场景一（遍历节点）**。如果图中有环（Cycle），没有 `visited` 数组，你的程序会在环里无限打转，导致栈溢出（Stack Overflow）。

#### 2. `onPath` 数组

- **作用：** 记录**当前**递归路径。
- **含义：** “在这个**当前的递归链条**（正在进行的路径探索）中，这个节点是否正在被占用？”
- **生命周期：** 这是一个动态的状态。进入节点时（前序）设为 `true`，离开节点回溯时（后序）必须**撤销**，设回 `false`。
- **为什么需要它：** 主要用于**场景三（寻找路径）**。
  - 我们在寻找路径时，允许“在这个路径选了节点A，在另一个路径也选节点A”。
  - 但是，**绝不允许**“在同一条路径中两次经过节点A”，因为这意味着兜圈子（成环）了，路径永远走不到终点。
  - 所以 `onPath` 是为了防止**当前路径**成环，而不是防止节点被重复利用。

#### 3. `path` 数组

- **作用：** 记录**结果**快照。
- **含义：** “如果我现在找到了终点，我该如何打印出我是怎么来的？”
- **实现细节：** 它通常是一个 `std::vector` 或 `std::list`。
  - **入栈：** 当你决定“尝试”走这个节点时（前序），把它加入 `path`。
  - **出栈：** 当你发现这条路走不通，或者已经找完这条路需要回退时（后序），把它从 `path` 中移除（`pop_back`）。
- **关系：** `path` 里的内容，通常就是 `onPath` 为 `true` 的那些节点（按顺序排列）。

------

# 797 & 257
| **特性**                 | **LeetCode 797 (图)**                                        | **LeetCode 257 (原写法)**                                    | **LeetCode 257 (重构后)**                                    |
| ------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| **适用场景**             | **N叉结构** (图/多叉树) 子节点数量不固定                     | **二叉结构** (二叉树) 左右孩子明确                           | **二叉结构** (尝试统一风格) 强行套用图的逻辑                 |
| **入栈时刻** (`push`)    | 函数刚开始，加入 `src`                                       | 函数刚开始，加入 `node`                                      | 函数刚开始，加入 `node`                                      |
| **出栈时刻** (`pop`)     | **函数即将结束前** (Loop 循环外面)                           | **子递归返回后立即执行** (If 语句块内部)                     | **函数即将结束前** (If-Else 结构外面)                        |
| **谁负责清理现场**       | **自己负责** “我进来了，我走了，把自己删掉”                  | **父节点负责** “刚才把孩子送进去了，孩子回来了，我把孩子删掉” | **自己负责** “我进来了，我走了，把自己删掉”                  |
| **代码结构特征**         | **对称闭环** `push` 和 `pop` 在同一缩进层级                  | **三明治结构** `push`... `recurse`... `pop`                  | **对称闭环** `push` 和 `pop` 在同一缩进层级                  |
| **对 `return` 的容忍度** | **低** 中间随意 `return` 会导致没运行到 `pop`                | **高** 子函数随便 `return`，父节点保证清理                   | **低** 必须小心控制流，不能跳过底部的 `pop`                  |
| **典型伪代码**           | `cpp void dfs(u){ path.push(u); for(v:adj) dfs(v); path.pop(); } ` | `cpp void dfs(root){ path.push(root); if(L) {dfs(L); pop();} if(R) {dfs(R); pop();} } ` | `cpp void dfs(root){ path.push(root); if(Leaf) record(); else {dfs(L); dfs(R);} path.pop(); } ` |