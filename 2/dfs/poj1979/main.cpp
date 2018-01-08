#include <stdio.h>
#include <assert.h>
#include <utility>

using namespace std;

struct tile{
  bool black; // visitable
  bool visited;
};

pair<int, int> adjs[4];

int w, h;
pair<int, int> pos;
tile map[21][21];
int blacks;

int solve(pair<int, int> pos){
  tile* current = &map[pos.first][pos.second];
  if(current->visited == false && current->black){
    current->visited = true;
    blacks++;
    for(int i=0; i < 4; i++){
      pair<int, int> next = pos;
      next.first += adjs[i].first;
      next.second += adjs[i].second;
      if(0 <= next.first && next.first < w){
        if(0 <= next.second && next.second < h){
          solve(next);
        }
      }
    }
  }
  return blacks;
}

void testMap(){
  for(int y=0; y < h; y++){
    for(int x=0; x < w; x++){
      if(map[x][y].black){
        printf(".");
      }else{
        printf("#");
      }
    }
    printf("\n");
  }
}

int main(){
  adjs[0].first = 1; adjs[0].second = 0;
  adjs[1].first = -1; adjs[1].second = 0;
  adjs[2].first = 0; adjs[2].second = 1;
  adjs[3].first = 0; adjs[3].second = -1;
  while(true){
    scanf("%d %d\n", &w, &h);
    if(w == 0 && h == 0){
      break;
    }
    for(int y=0; y < h; y++){
      for(int x=0; x < w + 1; x++){
        map[x][y].visited = false;
        char c;
        scanf("%c", &c);
        if(c == '.'){
          map[x][y].black = true;
        }else if(c == '#'){
          map[x][y].black = false;
        }else if(c == '@'){
          map[x][y].black = true;
          pos.first = x;
          pos.second = y;
        }else if(c == '\n'){
          
        }else{
          assert(false);
        }
      }
    }
    // testMap();
    blacks = 0;
    printf("%d\n", solve(pos));
  }
  return 0;
}
