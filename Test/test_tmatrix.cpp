#include "SquareMatrix.h"

#include <../gtest/gtest.h>

TEST(TSquareMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TSquareMatrix<int> m(5));
}

TEST(TSquareMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TSquareMatrix<int> v(-5));
}

TEST(TSquareMatrix, can_create_copied_matrix)
{
  TSquareMatrix<int> m(5);

  ASSERT_NO_THROW(TSquareMatrix<int> m1(m));
}

TEST(TSquareMatrix, copied_matrix_is_equal_to_source_one)
{
  TSquareMatrix<int> m(5);
  TSquareMatrix<int> m1(m);
  EXPECT_EQ(m, m1);
}

TEST(TSquareMatrix, copied_matrix_has_its_own_memory)
{
  TSquareMatrix<int>&& m(10);
  ASSERT_NO_THROW(TSquareMatrix<int> m1(m));
}

TEST(TSquareMatrix, can_get_size)
{
  TSquareMatrix<int> m(5);
  EXPECT_EQ(5, m.size());
}

TEST(TSquareMatrix, can_set_and_get_element)
{
  TSquareMatrix<int> m(2);
  m[1][1] = 4;

  EXPECT_EQ(4, m[1][1]);
}

TEST(TSquareMatrix, throws_when_set_element_with_negative_index)
{
  TSquareMatrix<int> m(2);
  ASSERT_ANY_THROW(m[-1][1] = 4);
}

TEST(TSquareMatrix, throws_when_set_element_with_too_large_index)
{
  TSquareMatrix<int> m(2);
  ASSERT_ANY_THROW(m[3][1] = 4);
}

TEST(TSquareMatrix, can_assign_matrix_to_itself)
{
  TSquareMatrix<int> m(4);
  ASSERT_ANY_THROW(m = m);
}

TEST(TSquareMatrix, assign_operator_change_matrix_size)
{
  TSquareMatrix<int> m(1);
  TSquareMatrix<int> m1(4);
  m = m1;
  EXPECT_EQ(4, m.size());
}

TEST(TSquareMatrix, can_assign_matrix_of_different_size)
{
  TSquareMatrix<int> m(4);
  TSquareMatrix<int> m1(45);
  ASSERT_NO_THROW(m == m1);
}

TEST(TSquareMatrix, compare_equal_matrices_return_true)
{
  TSquareMatrix<int> m(4);
  TSquareMatrix<int> m1(4);
  EXPECT_EQ(true, m == m1);
}

TEST(TSquareMatrix, compare_matrix_with_itself_return_true)
{
  TSquareMatrix<int> v(4);
  EXPECT_EQ(true, v == v);
}

TEST(TSquareMatrix, matrices_with_different_size_are_not_equal)
{
  TSquareMatrix<int> m(4);
  TSquareMatrix<int> m1(5);
  EXPECT_EQ(false, m == m1);
}

TEST(TSquareMatrix, can_add_matrices_with_equal_size)
{
  int arr[4] = { 1, 0, 1, -2 };
  int arr1[4] = { 2, 2, 2, 2 };
  int arr2[4] = { 3, 2, 3, 0 };
  TSquareMatrix<int> m(2, arr);
  TSquareMatrix<int> m1(2, arr1);
  TSquareMatrix<int> m2(2, arr2);
  m = m + m1;
  EXPECT_EQ(m, m2);
}

TEST(TSquareMatrix, cant_add_matrices_with_not_equal_size)
{
  TSquareMatrix<int> m(2);
  TSquareMatrix<int> m1(3);
  ASSERT_ANY_THROW(m + m1);
}

TEST(TSquareMatrix, can_subtract_matrices_with_equal_size)
{
  int arr[4] = { 1, 0, 1, -2 };
  int arr1[4] = { 2, 2, 2, 2 };
  int arr2[4] = { 3, 2, 3, 0 };
  TSquareMatrix<int> m(2, arr);
  TSquareMatrix<int> m1(2, arr1);
  TSquareMatrix<int> m2(2, arr2);
  m2 = m2 - m1;
  EXPECT_EQ(m, m2);
}

TEST(TSquareMatrix, cant_subtract_matrixes_with_not_equal_size)
{
  TSquareMatrix<int> m(2);
  TSquareMatrix<int> m1(3);
  ASSERT_ANY_THROW(m - m1);
}

TEST(TSquareMatrix, can_multiply_matrix_with_equal_size)
{
  TSquareMatrix<int> m1(2);
  TSquareMatrix<int> m2(2);
  int arr[4] = { 2,3,5,9 };
  TSquareMatrix<int> m3(2, arr);

  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
    {
      m1[i][j] = i + j;
      m2[i][j] = i + j + 1;
    }
  m2[0][1] = 3;
  m1 = m1 * m2;
  
  EXPECT_EQ(m1,m3);
}

TEST(TSquareMatrix, cant_multiply_matrix_with_not_equal_size)
{
  TSquareMatrix<int> m(4);
  TSquareMatrix<int> m1(5);
  ASSERT_ANY_THROW(m1 * m);
}

