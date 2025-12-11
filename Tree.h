#ifndef TREE_H
#define TREE_H
#include "TreeNode.h"

template<class T>
class Tree{
public:
      Tree();
      virtual ~Tree(){};
      TreeNode<T>* getRoot();
      void CreateRoot(const T& rootValue);
      bool isEmpty();
      TreeNode<T>* Parent(TreeNode<T>* node); // 返回当前节点的父节点
      TreeNode<T>* PrevSibling(TreeNode<T>* node);
      void DeleteSubTree(TreeNode<T>* subroot);
      void RootFirstTraverse(TreeNode<T>* node);
      void RootLastTraverse(TreeNode<T>* node);
      void WidthTraverse(TreeNode<T>* root);
      void DestroyNodes(TreeNode<T>* root);
      Tree(DualTagTreeNode<T>* nodeArray,int count);


private:
      TreeNode<T>* root;
};

#endif
