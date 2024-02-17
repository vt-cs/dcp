#include <iostream>

int abc::is_instantiated = 0;

int func ()
{
    std::cout << "func" << std::endl;
    std::cout << is_instantiated << std::endl;
    return 0;
}

class abc
{
    private:
        static int is_instantiated;
    private:
	abc();
	~abc();
    friend int func();
};

abc::abc()
{

}

int main ()
{
    abc *obj;
    obj.func();
}
