#include <stdio.h>
#include <string.h>

#define MAX 50

// ---------- STRUCTURES ----------
typedef struct {
    int id;
    char name[50];
} Course;

typedef struct {
    int id;
    char name[50];
    int courseId;
    char grade;
} Student;

// ---------- GLOBAL DATA ----------
Course courses[MAX];
Student students[MAX];
int courseCount = 0, studentCount = 0;

// ---------- FUNCTIONS ----------
void addCourse() {
    Course c;
    printf("Enter Course ID: ");
    scanf("%d", &c.id);
    printf("Enter Course Name: ");
    getchar();
    fgets(c.name, 50, stdin);
    c.name[strcspn(c.name, "\n")] = 0;

    courses[courseCount++] = c;
    printf("Course Added.\n");
}

void viewCourses() {
    printf("\n--- Courses ---\n");
    for (int i = 0; i < courseCount; i++)
        printf("%d - %s\n", courses[i].id, courses[i].name);
}

void enrollStudent() {
    Student s;
    printf("Enter Student ID: ");
    scanf("%d", &s.id);
    printf("Enter Student Name: ");
    getchar();
    fgets(s.name, 50, stdin);
    s.name[strcspn(s.name, "\n")] = 0;

    printf("Enter Course ID to Enroll: ");
    scanf("%d", &s.courseId);

    s.grade = '-';  // No grade yet
    students[studentCount++] = s;

    printf("Student Enrolled.\n");
}

void viewSchedule() {
    int sid;
    printf("Enter Student ID: ");
    scanf("%d", &sid);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == sid) {
            printf("\nStudent: %s\nCourse ID: %d\nGrade: %c\n",
                   students[i].name, students[i].courseId, students[i].grade);
            return;
        }
    }
    printf("Student not found.\n");
}

void giveGrade() {
    int sid;
    char g;
    printf("Enter Student ID: ");
    scanf("%d", &sid);
    printf("Enter Grade: ");
    scanf(" %c", &g);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == sid) {
            students[i].grade = g;
            printf("Grade Updated.\n");
            return;
        }
    }
    printf("Student not found.\n");
}

// ---------- MAIN MENU ----------
int main() {
    int choice;

    while (1) {
        printf("\n--- COURSE REGISTRATION SYSTEM ---\n");
        printf("1. Add Course (Admin)\n");
        printf("2. View Courses\n");
        printf("3. Enroll Student\n");
        printf("4. View Student Schedule\n");
        printf("5. Give Grade (Faculty)\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addCourse(); break;
            case 2: viewCourses(); break;
            case 3: enrollStudent(); break;
            case 4: viewSchedule(); break;
            case 5: giveGrade(); break;
            case 6: return 0;
            default: printf("Invalid option!\n");
        }
    }
}