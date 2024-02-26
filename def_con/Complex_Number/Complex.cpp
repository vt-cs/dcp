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
	Complex operator+ (const Complex&);

	void print ();
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

Complex Complex::operator+ (const Complex &c_obj)
{
    std::cout << "+ operator overloading\n";
    Complex temp;
    temp.real = real+c_obj.real;
    temp.imag = imag+c_obj.imag;

    return temp;
}

void Complex::print ()
{
    std::cout << "real: " << real << ", imag: " << imag << std::endl;
}

int main (int argc, char **argv)
{
    Complex a1;
    Complex a2(2,3);
    Complex a3(a2);
    Complex a4;
    a4 = a3;
    a4 = a4;
    Complex a5 = a3+a4;
    a5 = a5;
    std::cout << "\na1::\n";
    a1.print ();
    std::cout << "\na2::\n";
    a2.print ();
    std::cout << "\na3::\n";
    a3.print ();
    std::cout << "\na4::\n";
    a4.print ();
    std::cout << "\na5::\n";
    a5.print ();
    return 0;
}
