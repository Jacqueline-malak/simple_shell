#include "shell.h"
/**
 * env_command - print command to excute after that
 * Return: void
 */
void env_command(void)
{
int i;
char **en = environ;
i = 0;
while (en[i])
{
write(1, en[i], str_length(en[i]));
write(1, "\n", 1);
i++;
}
}
/**
 * _get_env - that func get env by simple explaintion
 * @name: string
 * Return: variable value of env
 */
char *_get_env(char *name)
{
int i;
char *res;
char **env;
i = 0;
if (!name || !name[0])
{
return (NULL);
}
env = environ;
while (env[i])
{
if (strncmp(env[i], name, (int)str_length(name)) == 0
&& env[i][str_length(name)] == '=')
{
res = env[i] + str_length(name) + 1;
return (res);
}
i++;
}
return (NULL);
}
