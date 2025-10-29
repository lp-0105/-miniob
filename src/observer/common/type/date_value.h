// date_value.h
#pragma once

#include <string>

struct DateValue {
    int year;
    int month;
    int day;
    
    DateValue() : year(1970), month(1), day(1) {}
    DateValue(int y, int m, int d) : year(y), month(m), day(d) {}
    
    bool is_valid() const;
    static bool is_leap_year(int year);
    int to_int() const; // 转换为整数存储 YYYYMMDD
    static DateValue from_int(int int_value);
    static DateValue from_string(const char *date_str);
    std::string to_string() const;
    
    bool operator==(const DateValue &other) const {
        return year == other.year && month == other.month && day == other.day;
    }
    
    bool operator<(const DateValue &other) const {
        return to_int() < other.to_int();
    }
};