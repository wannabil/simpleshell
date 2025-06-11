#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	
	while(1) /* infinite loop of "$ " */
	{
		printf("$ ");
		fflush(stdout); /* clear out buffer */
		read = getline(&line, &len, stdin); /* read input from user */

		line[strlen(line) - 1] = '\0'; /* clean line to trim newline */
		/* type 'exit' and [ENTER] to exit */
		if (strcmp(line, "exit") == 0)
		{
			exit(EXIT_SUCCESS);
		}
	
		else {
			printf("$simpleshell: command not found: %s\n", line);
		}
	}
}
