#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>  /* for fork(), execvp() */
#include <sys/wait.h>  /* for wait() */

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
			tokens[count] = NULL;  /* execvp requires NULL-terminated array */
		

			/* built-in pwd */ 	
			if (strcmp(tokens[0], "pwd") == 0) {
				char cwd[1024];
				if (getcwd(cwd, sizeof(cwd)) != NULL)
					printf("[simpleshell]%s\n", cwd);
				else
					perror("getcwd() error pls check");
				continue; // skip execvp
			}

			pid_t pid = fork();  /* create child process */
			if (pid == 0) {
				/* Child process: execute the command */
				execvp(tokens[0], tokens);
				/* If execvp returns, there was an error */
				printf("Command not found\n");
				exit(EXIT_FAILURE);
			} else {
				/* Parent process: wait for child to finish */
				wait(NULL);
			}
		}
		}
}
