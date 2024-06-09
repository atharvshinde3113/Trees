/*
Approach:
- We can divide the boundary traversal into three parts: left boundary nodes, leaf nodes, and reverse right boundary nodes.
- To find the left boundary nodes, we can traverse the left subtree from the root to the leftmost leaf node. We add the values of the nodes to the answer vector during this traversal.
- To find the leaf nodes, we can perform a separate recursive traversal of the binary tree and add the values of the leaf nodes (excluding the ones already included in the left boundary or right boundary) to the answer vector.
- To find the reverse right boundary nodes, we can traverse the right subtree from the root to the rightmost leaf node (excluding the root). We add the values of the nodes to the answer vector during this traversal.

o(n) o(height)
*/

//iterative

void addLeftBoundary(Node* root, vector<int> &res){
	Node* curr = root->left;
	while(curr){
		if(!isLeaf(cur)) res.push_back(cur->val);
		if(cur->left) cur = cur->left;
		else cur = cur->right;
	}
}

void addRightBoundary(Node* root, vector<int> &res){
	Node* cur = root->right;
	vector<int> tmp;
	while(cur){
		if(!isLeaf(cur)) tmp.push_back(cur);
		if(cur->right) cur = cur->right;
		else cur = cur->left;
	}

	for(int i = tmp.size()-1;i>=0;i--){
		res.push_back(tmp[i]);
	}
}

void addLeaves(Node* root, vector<int> &res){
	if(isLeaf(root)){
		res.push_back(root->val);
		return;
	}
	if(root->left) addLeaves(root->left,res);
	if(root->right) addLeaves(root->right,res);
}

bool isLeaf(Node* root){
	if(root->left == NULL && root->right == NULL){
		return true;
	}
	return false;
}

vector<int> boundaryTraversal(Node* root){
	vector<int> res;
	if(!root) return res;
	if(!isLeaf(root)) res.push_back(root->data);
	addLeafBoundary(root,res);
	addLeaves(root,res);
	addRightBoundary(root,res);
	return res;
}



----------------------
//Recursive
void leftTraversal(TreeNode<int>* root, vector<int>& ans) {
    if (!root) return;
    if (!root->left && !root->right) return; //if isleaf, return

    ans.push_back(root->val);

    if (root->left)
        leftTraversal(root->left, ans);
    else
        leftTraversal(root->right, ans);
}

//leaf traversal any traversal works(pre,in,post) as left comes before right
void leafTraversal(TreeNode<int>* root, vector<int>& ans) {
    if (!root) return;
    if (!root->left && !root->right) { //if isLeaf
        ans.push_back(root->val);
    }
    leafTraversal(root->left, ans);
    leafTraversal(root->right, ans);
}

void rightTraversal(TreeNode<int>* root, vector<int>& ans) {
    if (!root) return;
    if (!root->left && !root->right) return;

    int temp = root->val;

    if (root->right)
        rightTraversal(root->right, ans);
    else
        rightTraversal(root->left, ans);
    //Important to add it later as you have to do reverse traversal i.e. after coming back from rec calls
    ans.push_back(temp);
}

vector<int> boundaryTraversal(TreeNode<int>* root) {
    if (!root) return {};
    vector<int> ans;

    ans.push_back(root->val);
    leftTraversal(root->left, ans);
    leafTraversal(root->left, ans);
    leafTraversal(root->right, ans);
    rightTraversal(root->right, ans);

    return ans;
}
