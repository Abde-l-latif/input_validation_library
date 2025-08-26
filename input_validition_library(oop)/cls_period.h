#pragma once
#include "cls_date.h"

class cls_period
{
public:

    cls_date StartDate;
    cls_date EndDate;

    cls_period(cls_date StartDate, cls_date DateTo)
    {
        this->StartDate = StartDate;
        this->EndDate = DateTo;

    }

    static bool IsOverlapPeriods(cls_period Period1, cls_period Period2)
    {
 
        if (cls_date::check_if_date1_before_date2(Period1.EndDate, Period2.StartDate))
        	return false;
        if (cls_date::check_if_date1_after_date2(Period1.StartDate, Period2.EndDate))
        	return false;
        
        return true;
    }


    bool IsOverLapWith(cls_period Period2)
    {
        return IsOverlapPeriods(*this, Period2);
    }

    void print()
    {
        cout << "Period Start: ";
        StartDate.print();


        cout << "Period End: ";
        EndDate.print();
    }
};

