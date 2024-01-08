#include "shell.h"
/**
 * main - that function check inter or non
 * @argc: argc
 * @argv: argv
 * Return: 0 or 1;
 */
int main(__attribute__((unused))int argc, char **argv)
{
int mode;
mode = isatty(STDIN_FILENO);
mode == 0 ? non_inter(argv) : inter(argv);
return (0);
}
/**
 * non_inter - when non interactive mode
 * @argv: argv
 * Return: void
 */
void non_inter(char **argv)
{
int times = 0, check, status = 0;
ssize_t  r_line;
size_t length = 0;
char **cmdAft = {NULL};
char *commnd, *line = NULL, *line_handled;
char *environ[] = {NULL};
while (1)
{
times++;
r_line = getline(&line, &length, stdin);
if (r_line == -1)
{
break;
}
line_handled = handle_line(line);
commnd = excable(line_handled);
if (str_compare(line_handled, "\n") == 0 || line_handled[0] == '#')
	continue;
else if (builtinOrNo(line_handled, argv[0], times, line, &status) != -1)
{
free(commnd);
continue;
}
else if (commnd)
{
cmdAft = cmdAfter(line_handled);
check = excute(commnd, cmdAft, environ, &status);
if (check == 0)
{
_error_(times, argv[0], status, line_handled);
}
}
else if (commnd == NULL)
{
excute_sec_case(line_handled, cmdAft, environ, &status);
_error_(times, argv[0], status, line_handled);
}
free(commnd);
}
free(line);
}
/**
 * inter - that when interactive mode
 * @argv: argv
 * Return: void
 */
void inter(char **argv)
{
int times = 0, check, status = 0;
ssize_t  r_line;
size_t length = 0;
char **cmdAft = {NULL}, *environ[] = {NULL};
char *commnd, *line = NULL, *line_handled;
while (1)
{
times++;
write(STDOUT_FILENO, "$ ", 2);
r_line = getline(&line, &length, stdin);
if (r_line == -1)
{
write(STDOUT_FILENO, "\n", 1);
break;
}
line_handled = handle_line(line);
commnd = excable(line_handled);
if (str_compare(line_handled, "\n") == 0 || line_handled[0] == '#')
	continue;
else if (builtinOrNo(line_handled, argv[0], times, line, &status) != -1)
{
free(commnd);
continue;
}
else if (commnd)
{
cmdAft = cmdAfter(line_handled);
check = excute(commnd, cmdAft, environ, &status);
if (check == 0)
	_error_(times, argv[0], status, line_handled);
}
else if (commnd == NULL)
{
excute_sec_case(line_handled, cmdAft, environ, &status);
_error_(times, argv[0], status, line_handled);
}
free(commnd);
}
free(line);
}
/**
 * handle_line - that handle line from start spaces oth..
 * @line: line from user
 * Return: new
 */
char *handle_line(char *line)
{
int i = 0;
ssize_t len;
while (line[i])
{
if (line[i] != ' ')
{
line += i;
break;
}
i++;
}
len = str_length(line);
if (line[0] == '\n' && len == 1)
{
return (line);
}
if (line[len - 1] == '\n')
{
line[len - 1] = '\0';
}
return (line);
}
/**
 * excable - that can excute or no
 * @l: line
 * Return: string
 */
char *excable(char *l)
{
char *p;
char *buff;
char *token;
char *p_copied;
int len_cmd;
p = _str_dup(_get_env("PATH"));
p_copied = _str_dup(l);
strtok(p_copied, DEL);
if (access(p_copied, F_OK) == 0)
{
if (p_copied[0] == '/' || p_copied[1] == '/' || p_copied[2] == '/')
{
free(p);
return (p_copied);
}
}
len_cmd = str_length(p_copied);
token = strtok(p, ":");
while (token)
{
buff = malloc(len_cmd + str_length(token) + 2);
_str_copy(buff, token);
_str_concat(buff, "/");
_str_concat(buff, p_copied);
if (access(buff, F_OK) == 0)
{
free(p_copied);
free(p);
return (buff);
}
free(buff);
token = strtok(NULL, ":");
if (token == NULL)
{
free(p_copied);
free(p);
}
}
return (NULL);
}
