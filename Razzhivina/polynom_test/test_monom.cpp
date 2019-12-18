#include <gtest.h>
#include "monom.h"

TEST(Monom, can_create_monom_without_parametrs) {
	ASSERT_NO_THROW(Monom m);
}

TEST(Monom, can_created_monom_with_paramtrs) {
	ASSERT_NO_THROW(Monom m(1, 2, 3, 4));
}

TEST(Monom, can_create_monom_on_other_monom) {
	Monom m(1, 2, 3, 4);
	ASSERT_NO_THROW(Monom m1(m));
}

TEST(Monom, funcion_GetCoef_and_GetDEGS_is_correct) {
	Monom m(1, 2, 3, 4);
	EXPECT_EQ(m.GetCoef(), 1);
	EXPECT_EQ(m.GetDegX(), 2);
	EXPECT_EQ(m.GetDegY(), 3);
	EXPECT_EQ(m.GetDegZ(), 4);
}

TEST(Monom, Clean_is_correct) {
	Monom m(1, 2, 3, 4);
	m.Clean();
	EXPECT_EQ(m.GetCoef(), 0);
	EXPECT_EQ(m.GetDegX(), 0);
	EXPECT_EQ(m.GetDegY(), 0);
	EXPECT_EQ(m.GetDegZ(), 0);
}

TEST(Monom, SetData_is_correct) {
	Monom m;
	m.SetData(1, 2, 3, 4);
	EXPECT_EQ(m.GetCoef(), 1);
	EXPECT_EQ(m.GetDegX(), 2);
	EXPECT_EQ(m.GetDegY(), 3);
	EXPECT_EQ(m.GetDegZ(), 4);
}

TEST(Monom, SetCoef_is_correct) {
	Monom m;
	m.SetCoef(1);
	EXPECT_EQ(m.GetCoef(), 1);
}

TEST(Monom, equal_is_correct) {
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 2, 3, 4);
	EXPECT_EQ(m1 == m2, true);
	m2.SetCoef(20);
	EXPECT_EQ(m1 == m2, false);
}

TEST(Monom, not_equal_is_correct) {
	Monom m1(1, 2, 3, 4);
	Monom m2(2, 2, 3, 4);
	EXPECT_EQ(m1 != m2, true);
	m2.SetCoef(1);
	EXPECT_EQ(m1 != m2, false);
}

TEST(Monom, Mult_is_correct) {
	Monom m1(1, 2, 3, 4),
		m2(5, 6, 7, 8),
		res;
	res = m1 * m2;
	EXPECT_EQ(res.GetCoef(), 5);
	EXPECT_EQ(res.GetDegX(), 8);
	EXPECT_EQ(res.GetDegY(), 10);
	EXPECT_EQ(res.GetDegZ(), 12);
}

TEST(Monom, operator_assigment_is_correct) {
	Monom m1, m2(1, 2, 3, 4);
	m1 = m2;
	EXPECT_EQ(m1.GetCoef(), 5);
	EXPECT_EQ(m1.GetDegX(), 8);
	EXPECT_EQ(m1.GetDegY(), 10);
	EXPECT_EQ(m1.GetDegZ(), 12);
}