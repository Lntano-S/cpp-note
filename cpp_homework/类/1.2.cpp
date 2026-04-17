#include <iostream>
#include <iomanip>

using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

struct Time {
    int hour;
    int minutes;
    int seconds;
};

class DateTime {
private:    
    Date* date;
    Time* time;

public:
    DateTime() 
        : date(new Date{0, 0, 0}), time(new Time{0, 0, 0}) {}

    DateTime(int y, int m, int d, int h, int min, int s)
        : date(new Date{y, m, d}), time(new Time{h, min, s}) {}

    void setDateTime(int y, int m, int d, int h, int min, int s) {
        date->year = y;
        date->month = m;
        date->day = d;
        time->hour = h;
        time->minutes = min;
        time->seconds = s;
    }

    void print() const{
        cout << date->year << "-"
             << setw(2) << setfill('0') << date->month << "-"
             << setw(2) << setfill('0') << date->day << " "
             << setw(2) << setfill('0') << time->hour << ":"
             << setw(2) << setfill('0') << time->minutes << ":"
             << setw(2) << setfill('0') << time->seconds << "\n";
    }
    
    ~DateTime() {
        delete date;
        delete time;
    }
};

int main(void) {
    int y, m, d, h, min, s;
    cin >> y >> m >> d >> h >> min >> s;

    DateTime dt;
    dt.setDateTime(y, m, d, h, min, s);
    dt.print();

    return 0;
}