* 多叉树结构就是二叉树结构 的延伸，二叉树是特殊的多叉树。
* 多叉树的遍历就是二叉树遍历 的延伸。
* 森林是指多个多叉树的集合，单独一棵多叉树是一个特殊的森林。，用代码表示就是多个多叉树的根节点列表，类似这样：`List<Node> forest;`
  * 只需对每个根节点分别进行 DFS/BFS 遍历，即可遍历森林的所有节点。
  * 在并查集Union Find算法中，我们会同时持有多棵多叉树的根节点，那么这些根节点的集合就是一个森林。
* 节点定义
  ```cpp
    class Node {
    public:
        int val;
        vector<Node*> children;
    };
# 多叉树的遍历
* 递归遍历（DFS）和层序遍历（BFS）两种
* DFS
  ```cpp
  // 二叉树的遍历框架
    void traverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        // 前序位置
        traverse(root->left);
        // 中序位置
        traverse(root->right);
        // 后序位置
    }

    // N 叉树的遍历框架
    void traverse(Node* root) {
        if (root == nullptr) {
            return;
        }
        // 前序位置
        for (Node* child : root->children) {
            traverse(child);
        }
        // 后序位置
    }
* 多叉树没有了中序位置，因为可能有多个节点嘛，所谓的中序位置也就没什么意义了。
# BFS
> 对应二叉树层序遍历/BFS的三种写法
* 写法一：无法记录节点深度
  ```cpp
  void levelOrderTraverse(Node* root) {
    if (root == nullptr) {
        return;
    }
    std::queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();
        // 访问 cur 节点
        std::cout << cur->val << std::endl;

        // 把 cur 的所有子节点加入队列
        for (Node* child : cur->children) {
            q.push(child);
        }
    }
  }
* 写法二：能够记录节点深度
  ```cpp
    #include <iostream>
    #include <queue>
    #include <vector>

    void levelOrderTraverse(Node* root) {
        if (root == nullptr) {
            return;
        }
        std::queue<Node*> q;
        q.push(root);
        // 记录当前遍历到的层数（根节点视为第 1 层）
        int depth = 1;

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                Node* cur = q.front();
                q.pop();
                // 访问 cur 节点，同时知道它所在的层数
                std::cout << "depth = " << depth << ", val = " << cur->val << std::endl;

                for (Node* child : cur->children) {
                    q.push(child);
                }
            }
            depth++;
        }
    }
* 写法三：适配不同权重边的写法
  ```cpp
    // 多叉树的层序遍历
    // 每个节点自行维护 State 类，记录深度等信息
    class State {
    public:
        Node* node;
        int depth;

        State(Node* node, int depth) : node(node), depth(depth) {}
    };

    void levelOrderTraverse(Node* root) {
        if (root == nullptr) {
            return;
        }
        std::queue<State> q;
        // 记录当前遍历到的层数（根节点视为第 1 层）
        q.push(State(root, 1));

        while (!q.empty()) {
            State state = q.front();
            q.pop();
            Node* cur = state.node;
            int depth = state.depth;
            // 访问 cur 节点，同时知道它所在的层数
            std::cout << "depth = " << depth << ", val = " << cur->val << std::endl;

            for (Node* child : cur->children) {
                q.push(State(child, depth + 1));
            }
        }
    }
