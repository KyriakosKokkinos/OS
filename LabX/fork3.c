#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

// Handler για το σήμα
void signal_handler(int sig) {
    printf("Child process received signal: %d\n", sig);
    exit(0); // Τερματίζει το child process
}

int main() {
    pid_t pid = fork(); // Δημιουργία child process

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process
        printf("Child process started. PID: %d\n", getpid());

        // Ορισμός handler για το σήμα
        signal(SIGUSR1, signal_handler);

        // Περιμένει σήμα από τον γονέα
        pause();
    } else {
        // Parent process
        printf("Parent process sending signal to child. PID: %d\n", pid);

        sleep(1); // Μικρή καθυστέρηση για να εξασφαλιστεί ότι το child είναι έτοιμο
        kill(pid, SIGUSR1); // Στέλνει το σήμα SIGUSR1 στο child process

        wait(NULL); // Περιμένει το child process να ολοκληρωθεί
        printf("Parent process finished.\n");
    }

    return 0;
}
