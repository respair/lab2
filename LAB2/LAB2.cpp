#include <iostream>
#include <complex>
#include <cassert>
#include "Polinom.hpp"


//template <class T>
void TestAddPoly() {
	{
		int arr[5] = { 1,0,2,3,-1 };
		int arr1[5] = { 2,-2,0,3,0 };
		int arr2[5] = { 3,-2,2,6,-1 };
		Polynom<int> poly1(arr, 5);
		Polynom<int> poly2(arr1, 5);
		Polynom<int> poly3(arr2, 5);
		assert(poly1+(poly2) == poly3);
	}
	{
		int arr[5] = { 1,0,2,3,-1 };
		int arr1[4] = { -2,0,3,0 };
		int arr2[5] = { -1,0,5,3,-1 };
		Polynom<int> poly1(arr, 5);
		Polynom<int> poly2(arr1, 4);
		Polynom<int> poly3(arr2, 5);
		assert(poly1+(poly2) == poly3);
	}
	{
		double arr3[5] = { 1.12, 0.01, 2.25, 3.21,-1 };
		double arr4[5] = { 2.12, -2, 0.25, 3.45, 0 };
		double arr5[5] = { 3.24,-1.99,2.5,6.66,-1 };
		Polynom<double> poly4(arr3, 5);
		Polynom<double> poly5(arr4, 5);
		Polynom<double> poly6(arr5, 5);
		assert(poly4+poly5 == poly6);
	}
	{
		int arr[1] = { 0 };
		int arr1[1] = { 0 };
		int arr2[1] = { 0 };
		Polynom<int> poly1(arr, 1);
		Polynom<int> poly2(arr1, 1);
		Polynom<int> poly3(arr2, 1);
		assert(poly1+poly2 == poly3);
	}
	{
		int arr[1] = { 7744444444444444 };
		int arr1[1] = { 5555555555 };
		int arr2[1] = { 7744449999999999 };
		Polynom<int> poly1(arr, 1);
		Polynom<int> poly2(arr1, 1);
		Polynom<int> poly3(arr2, 1);
		assert(poly1+poly2 == poly3);
	}
	{
		std::complex<double> arr3[3] = { (1.12, 0.01),(2.25, 3.21),(-1.1,2) };
		std::complex<double> arr4[3] = { (2.12, -2),  (0.25, 3.45), (0,3) };
		std::complex<double> arr5[3] = { (3.24,-1.99),(2.5,6.66),(-1.1,5) };
		Polynom<std::complex<double>> poly4(arr3, 3);
		Polynom<std::complex<double>> poly5(arr4, 3);
		Polynom<std::complex<double>> poly6(arr5, 3);
		assert(poly4+poly5 == poly6);
	}
	std::cout << "test Add: 1: OK!" << std::endl;
	std::cout << "test Add: 2: OK!" << std::endl;
	std::cout << "test Add: 3: OK!" << std::endl;
	std::cout << "test Add: 4: OK!" << std::endl;
	std::cout << "test Add: 5: OK!" << std::endl;
	std::cout << "test Add: 6: OK!" << std::endl;

}

void TestSubPoly() {
	{
		int arr[5] = { 1,0,2,3,-1 };
		int arr1[5] = { 2,-2,0,3,0 };
		int arr2[5] = { -1,2,2,0,-1 };
		Polynom<int> poly1(arr, 5);
		Polynom<int> poly2(arr1, 5);
		Polynom<int> poly3(arr2, 5);
		assert(poly1-poly2 == poly3);
	}
	{
		int arr[4] = { 1,2,0,-1 };
		int arr1[2] = { 1,-2 };
		int arr2[4] = { 0,4,0,-1 };
		Polynom<int> poly1(arr, 4);
		Polynom<int> poly2(arr1, 2);
		Polynom<int> poly3(arr2, 4);
		assert(poly1-poly2 == poly3);
	}
	{
		double arr3[2] = { 0.5, 1.3 };
		double arr4[2] = { 0.2, -1 };
		double arr5[2] = { 0.3, 2.3 };
		Polynom<double> poly4(arr3, 2);
		Polynom<double> poly5(arr4, 2);
		Polynom<double> poly6(arr5, 2);
		assert(poly4-poly5 == poly6);
	}
	{
		double arr3[7] = { 0.511, 1.3, 6, 2, 0, 0.5, 3 };
		double arr4[7] = { 0.201, -1, 1.1, 2, -1.155, 0.2, 0.1 };
		double arr5[7] = { 0.31, 2.3, 4.9, 0, 1.155, 0.3, 2.9 };
		Polynom<double> poly4(arr3, 7);
		Polynom<double> poly5(arr4, 7);
		Polynom<double> poly6(arr5, 7);
		assert(poly4-poly5 == poly6);
	}
	{
		int arr[1] = { 0 };
		int arr1[1] = { 0 };
		int arr2[1] = { 0 };
		Polynom<int> poly1(arr, 1);
		Polynom<int> poly2(arr1, 1);
		Polynom<int> poly3(arr2, 1);
		assert(poly1-poly2 == poly3);
	}
	{
		int arr[1] = { 0 };
		int arr1[1] = { -12345234534534444 };
		int arr2[1] = { 12345234534534444 };
		Polynom<int> poly1(arr, 1);
		Polynom<int> poly2(arr1, 1);
		Polynom<int> poly3(arr2, 1);
		assert(poly1-poly2 == poly3);
	}
	{
		std::complex<double> arr3[2] = { (1, 0),(0.5, 1.3) };
		std::complex<double> arr4[2] = { (2, -2), (0.2, -1) };
		std::complex<double> arr5[2] = { (-1, 2),(0.3, 2.3) };
		Polynom<std::complex<double>> poly4(arr3, 2);
		Polynom<std::complex<double>> poly5(arr4, 2);
		Polynom<std::complex<double>> poly6(arr5, 2);
		assert(poly4-poly5 == poly6);
	}
	std::cout << "test Sub: 1: OK!" << std::endl;
	std::cout << "test Sub: 2: OK!" << std::endl;
	std::cout << "test Sub: 3: OK!" << std::endl;
	std::cout << "test Sub: 4: OK!" << std::endl;
	std::cout << "test Sub: 5: OK!" << std::endl;
	std::cout << "test Sub: 6: OK!" << std::endl;
	std::cout << "test Sub: 7: OK!" << std::endl;

}

