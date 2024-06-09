//tree is balanced if ht(left subtree) - ht(right subtree) <=1

---------------------------
//Brute: 
bool check(TreeNode* root){
	if(!node) return true;

	int lh = findht(root->left);
	int rh = findht(root->right);

	if(abs(lh-rh)>1) return false;

	bool left = check(node->left);
	bool right = check(node->right);

	if(!left || !right) return false;

	return true;
}
-----------------------------------------------

void solve(TreeNode* root){
	if(!root) return 0;

	int lh = solve(node->left);
	int rh = solve(node->right);

	//if previous recursion calls returned a -1 i.e. conditioned for a BT fails at any node
	if(lh==-1 || rh==-1) return -1;

	if(abs(lh-rh)>1) return -1;

	return 1+max(lh,rh);
}

bool isBalanced(TreeNode* root){
	int a = solve(root);
	if(a==-1){
		return false;
	}
	else{
		return true;
	}
}