#include<iostream>
using namespace std;

class Edge{
	public:
	int src,dest,wt;

};
class Graph{
	public:
	int V,E;
	Edge *edges; 

	Graph(int V, int E){
		this->V=V;
		this->E=E;
		this->edges = new Edge[E*sizeof(Edge)];
	}

};

int find(int parent[], int x){

	if(parent[x]==-1) return x;

	return find(parent, parent[x]);

}

void Union(int parent[] , int x, int y ){

	int xset = find(parent, x);
	int yset = find(parent, y);

	if(xset!=yset){
		parent[xset]=yset;
	}

}

bool isCycle( Graph *g ){

	int parent[g->V];
	memset( parent, -1 , sizeof(parent) );

	for(int i = 0 ; i < g->E ; ++i){
		int src = g->edges[i].src;
		int dest = g->edges[i].dest;
		int x = find(parent , src);
		int y = find(parent ,dest);
		
		if(x==y) return true;
		Union(parent,x,y);

	}

	return false;
}

int main(){
	Graph *graph = new Graph(3,3);
	graph->edges[0].src = 0;  
    graph->edges[0].dest = 1;  
  
    // add edge 1-2  
    graph->edges[1].src = 1;  
    graph->edges[1].dest = 2;  
  
    // add edge 0-2  
    graph->edges[2].src = 0;  
    graph->edges[2].dest = 2; 

    if(isCycle(graph)) cout<<"cycle detected";
    else cout<<"no cycle detected";

}
