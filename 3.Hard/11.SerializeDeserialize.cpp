/* Root->serialize->string, string->deserialize->root

Level order

*/

string serialize(TreeNode* root){
	if(!root) return "";

	string s = "";
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()){
		TreeNode* current = q.front();
		q.pop();
		if(current==NULL) s.append("#,");
		else s.append(to_string(current->val)+',');
		if(current!=NULL){
			q.push(current->left); // for next iteration
			q.push(current->right);
		}
	}
	return s;
}

TreeNode* deserialize(string data){
	if(data.size()==0) return NULL;
	stringstream s(data); // allows the string to be iterated over as objects
	string str; 
	getline(s,str,','); // ',' is the separator. 
	TreeNode* root=new TreeNode(stoi(str));
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()){

		TreeNode* node = q.front();
		q.pop();

		getline(s,str,',');
		if(str=="#"){
			node->left = NULL;
		}
		else{
			TreeNode* leftnode = new TreeNode(stoi(str));
			node->left=leftnode;
			q.push(leftnode);
		}

		getline(s,str,',');
		if(str=="#"){
			node->right=NULL;
		}
		else{
			TreeNode* rightnode = new TreeNode(stoi(str));
			node->right=rightnode;
			q.push(rightnode);
		}
	}
	return root;
}


------

// 2nd format
void check(TreeNode* root, string& str) {
        if(root == NULL)
            return;
        
        str += to_string(root->val);

        if(root->left || root->right) {
            str+='(';
            check(root->left, str);
            str+=')';
        }
        if(root->right) {
            str+='(';
            check(root->right, str);
            str+=')';
        }
    }

    string tree2str(TreeNode* root) {
        string str = "";
        check(root, str);
        return str;
    }