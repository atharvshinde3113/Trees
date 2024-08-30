//any traversals of both the trees must be the same


bool isSameTree(TreeNode* p, TreeNode* q){
    // 3 Base Cases
	if(p == NULL &&  q== NULL) return true; //end reached
    if(p == NULL ||  q== NULL) return false; //1 node is null and other one isnt
    if(p->val != q->val) return false; //basic cond fails

    return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
}


