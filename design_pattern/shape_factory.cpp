#include <iostream>

/*
 * shape:
 *     draw();
 */

class shape
{
    public:
        virtual void draw () = 0;
};

class circle : public shape
{
    public:
        void draw ()
	{
            std::cout << "circle draw" << std::endl;
	}
};

class square : public shape
{
    public:
        void draw ()
	{
            std::cout << "square draw" << std::endl;
	}
};

class triangle : public shape
{
    public:
        void draw ()
	{
            std::cout << "triangle draw" << std::endl;
	}
};

class shape_factory
{
    public:
        static shape* create_shape (std::string shape_name);
};

shape* shape_factory::create_shape (std::string shape_name)
{
    if (shape_name == "circle")
    {
        return new circle ();
    }
    else if (shape_name == "square")
    {
        return new square ();
    }
    else if (shape_name == "triangle")
    {
        return new triangle ();
    }
    else
    {
        return nullptr;
    }
}



void client_code (std::string shape_name)
{
    shape *shape_obj_ptr = shape_factory::create_shape (shape_name);
    if (shape_obj_ptr != nullptr)
    {
        shape_obj_ptr->draw ();
	delete shape_obj_ptr;
	shape_obj_ptr = nullptr;
    }
    else
    {
        std::cout << "shape unknown:: " << shape_name << std::endl;
    }
    return;
}

int main (int argc, char **argv)
{
    client_code ("circle");
    client_code ("square");
    client_code ("triangle");
    client_code ("unknown");
    return 0;
}
