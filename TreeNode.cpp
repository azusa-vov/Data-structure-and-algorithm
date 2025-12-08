#include<iostream>
#include "TreeNode.h"
template<class T>
class TreeNode{
public:
      TreeNode(const T& value);
      virtual ~TreeNode(){};
      bool isLeaf();
      T Value();
      TreeNode <T> *LeftMostChild();
      TreeNode <T> *RightSibling();
      void setValue(const T& value);
      void setChild(TreeNode<T>* pointer);
      void InsertFirst(TreeNode<T>* node);
      void InsertNext(TreeNode<T>* node);
private:
      T m_value;
      TreeNode<T>* pChild;
      TreeNode<T>* pSibling;
};

template<class T>
bool TreeNode<T>::isLeaf(){
      if(pChild== nullptr){
            return true;
      }
      return false;
}

template<class T>
void TreeNode<T>::setValue(const T& value){
      m_value = value;
}
template<class T>
void TreeNode<T>::InsertFirst(TreeNode<T>* node){
      if(pChild==NULL){
            pChild=node;
      }else {
            node->setSibling(pChild);
            pChild=node;
      }

}