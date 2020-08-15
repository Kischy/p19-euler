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

	bool operator<=(const Date& rhs) const
	{
		if (*this < rhs)
		{
			return true;
		}

		if (*this == rhs)
		{
			return true;
		}

		return false;

	}


	bool operator>=(const Date& rhs)
	{
		if (*this > rhs)
		{
			return true;
		}

		if (*this == rhs)
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

		if (*this == rhs)
		{
			return false;
		}

		return true;
	}

	bool operator==(const Date& rhs) const
	{
		if (this->day == rhs.day && this->month == rhs.month && this->year == rhs.year)
		{
			return true;
		}

		return false;
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

	void addSevenDays()
	{
		const int NoDays = 7;
		int futureDay = day + 7;

		if (futureDay <= 28)
		{
			day = futureDay;
		}
		else if (futureDay > 31) 
		{
			goToNextMonth(NoDays);
		}
		else if (futureDay == 31)
		{
			if ((is30dayMonth() || isFeb()))
			{
				goToNextMonth(NoDays);
			}
			else
			{
				day = futureDay;
			}
		}
		else if (futureDay == 30)
		{
			if (isFeb())
			{
				goToNextMonth(NoDays);
			}
			else
			{
				day = futureDay;
			}
		}
		else if (futureDay == 29)
		{
			if (isFeb() && !isLeapYear())
			{
				goToNextMonth(NoDays);
			}
			else
			{
				day = futureDay;
			}
		}


		
	}


private:
	int day, month, year;

	void goToNextMonth(const int NoDaysAdded)
	{
		if (is30dayMonth())
		{
			setNewDateNextMonth(30,NoDaysAdded);
			return;
		}

		if (is31dayMonth())
		{
			setNewDateNextMonth(31, NoDaysAdded);
			if (month == 13)
			{
				month = 1;
				year++;
			}
			return;
		}

		if (isLeapYear())
		{
			setNewDateNextMonth(29, NoDaysAdded);
		}
		else
		{
			setNewDateNextMonth(28, NoDaysAdded);
		}
	}

	void setNewDateNextMonth(const int daysInMonth, const int NoDaysAdded)
	{
		int used_days = daysInMonth - day;
		int rem_days = NoDaysAdded - used_days;
		day = rem_days;
		month++;
	}

	bool isLeapYear() const
	{
		if ((year % 4) == 0)
		{
			if ((year % 100) == 0 && (year % 400) != 0)
			{
				return false;
			}

			return true;
		}

		return false;
	}

	

	bool is31dayMonth()
	{
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			return true;
		}

		return false;
	}

	bool is30dayMonth()
	{
		if (is31dayMonth() || isFeb())
		{
			return false;
		}

		return true;
	}

	bool isFeb() const
	{
		if (month == 2)
		{
			return true;
		}

		return false;
	}

	bool isDec() const
	{
		if (month == 12)
		{
			return true;
		}

		return false;
	}


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

