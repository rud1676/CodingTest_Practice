#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> map1(n);
  vector<vector<int>> map2(n);

  for (int i = 0; i < n; i++) {
    vector<int> temp(m);
    map1[i] = temp;
    for (int j = 0; j < m; j++) {
      scanf("%1d", &map1[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    vector<int> temp(m);
    map2[i] = temp;
    for (int j = 0; j < m; j++) {
      scanf("%1d", &map2[i][j]);
    }
  }

  if (n < 3 || m < 3) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (map1[i][j] != map2[i][j]) {
          cout << -1 << endl;
          return 0;
        }
      }
    }
    cout << 0 << endl;
    return 0;
  }
  int changecount = 0;
  for (int i = 0; i < n - 2; i++) {
    for (int j = 0; j < m - 2; j++) {
      if (map1[i][j] != map2[i][j]) {
        changecount++;
        // change
        for (int k = 0; k < 3; k++) {
          for (int l = 0; l < 3; l++) {
            map1[k + i][l + j] = 1 - map1[k + i][l + j];
          }
        }
        //
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (map1[i][j] != map2[i][j]) {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  cout << changecount << endl;
  return 0;
}
