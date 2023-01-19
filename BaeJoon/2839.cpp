#include <iostream>

using namespace std;

int main() {
  int kg;
  cin >> kg;

  int a, b;
  b = kg / 5;

  while (1) {
    if (b < 0) {
      cout << "-1";
      return 0;
    }
    if ((kg - (5 * b)) % 3 == 0) {
      a = (kg - (5 * b)) / 3;
      break;
    }
    b--;
  }
  cout << a + b << endl;
  return 0;
}
