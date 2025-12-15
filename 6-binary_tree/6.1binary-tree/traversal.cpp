/*defition of the node*/
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

/*preorder traversal*/
void traversal(TreeNode *cur,vector<int>& vec){
    if(cur==nullptr) return;
    vec.push_back(cur->val);//root
    traversal(cur->left,vec);//left
    traversal(cur->right,vec);//right

}
vector<int> preorderTraversal(TreeNode *root){
    vector<int> res;
    traversal(root,res);
    return res;
}

/*inorder traversal*/
void traversal(TreeNode *cur,vector<int>& vec){
    if(cur==nullptr) return;
    traversal(cur->left,vec);
    vec.push_back(cur->val);
    traversal(cur->right,vec);
}

vector<int> inorderTraversal(TreeNode *root){
    vector<int> res;
    traversal(root,res);
    return res;
}

/*postorder traversal*/
void traversal(TreeNode *root,vector<int>& vec){
    if(cur==nullptr) return;
    traversal(cur->left,vec);
    traversal(cur->right,vec);
    vec.push_back(cur->val);
}

vector<int> postorderTraversal(TreeNode *root){
    vector<int> res;
    traversal(root,res);
    return res;
}