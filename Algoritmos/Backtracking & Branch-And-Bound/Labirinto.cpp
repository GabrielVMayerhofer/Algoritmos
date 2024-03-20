#include <iostream>
#include <set>
#include <utility>

using namespace std;

class Labirinto{
public:
  int startX, startY;
  char mapa[41][41];
  int linhas, colunas, limiteInicial, limite;
  bool tesouro = false;
  set<pair<int, int>> visited;

  Labirinto(){}
  Labirinto(int linha, int coluna, int spikes){
    this->linhas = linha;
    this->colunas = coluna;
    this->limite = spikes;
    this->limiteInicial = spikes;

    for(int i = 0; i < linha; i++)
      for(int j = 0; j < coluna; j++){
        cin >> mapa[i][j];
        if(mapa[i][j] == '@'){
          startX = i; startY = j;
        }
      }
  }
  ~Labirinto(){}

  bool isValid(int x, int y){
    if(mapa[x][y] == '#' || (mapa[x][y] == 's' && limite == 0) || x >= linhas || y >= colunas || x < 0 || y < 0)
      return false;
    else  
      return true;
  }

  bool backtracking(int x, int y){
    pair <int,int> atual(x,y);
    if(visited.find(atual) != visited.end())
      return false;
    visited.insert(atual);

    // cout << "\n" << x << " " << y << "\n";
    int movesX[] = {-1, 1, 0, 0};
    int movesY[] = {0, 0, -1, 1};

    for(int i = 0; i < 4; i++){
      int novoX = x+movesX[i];
      int novoY = y+movesY[i];
      if(!isValid(novoX, novoY))
        continue;

      // cout << novoX << " " << novoY << "\n";
      if(mapa[novoX][novoY] == '.'){
        if(backtracking(novoX, novoY))
          return true;
      }
      else if(mapa[novoX][novoY] == 's'){
        limite--;
        if(backtracking(novoX, novoY)) 
          return true;
        limite++;
      }
      else if(mapa[novoX][novoY] == 'x'){
        if(2*limite >= limiteInicial){
          tesouro = true;
          cout << "SUCCESS";
          return true;
        }
        else
          return false;
      }
    }
    return false;
  }
};

int main(){
  int rows, columns, limite;
  cin >> rows >> columns >> limite;
  Labirinto lab(rows, columns, limite);

  lab.backtracking(lab.startX, lab.startY);

  if(!lab.tesouro)
    cout << "IMPOSSIBLE";

}