#include <iostream>
#include "Vector.h"
using namespace std;

int main()
{
  int n = 3;
  TDynamicVector<int> a(n);

  for (int i = 0; i < n; i++)
    a[i] = i + 1;

  TDynamicVector<int> b = a;
  TDynamicVector<int> c;

  c = a + b;
  cout << c;

  for (auto i = c.begin(); i != c.end(); ++i)
    cout << *i;
  return 0;
}