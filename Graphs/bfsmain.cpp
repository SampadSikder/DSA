#include<iostream>

using namespace std;

const int N = 100;

#define WHITE 0 
#define GRAY 1
#define BLACK 2
#define RED 4
#define BLUE 5
#define NIL -1
#define INF 1e8 + 5


int graph [ N ] [ N ] ;
int color[N];
int prevv[N];
int d[N];


struct Queue{
	
	int q [ N + N] ;
	int front;
	int back;
	
	int size;
	Queue(){
		front = 0;
		back = 0;
		size = 0;
	}
	
	bool empty(){
		return size <= 0;
	}
	
	void push(int x){
		q[back++] = x;
		size++;
	}
	int pop(){
		--size;
		return q[front++];
	}
};
	
void bfs(int source){
	
	for (int i=0;i<N;i++){
		color[i] = WHITE;
		prevv[i] = NIL;
		d[i] = INF;
	}
	
	color[source] = GRAY;
	d[source] = 0;
	prevv[source] = NIL;
	
	Queue q;
	q.push(source);
	
	while (!q.empty()){
		int u = q.pop();
		
		for(int v=0;v<N;v++){
			if (graph[u][v] == 1){
				if (color [v] == WHITE){
					color[v] = GRAY;
					d[v] = d[u] + 1;
					prevv[v] = u;
					
					//cout << "current node " << v << " parent[v] : " << u << endl;
					q.push(v);
				}
			}
		}
		color[u] = BLACK;
	}
}

bool check_bipartite(int source, int nodes){
	
	bool bipartite = 1;
	
	for (int i=0;i<N;i++){
		color[i] = WHITE;
	//	prevv[i] = NIL;
		d[i] = INF;
	}
	
	color[source] = BLUE;
	d[source] = 0;
	prevv[source] = NIL;
	
	Queue q;
	q.push(source);
	
	while (!q.empty()){
		int u = q.pop();
		
		for (int v=0;v<N;v++){
			if (graph[u][v] == 1){
				if (color[v] == WHITE){
					
					if (color[u] == BLUE){
						color[v] = RED;
					}
					else color[v] = BLUE;
					
					prevv[v] = u;
				}		
			}
		}
	}
	
	for (int u = 0;u<nodes;u++){
		
		for (int v=0;v<nodes;v++){
			if (graph[u][v] == 1){
				if (color[u] == color[v])
					bipartite = 0;
			}
		}
	}
	
	
	return bipartite;
}
void print_path(int s, int v){
	
	if (v == s){
		cout << s << " ";
	}
	else if (prevv[v] == NIL){
		cout << "No path\n";
	}
	else {
		print_path(s,prevv[v]);
		cout << v << " ";
	}
}
int main (){
	//cout << "Enter the number of nodes: ";
	int nodes;
	cin >> nodes;
	
	while(1){
		int u,v;
		cin>>u >>v;
		
		if (u == -1 and v == -1) break;
		
		graph[u][v] = 1;
		graph[v][u] = 1;
	}
	
	//cout << "Enter the source: ";
	//int source;
	//cin>>source;
	//cout << endl;
	
	//bfs(source);
	
	//for (int i=0;i<nodes;i++){
		//cout << "d[" << i << "] = " << d[i] << endl;
	//}
	
	//cout << "Enter source and destination: ";
	int s, v;
	cin >> s  >> v;
//	cout << endl;
	
	//bfs(s);
	//cout << "Path from " << s << " to " << v<< endl;
	//print_path(s,v);
	//cout << endl;
	
	for (int i=0;i<nodes;i++){
		if (check_bipartite(i,nodes)){
			cout << "Bipartite, when checked from source " << i << "\n";
			return 0;
		}
	}
	cout << "Not bipartite\n";
}