// A stack node
class snode {
public:
	node* t;
	snode* next;
};


void merge(node* root1, node* root2)
{
	// s1 is stack to hold nodes of first BST
	snode* s1 = NULL;

	// Current node of first BST
	node* current1 = root1;

	// s2 is stack to hold nodes of second BST
	snode* s2 = NULL;

	// Current node of second BST
	node* current2 = root2;

	// If first BST is empty, then output is inorder
	// traversal of second BST
	if (root1 == NULL) {
		inorder(root2);
		return;
	}
	// If second BST is empty, then output is inorder
	// traversal of first BST
	if (root2 == NULL) {
		inorder(root1);
		return;
	}

	// Run the loop while there are nodes not yet printed.
	// The nodes may be in stack(explored, but not printed)
	// or may be not yet explored
	while (current1 != NULL || !isEmpty(s1)
		|| current2 != NULL || !isEmpty(s2)) {
		// Following steps follow iterative Inorder
		// Traversal
		if (current1 != NULL || current2 != NULL) {
			// Reach the leftmost node of both BSTs and push
			// ancestors of leftmost nodes to stack s1 and
			// s2 respectively
			if (current1 != NULL) {
				push(&s1, current1);
				current1 = current1->left;
			}
			if (current2 != NULL) {
				push(&s2, current2);
				current2 = current2->left;
			}
		}
		else {
			// If we reach a NULL node and either of the
			// stacks is empty, then one tree is exhausted,
			// print the other tree
			if (isEmpty(s1)) {
				while (!isEmpty(s2)) {
					current2 = pop(&s2);
					current2->left = NULL;
					inorder(current2);
				}
				return;
			}
			if (isEmpty(s2)) {
				while (!isEmpty(s1)) {
					current1 = pop(&s1);
					current1->left = NULL;
					inorder(current1);
				}
				return;
			}

			// Pop an element from both stacks and compare
			// the popped elements
			current1 = pop(&s1);
			current2 = pop(&s2);

			// If element of first tree is smaller, then
			// print it and push the right subtree. If the
			// element is larger, then we push it back to
			// the corresponding stack.
			if (current1->data < current2->data) {
				cout << current1->data << " ";
				current1 = current1->right;
				push(&s2, current2);
				current2 = NULL;
			}
			else {
				cout << current2->data << " ";
				current2 = current2->right;
				push(&s1, current1);
				current1 = NULL;
			}
		}
	}
}

