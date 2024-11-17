#include "gtest.h"

#include "stack_queue.h"

TEST(Stack, can_be_instantiated)
{
    EXPECT_NO_THROW(Stack<int> stack);
}

TEST(Stack, reports_empty_status_correctly)
{
    Stack<int> stack;

    EXPECT_TRUE(stack.isEmpty());
}

TEST(Stack, throws_exception_when_popping_empty_stack)
{
    Stack<int> stack;

    EXPECT_ANY_THROW(stack.pop());
}

TEST(Stack, reports_full_status_correctly)
{
    Stack<int> stack;

    stack.push(5);

    stack.push(10);

    EXPECT_TRUE(stack.isFull());
}

TEST(Stack, returns_correct_capacity)
{
    Stack<int> stack;

    EXPECT_EQ(2, stack.getVector_capacity());
}

TEST(Stack, returns_correct_size)
{
    Stack<int> stack;

    stack.push(3);

    stack.push(7);

    stack.push(5);

    EXPECT_EQ(3, stack.size());
}

TEST(Stack, correctly_pops_elements)
{
    Stack<int> stack;

    stack.push(7);

    stack.push(9);

    stack.push(5);

    stack.pop();

    EXPECT_EQ(2, stack.size());
}

TEST(Stack, correctly_pushes_elements)
{
    Stack<int> stack;

    stack.push(3);

    stack.push(11);

    EXPECT_EQ(11, stack.top());
}

TEST(Stack, returns_top_element)
{
    Stack<int> stack;

    stack.push(15);

    stack.push(25);

    EXPECT_EQ(25, stack.top());
}

TEST(Stack, resizes_capacity_when_needed)
{
    Stack<int> stack;

    stack.push(4);

    stack.push(4);

    stack.push(4);

    EXPECT_EQ(3 * 2 + 2, stack.getVector_capacity());
}