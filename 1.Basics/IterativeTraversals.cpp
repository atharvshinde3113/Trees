/* Iterative Preorder Root L R

 We start by pushing the root node into the stack.
- Then, while the stack is not empty, we pop a node from the stack, add its value to the result vector, and push its right child (if it exists) followed by its left child (if it exists) into the stack.
- By pushing the right child before the left child, we ensure that the left child is processed first during the traversal.

push root then in loop push right then left , stack is LIFO so left is proc first
o(n),o(n)
*/


vector<int> preorder(TreeNode* root){
	stack<TreeNode*> st;
	vector<int> ans;
	st.push(root);
	if(!root){
		return ans;
	}
	while(!st.empty()){
		// int top = st.top();
		// st.pop();
		// ans.push_back(top);
		//This cant be done as st stores TreeNode* elements int top != st.top() 

		TreeNode* curr = st.top();
		st.pop();
		int top = curr->val;
		ans.push_back(top);

		//ans.push_back(st.top()->val);
		//st.pop();

		if(curr->right != NULL){
			st.push_back(curr->right);
		}
		if(curr->left){
			st.push_back(curr->left);
		}

	}
	return ans;
}

-----------------------------
/* 2. Inorder Traversal L Root R
Reach at a node, put it in a stack. go to as left as possible of the node, then at right

stack is used to replicate the auxiliary stack space of recursion(left-print-right)
*/
vector<int> inorder(TreeNode* root){
	stack<TreeNode*> st;
	TreeNode* curr = root;
	// DONT PUSH THE ROOT FIRST
	vector<int> ans;
	while(true){
		if(curr){
			st.push(curr);
			curr = curr->left;
		}
		else{
			//node is null
			if(st.empty()) break; // tree traversal is done

			curr = st.top();
			st.pop();
			ans.push_back(curr->val);

			curr = curr->right;
		}
	}
	return ans;
} 

-----------------------------------
/*		Post Order L R Root
2 stacks
	

o(n),o(2n)
*/
vector<int> postTraversal(TreeNode* root) {
	stack<TreeNode*> st1,st2;
	vector<int> ans;
	st1.push(root);

	TreeNode* curr = root;

	while(!st1.empty()){
		curr = st1.top();
		st1.pop();
		st2.push(curr);
		if(curr->left){
			st1.push(curr->left);
		}
		if(curr->right){
			st1.push(curr->right);
		}

	}

	while(!st2.empty()){
		//st2 in reverse is your postorder traversal
		ans.push_back(st2.top()->val);
		st2.pop();
	}
	return ans;
}

-----------------------------------

//1 stack postorder

while(curr!=null || !st.empty()){
	if(curr){
		st.push(curr);
		curr = curr->left;
	}
	else{
		temp = st.top()->right;
		if(temp==null){
			temp = st.pop();
			ans.push_back(temp);
			while(!st.empty() && temp==st.top()->right){
				temp=st.top();
				st.pop();
				ans.push_back(temp->val);
			}
		}
		else{
			curr = temp;
		}
	}
}

-----------------------

