#include "shell.h"
/**
 * builtinOrNo - that function check isbuilt or no
 * @line: line
 * @prog: program name
 * @count: count
 * @ml: *delim
 * @status: status
 * Return: 0 or -1 or other
 */
int builtinOrNo(char *line, char *prog, int count, char *ml,  int *status)
{
int flag = 1, i;
char *copied;
char *built_cmd[] = {"exit", "env", "echo"};
copied = strtok(strdup(line), " ");
for (i = 0; i < 2 ; i++)
{
if (str_compare(copied, built_cmd[i]) == 0)
{
flag = 0;
free(copied);
break;
}
}
if (i == 0)
{
_exit_(line, prog, count, ml, status);
}
if (i == 1)
{
env_command();
}
if (flag)
{
free(copied);
return (-1);
}
return (i);
}
/**
 * _exit_ - that function retunr intger
 * @line: line
 * @prog: program name
 * @count: count
 * @ml: delim
 * @status: status
 * Return: 1 or 0
 */
int _exit_(char *line, char *prog, int count, char *ml, int *status)
{
int i = 0, key = 0, key_valid = 1;
char *st, *copied;
copied = strtok(strdup(line), " ");
st = strtok(NULL, " ");
if (st == NULL)
{
free(ml);
free(copied);
exit(*status);
}
else
{
if (st[0] == '-')
{
key_valid = 0;
}
while (st[i])
{
if (st[i] < 48 || st[i] > 57)
{
key_valid = 0;
break;
}
i++;
}
if (key_valid == 0)
{
*status = 2;
_error_(count, prog, *status, line);
free(copied);
}
else
{
key = _atoi(st);
free(line);
free(copied);
exit(key);
}
}
return (key);
}
/**
 * cmdAfter - that func return string
 * @line: line
 * Return: string
 */
char **cmdAfter(char *line)
{
int i = 0;
char **argvArr;
char *id;
id = strtok(line, DEL);
argvArr = malloc(sizeof(char *) * (str_length(line) + 1));
if (argvArr == NULL)
{
perror("malloc");
}
while (id)
{
if (id[0] == '#')
{
break;
}
argvArr[i] = id;
id = strtok(NULL, DEL);
i++;
}
argvArr[i] = NULL;
return (argvArr);
}
/**
 * excute - that exc in case one
 * @cmd: command
 * @argv: array of commend
 * @environment: environment
 * @status: status
 * Return: intger to check
 */
int excute(char *cmd, char **argv, char *environment[], int *status)
{
pid_t pid;
int e;
pid = fork();
if (pid ==  -1)
{
perror("ERROR IN PROCCESS ID");
}
if (pid == 0)
{
e = execve(cmd, argv, environment);
e == -1 ? exit(126) : exit(EXIT_FAILURE);
}
else
{
waitpid(pid, status, WUNTRACED);
*status = WEXITSTATUS(*status);
}
free(argv);
return (0);
}
/**
 * excute_sec_case - that fun excute in case two
 * @cmd: commend
 * @argv: array of commen
 * @environment: environment
 * @status: status
 * Return: void
 */
void excute_sec_case(char *cmd, char **argv, char *environment[], int *status)
{
int e;
pid_t pid;
pid = fork();
if (pid == -1)
{
perror("FORK ERROR");
}
if (pid == 0)
{
e = execve(cmd, argv, environment);
if (e == -1)
{
exit(127);
}
exit(EXIT_FAILURE);
}
else
{
waitpid(pid, status, WUNTRACED);
*status = WEXITSTATUS(*status);
}
}
