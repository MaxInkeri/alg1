#include "pch.h"
#include "CppUnitTest.h"
#include "../alg1/List.h"
#include <vector>
#include <sstream>

#define _STREAM ostringstream stream; stream // initialize ostringstream object and use it
#define _STREAMSTR stream.str().c_str() // get string from ostringstream object

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace alg1unittest
{
	TEST_CLASS(alg1unittest)
	{
	private:
		vector<int> testVector = { 1, 2, 3 };

	public:
		
		TEST_METHOD(constructor_fromVector)
		{
			List listFromVector(testVector);
			_STREAM << listFromVector;
			Assert::AreEqual("{  1  2  3  }", _STREAMSTR);
		}

		TEST_METHOD(constructor_fromEmptyVector)
		{
			vector<int> emptyVector = {};
			List listFromVector(emptyVector);
			_STREAM << listFromVector;
			Assert::AreEqual("{  }", _STREAMSTR);
		}

		TEST_METHOD(constructor_fromArray)
		{
			size_t testArraySize = 3;
			int* testArray = new int[testArraySize] { 1, 2, 3 };
			List listFromArray(testArray, testArraySize);
			_STREAM << listFromArray;
			Assert::AreEqual("{  1  2  3  }", _STREAMSTR);
		}

		TEST_METHOD(constructor_fromValues)
		{
			List listFromValues(3, 1, 2, 3);
			_STREAM << listFromValues;
			Assert::AreEqual("{  1  2  3  }", _STREAMSTR);
		}

		TEST_METHOD(constructor_fromInitializerList)
		{
			List listFromInitializerList({ 1, 2, 3 });
			_STREAM << listFromInitializerList;
			Assert::AreEqual("{  1  2  3  }", _STREAMSTR);
		}

		TEST_METHOD(constructor_default)
		{
			List listEmpty = *new List();
			_STREAM << listEmpty;
			Assert::AreEqual("{  }", _STREAMSTR);
		}

		TEST_METHOD(function_pushBack)
		{
			List list(testVector);
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
			List list(testVector);
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
			List list(testVector);
			int val = list.pop_back();
			_STREAM << list;
			Assert::IsTrue(val == 3);
			Assert::AreEqual("{  1  2  }", _STREAMSTR);
		}

		TEST_METHOD(function_popFront)
		{
			List list(testVector);
			int val = list.pop_front();
			_STREAM << list;
			Assert::IsTrue(val == 1);
			Assert::AreEqual("{  2  3  }", _STREAMSTR);
		}

		TEST_METHOD(function_insert_front)
		{
			List list(testVector);
			list.insert(0, 0); // insert at the beginning
			_STREAM << list;
			Assert::AreEqual("{  0  1  2  3  }", _STREAMSTR);
		}

		TEST_METHOD(function_insert_middle)
		{
			List list(testVector);
			list.insert(1, -1); // insert in the middle
			_STREAM << list;
			Assert::AreEqual("{  1  -1  2  3  }", _STREAMSTR);
		}

		TEST_METHOD(function_insert_back)
		{
			List list(testVector);
			list.insert(3, 4); // insert at the end
			_STREAM << list;
			Assert::AreEqual("{  1  2  3  4  }", _STREAMSTR);
		}

		TEST_METHOD(function_at)
		{
			List list(testVector);
			int val1 = list.at(0);
			int val2 = list.at(1);
			int val3 = list.at(2);
			Assert::IsTrue(val1 == 1 && val2 == 2 && val3 == 3);
		}

		TEST_METHOD(function_remove)
		{
			List list(testVector);
			int val = list.remove(1);
			_STREAM << list;
			Assert::AreEqual("{  1  3  }", _STREAMSTR);
			Assert::IsTrue(val == 2);
		}

		TEST_METHOD(function_clear)
		{
			List list(testVector);
			list.clear();
			_STREAM << list;
			Assert::AreEqual("{  }", _STREAMSTR);
		}

		TEST_METHOD(function_set)
		{
			List list(testVector);
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
			List list(testVector);
			Assert::IsFalse(list.isEmpty());
		}

		TEST_METHOD(function_reverse)
		{
			List list(testVector);
			list.reverse();
			_STREAM << list;
			Assert::AreEqual("{  3  2  1  }", _STREAMSTR);
		}
	};
}
