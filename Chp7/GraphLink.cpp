#include "GraphAbs.h"
#include "Graph.cpp"
struct listUnit{
      int vertex;
      int weight;
};

template<class Elem>
class Link{ //链表元素
      public:
            Elem element;
            Link *next;
            Link(const Elem& elemval,Link* nextval=nullptr){
                  element=elemval;
                  next=nextval;
            }
            Link(Link* nextval=nullptr){
                  next=nextval;
            }
};
template <class Elem>
class LList{ //链表
      public:
            Link<Elem>* head;
            LList(){
                  head=new Link<Elem>();
            }

};
class Graphl:public Graph{
      private:
            LList<listUnit>* graList;
      public:
            Graphl(int numVert):Graph(numVert){
                  graList=new LList<listUnit>[numVertex];
            }
            Edge FirstEdge(int oneVertex){
                  Edge myEdge;
                  myEdge.from=oneVertex;
                  Link<listUnit>* temp=graList[oneVertex].head; //这是目前考察的起点
                  if(temp->next!=nullptr){
                        myEdge.to=temp->next->element.vertex;
                        myEdge.weight=temp->next->element.weight;

                  }
                  return myEdge;
            };
            

      Edge NextEdge(Edge preEdge){
      Edge myEdge;
      myEdge.from=preEdge.from;
      Link<listUnit>* temp=graList[preEdge.from].head;
      while(temp->next!=nullptr && temp->next->element.vertex<=preEdge.to){
            temp=temp->next;
      }if(temp->next!=nullptr){
            myEdge.to=temp->next->element.vertex;
            myEdge.weight=temp->next->element.weight;
            }
      return myEdge;
      };
      void setEdge(int from,int to,int weight){
            Link<listUnit>* temp=graList[from].head;
            while(temp->next!=nullptr && temp->next->element.vertex<to){
                  temp=temp->next;
            }
            if(temp->next==nullptr){ //这条边不存在,并且顺序在最后面
                  temp->next=new Link<listUnit>;
                  temp->next->element.vertex=to;
                  temp->next->element.weight=weight;
                  numEdge++;
                  Indegree[to]++;
                  return;
            }
            if(temp->next->element.vertex==to){ //这条边存在，只需要改变边的权重
                  temp->next->element.weight=weight; 
                  return;
            }
            if(temp->next->element.vertex>to){ //不存在，且后面还有边，需要插入
                  Link<listUnit>* other=temp->next;
                  temp->next=new Link<listUnit>;
                  temp->next->element.vertex=to;
                  temp->next->element.weight=weight;
                  temp->next->next=other;
                  numEdge++;
                  Indegree[to]++;
                  return;
            }
      }
      void delEdge(int from,int to){
            Link<listUnit>* temp=graList[from].head;
            while(temp->next!=nullptr && temp->next->element.vertex<to){
                  temp=temp->next; //temp指向要删除边的前一个结点
            }
            if(temp->next==nullptr) return; //说明边不存在
            if(temp->next->element.vertex==to){ //说明边存在
                  Link<listUnit>* other=temp->next;
                  temp->next=other->next;
                  delete other;
                  numEdge--;
                  Indegree[to]--;
                  return;
            }
            if(temp->next->element.vertex>to) return; //说明边不存在
      }


};