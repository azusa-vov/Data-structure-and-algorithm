#include "TREE.H"
template<class T>
bool IsEqual(TreeNode<T>* root1,TreeNode<T>* root2){
      while(root1!=NULL && root2!=NULL){
            if(root1->Value!=root2->Value){
                  return false; //如果连value都不一样肯定不同
            }
            if((IsEqual(root1->LeftMostChild(),root2->LeftMostChild())==false)){
                  return false;

            }
            root1=root1->RightSibling();
            root2=root2->RightSibling();
            // 去比较下一个兄弟结点
      }
      if(root1=NULL && root2==NULL){
            return true; //同时到达了结束
      }
      return false;
}