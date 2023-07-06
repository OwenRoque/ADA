#include <iostream>
#include <vector>
class CArithmetic
{

public:
    static double Addition (double a, double b) { return a+b; }
    static double Substraction (double a, double b) { return a - b; }
    static double Multiplication (double a, double b) { return a*b; }
    static double Division (double a, double b) {
        if (b == 0) throw std::invalid_argument("2nd argument must be non-zero.");
        return a/b;
    }
// More methods go here
};

int main() {
    typedef double (*op)(double, double);
    // CVector of pointer to functions
    op vpf[4] = {CArithmetic::Addition, CArithmetic::Substraction, CArithmetic::Multiplication, CArithmetic::Division};
    double a, b, c;
    int opt;
    // enter the operands
    std::cin >> a >> b;
    // enter the operation 0-Addition, 1-Subtraction, 3-Multiplication, 4-Division
    std::cin >> opt;
    // The next line replaces the switch and replaces the whole switch
    c = (*vpf[opt])(a, b);
    std::cout << c << std::endl;
    return 0;
}
