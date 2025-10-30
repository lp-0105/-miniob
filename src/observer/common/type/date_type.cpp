#include "common/type/date_type.h"
#include "common/type/date_value.h"
#include "common/value.h"
#include "common/log/log.h"

int DateType::compare(const Value &left, const Value &right) const {
  // Value::compare already handles AttrType::DATES
  return left.compare(right);
}

RC DateType::set_value_from_str(Value &val, const string &data) const {
  // Accept 'YYYY-MM-DD' or YYYY-MM-DD (with or without quotes)
  // strip quotes if present
  string tmp = data;
  if (tmp.size() >= 2 && ((tmp.front() == '\'' && tmp.back() == '\'') || (tmp.front() == '"' && tmp.back() == '"'))) {
    tmp = tmp.substr(1, tmp.size() - 2);
  }
  DateValue dv = DateValue::from_string(tmp.c_str());
  if (!dv.is_valid()) {
    LOG_WARN("DateType: invalid date string '%s'", tmp.c_str());
    return RC::INVALID_ARGUMENT;
  }
  val.set_date(dv);
  return RC::SUCCESS;
}
