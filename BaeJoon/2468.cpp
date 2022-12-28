#include <iostream>
#include <queue>
#include <vector>
#define MAX 101

using namespace std;

int map[MAX][MAX];
int v[MAX][MAX];
int n;
int dir_x[] = {0, 0, 1, -1};
int dir_y[] = {1, -1, 0, 0};

bool isMove(int y, int x) {
  if (v[y][x] == 1)
    return false;
  if (y < 0 || y >= n)
    return false;
  if (x < 0 || x >= n)
    return false;
  return true;
}

int main() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> map[i][j];
    }
  }

  int maxN = -1;
  for (int a = 0; a <= 100; a++) {
    // visit init
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        v[i][j] = 0;
      }
    }

    // visit info draw
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (map[i][j] <= a) {
          v[i][j] = 1;
        }
      }
    }

    // bfs
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (v[i][j] == 0) {
          cnt++;

          queue<vector<int>> q;
          vector<int> t = {i, j};
          q.push(t);
          while (!q.empty()) {
            vector<int> tc = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
              if (isMove(tc[0] + dir_y[k], tc[1] + dir_x[k])) {
                vector<int> tcc = {tc[0] + dir_y[k], tc[1] + dir_x[k]};
                q.push(tcc);
                v[tcc[0]][tcc[1]] = 1;
              }
            }
          }
        }
      }
    }
    if (maxN < cnt)
      maxN = cnt;
  }
  cout << maxN << endl;
}
