#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

int main(){
  int numRocks, maxJump;
  cin >> numRocks >>maxJump;

  int caminho[numRocks];
  for(int i = 0; i < numRocks; i++)
    cin >> caminho[i];

  int cost[numRocks];
  cost[0] = 0;

  for(int i = 1; i < numRocks; i++){
    int minCost = INT_MAX;
    for(int j = 1; j <= (maxJump < i ? maxJump : i); j++){
      int currCost = abs(caminho[i] - caminho[i-j]) + cost[i-j];
      minCost = (minCost < currCost ? minCost : currCost);
    } 
    cost[i] = minCost;
  }
  cout << cost[numRocks-1];
}