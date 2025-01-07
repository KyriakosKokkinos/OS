#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int pipe_fd[2];
    pid_t pid;

    if (pipe(pipe_fd) == -1) {
        perror("Pipe failed");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {

        close(pipe_fd[1]);

        char buffer[100];
        read(pipe_fd[0], buffer, sizeof(buffer));
        printf("Child process received: %s\n", buffer);

        close(pipe_fd[0]);
        exit(0);

    } else {

        close(pipe_fd[0]);

        char message[] = "Hello from parent!";
        write(pipe_fd[1], message, sizeof(message));
        printf("Parent process sent: %s\n", message);

        close(pipe_fd[1]);
        wait(NULL);
    }

    return 0;
}
