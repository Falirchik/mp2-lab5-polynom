#include "polinom.cpp"
#include <gtest.h>

TEST(Polinom, can_create_polinom) {
	ASSERT_NO_THROW(Polinom p(""));
}

TEST(Polinom, sorting_is_correct) {
	Polinom p("z^2x^3+z^3x^2-x^2+3");
	p.Sorting();
	EXPECT_EQ(p.GetPolinom(), "-1x^2+3x^2z^3+x^3z^2+3");
}

TEST(Polinom, can_add_polinoms) {
	Polinom p1("x^2+2x^3z^4-3y^2z^3"), 
		p2("-x^2+3x^3z^4+5x^2y^2z^2"), res("");
	res = p1 + p2;
	EXPECT_EQ(res.GetPolinom(), "5x^2y^2z^2+5x^3z^4-3y^2z^3");
}

TEST(Polinom, can_sub_polinoms) {
	Polinom p1("x^2y^2z^2+3x^3z^4-3y^2z^3"),
		p2("-x^2y^2z^2+3x^3z^4-5z^5"), res("");
	res = p1 - p2;
	EXPECT_EQ(res.GetPolinom(), "2x^2y^2z^2-3y^2z^3+5z^5");
}

TEST(Polinom, equal_polinoms) {
	Polinom p1("x^2+2x^3z^4-3y^2z^3"),
		p2("x^2+2x^3z^4-3y^2z^3");
	EXPECT_EQ(p1 == p2, true);
}

TEST(Polinom, not_equal_polinom) {
	Polinom p1("x^2y^2z^2+3x^3z^4-3y^2z^3"),
		p2("-x^2y^2z^2+3x^3z^4-5z^5");
	EXPECT_EQ(p1 != p2, true);
}

TEST(Polinom, mult_polinoms_is_correct) {
	Polinom p1("x^2y^2+y^2z^2"),
		p2("x^2z^2+y^3"),
		res("");
	res = p1 * p2;
	EXPECT_EQ(res.GetPolinom(), "x^4y^2z^2+x^2y^5+x^2y^2z^4+y^5z^2");
}

TEST(Polinom, mult_on_const_is_correct) {
	Polinom p1("x^2y^2+y^2z^2");
	p1 = p1 * 5;
	EXPECT_EQ(p1.GetPolinom(), "5x^2y^2+5y^2z^2");
}

TEST(Polinom, operator_assigment_is_correct) {
	Polinom p1("x^2y^2+y^2z^2"), p2("");
	p2 = p1;
	EXPECT_EQ(p1 == p2, true);
}