#include<stdio.h>

#define n 4

int completedPhilo = 0, i;

// Arrays to represent the status of forks and philosophers
int ForkAvil[n], PhiloStatusLeft[n], PhiloStatusRight[n];

void goForDinner(int philID) {
    int leftFork = philID;
    int rightFork = (philID + 1) % n;

    // Check if both forks are available
    if (ForkAvil[leftFork] == 0 && ForkAvil[rightFork] == 0) {
        printf("Philosopher %d completed his dinner\n", philID + 1);
        PhiloStatusLeft[philID] = PhiloStatusRight[philID] = 10;
        ForkAvil[leftFork] = ForkAvil[rightFork] = 0;
        printf("Philosopher %d released fork %d and fork %d\n", philID + 1, leftFork + 1, rightFork + 1);
        completedPhilo++;
    } else {
        // Philosophers take one fork
        if (ForkAvil[leftFork] == 0) {
            ForkAvil[leftFork] = PhiloStatusLeft[philID] = 1;
            printf("Fork %d taken by philosopher %d\n", leftFork + 1, philID + 1);
        } else if (ForkAvil[rightFork] == 0) {
            ForkAvil[rightFork] = PhiloStatusRight[philID] = 1;
            printf("Fork %d taken by philosopher %d\n", rightFork + 1, philID + 1);
        } else {
            printf("Philosopher %d is waiting for fork %d\n", philID + 1, leftFork + 1);
            printf("Philosopher %d is waiting for fork %d\n", philID + 1, rightFork + 1);
        }
    }
}

int main() {
    for (i = 0; i < n; i++) {
        ForkAvil[i] = PhiloStatusLeft[i] = PhiloStatusRight[i] = 0;
    }

    while (completedPhilo < n) {
        for (i = 0; i < n; i++) {
            goForDinner(i);
        }
        printf("\nTill now num of philosophers completed dinner are %d\n\n", completedPhilo);
    }

    return 0;
}
