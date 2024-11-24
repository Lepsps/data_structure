#include "stack.h"
#include <gtest.h>


TEST(Stack, can_create_stack)
{
	ASSERT_NO_THROW(Stack<int> st);
}

TEST(Stack, can_get_stack_top)
{
	Stack<int> st;

	st.push(1);

	ASSERT_EQ(st.top(),1);
}

TEST(Stack, can_get_empty_stack_top)
{
	Stack<int> st;

	ASSERT_ANY_THROW(st.top());
}

TEST(Stack, can_check_stack_empty)
{
	Stack<int> st;

	ASSERT_TRUE(st.empty());
}

TEST(Stack, can_check_stack_full)
{
	Stack<int> st;
	st.push(1);

	ASSERT_FALSE(st.empty());
}

TEST(Stack, can_get_stack_size)
{
	Stack<int> st;
	st.push(1);
	st.push(1);

	ASSERT_EQ(st.size(), 2);
}

TEST(Stack, can_push_to_stack)
{
	Stack<int> st;

	st.push(100);

	ASSERT_EQ(st.size(), 1);
	ASSERT_EQ(st.top(), 100);
}


TEST(Stack, can_several_push_to_stack)
{
	Stack<int> st;

	st.push(1);
	st.push(2);
	st.push(3);

	ASSERT_EQ(st.size(), 3);
	ASSERT_EQ(st.top(), 3);
}

TEST(Stack, can_pop_from_stack)
{
	Stack<int> st;
	st.push(1);

	st.pop();
	
	ASSERT_TRUE(st.empty());
}

TEST(Stack, can_several_pop_from_stack)
{
	Stack<int> st;
	st.push(1);
	st.push(1);

	st.pop();
	st.pop();

	ASSERT_TRUE(st.empty());
}

TEST(Stack, cant_pop_from_empty_stack)
{
	Stack<int> st;
	
	ASSERT_ANY_THROW(st.pop());
}

TEST(Stack, can_clear_stack)
{
	Stack<int> st;
	st.push(1);
	st.push(1);

	st.clear();

	ASSERT_TRUE(st.empty());
}
