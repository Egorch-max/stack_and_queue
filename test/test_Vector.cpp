#include "gtest.h"
#include "stack_queue.h"

TEST(TVector, can_create_vector_with_positive_length) 
{
    ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, throws_when_create_vector_with_negative_length) 
{
    ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, can_create_copied_vector) 
{
    TVector<int> v(10);

    ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source)
{
    TVector<int> v(5);

    v[0] = 1;

    TVector<int> vcopy(v);

    EXPECT_EQ(v, vcopy);
}

TEST(TVector, copied_vector_has_its_own_memory) 
{
    TVector<int> v(5);

    TVector<int> vcopy(v);

    EXPECT_NE(&v, &vcopy);
}

TEST(TVector, can_get_size_of_vector) 
{
    TVector<int> v(4);

    EXPECT_EQ(4, v.size());
}

TEST(TVector, can_get_capacity_of_vector)
{
    TVector<int> v;

    EXPECT_EQ(2, v.getVector_capacity());
}

TEST(TVector, can_set_and_get_element) 
{
    TVector<int> v(8);

    v[0] = 8;

    EXPECT_EQ(8, v[0]);
}

TEST(TVector, can_assign_vector_to_itself) 
{
    TVector<int> v(10);

    v[0] = 1;

    TVector<int> vcopy(v);

    v = v;

    EXPECT_EQ(v, vcopy);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
    TVector<int> v1(10);

    TVector<int> v2(10);

    v2[0] = 3;

    v1 = v2;

    EXPECT_EQ(v1, v2);
}

TEST(TVector, assign_operator_changes_vector_size)
{
    TVector<int> v1(10);

    TVector<int> v2(5);

    v1 = v2;

    EXPECT_EQ(5, v1.size());
}

TEST(TVector, can_assign_vectors_of_different_size) 
{
    TVector<int> v1(10);

    TVector<int> v2(5);

    v2[4] = 8;

    v1 = v2;

    EXPECT_EQ(v1, v2);
}

TEST(TVector, compare_vector_with_itself_returns_true) 
{
    TVector<int> v(5);

    v[3] = 4;

    EXPECT_TRUE(v == v);

}

TEST(TVector, vectors_with_different_size_are_not_equal) 
{
    TVector<int> v1(4);

    TVector<int> v2(5);

    EXPECT_FALSE(v1 == v2);
}

TEST(TVector, can_check_if_vector_is_full_1) 
{
    TVector<int> v;

    EXPECT_FALSE(v.isFull());
}

TEST(TVector, can_check_if_vector_is_full_2) 
{
    TVector<int> v;

    v.push_back(5);

    v.push_back(2);

    EXPECT_TRUE(v.isFull());
}

TEST(TVector, can_check_if_vector_is_empty) 
{
    TVector<int> v;

    EXPECT_TRUE(v.isEmpty());
}

TEST(TVector, can_create_vector_from_array) 
{
    int* a = new int[4] {1, 3, 5, 7};

    TVector<int> v(a, 5);

    int f = 0;

    for (size_t i = 0; i < 4; i++)
    {
        if (v[i] != a[i])
        {
            f = 1;
        }
    }
    delete[] a;
    
    EXPECT_EQ(0, f);
}

TEST(TVector, compare_equal_vectors_returns_true) 
{
    int* a1 = new int[3] {1, 3, 4};

    TVector<int> v1(a1, 3);

    delete[] a1;

    int* a2 = new int[3] {1, 3, 4};

    TVector<int> v2(a2, 3);

    delete[] a2;

    EXPECT_TRUE(v1 == v2);

}

TEST(TVector, can_push_back_element) 
{
    int* a = new int[3] {1, 2, 3};

    TVector<int> v1(a, 3);

    delete[] a;

    int* a_c = new int[4] {1, 2, 3, 14};

    TVector<int> v2(a_c, 4);

    delete[] a_c;

    v1.push_back(14);

    EXPECT_EQ(v1, v2);
}

TEST(TVector, can_push_back_element_with_resize) 
{
    int* a = new int[3] {2, 1, 2};

    TVector<int> v1(a, 3);

    delete[] a;

    int* a_c = new int[9] {2, 1, 2, 3, 4, 5, 6, 7, 8};

    TVector<int> v2(a_c, 9);

    delete[] a_c;

    for (size_t i = 3; i < 9; i++)
    {
        v1.push_back(i);
    }

    EXPECT_EQ(v1, v2);
}

TEST(TVector, can_push_front_element)
{
    int* a = new int[3] {1, 2, 3};

    TVector<int> v1(a, 3);

    delete[] a;

    int* a_c = new int[4] {4, 1, 2, 3};

    TVector<int> v2(a_c, 4);

    delete[] a_c;

    v1.push_front(4);

    EXPECT_EQ(v1, v2);
}

TEST(TVector, can_push_front_element_with_resize) 
{
    int* a = new int[3] {2, 1, 2};

    TVector<int> v1(a, 3);

    delete[] a;

    int* a_c = new int[9] {3, 4, 5, 6, 7, 8, 2, 1, 2};

    TVector<int> v2(a_c, 9);

    delete[] a_c;

    for (size_t i = 8; i > 2; i--)
    {
        v1.push_front(i);
    }

    EXPECT_EQ(v1, v2);
}

TEST(TVector, can_pop_back_element) 
{
    int* a = new int[3] {1, 2, 3};

    TVector<int> v1(a, 3);

    delete[] a;

    int* a_c = new int[2] {1, 2};

    TVector<int> v2(a_c, 2);

    delete[] a_c;

    v1.pop_back();

    EXPECT_EQ(v1, v2);
}

TEST(TVector, can_pop_front_element) 
{
    int* a = new int[3] {1, 2, 3};

    TVector<int> v1(a, 3);

    delete[] a;

    int* a_c = new int[2] {2, 3};

    TVector<int> v2(a_c, 2);

    delete[] a_c;

    v1.pop_front();

    EXPECT_EQ(v1, v2);
}

TEST(TVector, can_insert_element) 
{
    int* a = new int[3] {1, 2, 3};

    TVector<int> v1(a, 3);

    delete[] a;

    int* a_c = new int[4] {1, 2, 4, 3};

    TVector<int> v2(a_c, 4);

    delete[] a_c;

    v1.insert(4, 2);

    EXPECT_EQ(v1, v2);
}

TEST(TVector, can_insert_element_with_resize) 
{
    int* a = new int[3] {8, 10, 12};

    TVector<int> v1(a, 3);

    delete[] a;

    int* a_c = new int[9] {8, 3, 4, 5, 6, 7, 8, 10, 12};

    TVector<int> v2(a_c, 9);

    delete[] a_c;

    for (size_t i = 8; i > 2; i--)
    {
        v1.insert(i, 1);
    }

    EXPECT_EQ(v1, v2);
}

TEST(TVector, can_erase_element) 
{
    int* a = new int[3] {1, 2, 3};

    TVector<int> v1(a, 3);

    delete[] a;

    int* a_c = new int[2] {1, 3};

    TVector<int> v2(a_c, 2);

    delete[] a_c;

    v1.erase(1);

    EXPECT_EQ(v1, v2);
}

TEST(TVector, throws_when_pop_back_element_from_empty_vector)
{
    TVector<int> v;

    ASSERT_ANY_THROW(v.pop_back());
}

TEST(TVector, throws_when_pop_front_element_from_empty_vector)
{
    TVector<int> v;

    ASSERT_ANY_THROW(v.pop_front());
}

TEST(TVector, throws_when_erase_element_from_empty_vector)
{
    TVector<int> v;

    ASSERT_ANY_THROW(v.erase(0));
}
