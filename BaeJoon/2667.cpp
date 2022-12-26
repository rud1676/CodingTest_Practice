#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

#define MAX 625

int n;
int map[25][25];
int v[25][25];
int area = 1;
int dir_x[] = {0, 0, 1, -1};
int dir_y[] = {1, -1, 0, 0};

bool checkmove(int y, int x) {
  if (y >= n || y < 0 || x >= n || x < 0)
    return false;
  if (v[y][x] != 0)
    return false;
  if (map[y][x] == 0)
    return false;
  return true;
}
int main() {

  cin >> n;

  vector<int> areaCount;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%1d", &map[i][j]);
    }
  }

  // i => y , j => x
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (v[i][j] != 0)
        continue;
      if (map[i][j] == 0)
        continue;

      queue<pair<int, int>> q;
      q.push(make_pair(i, j));
      areaCount.push_back(1);
      v[i][j] = area;

      while (!q.empty()) {
        pair<int, int> c = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
          if (checkmove(c.first + dir_y[k], c.second + dir_x[k])) {
            q.push(make_pair(c.first + dir_y[k], c.second + dir_x[k]));
            v[c.first + dir_y[k]][c.second + dir_x[k]] = area;
            areaCount[area - 1]++;
          }
        }
      }

      area++;
    }
  }

  cout << area - 1 << endl;
  sort(areaCount.begin(), areaCount.end());
  for (int i = 0; i < areaCount.size(); i++) {
    cout << areaCount[i] << endl;
  }
}
