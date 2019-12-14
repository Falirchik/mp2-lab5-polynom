#include "polynom.cpp"
#include <gtest.h>


TEST(Pol_str, can_create_Pol_str) {
	ASSERT_NO_THROW(Pol_str pol("x1y2z3+4.5-x6y7z9"));
}

TEST(Pol_str, cannot_create_Pol_str_with_unwanted_variables) {
	ASSERT_ANY_THROW(Pol_str pol("x1y2z3x4"));
}

TEST(Pol_str, cannot_create_Pol_str_with_unwanted_simbol) {
	ASSERT_ANY_THROW(Pol_str pol("rx!x5_"));
}

TEST(Pol_str, cannot_create_Pol_str_with_big_deg) {
	ASSERT_ANY_THROW(Pol_str pol("x10y20z30"));
}

TEST(Pol_str, cannot_create_Pol_str_with_double_deg) {
	ASSERT_ANY_THROW(Pol_str pol("-5x7.6y7z8"));
}

TEST(Pol_str, cannot_create_polynom_without_deg) {
	ASSERT_ANY_THROW(Pol_str("xyz"));
}

TEST(Pol_str, GetString_is_correct) {
	Pol_str pol("x1y2z3-4.5z6+y5");
	EXPECT_EQ(pol.GetString(), "x1y2z3-4.5z6+y5");
}

TEST(Polynom, can_create_polynom) {
	Pol_str polstr("x1y2z3+4.5x6");
	ASSERT_NO_THROW(Polynom pol(polstr));
}

TEST(Polynom, add_is_correct) {
	Pol_str tmp1("x1y2z3+4.5x6y7");
	Pol_str tmp2("x1y2z3+4.5x6y7");
	Pol_str tmp3("2x1y2z3+9x6y7");
	Polynom pol1(tmp1), pol2(tmp2), pol3(tmp3);
	EXPECT_EQ((pol1 + pol2) == pol3, true);
}

TEST(Polynom, mult_is_correct) {
	Pol_str tmp1("x1y2+y4z3");
	Pol_str tmp2("x1y2+y4z3");
	Pol_str tmp3("x2y4+2x1y6z3+y8z6");
	Polynom pol1(tmp1), pol2(tmp2), pol3(tmp3);
	EXPECT_EQ((pol1 * pol2) == pol3, true);
}

TEST(Polynom, multbyconst_is_correct) {
	Pol_str tmp1("x1y2+3y4z5");
	Pol_str tmp3("2x1y2+6y4z5");
	Polynom pol1(tmp1), pol3(tmp3);
	EXPECT_EQ((pol1.MultByConst(2)) == pol3, true);
}

TEST(Polynom, calculation_is_correct) {
	Pol_str tmp("x2y3z4-x2z3+z5");
	Polynom pol(tmp);
	EXPECT_EQ(pol.Calculation(1, 2, -2), 104);
}

