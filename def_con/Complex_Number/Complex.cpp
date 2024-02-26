#include <iostream>

/*
 * A Complex Number has two parts:
 *     real part
 *     imaginary part
 *
 */

class Complex
{
    private:
        int real;
	int imag;
    public:
	Complex ();
	Complex (int, int);
	Complex (const Complex&);
	void operator= (const Complex&);
};

Complex::Complex () : real(0), imag(0)
{
    std::cout << "default constructor\n";
}

Complex::Complex (int r, int i): real(i), imag(i)
{
    std::cout << "parameterized constructor\n";
}

Complex::Complex (const Complex &c_obj)
{
    std::cout << "copy constructor\n";
    real = c_obj.real;
    imag = c_obj.imag;
}

void Complex::operator= (const Complex &c_obj)
{
    std::cout << "assignment operator overloaded\n";
    if (this == &c_obj)
    {
        std::cout << "self assignment detected\n";
    }
    else
    {
        real = c_obj.real;
        imag = c_obj.imag;
    }
}

int main (int argc, char **argv)
{
    Complex a1;
    Complex a2(2,3);
    Complex a3(a2);
    Complex a4;
    a4 = a3;
    a4 = a4;
    return 0;
}
