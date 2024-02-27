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
  }
  ~Graph(){
    delete[] distance;
    delete[] visited;
  }

  void prim(){
    for(long int i = 0; i < vertices; i++){
      visited[i] = 0;
      distance[i] = INT_MAX;
    }

    distance[0] = 0;
        
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int, pair<int,int>>>> heap;
    heap.push(make_pair(0, make_pair(0, 0)));

    int v;
    for(int i = 0; i < vertices; i++){
      do{
        if(heap.empty())
          return;
        v = heap.top().second.second;
        heap.pop();
      } while(visited[v]);
      visited[v] = 1;

      for(auto w : adjList[v]){
        if(!visited[w.destino] && distance[w.destino] > w.weight){
          distance[w.destino] = w.weight;
          heap.push(make_pair(distance[w.destino], make_pair(v, w.destino)));
        }
      }
    }
  }
};


int main(){
  while(1){
    int n, m;
    cin >> n >> m;
    if(n == 0 && m == 0)  return 0;
    
    Graph g(n);
    g.adjList.resize(n);
    for(long int i = 0; i < m; i++){
      long int origem, destino, weight;
      cin >> origem >> destino >> weight;

      Edge add;
      add.destino = destino;
      add.weight = weight;
      g.adjList[origem].push_back(add);
      add.destino = origem;
      g.adjList[destino].push_back(add);
    }

    g.prim();
    int maior = 0;
    for(int i = 0; i < n; i++)
      if(g.distance[i] > maior)
        maior = g.distance[i];
    if(maior == INT_MAX)
      cout << "IMPOSSIBLE\n";
    else
      cout << maior << "\n";
  }

}