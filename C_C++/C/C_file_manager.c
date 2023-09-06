#include <stdio.h>
#include <stdlib.h>

void create_file(char *filename) {
    FILE *fp;
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Unable to create file\n");
    } else {
        printf("File created successfully\n");
        fclose(fp);
    }
}

void read_file(char *filename) {
    FILE *fp;
    char ch;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file\n");
    } else {
        printf("File contents:\n");
        while ((ch = fgetc(fp)) != EOF) {
            printf("%c", ch);
        }
        fclose(fp);
    }
}

void update_file(char *filename) {
    FILE *fp;
    char data[100];
    fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error: Unable to open file\n");
    } else {
        printf("Enter data to append to file:\n");
        scanf("%s", data);
        fprintf(fp, "%s", data);
        printf("File updated successfully\n");
        fclose(fp);
    }
}

void delete_file(char *filename) {
    if (remove(filename) == 0) {
        printf("File deleted successfully\n");
    } else {
        printf("Error: Unable to delete file\n");
    }
}

int main() {
    int option;
    char filename[100];

    do {
        // Print the menu options
        printf("\nMenu:\n");
        printf("1. Create file\n");
        printf("2. Read file\n");
        printf("3. Update file\n");
        printf("4. Delete file\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                // Create file
                printf("Enter filename: ");
                scanf("%s", filename);
                create_file(filename);
                break;
            case 2:
                // Read file
                printf("Enter filename: ");
                scanf("%s", filename);
                read_file(filename);
                break;
            case 3:
                // Update file
                printf("Enter filename: ");
                scanf("%s", filename);
                update_file(filename);
                break;
            case 4:
                // Delete file
                printf("Enter filename: ");
                scanf("%s", filename);
                delete_file(filename);
                break;
            case 0:
                // Exit
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option\n");
                break;
        }

    } while (option != 0);

    return 0;
}

