#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> checkManyTLine(vector<string> arr, int n) {
  int total = 0;
  int maxn = 0, maxm = 0;
  for (int i = 0; i < n; i++) {
    int cur = 0;
    for (int j = 0; j < n; j++) {
      if (arr[i][j] == 'T')
        cur++;
    }
    if (cur > total) {
      maxn = i;
    }
  }

  total = 0;
  for (int j = 0; j < n; j++) {
    int cur = 0;
    for (int i = 0; i < n; i++) {
      if (arr[i][j] == 'T')
        cur++;
    }
    if (cur > total) {
      maxm = j;
    }
  }
  vector<int> re(2);
  if (maxm > maxn) {
    re[0] = 0;
    re[1] = maxm;
  } else {
    re[0] = maxn;
    re[1] = 0;
  }
  return re;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<string> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int totalt = 9999999;
  bool cont = true;
  while (cont) {
    vector<int> maxis = checkManyTLine(arr, n);
    cout << maxis[0] << ' ' << maxis[1] << endl;
    if (maxis[0] == 0 && maxis[1] == 0) {
      cout << 0 << endl;
      return 0;
    }
    if (maxis[0] == 0 && maxis[1] < totalt) {
      totalt = maxis[1];
    } else if (maxis[1] == 0 && maxis[0] < totalt) {
      totalt = maxis[0];
    } else {
      cont = false;
    }
  }
  cout << totalt << endl;
}
