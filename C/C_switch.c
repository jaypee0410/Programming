#include <stdio.h>
	
int main() {
    int grade;
    printf("Enter student's numeric grade: ");
    scanf("%d", &grade);

    // Use a switch statement to convert numeric grade to letter grade
    switch (grade / 10) {
        case 10:
        case 9:
            printf("Student grade: A\n");
            break;
        case 8:
            printf("Student grade: B\n");
            break;
        case 7:
            printf("Student grade: C\n");
            break;
        case 6:
            printf("Student grade: D\n");
            break;
        default:
            printf("Student grade: F (failed)\n");
            break;
    }

    return 0;
}

	
