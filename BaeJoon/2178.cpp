#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define MAX 101

using namespace std;

int m, n;
int map[MAX][MAX];
int vis[MAX][MAX];
int dist[MAX][MAX];
int dir_x[4] = {0, 0, 1, -1};
int dir_y[4] = {1, -1, 0, 0};

bool canmove(int y, int x) {
  if (y < 0 || y >= n)
    return false;
  else if (x < 0 || x >= m)
    return false;

  if (map[y][x] == 0)
    return false;
  if (vis[y][x])
    return false;
  return true;
}

void bfs(int starty, int startx) {
  queue<pair<int, int>> q;

  q.push(make_pair(0, 0));
  dist[0][0] = 1;

  while (!q.empty()) {
    pair<int, int> t = q.front(); // first y second x
    q.pop();
    // 4방향 체크해서 큐에 넣어주기
    pair<int, int> nt;
    for (int i = 0; i < 4; i++) {
      if (canmove(t.first + dir_y[i], t.second + dir_x[i])) {
        nt = make_pair(t.first + dir_y[i], t.second + dir_x[i]);
        dist[nt.first][nt.second] = dist[t.first][t.second] + 1;
        vis[nt.first][nt.second] = 1;
        q.push(make_pair(nt.first, nt.second));
      }
    }
  }
}

int main() {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%1d", &map[i][j]);
    }
  }
  bfs(0, 0);
  cout << dist[n - 1][m - 1] << endl;
}
