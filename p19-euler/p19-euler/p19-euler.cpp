#include <iostream>

#include "Date.h"

using namespace std;

int main()
{
    cout << "Calculation started" << endl;


    int answer_p19 = 0;

    Date d = Date(7, 1, 1900);
    Date start = Date(1, 1, 1901);
    Date end = Date(31, 12, 2000);

    while (d <= end)
    {
        if (d >= start)
        {
            if (d.iSFirstOfMonth())
            {
                answer_p19++;
            }
        }

        d.addSevenDays();

        //cout << d.getDay() << "\t" << d.getMonth() << "\t" << d.getYear() << endl;
    }



    cout << "The answer to problem 19 of project Euler is " << answer_p19 << "." << endl;
}

