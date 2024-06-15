/* o(h) tc o(h) sc
1. To insert a value 'val' into the BST, we start from the root node and traverse down the tree to find the appropriate position for insertion.
2. If the BST is empty (i.e., root is null), we create a new node with value 'val' and make it the root of the BST.
3. If the value of the current node is less than 'val', we move to the right subtree, as the value to be inserted will be greater than the current node.
4. If the value of the current node is greater than or equal to 'val', we move to the left subtree, as the value to be inserted will be less than or equal to the current node.
5. We continue this process of traversing down the tree until we reach a leaf node where we can insert the new value 'val'.
*/


TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (root->val < val) root->right = insertIntoBST(root->right, val); 
    else root->left =  insertIntoBST(root->left, val);
    return root;
}
