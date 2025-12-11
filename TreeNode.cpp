#include <iostream>
#include "TreeNode.h"

template<class T>
TreeNode<T>::TreeNode(const T& value) : m_value(value), pChild(nullptr), pSibling(nullptr) {}

template<class T>
bool TreeNode<T>::isLeaf() {
      return pChild == nullptr;
}

template<class T>
T TreeNode<T>::Value() {
      return m_value;
}

template<class T>
TreeNode<T>* TreeNode<T>::LeftMostChild() {
      return pChild;
}

template<class T>
TreeNode<T>* TreeNode<T>::RightSibling() {
      return pSibling;
}

template<class T>
void TreeNode<T>::setValue(const T& value) {
      m_value = value;
}

template<class T>
void TreeNode<T>::setChild(TreeNode<T>* pointer) {
      pChild = pointer;
}

template<class T>
void TreeNode<T>::setSibling(TreeNode<T>* pointer) {
      pSibling = pointer;
}

template<class T>
void TreeNode<T>::InsertFirst(TreeNode<T>* node) {
      if (!node) return;
      node->pSibling = pChild; // 新节点指向原最左孩子
      pChild = node;           // 作为新的最左孩子
}

template<class T>
void TreeNode<T>::InsertNext(TreeNode<T>* node) {
      if (!node) return;
      node->pSibling = pSibling; // 新兄弟接在当前节点之后
      pSibling = node;
}

// 显式实例化可按需要添加具体类型，例如：
template class TreeNode<int>;
template class TreeNode<char>;
template class TreeNode<std::string>;