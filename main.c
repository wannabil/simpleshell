#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *tokens[10]; /* token placeholder */

	while(1) /* infinite loop of "$ " */ {
		printf("%% ");
		fflush(stdout); /* clear out buffer */
		read = getline(&line, &len, stdin); /* read input from user */
		if (line[strlen(line) - 1] == '\n') {
			line[strlen(line) - 1] = '\0';
		} // remove newline
		if (strcmp(line, "exit") == 0) {
			exit(EXIT_SUCCESS);
		} else if (strcmp(line, "") == 0) {
			continue;
		} else {
			int count = 0;
			char *token = strtok(line, " "); /* first token */
			while (token != NULL) {
				tokens[count] = token;
				count += 1;
				token = strtok(NULL, " "); // going to next token
			}
				printf("command : %s\n", tokens[0]);
				for (int i = 1; i < count; i++)
				{
					printf("arg%d: %s\n", i, tokens[i]);
				}
			}
		}
}
