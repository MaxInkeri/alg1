#include "pch.h"
#include "CppUnitTest.h"
#include "../alg1/List.h"
#include <sstream>

#define _STREAM ostringstream stream; stream // initialize ostringstream object and use it
#define _STREAMSTR stream.str().c_str() // get string from ostringstream object

#define TEST_INIT_LIST { 1, 2, 3 }

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace alg1unittest
{
	TEST_CLASS(alg1unittest)
	{

	public:


		TEST_METHOD(constructor_fromInitializerList)
		{
			List list(TEST_INIT_LIST);
			_STREAM << list;
			Assert::AreEqual("{  1  2  3  }", _STREAMSTR);
		}

		TEST_METHOD(constructor_fromEmptyInitializerList)
		{
			List list({});
			_STREAM << list;
			Assert::AreEqual("{  }", _STREAMSTR);
		}

		TEST_METHOD(constructor_fromArray)
		{
			size_t testArraySize = 3;
			int* testArray = new int[testArraySize] { 1, 2, 3 };
			List list(testArray, testArraySize);
			_STREAM << list;
			Assert::AreEqual("{  1  2  3  }", _STREAMSTR);
		}

		TEST_METHOD(constructor_fromValues)
		{
			List list(3, 1, 2, 3);
			_STREAM << list;
			Assert::AreEqual("{  1  2  3  }", _STREAMSTR);
		}

		TEST_METHOD(constructor_default)
		{
			List list = *new List();
			_STREAM << list;
			Assert::AreEqual("{  }", _STREAMSTR);
		}

		TEST_METHOD(function_pushBack)
		{
			List list(TEST_INIT_LIST);
			list.push_back(4);
			_STREAM << list;
			Assert::AreEqual("{  1  2  3  4  }", _STREAMSTR);
		}

		TEST_METHOD(function_pushBack_toEmptyList)
		{
			List list = *new List();
			list.push_back(0);
			_STREAM << list;
			Assert::AreEqual("{  0  }", _STREAMSTR);
		}

		TEST_METHOD(function_pushFront)
		{
			List list(TEST_INIT_LIST);
			list.push_front(0);
			_STREAM << list;
			Assert::AreEqual("{  0  1  2  3  }", _STREAMSTR);
		}

		TEST_METHOD(function_pushFront_toEmptyList)
		{
			List list = *new List();
			list.push_front(0);
			_STREAM << list;
			Assert::AreEqual("{  0  }", _STREAMSTR);
		}

		TEST_METHOD(function_popBack)
		{
			List list(TEST_INIT_LIST);
			int val = list.pop_back();
			_STREAM << list;
			Assert::IsTrue(val == 3);
			Assert::AreEqual("{  1  2  }", _STREAMSTR);
		}

		TEST_METHOD(function_popFront)
		{
			List list(TEST_INIT_LIST);
			int val = list.pop_front();
			_STREAM << list;
			Assert::IsTrue(val == 1);
			Assert::AreEqual("{  2  3  }", _STREAMSTR);
		}

		TEST_METHOD(function_insert_front)
		{
			List list(TEST_INIT_LIST);
			list.insert(0, 0); // insert at the beginning
			_STREAM << list;
			Assert::AreEqual("{  0  1  2  3  }", _STREAMSTR);
		}

		TEST_METHOD(function_insert_middle)
		{
			List list(TEST_INIT_LIST);
			list.insert(1, -1); // insert in the middle
			_STREAM << list;
			Assert::AreEqual("{  1  -1  2  3  }", _STREAMSTR);
		}

		TEST_METHOD(function_insert_back)
		{
			List list(TEST_INIT_LIST);
			list.insert(3, 4); // insert at the end
			_STREAM << list;
			Assert::AreEqual("{  1  2  3  4  }", _STREAMSTR);
		}

		TEST_METHOD(function_at)
		{
			List list(TEST_INIT_LIST);
			int val1 = list.at(0);
			int val2 = list.at(1);
			int val3 = list.at(2);
			Assert::IsTrue(val1 == 1 && val2 == 2 && val3 == 3);
		}

		TEST_METHOD(function_remove)
		{
			List list(TEST_INIT_LIST);
			int val = list.remove(1);
			_STREAM << list;
			Assert::AreEqual("{  1  3  }", _STREAMSTR);
			Assert::IsTrue(val == 2);
		}

		TEST_METHOD(function_clear)
		{
			List list(TEST_INIT_LIST);
			list.clear();
			_STREAM << list;
			Assert::AreEqual("{  }", _STREAMSTR);
		}

		TEST_METHOD(function_set)
		{
			List list(TEST_INIT_LIST);
			list.set(1, -2);
			_STREAM << list;
			Assert::AreEqual("{  1  -2  3  }", _STREAMSTR);
		}

		TEST_METHOD(function_isEmpty_true)
		{
			List list({});
			Assert::IsTrue(list.isEmpty());
		}

		TEST_METHOD(function_isEmpty_false)
		{
			List list(TEST_INIT_LIST);
			Assert::IsFalse(list.isEmpty());
		}

		TEST_METHOD(function_reverse)
		{
			List list(TEST_INIT_LIST);
			list.reverse();
			_STREAM << list;
			Assert::AreEqual("{  3  2  1  }", _STREAMSTR);
		}
	};
}
