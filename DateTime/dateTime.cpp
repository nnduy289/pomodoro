#include "dateTime.h"

void getCurrentDateTime(int& day, int& month, int& year, int& hour, int& minute, int& second) {
    time_t timestamp = time(&timestamp);
struct tm datetime = *localtime(&timestamp);

    day = datetime.tm_mday;
    month = datetime.tm_mon + 1; // tm_mon is 0-based
    year = datetime.tm_year + 1900; // tm_year is years since 1900
    hour = datetime.tm_hour;
    minute = datetime.tm_min;
    second = datetime.tm_sec;

    std::cout << "Current Date and Time: " << day << "/" << month << "/" << year << " " << hour << ":" << minute << ":" << second << std::endl;
}
