#include <iostream>
#include <vector>
using namespace std;

int main() {

  int n;
  cin >> n;

  vector<int> map1(n);
  vector<int> copymap1(n);
  vector<int> map2(n);

  for (int i = 0; i < n; i++) {
    scanf("%1d", &map1[i]);
    copymap1[i] = map1[i];
  }
  for (int i = 0; i < n; i++) {
    scanf("%1d", &map2[i]);
  }

  int count = 0;
  // 안누르고 진행
  for (int i = 1; i < n; i++) {
    if (i == n - 1) {
      if (map1[i - 1] != map2[i - 1]) {
        count++;
        map1[i - 1] = 1 - map1[i - 1];
        map1[i] = 1 - map1[i];
      }
    } else {
      if (map1[i - 1] != map2[i - 1]) {
        count++;
        map1[i - 1] = 1 - map1[i - 1];
        map1[i] = 1 - map1[i];
        map1[i + 1] = 1 - map1[i + 1];
      }
    }
  }

  int check = false;
  for (int i = 0; i < n; i++) {
    if (map1[i] != map2[i]) {
      check = true;
    }
  }
  if (check == false) {
    cout << count << endl;
    return 0;
  }

  count = 1;
  // 누르고 진행
  copymap1[0] = 1 - copymap1[0];
  copymap1[1] = 1 - copymap1[1];
  for (int i = 1; i < n; i++) {
    if (i == n - 1) {
      if (copymap1[i - 1] != map2[i - 1]) {
        count++;
        copymap1[i - 1] = 1 - copymap1[i - 1];
        copymap1[i] = 1 - copymap1[i];
      }
    } else {
      if (copymap1[i - 1] != map2[i - 1]) {
        count++;
        copymap1[i - 1] = 1 - copymap1[i - 1];
        copymap1[i] = 1 - copymap1[i];
        copymap1[i + 1] = 1 - copymap1[i + 1];
      }
    }
  }

  check = false;
  for (int i = 0; i < n; i++) {
    if (copymap1[i] != map2[i]) {
      check = true;
    }
  }
  if (check == false) {
    cout << count << endl;
    return 0;
  }

  cout << -1 << endl;
  return 0;
}
