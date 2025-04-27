# "SmartCourse Finder Program"

### (CS C++ Program)

### Project Reflection


## What was the problem you were solving in the projects for this course?
The main problem was to build a course advising tool for ABCU’s Computer Science department. The system needed to allow advisors to load a file containing course information, display an alphabetically sorted course list, and search for a specific course to view its title and prerequisites.

## How did you approach the problem?
I first designed clear pseudocode for each major part of the program: loading files, sorting, searching, and printing course information. Then I carefully selected a data structure based on performance analysis. Understanding data structures was critical because it directly affected the program’s efficiency, especially when searching and validating course prerequisites. I used a hash table because of its fast lookup times and scalability.

## How did you overcome any roadblocks you encountered while going through the activities or project?
Some challenges included managing prerequisite validation properly and handling missing or malformed file data without crashing the program. To overcome these, I added additional error checking and user feedback in the file loading and search functions. Another roadblock was ensuring the course listing stayed sorted when using a hash table, which doesn’t naturally preserve order, I solved this by extracting and sorting keys separately before displaying them.

## How has your work on this project expanded your approach to designing software and developing programs?
This project helped me realize the importance of planning before coding. Writing detailed pseudocode first made the coding phase much smoother and faster. It also taught me to think more carefully about data structure choices based on the program’s use cases rather than just picking the easiest one.

## How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?
Throughout the project, I focused heavily on improving code readability and maintainability by adding clear function comments, consistent naming conventions, and modularizing tasks into functions. I also learned that even simple programs benefit from error handling, user input validation, and thoughtful design, which makes future updates and maintenance much easier.
