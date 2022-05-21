#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab2/Lab2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest3
{
TEST_CLASS(UnitTest3)
{
public:

TEST_METHOD(TestMethod1)
{
int* symb = new int[4];
symb[0] = 1;
symb[1] = 2;
symb[2] = 65;
symb[3] = 8;
ArraySequence<int> arr11(symb, 4);
delete[] symb;
int size_expected = 4;
int size_actual = arr11.GetLength();
Assert::AreEqual(size_expected, size_actual);
}

TEST_METHOD(TestMethod2)
{
int* symb = new int[4];
symb[0] = 1;
symb[1] = 2;
symb[2] = 65;
symb[3] = 8;
ArraySequence<int> arr11(symb, 4);
delete[] symb;
int elem_expected = 1;
int elem_actual;
try {
elem_actual = arr11.GetFirst();
}
catch (const char* msg) {
cout << msg << endl;
}
Assert::AreEqual(elem_expected, elem_actual);
}

TEST_METHOD(TestMethod3)
{
int* symb = new int[4];
symb[0] = 1;
symb[1] = 2;
symb[2] = 65;
symb[3] = 8;
ArraySequence<int> arr11(symb, 4);
delete[] symb;
int elem_expected = 8;
int elem_actual;
try {
elem_actual = arr11.GetLast();
}
catch (const char* msg) {
cout << msg << endl;
}
Assert::AreEqual(elem_expected, elem_actual);
}

TEST_METHOD(TestMethod4)
{
int* symb = new int[4];
symb[0] = 1;
symb[1] = 2;
symb[2] = 65;
symb[3] = 8;
ArraySequence<int> arr11(symb, 4);
arr11.Prepend(12);
delete[] symb;
int elem_expected = 12;
int elem_actual;
try {
elem_actual = arr11.GetFirst();
}
catch (const char* msg) {
cout << msg << endl;
}
Assert::AreEqual(elem_expected, elem_actual);
}

TEST_METHOD(TestMethod5)
{
int* symb = new int[4];
symb[0] = 1;
symb[1] = 2;
symb[2] = 65;
symb[3] = 8;
ArraySequence<int> arr11(symb, 4);
arr11.Append(12);
delete[] symb;
int elem_expected = 12;
int elem_actual;
try {
elem_actual = arr11.GetLast();
}
catch (const char* msg) {
cout << msg << endl;
}
Assert::AreEqual(elem_expected, elem_actual);
}

TEST_METHOD(TestMethod6)
{
int* symb = new int[4];
symb[0] = 1;
symb[1] = 2;
symb[2] = 65;
symb[3] = 8;
ArraySequence<int> arr11(symb, 4);
arr11.InsertAt(3, 1);
delete[] symb;
int elem_expected = 3;
int elem_actual;
try {
elem_actual = arr11.Get(1);
}
catch (const char* msg) {
cout << msg << endl;
}
Assert::AreEqual(elem_expected, elem_actual);
}
};
}
