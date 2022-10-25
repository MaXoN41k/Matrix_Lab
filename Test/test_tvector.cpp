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
  ADD_FAILURE();
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
  ADD_FAILURE();
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
  ADD_FAILURE();
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
  ADD_FAILURE();
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
  ADD_FAILURE();
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
  ADD_FAILURE();
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
  ADD_FAILURE();
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
  ADD_FAILURE();
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
  ADD_FAILURE();
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
  ADD_FAILURE();
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
  ADD_FAILURE();
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
  ADD_FAILURE();
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
  ADD_FAILURE();
}

