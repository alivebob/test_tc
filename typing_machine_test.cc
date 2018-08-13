// Copyright 2018 Minkyu Jo

#include "typing_machine.h"
#include "typing_machine_test.h"
#include "test.h"

class TmConstructorTestSuite
{
private:
  static void BarSeparatorTest() {
    TypingMachine tm;
    ASSERT_EQ(tm.Print('|'), std::string("|"));
	ASSERT_EQ(tm.Print(0), std::string(""));
  }

public:
  static void RunTest() {
    BarSeparatorTest();
    // add more..
  }
};

class KeyTestSuite
{
private:
	static void tmTest() {
		TypingMachine tm;

		tm.TypeKey('a');
		ASSERT_EQ(tm.Print('|'), std::string("a|"));
		tm.TypeKey('b');
		ASSERT_EQ(tm.Print('|'), std::string("ab|"));
		tm.TypeKey('c');
		ASSERT_EQ(tm.Print('|'), std::string("abc|"));

		tm.EndKey();
		ASSERT_EQ(tm.Print('|'), std::string("abc|"));
		tm.RightKey();
		ASSERT_EQ(tm.Print('|'), std::string("abc|"));
		tm.LeftKey();
		ASSERT_EQ(tm.Print('|'), std::string("ab|c"));

		tm.HomeKey();

		ASSERT_EQ(tm.Print('|'), std::string("|abc"));
		tm.LeftKey();
		ASSERT_EQ(tm.Print('|'), std::string("|abc"));
		tm.RightKey();
		ASSERT_EQ(tm.Print('|'), std::string("a|bc"));

		bool is_del = tm.EraseKey();
		ASSERT_TRUE(is_del);
		ASSERT_EQ(tm.Print('|'), std::string("|bc"));
		is_del = tm.EraseKey();
		ASSERT_FALSE(is_del);
		ASSERT_EQ(tm.Print('|'), std::string("|bc"));

		for (unsigned char c = 0; c < 0x20; c++){
			bool ret = tm.TypeKey(c);
			ASSERT_FALSE(ret);
			ASSERT_EQ(tm.Print('|'), std::string("|bc"));
		}


		for (unsigned char c = 0x7f; c < 0xff; c++){
			bool ret = tm.TypeKey(c);
			ASSERT_FALSE(ret);
			ASSERT_EQ(tm.Print('|'), std::string("|bc"));
		}
	}
public:
	static void RunTest() {
		// add more..
		tmTest();
	}
};

class SomeOtherTestSuite
{
private:

public:
  static void RunTest() {
    // add more..
  }
};

void TypingMachineTest() {
  TmConstructorTestSuite::RunTest();
  KeyTestSuite::RunTest();
  // add more..
}