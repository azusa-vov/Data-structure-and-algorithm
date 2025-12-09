#ifndef UNION_TREE_H
#define UNION_TREE_H
//实现并查集
template <class T>
class ParTreeNode{
      private:
            T value;
            ParTreeNode<T>* parent;
            int nCount;
      public:
            ParTreeNode();
            virtual ~ParTreeNode(){};
            T getValue();
            void setValue(const T& val);
            ParTreeNode<T>* getParent();
            void setParent(ParTreeNode<T>* par);
            int getCount();
            void setCount(const int count);

      };
template <class T>
class ParTree{
      private:
            ParTreeNode<T>* array;
            int size;
            ParTreeNode<T>* FindRoot(ParTreeNode<T>* node); //查找node的根节点
            ParTree(const int size);
            virtual ~ParTree();
            void Union(int i,int j);
            bool Diff(int i,int j);
            
};

// ---- ParTreeNode inline definitions ----
template <class T>
ParTreeNode<T>::ParTreeNode() : value(), parent(nullptr), nCount(1) {}

template <class T>
T ParTreeNode<T>::getValue() { return value; }

template <class T>
void ParTreeNode<T>::setValue(const T& val) { value = val; }

template <class T>
ParTreeNode<T>* ParTreeNode<T>::getParent() { return parent; }

template <class T>
void ParTreeNode<T>::setParent(ParTreeNode<T>* par) { parent = par; }

template <class T>
int ParTreeNode<T>::getCount() { return nCount; }

template <class T>
void ParTreeNode<T>::setCount(const int count) { nCount = count; }



#endif