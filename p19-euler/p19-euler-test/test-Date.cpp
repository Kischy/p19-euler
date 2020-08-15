#include "pch.h"

#include "../p19-euler/Date.h"


class DateOperatorDayTests : public testing::Test
{
public:
	Date biggerDate = Date(02, 01, 1900);
	Date smallerDate = Date(01, 01, 1900);
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
	Date biggerDate = Date(01, 02, 1900);
	Date smallerDate = Date(01, 01, 1900);
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
	Date biggerDate = Date(01, 01, 1901);
	Date smallerDate = Date(01, 01, 1900);
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

