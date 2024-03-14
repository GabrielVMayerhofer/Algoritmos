#include <iostream>
#include <set>

using namespace std;

class Tabuleiro{
public:
  int tabuleiro[10][10];
  int solucao = 101;
  int notReached = 0;

  Tabuleiro(){}
  Tabuleiro(int linhas){
    int espacos, quadrados;
    for(int i = 0; i < linhas; i++){
      cin >> espacos >> quadrados;
      for(int j = 0; j < 10; j++){
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
  }
  ~Tabuleiro(){}

  bool backtracking(int x, int y, int linhas){
    int movesX[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int movesY[] = {-1, 1, -2, 2, -2, 2, -1, 1};

    for(int i = 0; i < 8; i++){
      int novoX = x+movesX[i];
      int novoY = y+movesY[i];
      if(tabuleiro[novoX][novoY] == 0 && novoX < linhas && novoY < 10 && novoX >= 0 && novoY >= 0){
        tabuleiro[novoX][novoY] = 1;
        notReached--;
        solucao = (solucao < notReached ? solucao : notReached);
        backtracking(novoX, novoY, linhas);
        tabuleiro[novoX][novoY] = 0;
        notReached++;
      }
      
    }
    // tabuleiro[x][y] = 0;
    // notReached++;
    return false;
  }

  void print(int caso){
    if(solucao == 1)
      cout << "Case " << caso << ", " << solucao << " square can not be reached.\n";
    else
      cout << "Case " << caso << ", " << solucao << " squares can not be reached.\n";
  }
};

int main(){
  int caso = 1;
  while(1){
    int tamanho;
    cin >> tamanho;
    if(tamanho == 0)
      return 0;
    Tabuleiro mapa(tamanho);
    int startX, startY;
    bool achou = false;
    for(int i = 0; i < tamanho; i++){
      for(int j = 0; j < tamanho; j++){
        if(mapa.tabuleiro[i][j] == 0){
          startX = i; startY = j;
          mapa.tabuleiro[i][j] = 1;
          mapa.notReached--;
          mapa.solucao = mapa.notReached;
          achou = true;
          break;
        }
      }
      if(achou)
        break;
    }
    mapa.backtracking(startX, startY, tamanho);

    mapa.print(caso);
    caso++;
    mapa.notReached = 0;
    mapa.solucao = 101;
  }
}