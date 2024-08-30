/* 1 stack stores (Node*,num)

Enter root in stack first

preorder = root is at 1st place, inorder root at 2nd

if num = 1 -> goes in preorder -> push that no by doing ++ (reinsert). if there exists a left, enter it with num 1

if num = 2 -> goes in inorder -> push that no by doing ++ (reinsert). if there exists a right, enter it with num 1

if num = 3 -> goes in postorder -> do nothing.	

o(3N),o(4N)

*/

void traversal(TreeNode* root){

	stack<pair<TreeNode*, int>> st;
	vector<int> preorder,inorder,postorder;
	if(!root) return;

	while(!st.empty()){

		auto it = st.top();
		st.pop();

		if(it.second == 1){
			preorder.push_back(it.first->val);
			it.second++;
			st.push(it);

			if(it.first->left != NULL){
				st.push({it.first->left,1});
			}
		}


		if(it.second == 2){
			inorder.push_back(it.first->val);
			it.second++;
			st.push(it);
				
			if(it.first->right != NULL){
				st.push({it.first->right,1});
			}

		}

		else{
			postorder.push_back(it.first->val);
		}
	}
}

---------------------
//All in one recursive
void traversal(BinaryTreeNode<int>* root, vector<int>& pre, vector<int>& ino, vector<int>& pos) {
    if (root == NULL) {
        return;
    }

    // Pre-Order Traversal
    pre.push_back(root->data);
    traversal(root->left, pre, ino, pos);

    // In-Order Traversal
    ino.push_back(root->data);
    traversal(root->right, pre, ino, pos);
    
    // Post-Order Traversal
    pos.push_back(root->data);
}
