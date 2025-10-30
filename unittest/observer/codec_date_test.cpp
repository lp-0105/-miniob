#include "storage/common/codec.h"
#include "common/value.h"
#include "common/type/date_value.h"

#include "gtest/gtest.h"

TEST(CodecDateTest, EncodeDecodeDate)
{
  DateValue dv(2025, 10, 30);
  Value v(dv);
  bytes encoded;
  RC rc = Codec::encode_value(v, encoded);
  ASSERT_EQ(rc, RC::SUCCESS);

  span<byte_t> sp(encoded);
  Value out;
  rc = Codec::decode_value(sp, AttrType::DATES, out);
  ASSERT_EQ(rc, RC::SUCCESS);

  DateValue dv_out = out.get_date();
  ASSERT_TRUE(dv_out == dv);
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
