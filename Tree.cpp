#include "Tree.h"
template<class T>
TreeNode<T>* Tree<T>::Parent(TreeNode<T>* current){
      std::queue<TreeNode<T>*> q;
      TreeNode<T>* pointer=root;
      TreeNode<T>* upperlevelpointer=NULL;
      if(current!=NULL && pointer!=NULL){
            while(pointer!=NULL){
                  if(current==pointer){
                        return NULL;
                  }
                  q.push(pointer);
                  pointer=pointer->RightSibling(); // 入队整行根节点
            }
            while(!q.empty()){
                  pointer=q.front();
                  q.pop();
                  upperlevelpointer=pointer;
                  pointer=pointer->LeftMostChild(); // upper节点相当于打一拍
                  while(pointer){
                        if(current==pointer){
                              return upperlevelpointer;
                        }
                        else{
                              q.push(pointer);
                              pointer=pointer->RightSibling();
                        }
                  }
            }
      }
      return NULL;
}

template<class T>
void Tree<T>::DestroyNodes(TreeNode<T>* root){
      if(root!=NULL){
            DestroyNodes(root->LeftMostChild());
            DestroyNodes(root->RightSibling());
            delete root;
      }
}

template<class T> 
void Tree<T>::DeleteSubTree(TreeNode<T>* subroot){
      TreeNode<T>* pointer;
      if(subroot==NULL) return;
      pointer=Parent(subroot); // 找到父节点
      if(pointer==NULL){
            root=root->RightSibling(); // 往右遍历
      }else if(pointer->LeftMostSibling()==subroot){
            pointer->setChild(subroot->RightSibling()); 
            //因为删掉的是pointer左子节点，将sub的右兄弟作为pointer的新孩子
      }else{
            pointer=pointer->LeftMostChild(); //pointer下降
            while(pointer->RightSibling()!=subroot){
                  pointer=pointer->RightSibling(); //直到pointer的右兄弟是subroot
            }
            pointer->setSibling(subroot->RightSibling());
      }
      subroot->setSibling(NULL);
      DestroyNodes(subroot); //切断subroot和树的联系
}