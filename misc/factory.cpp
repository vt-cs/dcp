#include <iostream>

class shape
{
    public:
        virtual void draw () = 0;
};

class circle : public shape
{
    public:
        void draw ();
};

class square : public shape
{
    public:
        void draw ();
};


void circle::draw ()
{
    std::cout << "circle draw" << std::endl;
}

void square::draw ()
{
    std::cout << "square draw" << std::endl;
}

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
    else
    {
        return nullptr;
    }
}

// new client code
int new_client_code ()
{
    shape *random_shape = nullptr;
    std::string ip_shape;
    std::cin >> ip_shape;

    random_shape = shape_factory::create_shape(ip_shape);
    if (random_shape != nullptr)
    {
        random_shape->draw();
    }
    return 0;
}


// client code
int client_code ()
{
    shape *random_shape = nullptr;
    std::string ip_shape;
    std::cin >> ip_shape;
    if (ip_shape == "circle")
    {
        random_shape = new circle();
    }
    else if (ip_shape == "square")
    {
        random_shape = new square();
    }
    if (random_shape != nullptr)
    {
        random_shape->draw();
    }
    return 0;
}


int main (int argc, char **argv)
{
    new_client_code();
    return 0;
}
