#include <stdio.h>

// Συνάρτηση add() που παίρνει 3 ακέραιους και επιστρέφει το άθροισμά τους
int add(int a, int b, int c) {
    return a + b + c;
}

int main() {
    int x, y, z, sum;

    // Είσοδος τιμών από τον χρήστη
    printf("Enter three integers:\n");
    printf("First integer: ");
    scanf("%d", &x);
    printf("Second integer: ");
    scanf("%d", &y);
    printf("Third integer: ");
    scanf("%d", &z);

    // Κλήση της συνάρτησης add() και αποθήκευση του αποτελέσματος
    sum = add(x, y, z);

    // Εμφάνιση του αποτελέσματος
    printf("The sum of %d, %d, and %d is: %d\n", x, y, z, sum);

    return 0;
}
