#include<stdio.h>

int empty;
int full = 0;
int mutex = 1;
int data = 0;

int wait(int s) {
    return --s;
}

int signal(int s) {
    return ++s;
}

int producer() {
    mutex = wait(mutex);
    empty = wait(empty);
    full = signal(full);
    data++;
    printf("\nPRODUCER PRODUCES ITEM: %d\n", data);
    mutex = signal(mutex);
}

int consumer() {
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("CONSUMER CONSUMES ITEM: %d\n", data);
    data--;
    mutex = signal(mutex);
}

int main() {
    int bufferSize, choice, i;

    printf("ENTER THE BUFFER SIZE: ");
    scanf("%d", &empty);

    for (i = 1; i > 0; i++) {
        printf("\n1. 1 FOR PRODUCER\n2. 2 FOR CONSUMER\n3. 3 TO EXIT\nENTER YOUR CHOICE: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if ((mutex == 1) && (empty != 0)) {
                    producer();
                } else {
                    printf("BUFFER IS FULL\n");
                }
                break;
            case 2:
                if ((mutex == 1) && (full != 0)) {
                    consumer();
                } else {
                    printf("BUFFER IS EMPTY\n");
                }
                break;
            case 3:
                printf("EXITING PROGRAM\n");
                return 0;
            default:
                printf("INVALID CHOICE\n");
        }
    }

    return 0;
}
