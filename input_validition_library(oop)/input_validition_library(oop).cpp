#include <iostream>
#include "cls_input_validate.h"



using namespace std; 

int main()
{
	 cls_input_validate::is_date_between(cls_date(10, 5, 2025), cls_date(10, 10, 2025), cls_date(10, 3, 2025)) ?
		 cout << "true" : cout << "false";
}

