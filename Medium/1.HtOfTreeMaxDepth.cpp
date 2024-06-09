//height of tree / max depth 

// Brute: Level Order Traversal (BFS) but large tc and extra queue required
// sc: o(n) 

int maxdepth(TreeNode* root){
	if(!root){
		return null;
	}

	int lh = maxdepth(root->left);
	int rh = maxdepth(root->right);

	return 1+max(lh,rh); //+1 for the root node
}

// tc: sc:o(height) 

