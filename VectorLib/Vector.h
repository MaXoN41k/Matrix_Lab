#pragma once
#include <iostream>
#include "VectorIterator.h"
using namespace std;

template <typename T>
class TVectorIterator;

template <typename T>
class TDynamicVector
{
protected:
  size_t sz;
  T* pMem;

public:
  TDynamicVector(size_t size = 1);
  TDynamicVector(T* arr, size_t s);
  TDynamicVector(const TDynamicVector<T>& v);
  TDynamicVector(TDynamicVector<T>&& v) noexcept;
  ~TDynamicVector();
  TDynamicVector<T>& operator=(TDynamicVector<T>& v);
  TDynamicVector<T>& operator=(TDynamicVector<T>&& v) noexcept;

  size_t size(void) const noexcept;

  T& operator[](size_t ind);
  const T& operator[](size_t ind) const;

  T& at(size_t ind);
  const T& at(size_t ind) const;

  bool operator==(const TDynamicVector<T>& v) const noexcept;
  bool operator!=(const TDynamicVector<T>& v) const noexcept;

  TDynamicVector<T> operator+(T val);
  TDynamicVector<T> operator+(bool val);
  TDynamicVector<T> operator*(bool val);

  TDynamicVector<T> operator+(const TDynamicVector<T>& v);
  TDynamicVector<T> operator-(const TDynamicVector<T>& v);
  T operator*(const TDynamicVector<T>& v) noexcept(noexcept(T()));

  friend istream& operator>>(istream& istr, TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      istr >> v.pMem[i];
    return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      ostr << v.pMem[i] << ' ';
    return ostr;
  }

  TVectorIterator<T> begin();
  TVectorIterator<T> end();
};

template<typename T>
inline TDynamicVector<T>::TDynamicVector(size_t size)
{
  if (size <= 0)
    throw "Vector size <=0";
  sz = size;
  pMem = new T[sz];
  for (int i = 0; i < sz; i++)
    pMem[i] = 0;
}

template<typename T>
inline TDynamicVector<T>::TDynamicVector(T* arr, size_t s)
{
  if (s <= 0)
    throw "Vector size <=0";
  if (arr == nullptr)
    throw "Vector arr empty";
  sz = s;
  pMem = new T[sz];
  for (int i = 0; i < sz; i++)
    pMem[i] = arr[i];
}

template<typename T>
inline TDynamicVector<T>::TDynamicVector(const TDynamicVector<T>& v)
{
  if (v.pMem == nullptr)
  {
    sz = 0;
    pMem = nullptr;
  }
  else
  {
    sz = v.sz;
    pMem = new T[sz];
    for (int i = 0; i < sz; i++)
      pMem[i] = v.pMem[i];
  }
}

template<typename T>
inline TDynamicVector<T>::TDynamicVector(TDynamicVector<T>&& v) noexcept
{
  sz = v.sz;
  pMem = v.pMem;

  v.sz = 0;
  v.pMem = nullptr;
}

template<typename T>
inline TDynamicVector<T>::~TDynamicVector()
{
  if (pMem != nullptr)
  {
    delete[] pMem;
    sz = 0;
  }
}

template<typename T>
inline TDynamicVector<T>& TDynamicVector<T>::operator=(TDynamicVector<T>& v)
{
  if (this != &v)
  {    
    if (pMem == nullptr)
      delete[] pMem;
    if (v.pMem == nullptr)
    {
      sz = 0;
      pMem = nullptr;
    }
    else
    {
      sz = v.sz;
      pMem = new T[sz];
      for (int i = 0; i < sz; i++)
        pMem[i] = v.pMem[i];
    }
  }

  return *this;
}

template<typename T>
inline TDynamicVector<T>& TDynamicVector<T>::operator=(TDynamicVector<T>&& v) noexcept
{
  if (this != &v)
  {
    if (pMem != nullptr)
      delete[] pMem;

    sz = v.sz;
    pMem = v.pMem;

    v.sz = 0;
    v.pMem = nullptr;
  }

  return *this;
}

template<typename T>
inline size_t TDynamicVector<T>::size(void) const noexcept
{
  return sz;
}

template<typename T>
inline T& TDynamicVector<T>::operator[](size_t ind)
{
  return pMem[ind];
}

template<typename T>
inline const T& TDynamicVector<T>::operator[](size_t ind) const
{
  return pMem[ind];
}

template<typename T>
inline T& TDynamicVector<T>::at(size_t ind)
{
  if (pMem == nullptr)
    throw "emty memory";
  if (ind >= 0 && ind < sz)
    return pMem[ind];
  else
    throw "out of range";
}

