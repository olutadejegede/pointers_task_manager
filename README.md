Write a program to keep track of a task list (with no limitation on the maximum number of tasks) using a simple menu system.

You program should provide the user with a menu system:

The main menu provides 6 choice options:
1. Add a task X at a particular position p in the task list
2. Delete the task Y at position q from the task list
3. Print the number of tasks in the task list
4. Print all tasks in the task list in the order of position
5. Print all tasks in the task list in reverse order of position
6. Quit
Choice →

Detailed description of each option:
1: Program prompts the user for the task name and the position of the task after
addition. Task name must be alphanumeric, starting with at least one alphabet and
followed by at least one digit. No special characters or spaces are allowed.
Even though it is not the best User-friendly interface but to keep this assignment
simple, there is NO default mechanism as previously discussed. Both the task name
and its position p must be entered by the user.
If p is specified and valid, then the task is inserted to the pth task in the list.

Enter task name and its position -> AB1 1 // Insert AB1 as the first/last task
Enter task name and its position -> A12 1 // Insert A12 as the first task
Enter task name and its position -> B123 2 // Insert B123 as the second task
Enter task name and its position -> K9 4 // Insert K9 as the last task

You need to check if the specified position p is valid with respect to the addition
operation.

Task is added one at a time. Each time a task is added, the program displays the
main menu again.

2: Program prompts the user for the position q of the task to be deleted and print out
the task name that has been deleted.

Even though it is not the best User-friendly interface but to keep this assignment
simple, there is NO default mechanism as previously discussed. The position p of the task to be deleted must be entered by the user

Enter its position -> 1 // Delete the first task in the list
Enter its position -> 2 // Delete the second task in the list

You need to check if the specified position p is valid with respect to the delete operation.

Task is deleted one at a time. Each time a task is deleted, the program displays the
main menu again.

3: Program prints out the number of tasks in the list and returns back to the main menu

4: Program prints out the list of tasks by its name, one-by-one in a single column
format, in the order of the indices of the tasks, and returns back to the main menu

5: Program prints out the list of tasks by its name, one-by-one in a single column
format, in the REVERSE order of the indices of the tasks and returns back to the
main menu. Note that you are not using extra data structures.

6: Program exits the menu and terminates.
