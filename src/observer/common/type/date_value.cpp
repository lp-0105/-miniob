#include "common/type/date_value.h"
#include <cstdio>
#include <cstring>

bool DateValue::is_valid() const {
    // 检查范围
    if (year < 1970 || year > 2038) return false;
    if (month < 1 || month > 12) return false;
    
    // 每月天数
    int days_in_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (is_leap_year(year)) {
        days_in_month[1] = 29; // 闰年2月29天
    }
    
    if (day < 1 || day > days_in_month[month-1]) return false;
    return true;
}

bool DateValue::is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int DateValue::to_int() const {
    return year * 10000 + month * 100 + day;
}

DateValue DateValue::from_int(int int_value) {
    DateValue date;
    date.year = int_value / 10000;
    date.month = (int_value % 10000) / 100;
    date.day = int_value % 100;
    return date;
}

DateValue DateValue::from_string(const char *date_str) {
    DateValue date;
    // 解析 'YYYY-MM-DD' 格式
    if (sscanf(date_str, "%d-%d-%d", &date.year, &date.month, &date.day) == 3) {
        return date;
    }
    // 如果解析失败，返回默认值
    return DateValue(1970, 1, 1);
}

std::string DateValue::to_string() const {
    char buffer[11]; // YYYY-MM-DD + null terminator
    snprintf(buffer, sizeof(buffer), "%04d-%02d-%02d", year, month, day);
    return std::string(buffer);
}