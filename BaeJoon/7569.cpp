#include <iostream>
#include <queue>
#include <vector>
#define MAX 101

using namespace std;

int dir_y[] = {0, 0, 0, 0, 1, -1};
int dir_x[] = {0, 0, 1, -1, 0, 0};
int dir_z[] = {1, -1, 0, 0, 0, 0};
int m, n, h;
int map[MAX][MAX][MAX];
int v[MAX][MAX][MAX];

bool canmove(int y, int x, int z) {
  // scope check
  if (y < 0 || y >= h)
    return false;
  if (x < 0 || x >= n)
    return false;
  if (z < 0 || z >= m)
    return false;

  if (map[y][x][z] != 0)
    return false;
  if (v[y][x][z] != 0)
    return false;

  return true;
}

int main() {

  queue<vector<int>> q;
  cin >> m >> n >> h;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        cin >> map[i][j][k];
        if (map[i][j][k] == 1) {
          vector<int> tv;
          tv.push_back(i);
          tv.push_back(j);
          tv.push_back(k);
          q.push(tv);
          v[i][j][k] = 1;
        }
      }
    }
  }

  int step = 1;

  while (!q.empty()) {
    int a = q.front()[0];
    int b = q.front()[1];
    int c = q.front()[2];
    q.pop();
    for (int l = 0; l < 6; l++) {
      vector<int> tc;
      tc.push_back(a + dir_y[l]);
      tc.push_back(b + dir_x[l]);
      tc.push_back(c + dir_z[l]);
      if (canmove(tc[0], tc[1], tc[2])) {

        q.push(tc);
        v[tc[0]][tc[1]][tc[2]] = v[a][b][c] + 1;
        if (step < v[a][b][c] + 1)
          step = v[a][b][c] + 1;
      }
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        if (v[i][j][k] == 0 && map[i][j][k] != -1) {
          cout << -1 << endl;
          return 0;
        }
      }
    }
  }

  cout << step - 1 << endl;
  return 0;
}
