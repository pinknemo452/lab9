#include "pch.h"

#include <gtest/gtest.h>

#include "../lab9/my_lab.cpp"
#include "../lab9/my_lab.h"

TEST(to_field_test, standart) {
	const int field = 2;
  EXPECT_EQ(to_field(field, 1), 1);
  EXPECT_EQ(to_field(field, -2), 0);
  EXPECT_EQ(to_field(field, -1), 1);
  EXPECT_EQ(to_field(field, 5), 1);
  EXPECT_EQ(to_field(field, -5), 1);
  EXPECT_EQ(to_field(field, -6), 0);
}
TEST(multiply_test, standart) {
	int p1_degree = 5;
	int* p1_coefs = new int[5]{ 1,0,1,0,1 };
	int p2_degree = 3;
	int* p2_coefs = new int[3]{ 1,1,1 };
	auto p1 = new polynominal(5, p1_coefs);
	auto p2 = new polynominal(3, p2_coefs);
	EXPECT_EQ(p2->multiply(*p1), 2);
	int* temp = new int[5]{ 1,1,1,0,0 };
	for (int i = 0; i < 5; i++)
		EXPECT_EQ(p2->coeffs[i], temp[i]);
}
TEST(minus_operator, standart) {
	auto* p1 = new polynominal(5, new int[5]{ 1,1,1,0,0 });
	auto* p2 = new polynominal(5, new int[5]{ 1,1,0,1,0 });
	int* temp = new int[3]{ 1,1,0 };
	auto a = *p1 - *p2;
	EXPECT_EQ(a.degree, 3);
	for (int i = 0; i < 3; i++)
		EXPECT_EQ(a.coeffs[i], temp[i]);
}
TEST(polynominal_divide, standart) {
	try {
		const auto p1 = new polynominal(15, new int[15]{1,1,1,0,0,0,0,1,0,1,0,0,0,0,0});
		const auto p2 = new polynominal(6, new int[6]{1,1,0,1,0,1});
		int* temp = new int[5]{ 1,0,1,0,1 };
		auto a = polynominaldivide(*p1, *p2);
		EXPECT_EQ(a.degree, 5);
		for (int i = 0; i < 5; i++)
			EXPECT_EQ(a.coeffs[i], temp[i]);
	}
	catch (const exception& e) {
		std::cout << e.message;
	}

}
