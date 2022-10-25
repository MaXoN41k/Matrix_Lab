#include "SquareMatrix.h"

#include <../gtest/gtest.h>

TEST(TSquareMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TSquareMatrix<int> m(5));
}

TEST(TSquareMatrix, can_create_copied_matrix)
{
  TSquareMatrix<int> m(5);

  ASSERT_NO_THROW(TSquareMatrix<int> m1(m));
}

TEST(TSquareMatrix, copied_matrix_is_equal_to_source_one)
{
  ADD_FAILURE();
}

TEST(TSquareMatrix, copied_matrix_has_its_own_memory)
{
  ADD_FAILURE();
}

TEST(TSquareMatrix, can_get_size)
{
  ADD_FAILURE();
}

TEST(TSquareMatrix, can_set_and_get_element)
{
  ADD_FAILURE();
}

TEST(TSquareMatrix, throws_when_set_element_with_negative_index)
{
  ADD_FAILURE();
}

TEST(TSquareMatrix, throws_when_set_element_with_too_large_index)
{
  ADD_FAILURE();
}

TEST(TSquareMatrix, can_assign_matrix_to_itself)
{
  ADD_FAILURE();
}

TEST(TSquareMatrix, can_assign_matrices_of_equal_size)
{
  ADD_FAILURE();
}

TEST(TSquareMatrix, assign_operator_change_matrix_size)
{
  ADD_FAILURE();
}

TEST(TSquareMatrix, can_assign_matrices_of_different_size)
{
  ADD_FAILURE();
}

TEST(TSquareMatrix, compare_equal_matrices_return_true)
{
  ADD_FAILURE();
}

TEST(TSquareMatrix, compare_matrix_with_itself_return_true)
{
  ADD_FAILURE();
}

TEST(TSquareMatrix, matrices_with_different_size_are_not_equal)
{
  ADD_FAILURE();
}

TEST(TSquareMatrix, can_add_matrices_with_equal_size)
{
  ADD_FAILURE();
}

TEST(TSquareMatrix, cant_add_matrices_with_not_equal_size)
{
  ADD_FAILURE();
}

TEST(TSquareMatrix, can_subtract_matrices_with_equal_size)
{
  ADD_FAILURE();
}

TEST(TSquareMatrix, cant_subtract_matrixes_with_not_equal_size)
{
  ADD_FAILURE();
}

