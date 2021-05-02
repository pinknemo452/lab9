#ifndef MY_LAB_H
#define MY_LAB_H

#include <iostream>
class exception {
public:
	exception(std::string mes);
	std::string message;
};

class polynominal {
public:
	int degree;
	int* coeffs;

	polynominal(int deg, int* coe);
	polynominal operator-(polynominal& deductible);
	int multiply(polynominal& target);
	void print();
	~polynominal();
};

polynominal polynominaldivide(const polynominal& first, const polynominal& second);
#endif