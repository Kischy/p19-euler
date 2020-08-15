#pragma once

class Date
{
public:
	Date(int day, int month, int year)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}


	bool operator>(const Date& rhs)
	{
		if (this->year > rhs.year)
		{
			return true;
		}

		if (this->year == rhs.year)
		{
			if (isBiggerMonth(rhs.month, rhs.day))
			{
				return true;
			}
		}

		return false;
	}


	bool operator<(const Date& rhs)
	{
		return true;
	}


private:
	int day, month, year;


	bool isBiggerMonth(const int rhs_month, const int rhs_day)
	{
		if (this->month > rhs_month)
		{
			return true;
		}

		if (this->month == rhs_month)
		{
			if (this->day > rhs_day)
			{
				return true;
			}
		}

		return false;
	}




};

