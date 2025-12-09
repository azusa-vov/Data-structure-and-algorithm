#include "UnionTree.h"
#include <iostream>
template<class T>
//查找node的根节点
ParTreeNode<T>* ParTree<T>::FindRoot(ParTreeNode<T>* node){
      ParTreeNode<T>* pointer=node;
      while(pointer->getParent()!=NULL){
            pointer=pointer->getParent();
            
      }
      return pointer;
}
template<class T>
//Diff
bool ParTree<T>::Diff(int i,int j){
      ParTreeNode<T>* root1=FindRoot(&array[i]);
      ParTreeNode<T>* root2=FindRoot(&array[j]);
      return root1!=root2;
}
//Union
//这AI太他妈叼了，直接帮我写完了
template<class T>
void ParTree<T>::Union(int i,int j){
      ParTreeNode<T>* root1=FindRoot(&array[i]);
      ParTreeNode<T>* root2=FindRoot(&array[j]);
      if(root1!=root2){
            if(root1->getCount()>=root2->getCount()){
                  root2->setParent(root1); //小接在大的下面
                  root1->setCount(root1->getCount()+root2->getCount()); //更新节点数
      }else{
                  root1->setParent(root2);
                  root2->setCount(root1->getCount()+root2->getCount());
            }
      }
}
