#include "shell.h"
/**
 * print_num - that covert int(number) to str
 * @n: number that will covert
 * Return: str after covert
 */
char *print_num(int n)
{
unsigned int d;
unsigned int c;
char *output;
int len;
int i;
len = 0;
i = 0;
while (d > 9)
{
d = d / 10;
c = c * 10;
len++;
}
len++;
output = (char *)malloc(len + 1);
if (!output)
{
return (NULL);
}
while (c > 0)
{
output[i] = ((n / c) % 10) + '0';
i++;
c = c / 10;
}
output[len] = '\0';
return (output);
}
/**
 * _atoi - that func covert str to intger
 * @str: string will coverted
 * Return: intger
 */
int _atoi(char *str)
{
int i;
int result;
result = 0;
i = 0;
while (str[i])
{
if (str[i] >= 48 && str[i] <= 57)
{
result = result * 10 + str[i] - '0';
}
else
{
return (-1);
}
i++;
}
return (result);
}
