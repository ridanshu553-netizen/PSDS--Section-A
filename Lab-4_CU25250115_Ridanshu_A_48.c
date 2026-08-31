// -- CREATE DATABASE CollegeDB;

// -- USE CollegeDB;

// -- CREATE TABLE Student (
// --     student_id INT PRIMARY KEY,
// --     name VARCHAR(50) NOT NULL,
// --     email VARCHAR(100)
// -- );

// -- CREATE TABLE Course (
// --     course_id INT PRIMARY KEY,
// --     course_name VARCHAR(50) NOT NULL
// -- );

// -- CREATE TABLE Enrollment (
// --     enrollment_id INT PRIMARY KEY,
// --     student_id INT,
// --     course_id INT,
// --     FOREIGN KEY (student_id) REFERENCES Student(student_id),
// --     FOREIGN KEY (course_id) REFERENCES Course(course_id)
// -- );

// -- SHOW TABLES;

#include <stdio.h>

struct Student {
    int id;              // Primary Key
    char name[30];
};

struct Course {
    int id;              // Primary Key
    char name[30];
};

struct Enrollment {
    int student_id;     // Foreign Key
    int course_id;      // Foreign Key
};

int main() {
    struct Student s = {101, "Rahul"};
    struct Course c = {201, "DBMS"};
    struct Enrollment e = {101, 201};

    printf("Student Table\n");
    printf("ID: %d  Name: %s\n", s.id, s.name);

    printf("\nCourse Table\n");
    printf("ID: %d  Course: %s\n", c.id, c.name);

    printf("\nEnrollment Table\n");
    printf("Student ID: %d  Course ID: %d\n",
           e.student_id, e.course_id);

    return 0;
}