#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, goal;
  cin >> n >> goal;
  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int sum = 0;
  for (int i = n - 1; i >= 0; i--) {
    sum += goal / arr[i];
    goal %= arr[i];
  }

  cout << sum << endl;
}
