#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	
	repeat:
	while(1) /* infinite loop of "$ " */ {
		printf("%% ");
		fflush(stdout); /* clear out buffer */
		read = getline(&line, &len, stdin); /* read input from user */

		/* type 'exit' and [ENTER] to exit */
		if (strcmp(line, "exit\n") == 0) {
			exit(EXIT_SUCCESS);
		} else if (strcmp(line, "\n") == 0) {
			goto repeat; /* loop back the file */
		} else {
			printf("simpleshell: command not found: %s", line);
		}
	}
}
