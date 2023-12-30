#include <iostream>

using namespace std;

class Complex
{
    public:
        int *real;
	int *imag;
    public:
        Complex()
	{
            cout << "constructor\n";
	    this->real = 0;
	    this->imag = 0;
	}
	~Complex()
	{
            cout << "destructor\n";
	}
	Complex(Complex &ref)
	{
            cout << "copy constructor\n";
	}
	Complex operator+(const Complex &ref)
	{
            Complex res;
            cout << "assignment overloaded\n";
            cout << "real=" << real << ", imag=" << imag << ", ref.real=" << ref.real << ", ref.imag=" << ref.imag << endl;
	    res.real = this->real + ref.real;
	    res.imag = this->imag + ref.imag;
	    return res;
	}
	void print ()
	{
            cout << "real=" << this->real << ", imag=" << this->imag << endl;
	}
};

class sub_Complex : public Complex
{
};

int main(int argc, char **argv)
{
    Complex a1;
    Complex a2;
    Complex a3;

    a1.real = 10;
    a1.imag = 20;

    a2.real = 30;
    a2.imag = 40;

    a3 = a1+a2;
    a3.print();

    return 0;
}
