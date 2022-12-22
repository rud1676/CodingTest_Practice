#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

void bfs(int start, vector<vector<int>> edge, int n) {
  vector<bool> visit(n + 1);
  queue<int> q;
  int s;

  q.push(start);
  while (q.size() != 0) {
    s = q.front();
    q.pop();

    if (false == visit[s]) {
      cout << s << " ";
      for (int i = 0; i < edge[s].size(); i++) {
        int t = edge[s][i];
        q.push(t);
      }
      visit[s] = true;
    }
  }
  cout << endl;
}

void dfs(int start, vector<vector<int>> edge, int n) {
  vector<bool> visit(n + 1);
  stack<int> q;
  int s;

  q.push(start);
  while (q.size() != 0) {
    s = q.top();
    q.pop();

    if (false == visit[s]) {
      cout << s << " ";
      for (int i = edge[s].size() - 1; i >= 0; i--) {
        int t = edge[s][i];
        q.push(t);
      }
      visit[s] = true;
    }
  }
  cout << endl;
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> edge(n + 1);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }

  for (int i = 1; i <= n; i++) {
    sort(edge[i].begin(), edge[i].end());
  }

  dfs(k, edge, n);
  bfs(k, edge, n);
}
