#ifndef TREE_NODE_H
#define TREE_NODE_H
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
      void setSibling(TreeNode<T>* pointer);
      void InsertFirst(TreeNode<T>* node);
      void InsertNext(TreeNode<T>* node);
      bool Compare(TreeNode<T>* root1, TreeNode<T>* root2);
private:
      T m_value;
      TreeNode<T>* pChild;
      TreeNode<T>* pSibling;
};


#endif 