#include "Vector.h"

#include <../gtest/gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
  TDynamicVector<int> v(10);

  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
  TDynamicVector<int> v(10);
  TDynamicVector<int> v1(v);

  ASSERT_NO_THROW(v1 == v);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
  TDynamicVector<int> &&v(10);
  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

TEST(TDynamicVector, can_set_and_get_element)
{
  TDynamicVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
  TDynamicVector<int> v(4);
  ASSERT_ANY_THROW(v[6]);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
  TDynamicVector<int> v(4);
  ASSERT_ANY_THROW(v = v);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
  TDynamicVector<int> v(4);
  TDynamicVector<int> v1(8);

  v = v1;
  EXPECT_EQ(8, v.size());
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
  TDynamicVector<int> v(4);
  TDynamicVector<int> v1(45);
  ASSERT_NO_THROW(v == v1);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
  TDynamicVector<int> v(4);
  TDynamicVector<int> v1(4);
  EXPECT_EQ(true, v == v1);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
  TDynamicVector<int> v(4);
  EXPECT_EQ(true, v == v);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
  TDynamicVector<int> v(4);
  TDynamicVector<int> v1(45);
  EXPECT_EQ(false, v == v1);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{  
  int arr[4] = {1, 1, 1, 1};
  int arr1[4] = {3, 3, 3, 3};
  TDynamicVector<int> v(arr, 4);
  TDynamicVector<int> v1(arr1, 4);
  int val = 2;
  v = v + val;
  EXPECT_EQ(v, v1);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
  int arr[4] = { 1, 1, 1, 1 };
  int arr1[4] = { 3, 3, 3, 3 };
  TDynamicVector<int> v(arr, 4);
  TDynamicVector<int> v1(arr1, 4);
  int val = 2;
  v1 = v1 - val;
  EXPECT_EQ(v, v1);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
  int arr[4] = { 1, 1, 1, 1 };
  int arr1[4] = { 2, 2, 2, 2 };
  TDynamicVector<int> v(arr, 4);
  TDynamicVector<int> v1(arr1, 4);
  int val = 2;
  v = v * val;
  EXPECT_EQ(v, v1);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
  int arr[4] = { 1, 1, 1, 1 };
  int arr1[4] = { 2, 2, 2, 2 };
  int arr2[4] = { 3, 3, 3, 3 };
  TDynamicVector<int> v(arr, 4);
  TDynamicVector<int> v1(arr1, 4);
  TDynamicVector<int> v2(arr2, 4);
  v = v + v1;
  EXPECT_EQ(v, v2);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
  TDynamicVector<int> v(4);
  TDynamicVector<int> v1(5);
  ASSERT_ANY_THROW(v1 + v);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
  int arr[4] = { 1, 1, 1, 1 };
  int arr1[4] = { 2, 2, 2, 2 };
  int arr2[4] = { 3, 3, 3, 3 };
  TDynamicVector<int> v(arr, 4);
  TDynamicVector<int> v1(arr1, 4);
  TDynamicVector<int> v2(arr2, 4);
  v2 = v2 - v1;
  EXPECT_EQ(v, v2);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
  TDynamicVector<int> v(4);
  TDynamicVector<int> v1(5);
  ASSERT_ANY_THROW(v1 - v);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
  const int test = 6;
  int arr1[4] = { 1, 2, 3, 4 };
  int arr2[4] = { 1, -1, 1, 1 };
  TDynamicVector<int> v1(arr1, 4);
  TDynamicVector<int> v2(arr2, 4);
  int mul = v1 * v2;
  EXPECT_EQ(test, mul);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
  TDynamicVector<int> v(4);
  TDynamicVector<int> v1(5);
  ASSERT_ANY_THROW(v1 * v);
}

