# 📝 cls_input_validate

cls_input_validate is a C++ utility class for input validation and range checking of numbers and dates. It simplifies user input handling and ensures type safety and correctness.

✨ Features

🔢 Number Range Validation

is_number_between(int/float/double num, from, to)
Check if a number is within a range (inclusive).

📅 Date Range Validation

is_date_between(cls_date date, cls_date date1, cls_date date2)
Check if a date is within a range. Automatically swaps dates if needed.

🖊 User Input Validation

read_number_input(string msg) → Reads and validates integer input.

read_double_number_input(string msg) → Reads and validates double input with decimal point.

read_int_number_between(short from, short to, string message) → Reads integer within range.

read_double_between_input(double from, double to, string message) → Reads double within range.

✅ Date Validation

is_validate_date(cls_date date) → Checks if a cls_date object is valid.

💻 Usage Example
#include <iostream>
#include "cls_input_validate.h"
#include "cls_date.h"

using namespace std;

int main() {
    int age = cls_input_validate::read_int_number_between(18, 60, "Age must be between 18 and 60!");  // 🔢
    double salary = cls_input_validate::read_double_between_input(1000.0, 5000.0, "Salary must be in range 1000-5000.");  // 💰

    cls_date date1(2023, 1, 1);
    cls_date date2(2023, 12, 31);
    cls_date myDate(2023, 6, 15);

    if (cls_input_validate::is_date_between(myDate, date1, date2)) {  // 📅
        cout << "Date is valid and within range!" << endl;
    }

    return 0;
}

⚠️ Notes

Uses regex to ensure doubles are entered with a decimal point.

Supports range checking for int, float, double, and dates.

Works with your cls_date class for date validation.

Requires C++11 or later (for regex and raw string literals).
