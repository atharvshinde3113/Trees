//brute: inorder : ascending

// optimal : traverse, every node must be in a range, 

bool solve(TreeNode* root, int low, int high){
    if(!root) return true;

    if(root->val <= low || root->val >= high) return false;

    return solve(root->left,low,root->val) && solve(root->right,root->val,high);
}

bool isValidBST(TreeNode* root) {
    return solve(root,INT_MIN,INT_MAX);
}

//use LONG_MAX LONG_MIN and typecast to long 