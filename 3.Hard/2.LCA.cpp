// path of node A = { } path of node B ={ } last element that matched = LCA
// derive path via RootToNodePath


//goes to the leftmost first then the right next

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return NULL;

    //if node is found while traversing, directly return it ("a node is a descendent of itself")
    if (root->val == p->val || root->val == q->val) return root;

    //search for left and right subtrees
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);


    // at a node, if you get a null and a not null , take and return the not null
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    //return root will be executed when if (!lef) and if (!rig) fail. i.e a node has not null values returned to it from both sides, making it the LCA
    return root;
}
