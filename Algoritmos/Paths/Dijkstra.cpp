#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
using namespace std;

struct Edge{
  int destino, weight;
};

class Graph{
public:
  long int vertices;
  int *distance;
  int *visited;
  int *parent;
  vector<vector<Edge>> adjList;

  Graph(){}
  Graph(long int vertices){
      this->vertices = vertices;
      distance = new int[vertices];
      visited = new int[vertices];
      parent = new int[vertices];
  }
  ~Graph(){
    delete[] distance;
    delete[] visited;
  }

  void dijkstra(long int start){
    for(long int i = 0; i < vertices; i++){
      visited[i] = 0;
      distance[i] = INT_MAX;
      parent[i] = -1;
    }
    distance[start] = 0;
        
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int, pair<int,int>>>> heap;
    int v = start, p;
    heap.push(make_pair(0, make_pair(start, start)));

    for(int i = 0; i < vertices; i++){
    do{
      if(heap.empty())
        return;
      p = heap.top().second.first;
      v = heap.top().second.second;
      heap.pop();
    } while(visited[v]);
    visited[v] = 1;
    parent[v] = p;

    for(auto w : adjList[v]){
      if(!visited[w.destino] && distance[w.destino] > distance[v] + w.weight){
        distance[w.destino] = distance[v] + w.weight;
        heap.push(make_pair(distance[w.destino], make_pair(v, w.destino)));
        }
      }
    }
  }
};


int main(){
  int casos;
  cin >> casos;
  int k = 1;

  for(int i = 0; i < casos; i++){
    long int n, ops, origemFind, destinoFind;
    cin >> n >> ops >> origemFind >> destinoFind;

    Graph g(n);
    g.adjList.resize(n);
    for(long int j = 0; j < ops; j++){
      long int origem, destino, weight;
      cin >> origem >> destino >> weight;

      Edge add;
      add.destino = destino;
      add.weight = weight;
      g.adjList[origem].push_back(add);
      add.destino = origem;
      g.adjList[destino].push_back(add);
    }

    g.dijkstra(origemFind);
    if(g.distance[destinoFind] == INT_MAX)
      cout << "Case #" << k << ": unreachable" << "\n";
    else
      cout << "Case #" << k << ": " << g.distance[destinoFind] << "\n";
    k++;
  }
}