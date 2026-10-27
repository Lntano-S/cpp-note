#include <iostream>
#include <vector>

using namespace std;

void month_day(int year, int yearday, int* pmonth, int* pday);

void month_day(int year, int yearday, int* pmonth, int* pday) {
    vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool is_leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (is_leap) { days[1] = 29; }
    
    for (size_t i = 0; i < days.size(); i++) {
        if (yearday > days[i]) {
            yearday -= days[i];       
        } else if (yearday <= days[i]) {
            *pmonth = i + 1;
            *pday = yearday;
            break;
        }
    }
}

int main(void) {
    int day, month, year, yearday; /*  定义代表日、月、年和天数的变量*/
    cin >> year >> yearday;        
    month_day (year, yearday, &month, &day );/* 调用计算月、日函数  */ 
    cout << year << " " << month << " " << day << endl;    
    return 0;
}