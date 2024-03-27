#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    friend Complex operator+(const Complex &c1, const Complex &c2);

   
    void display() {
        std::cout << real << " + " << imag << "i";
    }
};


Complex operator+(const Complex &c1, const Complex &c2) {
   
    double real_sum = c1.real + c2.real;
    double imag_sum = c1.imag + c2.imag;
    return Complex(real_sum, imag_sum);
}

int main() {
    Complex c1(2.0, 3.0);
    Complex c2(4.0, 1.0);

    Complex sum = c1 + c2; 
    std::cout << "Sum of ";
    c1.display();
    std::cout << " and ";
    c2.display();
    std::cout << " is ";
    sum.display();
    std::cout << std::endl;

    return 0;
}

