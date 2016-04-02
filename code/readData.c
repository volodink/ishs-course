#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <signal.h>
#include <zconf.h>

static const char *PORT_NAME = "/dev/ttyACM0";

FILE *f = NULL;

void signal_callback_handler(int signum);
int main() {

    uint8_t buffer;

    signal(SIGINT, signal_callback_handler);

    f = fopen(PORT_NAME, "r");
    if (f == NULL)
    {
        printf("Error\n");
        exit(1);
    }

    /* eat all until 1013)) */
    while (1) {
        fread(&buffer, 1, 1, f);
        if (buffer == '\n') break;
    }
    while (1)
    {
        fread(&buffer, 1, 1, f);
        if (buffer == '\n') putchar('\n');
         else putchar(buffer);
    }

    return 0;
}

void signal_callback_handler(int signum) {
    printf("Caught SIGTERM\n");
    fclose(f);
    exit(signum);
}
