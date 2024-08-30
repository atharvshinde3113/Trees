//diameter of tree

//longest path between any 2 nodes. it need not to pass through root

int solve(TreeNode* root, int& maxi){
	if(!root) return 0;
	int lh = solve(root->left);
	int rh = solve(root->right);
	maxi = max(maxi,lh+rh);
	return 1+max(rh,lh);
} 

int diameter(TreeNode* root){
	int maxi = 0;
	solve(root,maxi);
	return maxi;
}
