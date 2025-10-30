#include "common/type/data_type.h"
#include "common/value.h"
#include "common/type/date_value.h"

#include "gtest/gtest.h"

TEST(DateTypeTest, SetValueFromStr_ValidAndInvalid)
{
  Value v;
  // valid date
  RC rc = DataType::type_instance(AttrType::DATES)->set_value_from_str(v, string("2025-10-30"));
  ASSERT_EQ(rc, RC::SUCCESS);
  DateValue dv = v.get_date();
  ASSERT_EQ(dv.year, 2025);
  ASSERT_EQ(dv.month, 10);
  ASSERT_EQ(dv.day, 30);

  // invalid date (out of range / malformed)
  rc = DataType::type_instance(AttrType::DATES)->set_value_from_str(v, string("1969-12-31"));
  ASSERT_EQ(rc, RC::INVALID_ARGUMENT);

  rc = DataType::type_instance(AttrType::DATES)->set_value_from_str(v, string("2025-02-29"));
  // 2025 is not a leap year => invalid
  ASSERT_EQ(rc, RC::INVALID_ARGUMENT);
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
