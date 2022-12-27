#include <iostream>
#include <queue>
#include <vector>

#define MAX 101

using namespace std;

int n;
int v[MAX];

int bfs(int start, int end, vector<vector<int>> rel) {
  queue<int> q;
  q.push(start);
  while (!q.empty()) {
    int c = q.front();
    q.pop();

    for (int i = 0; i < rel[c].size(); i++) {
      if (rel[c][i] == end)
        return v[c] + 1;
      if (v[rel[c][i]] == 0) {
        v[rel[c][i]] = v[c] + 1;
        q.push(rel[c][i]);
      }
    }
  }
  return -1;
}

int main() {

  cin >> n;

  vector<vector<int>> rel(n + 1);

  int start, end;
  cin >> start >> end;

  int m;
  cin >> m;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    rel[a].push_back(b);
    rel[b].push_back(a);
  }
  cout << bfs(start, end, rel) << endl;
}
