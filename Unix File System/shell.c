#include "fs.h"
#include <stdio.h>
#include <string.h>

void shell_ls(void) {
    // Print all files in current directory
    printf("Listing directory content...\n");
}

int main() {
    fs_init();
    char cmd[128];
    while (1) {
        printf("fs> ");
        fgets(cmd, sizeof(cmd), stdin);
        cmd[strcspn(cmd, "\n")] = 0; // Remove newline

        if (strcmp(cmd, "ls") == 0) {
            shell_ls();
        } else if (strcmp(cmd, "exit") == 0) {
            break;
        } else {
            printf("Unknown command\n");
        }
    }
    return 0;
}
