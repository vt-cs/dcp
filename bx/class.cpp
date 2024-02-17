
/*
 * class:
 *   char*
 *   constru
 */

class myclass
{
    private:
	    char *buffer;
	    int size;
    public:
        myclass();
	myclass(char *value);
	myclass (const myclass &obj);

	virtual void display ()
	{
            std::cout << "base class" << std::endl;
	}

	int add_num (int n1, int n2);
	void add_num (int n1, int n2);
};


class derived : public myclass
{
	public:
	    void display ()
	    {
                std::cout << "derived" << std::endl;
	    }	    
};

int main ()
{
    myclass *obj = new derived();
    obj->display();

    delete obj;
}

