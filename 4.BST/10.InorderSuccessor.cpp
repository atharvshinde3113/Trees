// find and store inorder and do linear or binary search on it to find an ele > ele of whose successor you want to find. (BS as inorder of BST is sorted) 

// while doing the inorder find out the first value that is > given ele

//do the above step via BS:similar as finding the ceil i.e perform BS on BST -> o(h) TC o(1) SC


TreeNode* inordersuccessor(TreeNode* root, TreeNode* p){
	TreeNode* successor = NULL;
	while(root!=NULL){
		if(root->val > p->val){
			successor = root;
			root=root->left; // find a smaller successor that is also greater than p->val
		}
		else{
			root=root->right;//successor less than p->val. go right for higher val
		}
	}
	return successor;
}

//predecessor = a value that is just smaller than p->val. i.e floor
TreeNode* inorderpredecessor(TreeNode* root, TreeNode* p){
	TreeNode* predecessor = NULL;
	while(root!=NULL){
		if(root->val < p->val){
			predecessor = root;
			root=root->right; // find a larger predecessor that is also smaller than p->val
		}
		else{
			root=root->left;//predecessor larger than p->val. go left for smaller val
		}
	}
	return predecessor;
}
