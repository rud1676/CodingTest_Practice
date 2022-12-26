#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
int m, n;

class trace {
public:
  int m;
  int n;
  int count;
  trace(int n, int m) {
    this->m = m;
    this->n = n;
    this->count = 0;
  }
  trace(int n, int m, int c) {
    this->m = m;
    this->n = n;
    this->count = c;
  }

  bool operator==(const pair<int, int> other) {
    return (this->m == other.first && this->n == other.second);
  }
  bool operator==(const trace &other) {
    return (this->m == other.m && this->n == other.n);
  }
  bool operator==(const trace *other) {
    return (this->m == other->m && this->n == other->n);
  }
};
bool canmove(vector<vector<int>> map, pair<int, int> check) {
  if (check.first < 0 || check.first >= n)
    return false;
  else if (check.second < 0 || check.second >= m)
    return false;

  if (map[check.first][check.second] == 0)
    return false;
  return true;
}

int bfs(vector<vector<int>> map, int m, int n) {
  vector<trace *> v;
  queue<trace *> q;

  q.push(new trace(0, 0, 0));

  while (!q.empty()) {
    trace *t = q.front();
    q.pop();
    auto f = find(v.begin(), v.end(), t);
    // 방문하지 않았다면
    if (f == v.end()) {
      // 4방향 체크해서 큐에 넣어주기
      if (t->n == n - 1 && t->m == m - 1) {
        return t->count;
      }
      if (canmove(map, make_pair(t->n + 1, t->m))) {
        q.push(new trace(t->n + 1, t->m, t->count + 1));
      } else if (canmove(map, make_pair(t->n - 1, t->m))) {
        q.push(new trace(t->n - 1, t->m, t->count + 1));
      } else if (canmove(map, make_pair(t->n, t->m + 1))) {
        q.push(new trace(t->n, t->m + 1, t->count + 1));
      } else if (canmove(map, make_pair(t->n, t->m - 1))) {
        q.push(new trace(t->n, t->m - 1, t->count + 1));
      }
      v.push_back(new trace(t->n, t->m, t->count));
    }
  }
  return -1;
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> map(n);

  for (int i = 0; i < n; i++) {
    map[i].assign(m, 0);
    for (int j = 0; j < m; j++) {
      scanf("%1d", &map[i][j]);
    }
  }

  bfs(map, m, n);
}
