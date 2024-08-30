// max path sum which traversable path in tree form 1 node to other returns the max sum

//Brute: go through all combinations and see where max sum is found

// sum of path at a node = val at node youre at + sum of left subtree+ sum of right subtree
// use above formula for every node to find max path across any node

// o(n),o(height of tree)

int solve(TreeNode* root, int& maxi){
	if(!root) return 0;

	int leftsum = max(0,solve(root->left, maxi));  // max(0,) is done to ignore and not selecting negative nodes thereby increasing sum
	int rightsum = max(0,solve(root->right, maxi));
	maxi = max(maxi,root->val+leftsum+rightsum);

	return root->val+max(leftsum,rightsum); // This is done to pick/select a path which will yeild higher sum
}


int maxPathSum(TreeNode* root) {
	int maxi =0;
	solve(root,maxi);
	return maxi;	

}