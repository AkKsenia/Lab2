#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab2/Lab2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
TEST_CLASS(UnitTest1)
{
public:

TEST_METHOD(TestMethod1)
{
DynamicArray<int> arr1(5);
DynamicArray<int> arrr(std::move(arr1));
int arr1_size_expected = 0;
int arrr_size_expected = 5;
int arr1_size_actual = arr1.GetSize();
    int arrr_size_actual = arrr.GetSize();
Assert::AreEqual(arrr_size_expected, arrr_size_actual);
}
TEST_METHOD(TestMethod2)
{
DynamicArray<int> arr1(5);
DynamicArray<int> arrr(std::move(arr1));
int arr1_size_expected = 0;
int arrr_size_expected = 5;
int arr1_size_actual = arr1.GetSize();
int arrr_size_actual = arrr.GetSize();
Assert::AreEqual(arr1_size_expected, arr1_size_actual);
}

TEST_METHOD(TestMethod3)
{
DynamicArray<int> arr1(5);
int elem_actual;
try {
arr1.Set(0, 0);
elem_actual = arr1.Get(0);
}
catch (const char* msg) {
cout << msg << endl;
}
int elem_expected = 0;
Assert::AreEqual(elem_expected, elem_actual);
}

TEST_METHOD(TestMethod4)
{
DynamicArray<int> arr1(5);
int size_expected = 5;
int size_actual = arr1.GetSize();
Assert::AreEqual(size_expected, size_actual);
}

TEST_METHOD(TestMethod5)
{
DynamicArray<int> arr1(5);
arr1[0] = 6;
int elem_expected = 6;
int elem_actual = arr1.Get(0);
Assert::AreEqual(elem_expected, elem_actual);
}
};
}
