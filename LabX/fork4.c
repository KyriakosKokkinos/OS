#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    FILE *file;
    pid_t pid;

    // Δημιουργία και άνοιγμα αρχείου για εγγραφή (διαγραφή περιεχομένων)
    file = fopen("pids.txt", "w");
    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    fclose(file);

    // Άνοιγμα αρχείου σε λειτουργία "append" για προσθήκη δεδομένων
    file = fopen("pids.txt", "a");
    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    // Δημιουργία διεργασίας με fork()
    pid = fork();

    if (pid < 0) {
        // Αποτυχία fork
        perror("Fork failed");
        fclose(file);
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Παιδική διεργασία
        printf("Child process PID: %d\n", getpid());
        fprintf(file, "Child process PID: %d\n", getpid());
        fclose(file);
        exit(0);
    } else {
        // Γονική διεργασία
        printf("Parent process PID: %d\n", getpid());
        fprintf(file, "Parent process PID: %d\n", getpid());
        fclose(file);

        // Αναμονή για το παιδί να ολοκληρωθεί
        wait(NULL);
    }

    return 0;
}
