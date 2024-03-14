#include <iostream>

using namespace std;

bool backtracking(){
  
}

int main(){
  while(1){
    int tamanho;
    cin >> tamanho;
    if(tamanho == 0)
      return 0;
    int notReached = 0;
    int tabuleiro[tamanho][tamanho];
    int espacos, quadrados;
    for(int i = 0; i < tamanho; i++){
      cin >> espacos >> quadrados;
      for(int j = 0; j < tamanho; j++){
        if(espacos != 0){
          tabuleiro[i][j] = 2;
          espacos--;
        }
        else if(quadrados != 0){
          tabuleiro[i][j] = 0;
          notReached++;
          quadrados--;
        }
        else
          tabuleiro[i][j] = 2;
      }
    }

    for(int k = 0; k < tamanho; k++){
      if(tabuleiro[0][k] == 0){
        tabuleiro[0][k] = 1;
        notReached--;
      }
      
    }

    // for(int i = 0; i < tamanho; i++)
    //   for(int j = 0; j < tamanho; j++)
    //     if(tabuleiro[i][j] == 0)
    //       notReached++;

    int caso = 1;
    if(notReached == 1)
      cout << "Case " << caso << ", " << notReached << " square can not be reached.\n";
    else
      cout << "Case " << caso << ", " << notReached << " squares can not be reached.\n";
    caso++;
  }
}