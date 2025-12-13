#include "GraphAbs.h"
#include <climits>
#define UNVISITED 0
class Graph{
      public:
            int numVertex;
            int numEdge;
            int *Mark;
            int *Indegree;
            Graph(int numVert){
                  numVertex=numVert;
                  numEdge=0;
                  Indegree=new int[numVertex];
                  Mark=new int[numVertex];
                  for(int i=0;i<numVertex;i++){
                        Mark[i]=UNVISITED;
                        Indegree[i]=0;
                  }
            }
            ~Graph(){
                  delete []Mark;
                  delete []Indegree;

            }
            int VerticeNum(){
                  return numVertex;
                  
            }
            bool IsEdge(Edge oneEdge){
                  if(oneEdge.weight > 0 && oneEdge.weight < INT_MAX && oneEdge.to >=0){
                        return true;
                  }
            else{
                  return false;
            }
      }
};

class Graphm:public Graph{
      //图的邻接矩阵表示法
      private:
            int **mat;
      public:
            Graphm(int numVert):Graph(numVert){
                  int i,j;
                  mat=(int**) new int* [numVertex];
                  for(i=0;i<numVertex;i++) mat[i]=new int[numVertex];
                  for(i=0;i<numVertex;i++)
                        for(j=0;j<numVertex;j++)
                              mat[i][j]=0;
            }
            ~Graphm(){
                  for(int i=0;i<numVertex;i++){
                        delete [] mat[i]; //删去Mat指针指向的行向量空间

                  }
                  delete [] mat;//删去Mat 指针指向的行向量头
            }
            Edge FirstEdge(int oneVertex){
                  Edge myEdge;
                  myEdge.from=oneVertex;
                  for(int i=0;i<numVertex;i++){
                        if(mat[oneVertex][i]!=0){ //规定尾，也就是规定行，头即列索引
                              myEdge.to=i;
                              myEdge.weight=mat[oneVertex][i];
                              break;
                        } 
                  }
                  return myEdge;
            }
            Edge NextEdge(Edge preEdge){
                  //默认preEdge已经是上一条边
                  Edge myEdge;
                  myEdge.from=preEdge.from;
                  if(preEdge.to<numVertex){
                        for(int i=preEdge.to+1;i<numVertex;i++){
                              if(mat[preEdge.from][i]!=0){ myEdge.to=i;
                                    myEdge.weight=mat[preEdge.from][i];
                                    break;}
                                   
                              }
                        }return myEdge;
                  }
            void setEdge(int from,int to,int weight){
                  if(mat[from][to]<=0){
                        numEdge++;
                        Indegree[to]++;
                  }
                  mat[from][to]=weight;
            }
            void delEdge(int from,int to){
                  if(mat[from][to]>0){
                        numEdge--;
                        Indegree[to]--;
                  }
                  mat[from][to]=0;
            }
      };
