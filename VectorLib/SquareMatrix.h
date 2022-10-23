#pragma once
#include "Vector.h"

template <class T>
class TSquareMatrix : public TDynamicVector<TDynamicVector<T>>
{
  using::TDynamicVector<TDynamicVector<T>>::pMem;
  using::TDynamicVector<TDynamicVector<T>>::sz;
public:
  TSquareMatrix(size_t size1);
  TSquareMatrix(size_t size,const T* arr);
  TSquareMatrix(const TSquareMatrix<T>& mat) noexcept;
  TSquareMatrix(TSquareMatrix<T>&& mat);

  bool operator == (const TSquareMatrix<T>& mat) const noexcept;
  bool operator != (const TSquareMatrix<T>& mat) const noexcept;

  TSquareMatrix<T> operator + (const TSquareMatrix<T>& mat);
  TSquareMatrix<T> operator - (const TSquareMatrix<T>& mat);
  TSquareMatrix<T> operator * (const TSquareMatrix<T>& mat);
  
  TSquareMatrix<T> operator = (TSquareMatrix<T>&& mat);
  TSquareMatrix<T> operator = (const TSquareMatrix<T>& mat);
};

template<class T>
inline TSquareMatrix<T>::TSquareMatrix(size_t size, const T* arr) : TSquareMatrix<T>(size)
{
  if (size == 0)
    throw out_of_range("size must be greater than zero");
  for (size_t i = 0; i < sz*sz; i++)
    pMem[i / sz][i % sz] = arr[i];
}

template<class T>
inline TSquareMatrix<T>::TSquareMatrix(size_t size1): TDynamicVector<TDynamicVector<T>> (size1)
{
  for (size_t i = 0; i < sz; i++)
    pMem[i] = TDynamicVector<T>(sz);
}

template<class T>
inline TSquareMatrix<T>::TSquareMatrix(const TSquareMatrix<T>& mat) noexcept : TDynamicVector<TDynamicVector<T>> (mat)
{
  if (mat.pMem == nullptr)
  {
    pMem = nullptr;
    sz = 0;
  }
  else
  {
    sz = mat.sz;
    pMem = new TDynamicVector<T>[sz];
    for (size_t i = 0; i < sz; i++)
      pMem[i] = mat.pMem[i];
  }
}

template<class T>
inline TSquareMatrix<T>::TSquareMatrix(TSquareMatrix<T>&& mat)
{
  pMem = mat.pMem;
  sz = mat.sz;
  mat.pMem = nullptr;
  mat.sz = 0;
}

template<class T>
inline bool TSquareMatrix<T>::operator==(const TSquareMatrix<T>& mat) const noexcept
{
  return TDynamicVector<TDynamicVector<T>>::operator ==(mat);
}

template<class T>
inline bool TSquareMatrix<T>::operator!=(const TSquareMatrix<T>& mat) const noexcept
{
  return TDynamicVector<TDynamicVector<T>>::operator !=(mat);
}

template<class T>
inline TSquareMatrix<T> TSquareMatrix<T>::operator+(const TSquareMatrix<T>& mat)
{
  TSquareMatrix<T> res(sz);
  for (size_t i = 0; i < sz; i++)
    res.pMem[i] = pMem[i] + mat.pMem[i];
  return res;
}

template<class T>
inline TSquareMatrix<T> TSquareMatrix<T>::operator-(const TSquareMatrix<T>& mat)
{
  TSquareMatrix<T> res(sz);
  for (size_t i = 0; i < sz; i++)
    res.pMem[i] = pMem[i] - mat.pMem[i];
  return res;
}

template<class T>
inline TSquareMatrix<T> TSquareMatrix<T>::operator*(const TSquareMatrix<T>& mat)
{
  if (sz != mat.sz)
    throw "different sizes";
  TSquareMatrix<T> res(sz);
  for (size_t row = 0; row < sz; row++)
    for (size_t col = 0; col < sz; col++)
    {
      T sum = 0;
      for (size_t k = 0; k < sz; k++)
        sum += pMem[row][k] * mat.pMem[k][col];
      res.pMem[row][col] = sum;
    }
  return res;
}

template<class T>
inline TSquareMatrix<T> TSquareMatrix<T>::operator=(TSquareMatrix<T>&& mat)
{
  pMem = mat.pMem;
  sz = mat.sz;
  mat.pMem = nullptr;
  mat.sz = 0;
  return *this;
}

template<class T>
inline TSquareMatrix<T> TSquareMatrix<T>::operator=(const TSquareMatrix<T>& mat)
{
  TSquareMatrix tmp(mat.sz);
  for (size_t i = 0; i < mat.sz; i++)
    pMem[i] = mat.pMem[i];
  return *this;
}

template<class T>
ostream& operator <<(ostream& ostr, TSquareMatrix<T>& p)
{
  for (size_t i = 0; i < p.size(); i++)
  {
    auto v = p[i];
    for (size_t j = 0; j < p.size(); j++)
    {
      ostr << p[i][j] << "\t";
    }
    ostr << endl;
  }

  return ostr;
}

template<class T>
istream& operator >>(istream& istr, TSquareMatrix<T>& p)
{
  size_t size;
  istr >> size;
  TSquareMatrix<T> istrmatrix(size);
  for (size_t i = 0; i < size; i++)
    for (size_t j = 0; j < size; j++)
      istr >> istrmatrix[i][j];
  p = istrmatrix;
  return istr;
}
