// inorder traversal of BST is always sorted. so sort its preorder. you now have a preorder and inorder of a BT. 1 unique BT can be created from it which will always be a BST. TC (NlogN for sort + N )	 SC (N storing inorder) 


// optimal: use the concept of ranges of a node in a BT. only upper bound required. transfer the earlier node's upper bound to suffice lower bound's condition. TC O(N) O(h)

TreeNode* solve(int& index, vector<int>& pre, int bound) {
    if (index >= pre.size() || pre[index] > bound) {
        return NULL;
    }
    TreeNode* root = new TreeNode(pre[index]);
    index++;
    root->left = solve(index, pre, root->val); // left's ub is the node itself
    root->right = solve(index, pre, bound);// right's ub is previous ub
    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i = 0;// ptr to go across
    return solve(i, preorder, INT_MAX); // root's ub = INT_MAX
} 




