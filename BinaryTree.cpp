// 广度优先（层序）遍历二叉树示例
#include <iostream>
#include <queue>

struct Node {
	int value;
	Node* left;
	Node* right;

	explicit Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

void bfsTraversal(Node* root) {
	if (!root) return;

	std::queue<Node*> q;
	q.push(root);
/*
因为队列里存的是要访问的“节点本身”。你的树节点是用指针串起来的（left/right 都是指针）
，如果把节点按值放进队列，就会产生拷贝：拷贝体里的 left/right 仍是指向原节点的指针，
访问虽能用，但每次都在做不必要的拷贝；且若节点包含资源或较大数据，拷贝成本高。用 Node*
 则直接操作原始节点，不拷贝、无额外开销，符合层序遍历“按指针走原树”的需求。std::queue
  不能存引用，所以常用指针（或 std::reference_wrapper<Node>）
*/
	while (!q.empty()) {
		Node* curr = q.front();
		q.pop();
		std::cout << curr->value << ' ';

		if (curr->left) q.push(curr->left);
		if (curr->right) q.push(curr->right);
	}
}

int main() {
	// 构建一个简单的二叉树
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	bfsTraversal(root);
	std::cout << "\n";

	// 清理内存
	delete root->right->right;
	delete root->right->left;
	delete root->right;
	delete root->left->right;
	delete root->left->left;
	delete root->left;
	delete root;

	return 0;
}

