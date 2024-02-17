
5 = 000000101 op =2
8 = 1000 op =1
7 = 0111 op =3

32
5 = 0101

int main ()
{
    int num;
    std::cin >> num;

    int cnt_set = 0;
    for (int i=0; i<sizeof(int)*8; ++i)
    {
        if (num&1)
	{
            ++cnt_set;
	}
	num = num>>1;
    }
    std::cout << cnt_set;
}
