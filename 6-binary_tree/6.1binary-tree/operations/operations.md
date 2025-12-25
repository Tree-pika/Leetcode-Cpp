# 226
* 反转二叉树
* ![镜像二叉树](20717714d97fa04d509e4f0525a3089efefc2ea02cc08ce92b77978e9b51f15f-Picture1.png)
* 只需要对于每一个节点，交换其左右孩子即可，至于访问节点的顺序，无所谓，但要保证同一个节点只能反转一次。
* 涉及到遍历所有节点，两种选择
  * DFS：递归法和迭代法都可以
    * 前序遍历:
      * 递归就是先处理根节点，然后接下来想要先处理左孩子，再处理右孩子，这是我需要交给计算机去做的事情，所以调用递归来完成。
      * 迭代：使用前序遍历的模板即可，处理完根节点后，还是先压栈右孩子，再压栈左孩子，确保弹栈处理时先处理的是左孩子
        * 但其实这里只要能正确遍历即可，所以先压栈左孩子也可以
    * 后序遍历
      * 递归：左->右->根，思路同前序
      * 迭代：暂时不写
    * 中序遍历
      * 需要注意因为对根节点的处理夹在处理左右节点的中间，所以会导致原来的右孩子经过这一步后被交换到左孩子，所以在第三步处理右孩子的时候，传进入的参数应该是此时root的left
  * BFS：层序遍历，迭代法
* 迭代：BFS层序遍历的思路
  * 不过可以优化的点：不需要关心当前是第几
  * 使用队列先进先出，每次用完及时pop可以保证每个节点有且仅被遍历一次

# 114|flat
* flatten 函数的签名，返回类型为 void，也就是说题目希望我们在原地把二叉树拉平成链表。
  * 这样一来，没办法通过简单的二叉树**遍历**来解决这道题了。
* 二叉树中**分解**问题的思路，对应divide and conquer的算法思维
* 原始代码
  * 
  ```cpp
  //返回：子树展平后的根节点
  TreeNode *flatSubtree(TreeNode *node){
        if(!node) return nullptr;
        TreeNode *left = nullptr,*right = nullptr;//一定要记得初始化，否则会指向随机地址

        if(node->left)  left= flatSubtree(node->left);
        if(node->right) right = flatSubtree(node->right);
        
        node->left = nullptr;
        node->right = left;
        TreeNode *tail = node;
        while(tail->right){
            tail = tail->right;//移动到左链的最后一个节点
        }
        tail->right = right;
        
        return node;
    }
    void flatten(TreeNode* root) {
        flatSubtree(root);
  }
  ```
  * 空间复杂度： $O(H)$，其中 $H$ 是树的高度，主要用于递归栈。
  * 时间复杂度：
    * 每次递归回到当前节点，都要遍历刚刚展平的左子树来寻找尾节点。如果树主要向左偏（例如像一个链表 1->2->3->4... 都在左边），对于第 $k$ 个节点，寻找尾巴需要遍历下面所有的节点。
    * 这会导致总体时间复杂度退化为 $O(N^2)$。
  * 优化：`flatSubtree`返回子树展平后的尾节点，因为是前序遍历，所以头节点的话，直接通过当前的`node`即可访问到(`node->left`/`node->right`)
    * 时间复杂度： $O(N)$。每个节点只被访问一次。
  * 
  ```cpp
  TreeNode *flatSubtree(TreeNode *node){
      if(!node) return nullptr;
      if(!node->left && !node->right) return node;//叶子节点自己就是尾巴
      
      TreeNode *left = nullptr,*right = nullptr;

      if(node->left)  left= flatSubtree(node->left);
      if(node->right) right = flatSubtree(node->right);
      
      //如果左子树非空，才做拼接
      if(left){
          left->right = node->right;
          node->right = node->left;
          node->left = nullptr;
      }//左子树为空，直接维持原来的连接状态即可
      
      if(right) return right;
      return left;
  }
  void flatten(TreeNode* root) {
      flatSubtree(root);
  }
  ```
# 654 构造最大二叉树
* 递归思路：先构造出根节点，然后递归构造出左子树和右子树，递归函数返回构造好的子树的根节点，最后将根节点与左右子树相连即可
* 本题难点在于，传递给子树用于构造的参数数组的时候，按值传递每次拷贝复制太浪费时间了，而且题目本身其实不允许按值传递
  * `TreeNode* constructMaximumBinaryTree(vector<int>& nums)`
  * 参数为非常值引用，而按值传递的参数属于临时对象，不能将临时对象绑定到non-const variable上
* 所以想到可以传递参数来作为分割数组为小数组的索引
* 这个时候需要用到变量一致性，一开始构造函数的时候，定义好自己的索引代表什么意思，本题我规定为左闭右开区间
* 然后找数组最大值时也需注意，因为数组元素题目提示为非负数，所以可以初始化为-1（不同题目不同要求）/`nums[l]`/`INT_MIN`
* 想好base case：递归到什么情况，可以开始弹栈返回了：即最大值的左边（右边）数组没有元素了
* 细节
  * 在 build 函数中，我们只会读取 nums，绝对不会修改它。
  * `const vector<int>& nums`
* 复杂度分析
  * 时间 
    * worst case：当输入数组为升序排列的时候，比如[1, 2, 3, 4, 5]
    * 最后构造的二叉树会退化为单叉的，一个链表
    * 总运算次数 = $N + (N-1) + (N-2) + ... + 1$ = $\frac{N(N+1)}{2} \approx \frac{1}{2}N^2$ = $O(N^2)$。
    * 如果数组构造出来的树是平衡的（每次最大值都在中间，把数组一分为二），那么：递归深度只有 $\log N$ 层。每一层加起来总共遍历 $N$ 个元素。总复杂度 = 层数 $\times$ 每层代价 = $O(N \log N)$。
  * 空间
    * $O(H)$，其中 $H$ 是树的高度，主要用于递归栈。

# 105
* 容易看出，preorder[preStart] = root node,根据这个root可以决定中序序列数组中，子树的索引
* 接下来关键是想清楚先序序列数组中，子树的索引如何确定，因为先序数组 = root+root的左子树的先序+root右子树的先序
  * 所以想到索引可以利用子树的大小来决定--作为偏移量
* ![alt text](4.jpg)
* 通过 for 循环遍历的方式去确定 index 效率不算高，可以进一步优化。
  * 因为题目说二叉树节点的值不存在重复，所以可以使用一个 HashMap 存储元素到索引的映射，这样就可以直接通过 HashMap 查到 rootVal 对应的 index