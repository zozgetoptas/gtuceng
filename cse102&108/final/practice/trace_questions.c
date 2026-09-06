void f(int *z, int a)
{
    *z = 4;
    z = &a;
    *z = 5;
}

int main()
{
    int *z;
    int a = 2;
    z = &a;
    f(z, 3);
    f(z, *z = 3);
    f(&a, a);
}