#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main() {
	pid_t pid =  fork();

	if (pid < 0) {
		perror("Error al crear el proceso hijo");
		exit(1);
	} else if (pid == 0) {
		for (int i = 0; i < 10; i++) {
			printf("Soy el hijo\n");
			sleep(1);
		}
		exit(0);
	} else {

		for (int i = 0; i < 10; i++) {
			printf("Soy el padre\n");
			sleep(1);
		}

		wait(NULL);
		printf("Mi proceso hijo ya ha terminado\n");

	}

	return 0;

}
