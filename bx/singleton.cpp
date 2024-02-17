
single* single::instance = nullptr;
int single::instance_cnt = 0;

myclass single
{
	private:
             static single *instance;
	     static int instance_cnt;
	     static single* get_instance();
             single();
	     single(const single &obj);
	     single operator=(const single &obj);
};

i=0
cout << i++;

a = -8
b = 3

c1 = --a + b;

a = -9, b = 3
c1 = -9+3

c1 = -6


c2 = a-- + b;
c2 = -9 + 3

c2 = -6

a = -10
b = 3

for (int i=0; i<10; i++)
{

}

for (int i=0; i<10; ++i)
{

}

single::single()
{
    std::cout << "constructor" << std::endl;
    ++instance_cnt;
}

single* single::get_instance()
{
     if (instance == nullptr)
     {
     
     }
     else
     {
         return instance;
     }
}


