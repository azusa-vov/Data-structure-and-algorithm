#include "TreeNode.h"
template <class T>
bool TreeNode<T>::Compare(TreeNode<T>* root1,TreeNode<T>* root2){
      std::stack<TreeNode<T>>* s1,s2;
      TreeNode<T>* pointer1=root1;
      TreeNode<T>* pointer2=root2;
      while((!s1.empty() && !s2.empty()) || (pointer1 && pointer2)){
            //也就是必须栈和指针都为空才算遍历完
            if(pointer1 && pointer2){
                  //遍历阶段，需要沿着最左下行
                  if(pointer1->Value()!=pointer2->Value()){
                        s1.push(pointer1);
                        s2.push(pointer2);
                        pointer1=pointer1->LeftMostChild();
                        pointer2=pointer2->LeftMostChild();
                  }
                  else return false;
            }
            else{ //回溯阶段
                  pointer1=s1.top();
                  s1.pop();
                  pointer1=pointer1->RightSibling();
                  pointer2=s2.top();
                  s2.pop();
                  pointer2=pointer2->RightSibling();//向每一行的右兄弟方向遍历
                  }
      }
      if(pointer1==NULL && pointer2==NULL && s1.empty() && s2.empty()){
            return true; //同时到达了结束
      }else return false;

}