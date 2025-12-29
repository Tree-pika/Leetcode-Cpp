* 核心考点就是用 DFS/BFS 算法遍历二维数组。
* 在二维数组中运用DFS搜索的步骤
  * 把二维矩阵中的每一个位置看做一个节点，这个节点的上下左右四个位置就是相邻节点，那么整个矩阵就可以抽象成一幅网状的「图」结构。
  * 遍历图的所有节点框架：由遍历二叉树的框架演变而来
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
    * 二维数组上下左右的四个位置可以看作每个节点的在图中的临边`neighbors`
  * 需要使用visited 布尔数组防止走回头路：图中可能会成环
  ```cpp
  // 二叉树遍历框架
    void traverse(TreeNode* root) {
        traverse(root->left);
        traverse(root->right);
    }

    // 二维矩阵遍历框架
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n) {
            // 超出索引边界
            return;
        }
        if (visited[i][j]) {
            // 已遍历过 (i, j)
            return;
        }

        // 进入当前节点 (i, j)
        visited[i][j] = true;

        // 进入相邻节点（四叉树）
        // 上
        dfs(grid, i - 1, j, visited);
        // 下
        dfs(grid, i + 1, j, visited);
        // 左
        dfs(grid, i, j - 1, visited);
        // 右
        dfs(grid, i, j + 1, visited);
    }
  ```
  * 也可以改写为方向数组+for循环遍历邻居的形式：
  ```cpp
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n) {
            // 超出索引边界
            return;
        }
        if (visited[i][j]) {
            // 已遍历过 (i, j)
            return;
        }

        // 进入节点 (i, j)
        visited[i][j] = true;
        // 递归遍历上下左右的节点
        for (auto &d : dirs) {
            int next_i = i + d[0];
            int next_j = j + d[1];
            dfs(grid, next_i, next_j, visited);
        }
        // 离开节点 (i, j)
    }
  ```
# 岛屿数量200
## DFS with recursion
* 关键在于如何寻找并标记「岛屿」
* 因为每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
* 所以为了不重复数到同一个岛屿，遍历到一个1之后，需要使用DFS搜索其相邻的陆地，并将陆地淹没为海水
  * DFS可以将一整块岛屿的所有陆地全部搜索出来
* 时间复杂度 (Time Complexity): 
  * $O(M \times N)$$M$ 是行数，$N$ 是列数。
  * 我们虽然有双重循环，但在 DFS 过程中，每个格子最多被访问一次（一旦变成 '0' 就不再处理）。所以总操作次数与格子总数成正比。
* 空间复杂度 (Space Complexity): $O(M \times N)$
  * 在最坏情况下（例如整个地图都是陆地），DFS 的递归调用栈深度可能达到 $M \times N$。
* 这种DFS又称为FloodFill泛洪算法
## DFS with iteration | BFS with iteration
* 也可以使用`std::stack`手动模拟DFS递归过程--iteration
  * 对照使用recursion时我们这样调用`dfs(grid,i-1,j);`，因为需要拿到本陆地块的索引，才好在上下左右四个方向去找。
  * 所以模拟栈压栈时，也需要压入索引，使用`pair<int,int>`压入坐标对即可
  * 若用的是`std::queue`手动模拟递归，则属于BFS算法
  * BFS和DFS在这道题的区别仅在于“淹没陆地（访问节点）的顺序不同。
## Union-Find
| **特性**     | **DFS / BFS (搜索)**                 | **Union-Find (并查集)**                          |
| ------------ | ------------------------------------ | ------------------------------------------------ |
| **视角**     | **第一人称视角** (身在迷宫中)        | **上帝视角** (看着地图扫描)                      |
| **目标**     | 一口气找出当前这块陆地的**所有**部分 | 只要局部有连接，就先记录下来                     |
| **遍历驱动** | 顺着**陆地形状**走                   | 顺着**坐标索引** (i++, j++) 走                   |
| **方向需求** | **4个方向** (因为陆地可能弯曲回头)   | **2个方向** (因为之前的节点已经被遍历且处理过了) |
| **处理方式** | 发现陆地 -> 彻底淹没它               | 发现陆地 -> 建立局部关系，最后自会连通           |
* 因为DFS/BFS是顺着陆地扫描，所以导致得4个方向都找
* 而UF是顺着坐标扫描，所以可知只扫描右边和下边，减少搜索次数
  * 当我们站在 (i, j) 时：
    * (i-1, j) （上面）已经被遍历过了。如果它是陆地，它当时在处理的时候，已经检查过它的“下面”（也就是现在的你）了。
    * 同理，左边也检查过你了。
    * 所以，我们只需要对“未来”的节点（右边、下边）伸出橄榄枝即可。这样可以减少一半的检查次数。
* 解题思路
  * 因为我们找的是岛屿数量，所以初始化的时候，只管“陆地” ('1')，初始化它的父亲是它自己，并且让全局的 count（岛屿计数）加 1。
  * **顺着坐标索引遍历**网格，当我们遇到一块陆地时，检查它的 “右边” 和 “下边” 的邻居。
  * 如果邻居也是陆地，调用 union 操作。
    * 可以选择union by rank
    * 或者union by size
## 695
# 封闭岛屿1254
> 相比前面，需要边界处理的

在 C++ 的网格搜索类题目中，处理边界通常有两种成熟的“设计哲学”：
- **哲学 A：先知先觉 (Pre-processing)**
  - 既然靠边的陆地都不算封闭岛屿，我们可以先遍历网格的**四条边**。
  - 如果边上是陆地 `0`，就从边缘发起 DFS，把所有与边缘相连的陆地都淹没掉（变成 `1`）。
  - **逻辑：** 剩下的 `0` 肯定都是接触不到边缘的“封闭岛屿”。
- **哲学 B：后知后觉 (Boolean DFS)**
  - 修改 `dfs` 函数，让它返回一个 `bool` 值。
  - 如果在 DFS 过程中触碰到了边界，就返回 `false`（代表不封闭）。
  - 只有当 DFS 完整结束且从未触碰边界时，才返回 `true`。
本题中需要预处理是因为：
* 可能会出现陆地从中间延伸到了边缘。你的循环在中间找到了一个 0，然后调用 dfs。这样就多算了一个岛屿。

## 1020
* 分析题意：网格中 无法 在任意次数的移动中离开网格边界的陆地单元格的数量。
  * 就是求封闭陆地的单元格数量
