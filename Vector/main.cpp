#include <iostream>
#include "Vector.h"
#include "SquareMatrix.h"
#include <sstream>
using namespace std;

void testMatrix()
{
  constexpr int n = 3;
  TSquareMatrix<int> m1(n);
  TSquareMatrix<int> m2(m1);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      m1[i][j] = i + j;
      m2[i][j] = i + j + 10;
    }
  }

  TSquareMatrix<int> m3(n);

  m3 = m1 + m2;

  cout << "m1=" << m1;
  cout << "m2=" << m2;
  cout << "m3=" << m3;
}

void testMultMatrix()
{
  constexpr int n = 2;
  TSquareMatrix<int> m1(n);
  TSquareMatrix<int> m2(n);
  TSquareMatrix<int> m3(n);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      m1[i][j] = i + j;
      m2[i][j] = i + j + 1;
    }
  }

  m2[0][1] = 3;

  cout << "m1=" << m1 << endl;
  cout << "m2=" << m2 << endl;

  m3 = m1 * m2;
  cout << m3;
}

void testCreateMatix()
{
  const int arr[4] = {3, 2, 4, 5};
  TSquareMatrix<int> tmp(2, arr);
  cout << tmp;
}

void testVectorIterator()
{
  constexpr int n = 3;
  TDynamicVector<int> a(n);

  for (int i = 0; i < n; i++)
    a[i] = i + 1;

  TDynamicVector<int> b = a;
  TDynamicVector<int> c;

  c = a + b;
  cout << c;


  //for (auto i = c.begin(); i != c.end(); ++i)
  //  cout << *i;

  for (auto& v : c)
  {
    v = v + 1;
  }
  cout << c;

}

int main()
{
  try
  {
    testCreateMatix();
    //testMultMatrix();
    //testVectorIterator();
    //testMatrix();
  }
  catch (...)
  {
    cout << "exeption";
  }

  return 0;
}