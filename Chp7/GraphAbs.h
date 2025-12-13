#ifndef GRAPH_H
#define GRAPH_H

class Edge {
    public:
      int from,to,weight;
      Edge(){
            from=-1;to=-1;weight=0;
      }
      Edge(int f,int t,int w){
            from=f;to=t;weight=w;
      }
};

class Graph{
      public:
            int VerticeNum();
            int EdgesNum();
            Edge FirstEdge(int oneVertex);
            Edge NextEdge(Edge preEdge);
            bool setEdge(int fromVertex,int toVertex,int weight);
            bool delEdge(int fromVertex,int toVertex);
            bool IsEdge(Edge oneEdge);
            int FromVertex(Edge oneEdge);
            int ToVertex(Edge oneEdge);
            int Weight(Edge oneEdge);
};


#endif