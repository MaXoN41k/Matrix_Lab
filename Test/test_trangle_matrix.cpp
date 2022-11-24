#include "TrangleMatrix.h"

#include <../gtest/gtest.h>

TEST(TTrangleMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TTrangleMatrix<int> m(5));
}

TEST(TTrangleMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TTrangleMatrix<int> v(-5));
}

TEST(TTrangleMatrix, can_create_copied_matrix)
{
  TTrangleMatrix<int> m(5);

  ASSERT_NO_THROW(TTrangleMatrix<int> m1(m));
}

TEST(TTrangleMatrix, copied_matrix_is_equal_to_source_one)
{
  TTrangleMatrix<int> m(5);
  TTrangleMatrix<int> m1(m);
  EXPECT_EQ(m, m1);
}

TEST(TTrangleMatrix, copied_matrix_has_its_own_memory)
{
  TTrangleMatrix<int>&& m(10);
  ASSERT_NO_THROW(TTrangleMatrix<int> m1(m));
}

TEST(TTrangleMatrix, can_get_size)
{
  TTrangleMatrix<int> m(5);
  EXPECT_EQ(5, m.size());
}

TEST(TTrangleMatrix, can_set_and_get_element)
{
  TTrangleMatrix<int> m(2);
  m[1][1] = 4;

  EXPECT_EQ(4, m[1][1]);
}

TEST(TTrangleMatrix, throws_when_set_element_with_negative_index)
{
  TTrangleMatrix<int> m(2);
  ASSERT_ANY_THROW(m[-1][1] = 4);
}

TEST(TTrangleMatrix, throws_when_set_element_with_too_large_index)
{
  TTrangleMatrix<int> m(2);
  ASSERT_ANY_THROW(m[3][1] = 4);
}

TEST(TTrangleMatrix, can_assign_matrix_to_itself)
{
  TTrangleMatrix<int> m(4);
  ASSERT_ANY_THROW(m = m);
}

TEST(TTrangleMatrix, assign_operator_change_matrix_size)
{
  TTrangleMatrix<int> m(1);
  TTrangleMatrix<int> m1(4);
  m = m1;
  EXPECT_EQ(4, m.size());
}

TEST(TTrangleMatrix, can_assign_matrix_of_different_size)
{
  TTrangleMatrix<int> m(4);
  TTrangleMatrix<int> m1(45);
  ASSERT_NO_THROW(m == m1);
}

TEST(TTrangleMatrix, compare_equal_matrices_return_true)
{
  TTrangleMatrix<int> m(4);
  TTrangleMatrix<int> m1(4);
  EXPECT_EQ(true, m == m1);
}

TEST(TTrangleMatrix, compare_matrix_with_itself_return_true)
{
  TTrangleMatrix<int> v(4);
  EXPECT_EQ(true, v == v);
}

TEST(TTrangleMatrix, matrices_with_different_size_are_not_equal)
{
  TTrangleMatrix<int> m(4);
  TTrangleMatrix<int> m1(5);
  EXPECT_EQ(false, m == m1);
}

TEST(TTrangleMatrix, can_add_matrices_with_equal_size)
{
  int arr[3] = { 1, 0, 1 };
  int arr1[3] = { 2, 2, 2 };
  int arr2[3] = { 3, 2, 3 };
  TTrangleMatrix<int> m(2, arr);
  TTrangleMatrix<int> m1(2, arr1);
  TTrangleMatrix<int> m2(2, arr2);
  m = m + m1;
  EXPECT_EQ(m, m2);
}

TEST(TTrangleMatrix, cant_add_matrices_with_not_equal_size)
{
  TTrangleMatrix<int> m(2);
  TTrangleMatrix<int> m1(3);
  ASSERT_ANY_THROW(m + m1);
}

TEST(TTrangleMatrix, can_subtract_matrices_with_equal_size)
{
  int arr[3] = { 1, 0, 1};
  int arr1[3] = { 2, 2, 2};
  int arr2[3] = { 3, 2, 3};
  TTrangleMatrix<int> m(2, arr);
  TTrangleMatrix<int> m1(2, arr1);
  TTrangleMatrix<int> m2(2, arr2);
  m2 = m2 - m1;
  EXPECT_EQ(m, m2);
}

TEST(TTrangleMatrix, cant_subtract_matrixes_with_not_equal_size)
{
  TTrangleMatrix<int> m(2);
  TTrangleMatrix<int> m1(3);
  ASSERT_ANY_THROW(m - m1);
}

TEST(TTrangleMatrix, can_multiply_matrix_with_equal_size)
{
  int arr[3] = { 1,2,3 };
  int arr1[3] = { 2,3,1 };
  int arr2[3] = {2, 13,3};
  TTrangleMatrix<int> m1(2, arr);
  TTrangleMatrix<int> m2(2, arr1);
  TTrangleMatrix<int> m3(2, arr2);
  m1 = m1 * m2;

  EXPECT_EQ(m1, m3);
}

TEST(TTrangleMatrix, cant_multiply_matrix_with_not_equal_size)
{
  TTrangleMatrix<int> m(4);
  TTrangleMatrix<int> m1(5);
  ASSERT_ANY_THROW(m1 * m);
}

