#include "gtest.h"

#include "stack_queue.h"

TEST(Queue_Stack, can_instantiate_queue)
{
    ASSERT_NO_THROW(Queue_Stack<int> queueStack);
}

TEST(Queue_Stack, is_empty_on_creation)
{
    Queue_Stack<int> queueStack;

    EXPECT_TRUE(queueStack.isEmpty());
}

TEST(Queue_Stack, is_not_full_after_push)
{
    Queue_Stack<int> queueStack;

    queueStack.push(5);

    EXPECT_FALSE(queueStack.isFull());
}

TEST(Queue_Stack, correct_size_after_multiple_pushes)
{
    Queue_Stack<int> queueStack;

    queueStack.push(1);

    queueStack.push(2);

    queueStack.push(1);

    EXPECT_EQ(3, queueStack.size());
}

TEST(Queue_Stack, can_remove_element)
{
    Queue_Stack<int> queueStack;

    queueStack.push(6);

    queueStack.push(7);

    queueStack.pop();

    EXPECT_EQ(1, queueStack.size());
}

TEST(Queue_Stack, default_capacity_is_four)
{
    Queue_Stack<int> queueStack;

    EXPECT_EQ(4, queueStack.getVector_capacity());
}

TEST(Queue_Stack, can_insert_element)
{
    Queue_Stack<int> queueStack;

    queueStack.push(5);

    queueStack.push(10);

    EXPECT_EQ(5, queueStack.front());
}

TEST(Queue_Stack, retrieve_front_element)
{
    Queue_Stack<int> queueStack;

    queueStack.push(10);

    queueStack.push(5);

    EXPECT_EQ(10, queueStack.front());
}

TEST(Queue_Stack, retrieve_back_element)
{
    Queue_Stack<int> queueStack;

    queueStack.push(1);

    queueStack.push(2);

    EXPECT_EQ(2, queueStack.back());
}