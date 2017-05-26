#include <iostream>
#include<algorithm>
#include<queue>
using namespace std;
int a[100005], n;

struct node {
	int value;
	struct node* left;
	struct node* right;
};
struct node* newNode(int value) {
	struct node* newnode = new node;
	newnode->value = value;
	newnode->left = newnode->right = 0;

	return newnode;
}

struct node *arrayToBST(int start, int end) {
	if (start > end)
		return 0;
	int mid = start + (end - start) / 2;
	struct node *root = newNode(a[mid]);
	root->left = arrayToBST(start, mid - 1);
	root->right = arrayToBST(mid + 1, end);
	return root;
}

void preOrder(node * t) {
	if (!t)
		return;

	cout << t->value << " ";
	preOrder(t->left);
	preOrder(t->right);
}
int count(node *t) {
	if (!t)
		return 0;
	return count(t->left) + count(t->right) + 1;

}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	node *root = arrayToBST(0, n - 1);
	// cout<<count(root);
	// preOrder(root);
	//bfs
	queue<node*> q;
	q.push(root);
	while (!q.empty()) {

		node *temp = q.front();
		q.pop();
		cout << temp->value << " ";
		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(temp->right);
	}

	return 0;
}