void TestScalarPoly() {
	{
		int arr[5] = { 1,0,2,-3,-1 };
		int arr2[5] = { 5,0,10,-15,-5 };
		Polynom<int> poly1(arr, 5);
		Polynom<int> poly3(arr2, 5);
		poly1.ScalarPoly(5);
		assert(poly1 == poly3);
	}
	{
		double arr[5] = { 2,0,4,3,-1 };
		double arr2[5] = { 1,0,2,1.5,-0.5 };
		Polynom<double> poly1(arr, 5);
		Polynom<double> poly3(arr2, 5);
		poly1.ScalarPoly(0.5);
		assert(poly1 == poly3);
	}
	{
		int arr[1] = { 0 };
		int arr2[1] = { 0 };
		Polynom<int> poly1(arr, 1);
		Polynom<int> poly3(arr2, 1);
		poly1.ScalarPoly(2);
		assert(poly1 == poly3);
	}
	{
		double arr[2] = { 12345.7896, -345.987 };
		double arr2[2] = { 37037.3688, -1037.961 };
		Polynom<double> poly1(arr, 1);
		Polynom<double> poly3(arr2, 1);
		poly1.ScalarPoly(3);
		assert(poly1 == poly3);
	}
	{
		std::complex<double> arr3[3] = { (12, 0.02),(2.6, 4),(-1.1,1.2) };
		std::complex<double> arr5[3] = { (6,0.01),(1.3,2),(-0.5,0.6) };
		Polynom<std::complex<double>> poly4(arr3, 3);
		Polynom<std::complex<double>> poly6(arr5, 3);
		poly4.ScalarPoly(0.5);
		assert(poly4 == poly6);
	}
	std::cout << "test Scalar: 1: OK!" << std::endl;
	std::cout << "test Scalar: 2: OK!" << std::endl;
	std::cout << "test Scalar: 3: OK!" << std::endl;
	std::cout << "test Scalar: 4: OK!" << std::endl;
	std::cout << "test Scalar: 5: OK!" << std::endl;

}

void TestResultPoly() {
	{
		int arr[5] = { 1,0,2,-3,-1 };
		int arr1[5] = { 3,1,-2,1 };
		int rez = 8;
		Polynom<int> poly1(arr, 5);
		assert(poly1.GetRezult(arr1) == rez);
	}
	{
		int arr[5] = { 6,9,2,-3,1 };
		int arr1[4] = { 0,0,0,0 };
		int rez = 6;
		Polynom<int> poly1(arr, 5);
		assert(poly1.GetRezult(arr1) == rez);
	}
	{
		int arr[5] = { 0 };
		int arr1[5] = { 0 };
		int rez = 0;
		Polynom<int> poly1(arr, 5);
		assert(poly1.GetRezult(arr1) == rez);
	}
	{
		int arr[1] = { 2 };
		int arr1[2] = { 1, 2 };
		int rez = 2;
		Polynom<int> poly1(arr, 1);
		assert(poly1.GetRezult(arr1) == rez);

	}
	{
		double arr[5] = { 2.2,0.24,4,0,-1 };
		double arr2[4] = { 0,0.5,-4,1.1 };
		double rez = 3.1;
		Polynom<double> poly1(arr, 5);
		assert(poly1.GetRezult(arr2) == rez);
	}
	{
		std::complex<double> arr3[3] = { (12, 0.02),(1.3, 4),(-1.1,1.2) };
		std::complex<double> arr5[2] = { 2,0 };
		Polynom<std::complex<double>> poly4(arr3, 3);
		std::complex<double> rez = (14.6, 8.02);
		assert(poly4.GetRezult(arr5) == rez);
	}
	std::cout << "test Result: 1: OK!" << std::endl;
	std::cout << "test Result: 2: OK!" << std::endl;
	std::cout << "test Result: 3: OK!" << std::endl;
	std::cout << "test Result: 4: OK!" << std::endl;
	std::cout << "test Result: 5: OK!" << std::endl;
	std::cout << "test Result: 6: OK!" << std::endl;

}

int main() {
	std::cout << " polynomial addition test: " << std::endl;
	std::cout << std::endl;
	TestAddPoly();
	std::cout << std::endl;
	std::cout << " polynomial subtraction test: " << std::endl;
	std::cout << std::endl;
	TestSubPoly();
	std::cout << std::endl;
	std::cout << " scalar product test: " << std::endl;
	std::cout << std::endl;
	TestScalarPoly();
	std::cout << std::endl;
	std::cout << " test polynomial counting: " << std::endl;
	std::cout << std::endl;
	TestResultPoly();
	std::cout << std::endl;
	std::cout << " all tests are done! " << std::endl;
}
