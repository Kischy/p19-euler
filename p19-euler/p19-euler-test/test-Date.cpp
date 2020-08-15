#include "pch.h"

#include "../p19-euler/Date.h"


class DateOperatorDayTests : public testing::Test
{
public:
	Date biggerDate = Date(2, 1, 1900);
	Date smallerDate = Date(1, 1, 1900);
};


TEST_F(DateOperatorDayTests, IsBigger)
{
	EXPECT_TRUE(biggerDate > smallerDate);
	EXPECT_FALSE(smallerDate > biggerDate);
}

TEST_F(DateOperatorDayTests, IsSmaller)
{
	EXPECT_FALSE(biggerDate < smallerDate);
	EXPECT_TRUE(smallerDate < biggerDate);
}

class DateOperatorMonthTests : public testing::Test
{
public:
	Date biggerDate = Date(1, 2, 1900);
	Date smallerDate = Date(1, 1, 1900);
};


TEST_F(DateOperatorMonthTests, IsBigger)
{
	EXPECT_TRUE(biggerDate > smallerDate);
	EXPECT_FALSE(smallerDate > biggerDate);
}

TEST_F(DateOperatorMonthTests, IsSmaller)
{
	EXPECT_FALSE(biggerDate < smallerDate);
	EXPECT_TRUE(smallerDate < biggerDate);
}


class DateOperatorYearTests : public testing::Test
{
public:
	Date biggerDate = Date(1, 1, 1901);
	Date smallerDate = Date(1, 1, 1900);
};


TEST_F(DateOperatorYearTests, IsBigger)
{
	EXPECT_TRUE(biggerDate > smallerDate);
	EXPECT_FALSE(smallerDate > biggerDate);
}

TEST_F(DateOperatorYearTests, IsSmaller)
{
	EXPECT_FALSE(biggerDate < smallerDate);
	EXPECT_TRUE(smallerDate < biggerDate);
}

TEST(DateEqualOperator, IsEqual)
{
	Date firstDate = Date(1, 1, 1900);
	Date sameFirstDate = Date(1, 1, 1900);
	Date differentDate = Date(2, 1, 1900);
	Date differentDate2 = Date(1, 2, 1900);
	Date differentDate3 = Date(1, 1, 1800);

	EXPECT_TRUE(firstDate == sameFirstDate);
	EXPECT_FALSE(firstDate == differentDate);
	EXPECT_FALSE(firstDate == differentDate2);
	EXPECT_FALSE(firstDate == differentDate2);
}


TEST(DateFunctionTests, IsFirstOfTheMonth)
{
	Date firstOfMonth = Date(1, 2, 1900);
	Date NotFirstOfMonth = Date(2, 1, 1900);

	EXPECT_TRUE(firstOfMonth.iSFirstOfMonth());
	EXPECT_FALSE(NotFirstOfMonth.iSFirstOfMonth());	
}


TEST(DateAddSevenDaysTests, AddsSevenDays)
{
	Date d = Date(1, 2, 1900);
	const Date ex_d = Date(8, 2, 1900);

	d.addSevenDays();

	EXPECT_TRUE(d == ex_d);
}

TEST(DateAddSevenDaysTests, GoOverSeptember)
{
	Date d = Date(24, 9, 1900);
	const Date ex_d = Date(1, 10, 1900);

	d.addSevenDays();

	EXPECT_TRUE(d == ex_d);
}

TEST(DateAddSevenDaysTests, GoOverApril)
{
	Date d = Date(24, 4, 1900);
	const Date ex_d = Date(1, 5, 1900);

	d.addSevenDays();

	EXPECT_TRUE(d == ex_d);
}

TEST(DateAddSevenDaysTests, GoOverJune)
{
	Date d = Date(24, 6, 1900);
	const Date ex_d = Date(1, 7, 1900);

	d.addSevenDays();

	EXPECT_TRUE(d == ex_d);
}

TEST(DateAddSevenDaysTests, GoOverNovember)
{
	Date d = Date(24, 11, 1900);
	const Date ex_d = Date(1, 12, 1900);

	d.addSevenDays();

	EXPECT_TRUE(d == ex_d);
}


TEST(DateAddSevenDaysTests, GoOverJan)
{
	Date d = Date(25, 1, 1900);
	const Date ex_d = Date(1, 2, 1900);

	d.addSevenDays();

	EXPECT_TRUE(d == ex_d);
}

TEST(DateAddSevenDaysTests, GoOverMarch)
{
	Date d = Date(25, 3, 1900);
	const Date ex_d = Date(1, 4, 1900);

	d.addSevenDays();

	EXPECT_TRUE(d == ex_d);
}

TEST(DateAddSevenDaysTests, GoOverMarchBug)
{
	Date d = Date(24, 3, 1900);
	const Date ex_d = Date(31, 3, 1900);

	d.addSevenDays();

	EXPECT_TRUE(d == ex_d);
}

TEST(DateAddSevenDaysTests, GoOverMay)
{
	Date d = Date(25, 5, 1900);
	const Date ex_d = Date(1, 6, 1900);

	d.addSevenDays();

	EXPECT_TRUE(d == ex_d);
}

TEST(DateAddSevenDaysTests, GoOverJuly)
{
	Date d = Date(25, 7, 1900);
	const Date ex_d = Date(1, 8, 1900);

	d.addSevenDays();

	EXPECT_TRUE(d == ex_d);
}

TEST(DateAddSevenDaysTests, GoOverAugust)
{
	Date d = Date(25, 8, 1900);
	const Date ex_d = Date(1, 9, 1900);

	d.addSevenDays();

	EXPECT_TRUE(d == ex_d);
}


TEST(DateAddSevenDaysTests, GoOverOctober)
{
	Date d = Date(25, 10, 1900);
	const Date ex_d = Date(1, 11, 1900);

	d.addSevenDays();

	EXPECT_TRUE(d == ex_d);
}

TEST(DateAddSevenDaysTests, GoOverDecember)
{
	Date d = Date(25, 12, 1900);
	const Date ex_d = Date(1, 1, 1901);

	d.addSevenDays();

	EXPECT_TRUE(d == ex_d);
}



TEST(DateAddSevenDaysTests, GoOverFebruaryNonLeapYear)
{
	Date d = Date(22, 2, 1901);
	const Date ex_d = Date(1, 3, 1901);

	d.addSevenDays();

	EXPECT_TRUE(d == ex_d);
}

TEST(DateAddSevenDaysTests, GoOverFebruaryLeapYear)
{
	Date d = Date(23, 2, 1904);
	const Date ex_d = Date(1, 3, 1904);

	d.addSevenDays();

	EXPECT_TRUE(d == ex_d);
}

TEST(DateAddSevenDaysTests, GoOverFebruaryNonLeapYearCentury)
{
	Date d = Date(22, 2, 1900);
	const Date ex_d = Date(1, 3, 1900);

	d.addSevenDays();

	EXPECT_TRUE(d == ex_d);
}


TEST(DateAddSevenDaysTests, GoOverFebruaryLeapYearCentury)
{
	Date d = Date(23, 2, 2000);
	const Date ex_d = Date(1, 3, 2000);

	d.addSevenDays();

	EXPECT_TRUE(d == ex_d);
}






