#include <iostream>
#include <queue>
#include <vector>
#define MAX 301

using namespace std;

int n, m;
int v[MAX][MAX];
int map[MAX][MAX];
int dir_x[] = {0, 0, 1, -1};
int dir_y[] = {1, -1, 0, 0};
int yearcnt = 0;

int isSea(int y, int x, int copymap[][MAX], int mode = 0) {
  if (y < 0 || y >= n)
    return 0;
  if (x < 0 || x >= m)
    return 0;
  if (copymap[y][x] != 0 && mode == 0)
    return 0;
  if (mode == 1 && v[y][x] != 0)
    return 0;
  return 1;
}

void afterYear() {
  int copymap[MAX][MAX] = {
      0,
  };

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      copymap[i][j] = map[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int cnt = 0;
      for (int k = 0; k < 4; k++) {
        cnt += isSea(i + dir_y[k], j + dir_x[k], copymap);
      }
      map[i][j] -= cnt;
      if (map[i][j] < 0)
        map[i][j] = 0;
    }
  }
  yearcnt++;
}

int main() {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];
    }
  }

  bool change;
  do {
    change = false;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (map[i][j] != 0) {
          v[i][j] = 0;
          change = true;
        } else {
          v[i][j] = 1;
        }
      }
    }

    int area = 0;
    if (change) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

          if (v[i][j] == 0) {
            area++;
            queue<vector<int>> q;
            vector<int> t = {i, j};
            q.push(t);
            while (!q.empty()) {
              vector<int> tc = q.front();
              q.pop();
              for (int k = 0; k < 4; k++) {
                vector<int> tcc = {tc[0] + dir_y[k], tc[1] + dir_x[k]};
                if (isSea(tcc[0], tcc[1], v, 1)) {
                  q.push(tcc);
                  v[tcc[0]][tcc[1]] = 1;
                }
              }
            }
          }
        }
      }
    }

    if (area >= 2) {
      cout << yearcnt << endl;
      return 0;
    }
    afterYear();
  } while (change);
  cout << 0 << endl;
  return 0;
}
