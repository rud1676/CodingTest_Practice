#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define MAX 51

using namespace std;

int map[MAX][MAX];
int v[MAX][MAX];
int x, y;
int rdir = 0;
int dir = 0;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int result = 1;
bool tw = false;

int dirchange(int i) { return (dir + 3 - i) % 4; }
bool checkdir() {
  int c = 0;
  for (c = 0; c < 4; c++) {
    int d = dirchange(c);
    if (v[y + dy[d]][x + dx[d]] == 0) {
      y = y + dy[d];
      x = x + dx[d];
      v[y][x] = ++result;
      dir = d;
      return true;
    }
  }
  if (c == 4) {

    if (v[y + dy[(2 + dir) % 4]][x + dx[(2 + dir) % 4]] != -1) {
      y = y + dy[(2 + dir) % 4];
      x = x + dx[(2 + dir) % 4];
      return true;
    }
  }
  return false;
}
int main() {
  int n, m;

  cin >> n >> m;

  cin >> y >> x >> dir;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];
      if (map[i][j] == 1) {
        v[i][j] = -1;
      }
    }
  }
  v[y][x] = 1;
  while (checkdir()) {
  }
  cout << result << endl;
}
