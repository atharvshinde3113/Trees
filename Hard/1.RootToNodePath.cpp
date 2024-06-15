/* variation: return all paths from root to leaf

Preorder traversal

The idea is to traverse the tree from the root and keep track of the path in a vector. 
If the target node is found, add the node's value to the path vector, and return true. 
Otherwise, recursively search for the target node in the left and right subtrees.
OR is used as even if one of the subtrees has the node, it is enough for it to be directly returned 
If the target node is not found, remove the last node from the path vector before returning false.
*/

bool helper(TreeNode* root, int target, vector<int> ans){
	if(!root) return false;

	ans.push_back(root->val);

	if(root->val == target) return true;

	if(helper(root->left,target,ans) == true || helper(root->right,target,ans) == true){
		return true;
	}

	ans.pop_back(); // as the element you pushed back at line 15 failed conditions on line 17,19
	return false; 
} 

vector<int> getPathFromRootToNode(TreeNode* root, int target) {
    vector<int> path;
    findPath(root, target, path);
    return path;
}


--------------------------------------------------------------------

/*Given a binary tree, print out all of its root-to-leaf 
paths, one per line.*/
void printPaths(node* node) 
{ 
	vector<int> path; 
	printPathsRecur(node, path, 0); 
} 

void printPathsRecur(node* node, vector<int> path) 
{ 
	if (node == NULL) return; 
	/* append this node to the path array */
	path.push_back(node->data); 
	 
	
	/* it's a leaf, so print the path that lead to here */
	if (node->left == NULL && node->right == NULL) 
	{ 
		printArray(path); 
	} 
	else
	{ 
		/* otherwise try both subtrees */
		printPathsRecur(node->left, path); 
		printPathsRecur(node->right, path); 
	} 
} 


/* UTILITY FUNCTIONS */
void printArray(vector<int> v) 
{  
    for (int i = 0; i < v.size(); i++) 
    { 
        cout << v[i] << " "; 
    } 
    cout<<endl; 
} 

