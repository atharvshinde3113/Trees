/* whether it forms a mirror around its centre or not

Mirror property is    left == right and right == left
pre-order traversal on root->left subtree, (root, left, right)
modified pre-order traversal on root->right subtree, (root, right, left) 
compare the node vals if they are the same 
Do both traversals at the same time
if left is null or right is null, then both sides must match and return true (base case)

*/

bool isMirror(TreeNode* node1, TreeNode* node2) {
    if (!node1 && !node2)  return true;
    if (!node1 || !node2) return false;
    if (node1->val != node2->val) return false;
    return isMirror(node1->left, node2->right) && isMirror(node1->right, node2->left);
}

bool isSymmetric(TreeNode* root) {
    return isMirror(root->left, root->right);
}
