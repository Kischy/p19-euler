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

	
	bool iSFirstOfMonth() const
	{
		if (day == 1)
		{
			return true;
		}

		return false;
	}


	bool operator>(const Date& rhs) const
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


	bool operator<(const Date& rhs) const 
	{
		if (*this > rhs)
		{
			return false;
		}

		if (this->day == rhs.day && this->month == rhs.month && this->year == rhs.year)
		{
			return false;
		}

		return true;
	}

	int getDay() const
	{
		return day;
	}

	int getMonth() const
	{
		return month;
	}

	int getYear() const
	{
		return year;
	}


private:
	int day, month, year;


	bool isBiggerMonth(const int rhs_month, const int rhs_day) const 
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

