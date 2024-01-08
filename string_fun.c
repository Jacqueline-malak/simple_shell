#include "shell.h"
/**
 * str_length - that func return length of text
 * @text: text
 * Return: len
 */
int str_length(char *text)
{
int len;
len = 0;
while (text[len])
{
len++;
}
return (len);
}
/**
 * _str_dup - that function duplication str
 * @str:string used to dupli..
 * Return: duplic in new
 */
char *_str_dup(char *str)
{
int len;
char *new;
int i;
if (!str)
{
return (NULL);
}
len = str_length(str);
new = malloc(len + 1);
if (!new)
{
return (NULL);
}
for (i = 0; i < len; i++)
{
new[i] = str[i];
}
new[len] = '\0';
return (new);
}
/**
 * str_compare - that funcation compares for two strin.
 * @str1: string one
 * @str2: string two
 * Return: 0 or >0 or <0
 */
int str_compare(char *str1, char *str2)
{
int i;
i = 0;
while (str1[i] || str2[i])
{
if (str1[i] != str2[i])
{
return (str1[i] - str2[i]);
}
i++;
}
return (0);
}
/**
 * _str_copy - copy string in sec paste in first
 * @str1: first
 * @str2: second
 * Return: str one after paste
 */
char *_str_copy(char *str1, char *str2)
{
int i;
i = 0;
while (str2[i])
{
str1[i] = str2[i];
i++;
}
str1[i] = '\0';
return (str1);
}
/**
 * _str_concat - that function return str1 after concat with str2
 * @str1: string one
 * @str2: string two
 * Return: str1 after concat
 */
char *_str_concat(char *str1, char *str2)
{
int i;
int j;
i = str_length(str1);
j = 0;
while (str2[j])
{
str1[i] = str2[j];
j++;
i++;
}
str1[i] = '\0';
return (str1);
}
