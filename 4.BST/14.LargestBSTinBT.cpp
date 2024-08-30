//pass every node to ValidateBST() and it the func returns true, pass the node to a func that finds the number of nodes present in the tree. o(N) for validate BST, o(n) for finding number of nodes(via any traversal) also O(n) going to every node. o(n2) solution

//O(n) O(1) solution:

class NodeValue{
	int maxNode, minNode, maxsize;
	NodeValue(int minNode, int maxNode, int maxsize){
		this->minNode=minNode;
		this->maxNode=maxNode;
		this->maxsize=maxsize;
	}
}

NodeValue helper(TreeNode* root){
	if(!root) return NodeValue(INT_MAX, INT_MIN, 0);

	// post order traversal
	auto left = helper(root->left);
	auto right = helper(oot->right);

	//operation once reached at node
	if(left.maxNode<root->val && root->val<right.minNode){
		//it is a BST as curr node is larger than largest no in left and smaller than smallest no in right
		return NodeValue(min(root->val,left.minNode), max(root->val,right.maxNode),left.maxsize+right.maxsize+1);
	}

	//otherwise return [-inf,inf] so that parent cant be BST
	return NodeValue(INT_MIN,INT_MAX,max(left.maxsize,right.maxsize));
}

int largestBST(TreeNode* root){
	 return helper(root).maxsize;
}