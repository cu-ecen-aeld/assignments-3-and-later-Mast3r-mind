#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <errno.h>
#include <string.h>

void print_usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s <file> <string>\n", prog_name);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *file_path = argv[1];
    const char *string_to_write = argv[2];

    openlog("writer", LOG_PID | LOG_CONS, LOG_USER);

    FILE *file = fopen(file_path, "w");
    if (file == NULL) {
        syslog(LOG_ERR, "Error opening file %s: %s", file_path, strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    if (fprintf(file, "%s", string_to_write) < 0) {
        syslog(LOG_ERR, "Error writing to file %s: %s", file_path, strerror(errno));
        fclose(file);
        exit(EXIT_FAILURE);
    }

    syslog(LOG_DEBUG, "Writing %s to %s", string_to_write, file_path);

    if (fclose(file) != 0) {
        syslog(LOG_ERR, "Error closing file %s: %s", file_path, strerror(errno));
        exit(EXIT_FAILURE);
    }

    closelog();

    printf("File %s created with content:\n%s\n", file_path, string_to_write);

    return 0;
}

