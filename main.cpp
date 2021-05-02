
#include <iostream>
#include "my_lab.h"

int main()
{
    int max_degree_p1 = 0, max_degree_p2 = 0;
    std::cout << "enter first polynomial max degree ";
    std::cin >> max_degree_p1;
    int* p1_koef = new int[max_degree_p1];
    for (int i = 0; i < max_degree_p1; i++) {
        std::cout << "enter "<< max_degree_p1 - i << " degree of first polynominal ";
        std::cin >> p1_koef[i];
    }
    std::cout << "enter first polynomial max degree ";
    std::cin >> max_degree_p2;
    int* p2_koef = new int[max_degree_p2];
    for (int i = 0; i < max_degree_p2; i++) {
        std::cout << "enter " << max_degree_p2 - i << " degree of first polynominal ";
        std::cin >> p2_koef[i];
    }
    std::cout << "remainder from the division: ";
    const polynominal p1(max_degree_p1, p1_koef), p2(max_degree_p2, p2_koef);
    delete[] p1_koef;
    delete[] p2_koef;
    try {
        polynominaldivide(p1, p2);
    }
    catch (const exception& a) {
        std::cout << a.message << "\n";
    }
    

   
}
