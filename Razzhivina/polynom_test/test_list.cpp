#include <gtest.h>
#include "list.h"

TEST(List, can_create_list) {
	ASSERT_NO_THROW(List<int> l);
}

TEST(TList, can_insert_fict_node)
{
	List<int> l;
	l.InFict(2);
	EXPECT_EQ(l.GetData(), 2);
}

TEST(List, can_insert_first_node)
{
	List<int> l;
	l.InFict(2);
	l.InFirst(3);
	l.CurrInFirst();
	EXPECT_EQ(l.GetData(), 3);
}

TEST(List, can_insert_last_node)
{
	List<int> l;
	l.InFict(2);
	l.InLast(3);
	EXPECT_EQ(l.GetData(), 3);
}
TEST(List, can_insert_current_node)
{
	List<int> l;
	l.InFict(2);
	l.InFirst(3);
	l.InCurr(4);
	l.StepBack();
	EXPECT_EQ(l.GetData(), 4);
}

TEST(TList, empty_is_correct)
{
	List<int> l;
	l.InFict(2);
	EXPECT_EQ(l.IsEmpty(), true);
	l.InFirst(3);
	EXPECT_EQ(l.IsEmpty(), false);
}
TEST(List, list_is_end_correct)
{
	List<int> l;
	l.InFict(2);
	EXPECT_EQ(l.IsEnd(), true);
	l.InFirst(3);
	EXPECT_EQ(l.IsEnd(), false);
}

TEST(List, elem_is_last)
{
	List<int> l;
	l.InFict(2);
	l.InFirst(3);
	EXPECT_EQ(l.IsLast(), true);
	l.InFirst(4);
	l.CurrInFirst();
	EXPECT_EQ(l.IsEnd(), false);
}

TEST(List, function_step_forward_is_correct)
{
	List<int> l;
	l.InFict(2);
	l.InFirst(3);
	l.InLast(4);
	l.CurrInFirst();
	l.StepForward();
	EXPECT_EQ(l.GetData(), 4);
}
TEST(TList, function_step_back_is_correct)
{
	List<int> l;
	l.InCurr(2);
	l.InFirst(3);
	l.StepBack();
	EXPECT_EQ(l.GetData(), 2);
}

TEST(List, can_reset)
{
	List<int> l;
	l.InCurr(2);
	l.InFirst(3);
	l.InLast(4);
	l.CurrInFirst();
	EXPECT_EQ(l.GetData(), 3);
}

TEST(List, function_get_data_is_correct)
{
	List<int> l;
	l.InCurr(2);
	EXPECT_EQ(l.GetData(), 2);
}
TEST(List, function_set_data_is_correct)
{
	List<int> l;
	l.InFict(2);
	l.SetData(5);
	EXPECT_EQ(l.GetData(), 5);
}

TEST(List, can_delete_first)
{
	List<int> l;
	l.InFict(2);
	l.InFirst(3);
	l.InLast(4);
	l.DelFirst();
	EXPECT_EQ(l.GetData(), 4);
}
TEST(List, can_not_delete_first)
{
	List<int> l;
	l.InFict(2);
	ASSERT_ANY_THROW(l.DelFirst());
}
TEST(List, can_delete_last)
{
	List<int> l;
	l.InFict(2);
	l.InFirst(3);
	l.InLast(4);
	l.DelLast();
	l.StepBack();
	EXPECT_EQ(l.GetData(), 3);
}
TEST(List, can_delete_current)
{
	List<int> l;
	l.InFict(2);
	l.InFirst(3);
	l.InLast(4);
	l.InCurr(5);
	l.DelCur();
	EXPECT_EQ(l.GetData(), 5);
}
TEST(TList, can_delete_all_list)
{
	List<int> l;
	l.InFict(2);
	l.InFirst(3);
	l.InCurr(4);
	l.DelAll();
	EXPECT_EQ(l.IsEmpty(), true);
}