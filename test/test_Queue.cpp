#include "stack_queue.h"

#include <gtest.h>

TEST(Queue, can_instantiate_queue)
{
    ASSERT_NO_THROW(Queue<int> myQueue);
}


TEST(Queue, is_not_full_on_creation)
{
    Queue<int> myQueue;

    EXPECT_FALSE(myQueue.isFull());
}


TEST(Queue, is_empty_on_creation)
{
    Queue<int> myQueue;

    EXPECT_TRUE(myQueue.isEmpty());
}

TEST(Queue, throws_exception_when_popping_empty_queue)
{
    Queue<int> myQueue;

    ASSERT_ANY_THROW(myQueue.pop());
}

TEST(Queue, capacity_is_two)
{
    Queue<int> myQueue;

    EXPECT_EQ(2, myQueue.getVector_capacity());
}

TEST(Queue, correct_size_after_pushes)
{
    Queue<int> myQueue;

    myQueue.push(10);

    myQueue.push(20);

    myQueue.push(30);

    myQueue.push(40);

    EXPECT_EQ(4, myQueue.size());
}

TEST(Queue, can_extract_element)
{
    Queue<int> myQueue;

    myQueue.push(5);

    myQueue.push(10);

    myQueue.pop();

    EXPECT_EQ(1, myQueue.size());
}

TEST(Queue, can_insert_element)
{
    Queue<int> myQueue;

    myQueue.push(5);

    myQueue.push(7);

    EXPECT_EQ(7, myQueue.getBack());
}


TEST(Queue, front_is_correct)
{
    Queue<int> myQueue;

    myQueue.push(100);

    myQueue.push(200);

    EXPECT_EQ(100, myQueue.getFront());
}


TEST(Queue, back_is_correct)
{
    Queue<int> myQueue;

    myQueue.push(100);

    myQueue.push(200);

    EXPECT_EQ(200, myQueue.getBack());
}


TEST(Queue, can_fill_correctly)
{
    Queue<int> q;

    q.push(8); q.push(10); 

    q.pop(); 

    q.push(14); 

    EXPECT_EQ(0, q.getBackIndex());
}
