//ceil: val just >= key

int findCeil(Node* root, int key){
	int ceil = -1;

	while(root){
		if(root->val == key){
			ceil=root->data;
			return ceil;
		}

		if(root->val < key){
			root=root->right; //increase the val
		}
		else{//val is more than key
			ceil = root->val;
			root=root->left; // make ceil as less as possible
		}
	}
	return ceil;
}