class Test {
public:
    void* operator new(size_t size);
    void operator delete(void*);
    Test() { cout<<"\n Constructor called"; }
    ~Test() { cout<<"\n Destructor called"; }
};
 
void* Test::operator new(size_t size)
{
    cout<<"\n new called";
    void *storage = malloc(size);
    return storage;
}
 
void Test::operator delete(void *p )
{
    cout<<"\n delete called";
    free(p);
}
 
int main()
{
    Test *m = new Test();
    delete m;
    return 0;
}
