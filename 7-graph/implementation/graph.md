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
    // graph[x] 存储 x 的所有邻居节点以及对应的权重
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
* s代表第s个节点(从0开始)
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
  * 空间复杂度是O($v^2$)
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

## BFS
* BFS 算法一般只用来寻找那条最短路径，不会用来求所有路径。
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