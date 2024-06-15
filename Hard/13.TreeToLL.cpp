//cant create a new LL. Create an LL with preorder of the tree.

//Method 1 : Right Left Root

	TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->right);
        flatten(root->left);
        root->right=prev;
        root->left=NULL; //Since left is to be kept null
        prev=root; //when coming back, last value is assigned to prev 
    }

--------------
//iterative: st has levels in it from left to right
st.push(root);
while(!st.empty()){
	curr=st.top();
	st.pop();

	if(curr->right){
		st.push(curr->right);
	}
	if(curr->left){
		st.push(curr->left);
	}

	if(!st.empty()){
		curr->right=st.top();
	}
	curr->left=NULL;
}

---------------------------------
/*
1. We start with the current node as the root.
2. While the current node is not NULL, we do the following:
   - If the current node has a left child, we find the rightmost node of its left subtree.
     - We make the right child of the rightmost node point to the right child of the current node.
     - We set the left child of the current node to NULL.
     - We set the right child of the current node to its left child.
   - We move to the right child of the current node.
3. We repeat this process until we have visited all the nodes in the tree.

on the left subtree, whichever was the last node of preorder, connect it to the right of root/curr node O(n)time O(1) space Morris traversal
*/
void flatten(TreeNode* root) {
    TreeNode* curr = root;

    while (curr) {
        if (curr->left!=NULL) {
            TreeNode* prev = curr->left;
            while (prev->right)
                prev = prev->right;

            prev->right = curr->right;
            curr->left = NULL;
            curr->right = curr->left;
        }
        curr = curr->right;
    }
}