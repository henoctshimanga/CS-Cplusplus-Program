/* SNHU CS-500 C++ Programming
 * Project Two: Course Management System
 * Name : Henoc T. Mudibu
 */

 #include <iostream>
 #include <fstream>
 #include <sstream>
 #include <vector>
 #include <unordered_map>
 #include <algorithm>
 
 using namespace std;
 
 // Struct to represent a course
 struct Course {
     string courseNumber;
     string courseTitle;
     vector<string> prerequisites;
 };
 
 // Function to split a string by a delimiter (e.g., comma for CSV)
 vector<string> split(const string& line, char delimiter) {
     vector<string> tokens;
     string token;
     istringstream stream(line);
 
     // Read each token separated by the delimiter
     while (getline(stream, token, delimiter)) {
         tokens.push_back(token);
     }
     return tokens;
 }
 
 // Load courses from a file into a hash table
 void loadCourses(const string& filename, unordered_map<string, Course>& courseTable) {
     ifstream file(filename);
     if (!file.is_open()) {
         cout << "ERROR: Could not open file '" << filename << "'." << endl;
         return;
     }
 
     string line;
     while (getline(file, line)) {
         vector<string> tokens = split(line, ',');
 
         // Ensure each line has at least course number and title
         if (tokens.size() < 2) {
             cout << "Warning: Skipping malformed line." << endl;
             continue;
         }
 
         Course course;
         course.courseNumber = tokens[0];
         course.courseTitle = tokens[1];
 
         // Store all additional tokens as prerequisites
         for (size_t i = 2; i < tokens.size(); ++i) {
             course.prerequisites.push_back(tokens[i]);
         }
 
         // Insert the course into the hash table
         courseTable[course.courseNumber] = course;
     }
 
     file.close();
     cout << "Courses loaded successfully." << endl;
 }
 
 // Sort and print all courses alphanumerically
 void printCourseList(const unordered_map<string, Course>& courseTable) {
     if (courseTable.empty()) {
         cout << "No course data loaded. Please load data first." << endl;
         return;
     }
 
     vector<string> courseNumbers;
     // Collect all course numbers into a list
     for (const auto& entry : courseTable) {
         courseNumbers.push_back(entry.first);
     }
 
     // Sort course numbers alphabetically
     sort(courseNumbers.begin(), courseNumbers.end());
 
     // Print courses in sorted order
     for (const string& courseNum : courseNumbers) {
         const Course& course = courseTable.at(courseNum);
         cout << course.courseNumber << ": " << course.courseTitle << endl;
     }
 }
 
 // Display detailed course info including prerequisites
 void printCourseInfo(const unordered_map<string, Course>& courseTable, const string& courseNumber) {
     auto it = courseTable.find(courseNumber);
     if (it == courseTable.end()) {
         cout << "Course not found: " << courseNumber << endl;
         return;
     }
 
     const Course& course = it->second;
     cout << course.courseNumber << ": " << course.courseTitle << endl;
 
     if (course.prerequisites.empty()) {
         cout << "Prerequisites: None" << endl;
     } else {
         cout << "Prerequisites:" << endl;
         // Loop through and print each prerequisite
         for (const string& prereq : course.prerequisites) {
             auto prereqIt = courseTable.find(prereq);
             if (prereqIt != courseTable.end()) {
                 const Course& prereqCourse = prereqIt->second;
                 cout << " - " << prereqCourse.courseNumber << ": " << prereqCourse.courseTitle << endl;
             } else {
                 // Handle missing prerequisite gracefully
                 cout << " - " << prereq << " (Missing course data)" << endl;
             }
         }
     }
 }
 
 // Show main menu to the user
 void showMenu() {
     cout << "\nMenu:" << endl;
     cout << " 1. Load Courses" << endl;
     cout << " 2. Display All Courses" << endl;
     cout << " 3. Find Course" << endl;
     cout << " 9. Exit" << endl;
     cout << "Enter choice: ";
 }
 
 // Main driver function
 int main() {
     unordered_map<string, Course> courseTable;  // Hash table to store courses
     string filename;
     string courseNumber;
     int choice = 0;
 
     while (true) {
         showMenu();
         cin >> choice;
 
         switch (choice) {
             case 1:
                 cout << "Enter filename: ";
                 cin >> filename;
                 loadCourses(filename, courseTable);
                 break;
 
             case 2:
                 printCourseList(courseTable);
                 break;
 
             case 3:
                 cout << "Enter course number: ";
                 cin >> courseNumber;
                 printCourseInfo(courseTable, courseNumber);
                 break;
 
             case 9:
                 cout << "Goodbye!" << endl;
                 return 0;
 
             default:
                 cout << "Invalid selection. Please choose a valid option." << endl;
                 break;
         }
     }
 
     return 0;
 }
 