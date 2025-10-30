#pragma once

#include "common/type/data_type.h"

class DateType : public DataType {
public:
  DateType() : DataType(AttrType::DATES) {}
  ~DateType() override = default;

  int compare(const Value &left, const Value &right) const override;

  RC set_value_from_str(Value &val, const string &data) const override;
};
