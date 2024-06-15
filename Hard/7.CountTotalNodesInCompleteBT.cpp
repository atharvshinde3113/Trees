// Do any traversal and cnt++. o(n) and o(h)
    void inorder(TreeNode* root,int &cnt){
        if(!root) return;
        cnt++;
        inorder(root->left,cnt);
        inorder(root->right,cnt);
    }
    int countNodes(TreeNode* root) {
        int cnt = 0;
        inorder(root,cnt);
        return cnt;
    }

-----------------
/*"Complete" Tree. use a property of it: all levels are completely filled (either 0 or 2 childern)
 ht of tree = h. nodes = (2^h) - 1 

1. First, we calculate the height of the left and right subtrees starting from the root.
2. If the height of the left subtree is equal to the height of the right subtree, it means that the last level is completely filled, and the number of nodes in the tree is 2^h - 1, where h is the height of the tree.
3. If the heights are not equal, it means that the last level is not completely filled. In this case, we recursively calculate the number of nodes in the left and right subtrees and add 1 (for the root node) to get the total number of nodes in the tree.
*/
int leftHeight(TreeNode* root) {
    int h = 1;
    while (root) {
        h++;
        root = root->left;
    }
    return h;
}

int rightHeight(TreeNode* root) { //atmax youll traverse logN nodes
    int h = 1;
    while (root) {
        h++;
        root = root->right;
    }
    return h;
}

int countNodes(TreeNode* root) {
    if (!root) return 0;
    int lh = leftHeight(root->left);
    int rh = rightHeight(root->right);
    if (lh == rh)
        return pow(2, lh) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
//tc: o((logn)^2) 1 log n for traversing nodes(node->left till !node) 1 logn for finding ht countNode(node->left).
// sc: o(ht) = o(log n)