#include <iostream>
#include <queue>
#include <vector>

#define MAX 25 * 25

using namespace std;

int n;
int m;
int v[MAX];

int main() {
  cin >> n >> m;

  vector<vector<int>> gf(n + 1);

  queue<int> q;
  q.push(1);
  v[1] = 1;

  for (int i = 0; i < m; i++) {
    int k, l;
    cin >> k >> l;
    gf[k].push_back(l);
    gf[l].push_back(k);
  }

  while (!q.empty()) {
    int c = q.front();
    q.pop();
    for (int i = 0; i < gf[c].size(); i++) {
      if (v[gf[c][i]] == 0 && v[gf[c][i]] == 0) {
        q.push(gf[c][i]);
        v[gf[c][i]] = 1;
      }
    }
  }

  int count = 0;
  for (int i = 0; i < MAX; i++) {
    if (v[i] == 1)
      count++;
  }
  cout << count - 1 << endl;
}
