
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    if ((p->val < root->val) && (q->val < root->val)) { //both p and q lie on the left
        return lowestCommonAncestor(root->left, p, q);
    }

    if ((p->val > root->val) && (q->val > root->val)) { //both p and q lie on the right
        return lowestCommonAncestor(root->right, p, q);
    }

    // niether of the above conditions are true, i.e one element lies on the left of root and one on the right, making root the LCA
    return root;
}


//same code iteratively:
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return root;

        while(root != NULL) {
            if(root->val < p->val && root->val < q->val)
                root = root->right;
            else if(root->val > p->val && root->val > q->val)
                root = root->left;
            else
                return root;
        }
        
        return root;
    }