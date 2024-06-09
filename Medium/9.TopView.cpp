vector<int> findTopView(Node* root)
	{
		//level order traversal used
		vector<int>ans;
		if(root == NULL) return ans;
		map<int, int> mpp; // line position, node val 
		//map stores everything in sorted order(not unordered map) only once 
		
		queue<pair<Node*, int>> Q; // Node , line
		Q.push({root, 0});
		
		while(!Q.empty()){
			auto it = Q.front();
			Q.pop();
			Node* node = it.first;
			int line = it.second;
			
			if(mpp.find(line)== mpp.end()) mpp[line] = node->data; // add line to map if it doesnt exit. 
			//if it exists map it means that when viewed from top the node that exists would be seen

			//progress and store next nodes
			if(node->left != NULL) Q.push({node->left, line-1});
			if(node->right != NULL) Q.push({node->right, line+1});
		}
		
		for(auto x:mpp){
			ans.push_back(x.second);
		}
		return ans;
	}
};