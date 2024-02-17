#include <iostream>

/*
 *
 *Implement a C++ program with a base class "Shape"
  and two derived classes "Circle" and "Rectangle."
  Each class should have a method to calculate its area.
 */

class shape
{
    virtual int area();
};

class circle : shape
{
    private:
	    int radius;
    public:
	    circle(int r)
	    {
                radius = r;
	    }

	    int area()
	    {
                return 3.14*radius*radius;
	    }
}

class rectangle : shape
{
    private:
	    int length;
	    int width;
    public:
	    rectangle (int l, int w)
	    {
                length = l;
		width = w;
	    }
	    
	    int area()
	    { 
                return length*width;
	    }
}


int main ()
{
	shape *ptr = nullptr;

	ptr = new circle(10);
	std::cout << "circle area = " << ptr->area() << std::endl;
	delete ptr;
	ptr = nullptr;

	ptr = new rectangle(2,3);
	std::cout << "rectangle area = " << ptr->area() << std::endl;

	delete ptr;
	ptr = nullptr;

}
