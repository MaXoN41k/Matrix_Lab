#pragma once
#include "Vector.h"
#include "new"

template <class T>
class TSquareMatrix : public TDynamicVector<TDynamicVector<T>>
{
public:
  TSquareMatrix(const int size);
  TSquareMatrix(const TSquareMatrix<T>& mat) noexcept;
  TSquareMatrix(TSquareMatrix<T>&& mat);

  bool operator == (const TSquareMatrix<T>& mat) const noexcept;
  bool operator != (const TSquareMatrix<T>& mat) const noexcept;

  TSquareMatrix<T> operator + (const TSquareMatrix<T>& mat);
  TSquareMatrix<T> operator - (const TSquareMatrix<T>& mat);
  TSquareMatrix<T> operator * (const TSquareMatrix<T>& mat);
  
  TSquareMatrix<T> operator = (const TSquareMatrix<T>&& mat);
  TSquareMatrix<T> operator = (const TSquareMatrix<T>& mat);
};

template<class T>
inline TSquareMatrix<T>::TSquareMatrix(const int size)
{
  this->pMem = new TDynamicVector<T> [size](size);
  this->sz = size;
}

template<class T>
inline TSquareMatrix<T>::TSquareMatrix(const TSquareMatrix<T>& mat) noexcept : TDynamicVector<TDynamicVector<T>>::TDynamicVector<TDynamicVector<T>> (mat)
{
}

template<class T>
inline TSquareMatrix<T>::TSquareMatrix(TSquareMatrix<T>&& mat)
{

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
  return TDynamicVector<TDynamicVector<T>>::operator -(mat);
}

template<class T>
inline TSquareMatrix<T> TSquareMatrix<T>::operator-(const TSquareMatrix<T>& mat)
{
  return TDynamicVector<TDynamicVector<T>>::operator -(mat);
}

template<class T>
inline TSquareMatrix<T> TSquareMatrix<T>::operator*(const TSquareMatrix<T>& mat)
{
  





}

template<class T>
inline TSquareMatrix<T> TSquareMatrix<T>::operator=(const TSquareMatrix<T>&& mat)
{
  TDynamicVector<TDynamicVector<T>>::operator =(mat);
  return *this;
}

template<class T>
inline TSquareMatrix<T> TSquareMatrix<T>::operator=(const TSquareMatrix<T>& mat)
{
  TDynamicVector<TDynamicVector<T>>::operator =(mat);
  return *this;
}
