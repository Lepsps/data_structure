#include "cycle_queue.h"
#include <gtest.h>

TEST(Queue, can_create_queue)
{
    ASSERT_NO_THROW(Queue<int> q);
}

TEST(Queue, can_get_first_elem_from_queue)
{
    Queue<int> q;

    q.push(1);
    q.push(2);

    ASSERT_EQ(q.first(), 1);
}

TEST(Queue, can_get_first_elem_from_empty_queue)
{
    Queue<int> q;

    ASSERT_ANY_THROW(q.first());
}


TEST(Queue, can_get_last_elem_from_queue)
{
    Queue<int> q;

    q.push(1);
    q.push(2);

    ASSERT_EQ(q.back(), 2);
}

TEST(Queue, can_get_last_elem_from_empty_queue)
{
    Queue<int> q;

    ASSERT_ANY_THROW(q.back());
}

TEST(Queue, can_check_empty_queue)
{
    Queue<int> q;

    ASSERT_TRUE(q.empty());
}

TEST(Queue, can_check_not_empty_queue)
{
    Queue<int> q;
    q.push(1);

    ASSERT_FALSE(q.empty());
}

TEST(Queue, can_check_full_queue)
{
    Queue<int> q;

    for (int i = 0; i < 9; i++)
        q.push(i);

    ASSERT_TRUE(q.full());
}

TEST(Queue, can_check_not_full_queue)
{
    Queue<int> q;

    q.push(1);

    ASSERT_FALSE(q.full());
    ASSERT_FALSE(q.full());
}

TEST(Queue, can_several_elems_push_to_queue) {
    Queue<int> q;
    q.push(1);
    q.push(2);

    ASSERT_EQ(q.get_size(), 2);
    ASSERT_EQ(q.first(), 1);
    ASSERT_EQ(q.back(), 2);

}

TEST(Queue, can_pop_elems_from_queue) {
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    
    q.pop();
    q.pop();
    q.pop();

    ASSERT_TRUE(q.empty());
    ASSERT_ANY_THROW(q.first());
}

TEST(Queue, can_pop_elems_from_empty_queue) {
    Queue<int> q;

    ASSERT_ANY_THROW(q.pop());
}


TEST(Queue, can_repack_queue) {
    Queue<int> q;
    for (int i = 0; i < 10; i++) 
        q.push(i);

    ASSERT_FALSE(q.full());
}

TEST(queue, can_get_queue_size) {
    Queue<int> q;
    q.push(1);
    q.push(1);

    ASSERT_EQ(q.get_size(), 2);
}

TEST(Queue, can_clear_queue) {
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    q.clear();
    
    ASSERT_TRUE(q.empty());
}