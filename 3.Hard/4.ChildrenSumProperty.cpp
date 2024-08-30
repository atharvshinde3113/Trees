// [node] = [left] + [right]  you can increase a node's value, cant decrease it

//To indicate that the current node is not a Sum Tree, we return a special value (e.g., INT_MIN) from the recursive function. If the result is INT_MIN, then the binary tree is not a Sum Tree. Otherwise, it is a Sum Tree.

int solve(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return root->data; //leaf node
    
    int lef = solve(root->left);
    int rig = solve(root->right);
    
    if (lef + rig == root->data) return root->data;
	
	else return INT_MIN; // can even return -1(like a flag basically)
}


bool isSumTree(Node* root) {
    int ans = solve(root);
    if(ans == INT_MIN){
    	return false;
    } 
    else{
    	return true;
    }
}

---------------------------------
// convert any BT to children sum property following BT:

// while going down, increase the nodes val to max possible.
//while going back change nodes val to sum of children. youll never fall short.


void changetree(TreeNode* root){
	int childsum = 0;
	if(root->left){
		childsum+=root->left->data;
	}
	if(root->right){
		childsum+=root->right->data;
	}

	if(childsum>=root->data) root->data = childsum; // child sum is more therefore modify root
	else{
		if(root->left) root->left->data = root->data; // root is bigger therefore give left child its value
		else if(root->right) root->right->data = root->data;
	}

	changetree(root->left); //traverse left
	changetree(root->right); // traverse right

	int tot = 0; // has val of sum of children
	if(root->left) tot+=root->left->data;
	if(root->right) tot+=root->right->data;
	if(root->left || root->right) root->data = tot; // if its not a leaf node its only when you update the top guy with val of sum of its children 
}