/* #include <stdio.h>
int factorial(int n)
{
    int result = 1;
    while(n >= 1)
    {
        result *= n;
        n--;
    }
    return (result);
}
int main()
{
    int n;
    int arr[5];
    int i = 0;
    while(i < 5)
    {
        printf("enter a number:\n");
        scanf("%d", &n);
        arr[i] = factorial(n);
        i++;
    }
    i = 0;
    while(i < 5)
    {
        printf("number: %d | factorial: %d\n", i + 1, arr[i]);
        i++;
    }
    return (0);
} */
/* #include <stdio.h>
int main()
{
    char str[100];
    printf("enter a string:\n");
    scanf("%s", str);
    int counter = 0;
    int i = 0;
    while(str[i])
    {
        if(str[i] == 'a' || str[i] == 'e' ||
        str[i] == 'i' || str[i] == 'u' ||
        str[i] == 'o' || str[i] == 'A' || str[i] == 'E' ||
        str[i] == 'I' || str[i] == 'U' || str[i] == 'O' )
            counter++;
        i++;
    }
    printf("vowel count: %d\n", counter);
    return(0);
} */