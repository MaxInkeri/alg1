#include "pch.h"
#include "CppUnitTest.h"
#include "../alg1/List.h"
#include <vector>
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace alg1unittest
{
	TEST_CLASS(alg1unittest)
	{
	private:
		static const size_t testArraySize = 3;
		int* testArray = new int[testArraySize] { 1, 2, 3 };
		vector<int> testVector = { 1, 2, 3 };

	public:
		
		TEST_METHOD(constructor_fromVector)
		{
			List listFromVector(testVector);
			ostringstream stream;
			stream << listFromVector;
			Assert::AreEqual("{  1  2  3  }", stream.str().c_str());
		}

		TEST_METHOD(constructors_fromArray)
		{
			List listFromArray(testArray, testArraySize);
			ostringstream stream;
			stream << listFromArray;
			Assert::AreEqual("{  1  2  3  }", stream.str().c_str());
		}

		TEST_METHOD(constructor_fromValues)
		{
			List listFromValues(3, 1, 2, 3);
			ostringstream stream;
			stream << listFromValues;
			Assert::AreEqual("{  1  2  3  }", stream.str().c_str());
		}

		TEST_METHOD(constructor_fromInitializerList)
		{
			List listFromInitializerList({ 1, 2, 3 });
			ostringstream stream;
			stream << listFromInitializerList;
			Assert::AreEqual("{  1  2  3  }", stream.str().c_str());
		}

		TEST_METHOD(constructor_default)
		{
			List listEmpty = *new List();
			ostringstream stream;
			stream << listEmpty;
			Assert::AreEqual("{  }", stream.str().c_str());
		}

		TEST_METHOD(function_pushBack)
		{
			List list(testVector);
			list.push_back(4);
			ostringstream stream;
			stream << list;
			Assert::AreEqual("{  1  2  3  4  }", stream.str().c_str());
		}

		TEST_METHOD(function_pushFront)
		{
			List list(testVector);
			list.push_front(0);
			ostringstream stream;
			stream << list;
			Assert::AreEqual("{  0  1  2  3  }", stream.str().c_str());
		}

		TEST_METHOD(function_popBack)
		{
			List list(testVector);
			int val = list.pop_back();
			ostringstream stream;
			stream << list;
			Assert::IsTrue(val == 3);
			Assert::AreEqual("{  1  2  }", stream.str().c_str());
		}

		TEST_METHOD(function_popFront)
		{
			List list(testVector);
			int val = list.pop_front();
			ostringstream stream;
			stream << list;
			Assert::IsTrue(val == 1);
			Assert::AreEqual("{  2  3  }", stream.str().c_str());
		}

		TEST_METHOD(function_insert)
		{
			List list1(testVector);
			list1.insert(0, 0); // insert at the beginning
			ostringstream stream1, stream2, stream3;
			stream1 << list1;
			Assert::AreEqual("{  0  1  2  3  }", stream1.str().c_str());
			List list2(testVector);
			list2.insert(-1, 1); // insert in the middle
			stream2 << list2;
			Assert::AreEqual("{  1  -1  2  3  }", stream2.str().c_str());
			List list3(testVector);
			list3.insert(4, 3); // insert at the end
			stream3 << list3;
			Assert::AreEqual("{  1  2  3  4  }", stream3.str().c_str());
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
			ostringstream stream;
			stream << list;
			Assert::AreEqual("{  1  3  }", stream.str().c_str());
			Assert::IsTrue(val == 2);
		}

		TEST_METHOD(function_clear)
		{
			List list(testVector);
			list.clear();
			ostringstream stream;
			stream << list;
			Assert::AreEqual("{  }", stream.str().c_str());
		}

		TEST_METHOD(function_set)
		{
			List list(testVector);
			list.set(1, -2);
			ostringstream stream;
			stream << list;
			Assert::AreEqual("{  1  -2  3  }", stream.str().c_str());
		}

		TEST_METHOD(function_isEmpty)
		{
			List list({});
			Assert::IsTrue(list.isEmpty());
		}

		TEST_METHOD(function_reverse)
		{
			List list(testVector);
			list.reverse();
			ostringstream stream;
			stream << list;
			Assert::AreEqual("{  3  2  1  }", stream.str().c_str());
		}
	};
}
