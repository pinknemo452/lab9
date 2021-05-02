#include <iostream>
#include "my_lab.h"
exception::exception(std::string mes) : message(mes) {}

int polynominal::multiply(polynominal& target) {
	if (degree > target.degree)
		throw exception("in multiply degree > target.degree");
	if (degree == target.degree)
		return 0;
	int i = 0;
	const int old_degree = degree;
	while (target.coeffs[i] == 0) {
		i++;
	}
	const int newdegree = target.degree - i;
	if (newdegree > degree) {
		int* newcoef = new int[newdegree];
		for (int j = 0; j < newdegree; j++)
			newcoef[j] = 0;
		for (int j = 0; j < degree; j++) 
			newcoef[j] = coeffs[j];
		delete[] coeffs;
		coeffs = new int[newdegree];
		for (int j = 0; j < newdegree; j++)
			coeffs[j] = newcoef[j];
		delete[] newcoef;
		degree = newdegree;
	}
	return newdegree - old_degree;
}

polynominal polynominaldivide(const polynominal& first, const polynominal& second)
{
	if (first.degree < second.degree) {
		throw exception("in divide first degree < second degree");
	}
	auto* current = new polynominal(first.degree, first.coeffs);
	int* remainder = new int[first.degree];
	int max_multi = 0;
	for (int i = 0; i < first.degree; i++)
		remainder[i] = 0;
	for (size_t i = 0; i < first.degree; i++)
		remainder[i] = 0;
	int multiplier = first.degree - second.degree;
	while (multiplier != 0) {
		auto* divisor = new polynominal(second.degree, second.coeffs);
		if (current->degree < second.degree)
			break;
		multiplier = divisor->multiply(*current);
		if (multiplier > max_multi)
			max_multi = multiplier;
		remainder[max_multi -multiplier] = 1;
		if ((*current - *divisor).degree == 0) {
			delete divisor;
			break;
		}
		delete divisor;
	}
	current->print();
	
	std::cout << "result of the division is ";
	polynominal(max_multi+1, remainder).print();
	delete[] remainder;
	return *current;
}

void polynominal::print() {
	while (coeffs[0] == 0)
	{
		if (degree == 0) {
			std::cout << "0\n";
			return;
		}
		for (int i = 1; i < degree; i++)
			std::swap(coeffs[i], coeffs[i - 1]);
		degree--;
		
	}
	for (int i = 0; i < degree; i++) 
		std::cout << coeffs[i] << " ";
	std::cout << "\n";
}

int to_field(const int gF, int number) {
	while (number >= gF || number < 0)
	{
		while (number < 0)
		{
			number += gF;
		}
		while (number >= gF) {
			number -= gF;
		}
	}
	return number;
}

polynominal::~polynominal()
{
	delete[] coeffs;
}

polynominal::polynominal(int deg, int* coe)
{
	degree = deg;
	coeffs = new int[degree];
	for (int i = 0; i < degree; i++) {
		coeffs[i] = to_field(2, coe[i]);
	}
}

polynominal polynominal::operator-(polynominal& deductible)
{
	if (degree != deductible.degree)
		throw exception("in operator - degrees are not equal");
	for (int i = 0; i < degree; i++) {
		coeffs[i] = to_field(2, coeffs[i] - deductible.coeffs[i]);
	}
	while (coeffs[0] == 0)
	{
		for (int i = 1; i < degree; i++)
			std::swap(coeffs[i], coeffs[i - 1]);
		degree--;
		if (degree == 0)
			return polynominal(0,nullptr);
	}
	return polynominal(degree, coeffs);
}