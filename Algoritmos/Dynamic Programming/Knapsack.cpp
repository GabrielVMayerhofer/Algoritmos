#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int max(int a, int b){
  if(a > b)
    return a;
  return b;
}

int main(){
  int capacity, numItems;
  cin >> capacity >> numItems;

  int peso[numItems+1], valor[numItems+1];
  for(int i = 1; i <= numItems; i++){
    cin >> peso[i] >> valor[i];
  }

  int mochila[numItems+1][capacity+1];
  for(int i = 0; i <= numItems; i++)
    for(int j = 0; j <= capacity; j++){
      if(i == 0 || j == 0)
        mochila[i][j] = 0;
      else if(peso[i] <= j)
        mochila[i][j] = max(mochila[i-1][j], valor[i] + mochila[i-1][j-peso[i]]);
      else
        mochila[i][j] = mochila[i-1][j];
    }
  cout << mochila[numItems][capacity];
}