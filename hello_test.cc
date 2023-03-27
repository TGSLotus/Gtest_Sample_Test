#include "AdditionExample1.h"
#include "ClassExample1.cpp"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;
using ::testing::AtLeast;
using ::testing::Return;

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
  EXPECT_EQ(addition(1, 2), 3);
};

TEST(Test2, MockTest){
  MockClass1 mockClass1;
  EXPECT_CALL(mockClass1, CallTwoStringFunctionTwice()).Times(AtLeast(1)).WillOnce(Return(true));
  EXPECT_CALL(mockClass1, TwoStringFunction("a", "a")).Times(AtLeast(2)).WillRepeatedly(Return(true));
  EXPECT_EQ(mockClass1.CallTwoStringFunctionTwice(), true);
  EXPECT_EQ(mockClass1.TwoStringFunction("a", "a"), true);
  EXPECT_EQ(mockClass1.TwoStringFunction("a", "a"), true);
  EXPECT_CALL(mockClass1, TwoStringFunction("a", "b")).Times(AtLeast(1)).WillOnce(Return(false));
  EXPECT_EQ(mockClass1.TwoStringFunction("a", "b"), false);
};