#include <stdio.h>

// Program that implements a simple text editor.

int main() {
    printf("1. Create a new file\n");
    printf("2. View the required file\n");
    printf("3. Edit the required file\n");
    printf("4. Delete the file\n");
    printf("5. Exit\n");

    int choice;
    char file_name[100];
    FILE *fp;

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the file name: ");
            scanf("%s", file_name);
            fp = fopen(file_name, "w");
            if (fp == NULL) {
                printf("File not found\n");
            } else {
                printf("File created\n");
                fclose(fp);
            }
            break;
        case 2:
            printf("Enter the file name: ");
            scanf("%s", file_name);
            fp = fopen(file_name, "r");
            if (fp == NULL) {
                printf("File not found\n");
            } else {
                printf("File found\n");
                char ch;
                while ((ch = fgetc(fp)) != EOF) {
                    printf("%c", ch);
                }
                fclose(fp);
            }
            break;
        case 3:
            printf("Enter the file name: ");
            scanf("%s", file_name);
            fp = fopen(file_name, "w");
            if (fp == NULL) {
                printf("File not found\n");
            } else {
                printf("File found\n");
                printf("Enter the new text: ");
                char text[100];
                scanf("%s", text);
                fprintf(fp, "%s", text);
                fclose(fp);
            }
            break;
        case 4:
            printf("Enter the file name: ");
            scanf("%s", file_name);
            fp = fopen(file_name, "r");
            if (fp == NULL) {
                printf("File not found\n");
            } else {
                printf("File found\n");
                fclose(fp);
                remove(file_name);
                printf("File deleted\n");
            }
            break;

    return 0;
}

}