template<typename T>
inline const T& TDynamicVector<T>::at(size_t ind) const
{
  if (pMem == nullptr)
    throw "emty memory";
  if (ind >= 0 && ind < sz)
    return pMem[ind];
  else
    throw "out of range";
}

template<typename T>
inline bool TDynamicVector<T>::operator==(const TDynamicVector<T>& v) const noexcept
{
  if (sz != v.sz)
    return false;
  for (int i = 0; i < sz; i++)
    if (pMem[i] != v.pMem[i])
      return false;
  return true;
}

template<typename T>
inline bool TDynamicVector<T>::operator!=(const TDynamicVector<T>& v) const noexcept
{
  return !(this->operator==(v));
}

template<typename T>
inline TDynamicVector<T> TDynamicVector<T>::operator+(T val)
{
  TDynamicVector res(*this);
  for (int i = 0; i < sz; i++)
    res.pMem[i] += val;
  return res;
}

template<typename T>
inline TDynamicVector<T> TDynamicVector<T>::operator+(bool val)
{
  TDynamicVector res(*this);
  for (int i = 0; i < sz; i++)
    res.pMem[i] -= val;
  return res;
}

template<typename T>
inline TDynamicVector<T> TDynamicVector<T>::operator*(bool val)
{
  TDynamicVector res(*this);
  for (int i = 0; i < sz; i++)
    res.pMem[i] *= val;
  return res;
}

template<typename T>
inline TDynamicVector<T> TDynamicVector<T>::operator+(const TDynamicVector<T>& v)
{
  if (sz != v.sz)
    throw "different sizes";
  TDynamicVector res(*this);
  for (int i = 0; i < sz; i++)
    res.pMem[i] += v.pMem[i];
  return res;
}

template<typename T>
inline TDynamicVector<T> TDynamicVector<T>::operator-(const TDynamicVector<T>& v)
{
  if (sz != v.sz)
    throw "different sizes";
  TDynamicVector res(*this);
  for (int i = 0; i < sz; i++)
    res.pMem[i] -= v.pMem[i];
  return res;
}

template<typename T>
inline T TDynamicVector<T>::operator*(const TDynamicVector<T>& v) noexcept(noexcept(T()))
{
  if (sz != v.sz)
    throw "different sizes";
  T res = 0;
  for (int i = 0; i < sz; i++)
    res += pMem[i] * v.pMem[i];
  return res;
}

template<typename T>
inline TVectorIterator<T> TDynamicVector<T>::begin()
{
  return TVectorIterator<T>(*this);
}

template<typename T>
inline TVectorIterator<T> TDynamicVector<T>::end()
{
  return TVectorIterator<T>(*this, this->size());
}

////////////////////////////////

template <typename T>
class TVectorIterator
{
public:
  TVectorIterator(TDynamicVector<T>& v);
  TVectorIterator(TDynamicVector<T>& v, int ind);
  TVectorIterator(TVectorIterator<T>& iv);

  bool operator ==(const TVectorIterator<T>& v);
  bool operator !=(const TVectorIterator<T>& v);

  TVectorIterator<T> operator++ ();
  TVectorIterator<T> operator-- ();

  T& operator*();
private:
  TDynamicVector<T>& vector;
  int index;
};

template<typename T>
inline TVectorIterator<T>::TVectorIterator(TDynamicVector<T>& v) :vector(v)
{
  index = 0;
}

template<typename T>
inline TVectorIterator<T>::TVectorIterator(TDynamicVector<T>& v, int ind) :vector(v)
{
  index = ind;
}

template<typename T>
inline TVectorIterator<T>::TVectorIterator(TVectorIterator<T>& iv) :vector(iv.vector), index(iv.index)
{
}

template<typename T>
inline bool TVectorIterator<T>::operator==(const TVectorIterator<T>& v)
{
  if (&vector == &(v.vector) && index == v.index)
    return true;
  else
    return false;
}

template<typename T>
inline bool TVectorIterator<T>::operator!=(const TVectorIterator<T>& v)
{
  return !(this->operator==(v));
}

template<typename T>
inline TVectorIterator<T> TVectorIterator<T>::operator++()
{
  TVectorIterator<T> res(*this);
  res.index++;
  if (res.index > res.vector.size())
    res.index = res.vector.size();
  return res;
}

template<typename T>
inline TVectorIterator<T> TVectorIterator<T>::operator--()
{
  TVectorIterator<T> res(*this);
  res.index--;
  if (res.index < 0)
    res.index = 0;
  return res;
}

template<typename T>
inline T& TVectorIterator<T>::operator*()
{
  return vector.at(index);
}