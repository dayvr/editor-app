#include <stdio.h>

// Create a program that implements a simple text editor.
// The editor should have the following features:
// - The user can type in commands to manipulate the text.
// STEP 1: Start the program execution.
// STEP 2: List the menu.
// STEP 3: Get the choice.
// STEP 4: If choice is 1, create a new file.
// STEP 5: If choice is 2, view the required file.
//STEP 6: If choice is 3, get the file name to be edited, enter the new text.
// STEP 7: If choice is 4, delete the file.
// STEP 8: If choice is 5, exit.
// STEP 9: Stop the program execution.

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