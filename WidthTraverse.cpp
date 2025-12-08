#include <iostream>
#include <queue>

struct TreeNode {
      int value;
      TreeNode* firstChild;   // 最左孩子
      TreeNode* nextSibling;  // 右兄弟
      TreeNode* parent;
      explicit TreeNode(int v) : value(v), firstChild(nullptr), nextSibling(nullptr), parent(nullptr) {}
};

// 返回当前节点的右兄弟
TreeNode* RightSibling(TreeNode* node) {
      return node ? node->nextSibling : nullptr;
}

// 返回当前节点的最左孩子
TreeNode* LeftMostChild(TreeNode* node) {
    return node ? node->firstChild : nullptr;
}

// 访问节点的示例操作，这里简单输出值
void Visit(int v) {
    std::cout << v << ' ';
}

void WidthTraverse(TreeNode* root){
      if(!root) return;

      std::queue<TreeNode*> q;
      TreeNode* pointer=root;
      // 先把整行的根（root 及其右兄弟）入队，用于遍历“森林”的每棵树根
      while(pointer){
            q.push(pointer);
            pointer=RightSibling(pointer);
      }
      while(!q.empty()){
            pointer=q.front();
            q.pop();
            Visit(pointer->value);
            pointer=LeftMostChild(pointer);
            while(pointer){
                  q.push(pointer);
                  pointer=RightSibling(pointer);
            }
      }

}

     