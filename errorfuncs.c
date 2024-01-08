#include "shell.h"
/**
 * _error_ - that funcation print error
 * @count: count
 * @prog: program name
 * @status: status
 * @line: line
 * Return: void
 */
void _error_(int count, char *prog, int status, char *line)
{
if (status ==  126)
{
	errorPath(line, print_num(count), prog);
}
if (status == 127)
{
	errorcmd(line, print_num(count), prog);
}
if (strncmp(line, "exit", 4) == 0 && status == 2)
{
errorExit(line, print_num(count), prog);
}
}
/**
 * errorPath - that funcation prints the error path
 * @line: line
 * @c: c
 * @prog: programName
 * Return: void
 */
void errorPath(char *line, char *c, char *prog)
{
write(STDERR_FILENO, prog, str_length(prog));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, c, str_length(c));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, line, str_length(line));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, "Permission denied\n", sizeof("permission denied\n") - 1);
}
/**
 * errorcmd - that func prints the error
 * @line: line
 * @c: c
 * @prog: prog
 * Return: void
 */
void errorcmd(char *line, char *c, char *prog)
{
write(STDERR_FILENO, prog, str_length(prog));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, c, str_length(c));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, line, str_length(line));
write(STDERR_FILENO, ": not found\n", sizeof(": notfound\n") - 1);
}
/**
 * errorExit - that func prints the error Exit
 * @line: line
 * @c: c
 * @prog: prog
 * Return: void
 */
void errorExit(char *line, char *c, char *prog)
{
char *token;
strtok(line, DEL);
write(STDERR_FILENO, prog, str_length(prog));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, c, str_length(c));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, line, str_length(line));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, "Illegal number", sizeof("Illegal number:") - 1);
write(STDERR_FILENO, ": ", 2);
token = strtok(NULL, DEL);
write(STDERR_FILENO, token, strlen(token));
write(STDERR_FILENO, "\n", 1);
}
