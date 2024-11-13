#include <iostream>
#include <string>
using namespace std;

//-----------------------------------------------------/
// Program: Task Manager (pointers)                    /
// Author: Olutade Jegede                              /
// Class: Data Structures & Algorithms                 /
//-----------------------------------------------------/

//-----------------------------------------------------/
// LinkedList class with functions:                    /  
//-----------------------------------------------------/

class LinkedList
{
    public:
            LinkedList ();
            void insertNode (string addData, int pos);
            void deleteNode (int pos);
            void displayList ();
            void displayReverseList ();
            int getLength();
            
    protected:
        private:
                struct Node
                {
                    string data;
                    Node *next;
                };
                typedef Node* Node_ptr;
                
                Node_ptr head;
                Node_ptr current;
                Node_ptr temp;
                int listLength;
};

//-----------------------------------------------------/
// Function prototypes:                                /  
//-----------------------------------------------------/

void displayMenu ();
void addTask (LinkedList &Task, string taskname, int position);
void deleteTask (LinkedList &Task, int position);
void printCount (LinkedList &Task);
void displayTasks (LinkedList &Task);
void displayReverseTasks (LinkedList &Task);
void terminateProgram ();
bool checkPosition ( LinkedList &Task, int position);
bool isValid (string task);
string capitalize(string task);

//-----------------------------------------------------/
// Main function:                                      /  
//-----------------------------------------------------/

int main ()
{
    LinkedList Task;
    int choice;
    string taskname;
    int position;

    do 
    {
        displayMenu ();
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << endl << "Enter a digit 1 - 6!" << endl << endl;
            continue;
        }

        switch(choice)
        {
            case 1:
                    cout << endl << "Enter task name and its position (seperate with one space) ->";
                    cin >> taskname >> position;
                    addTask (Task, capitalize(taskname), position);
                    break;

            case 2:
                    cout << endl << "Enter a position to delete ->";
                    cin >> position;
                    deleteTask(Task, position);
                    break;

            case 3:
                    printCount(Task);
                    break;

            case 4:
                    displayTasks(Task);
                    break;

            case 5:
                    displayReverseTasks(Task);
                    break;

            case 6:
                    terminateProgram ();
                    break;
                    
            default:
                    cout << endl << "Enter a digit 1 - 6!" << endl;
        }
    }
    while (choice != 6);

    return 0;
}

//-----------------------------------------------------/
// LinkedList constructor:                             /  
//-----------------------------------------------------/

LinkedList::LinkedList()
{
    head = NULL;
    current = NULL;
    temp = NULL;
    listLength = 0;
}

//-----------------------------------------------------/
// LinkedList class function to add to the list:       /  
//-----------------------------------------------------/

 void LinkedList::insertNode (string addData, int pos)
 {
    Node_ptr n = new Node;
    n->data = addData;
    n->next = NULL; 
    pos = pos - 1;

    if (pos == 0)
    {
        n->next = head;
        head = n;
    }

    else
    {
        current = head;

        for (int i = 0; i < pos-1; i++) 
        {
            current = current->next;
        }

        n->next = current->next;
        current->next = n;
    }

    listLength++;
 }

//-----------------------------------------------------/
// LinkedList class function to delete from the list:  /  
//-----------------------------------------------------/

 void LinkedList::deleteNode (int pos)
 {
    Node_ptr delPtr = NULL;
    temp = head;
    current = head;
    pos = pos - 1;
    int count = 0;

    while (current != NULL && count != pos)
    {
        temp = current;
        current = current->next;
        count++;
    }

    if (current == NULL)
    {
        cout << "Position is not in the list!" << endl << endl;
        delete delPtr;
    }

    else if (count == pos)
    {
        cout << current->data << " has been deleted!" << endl << endl;
        delPtr = current;
        current = current->next;
        temp->next = current;

        if (delPtr == head)
        {
            head = head->next;
            temp = NULL;
        }

        delete delPtr;
    }
    listLength--;
 }

//-----------------------------------------------------/
// LinkedList class function to display the list:      /  
//-----------------------------------------------------/

 void LinkedList::displayList () 
 {
    current = head;
    cout << endl << endl;
    cout << "          List:            " << endl << endl;

    while (current != NULL) 
    {
        cout << current->data;

        if (current->next != NULL) 
        {
            cout << " ---> ";
        }

        current = current->next;
    }
    cout << endl << endl;
 }

//------------------------------------------------------------/
// LinkedList class function to display the list in reverse:  /  
//------------------------------------------------------------/

void LinkedList::displayReverseList ()
{
    Node_ptr reverse = NULL;
    current = head;
    temp = NULL;

    while (current != NULL)
    {
        temp = current->next;
        current->next = reverse;
        reverse = current;
        current = temp;
    }
    
    current = reverse;
    cout << endl << endl;
     cout << "          Reverse List:    " << endl << endl;

     while (current != NULL) 
    {
        cout << current->data;

        if (current->next != NULL) 
        {
            cout << " ---> ";
        }

        current = current->next;
    }

    cout << endl << endl;

    current = reverse;
    reverse = NULL;

    while (current != NULL)
    {
        temp = current->next;
        current->next = reverse;
        reverse = current;
        current = temp;
    }

    head = reverse;
}

//------------------------------------------------------------/
// LinkedList class function to get length of the list:       /
//------------------------------------------------------------/

int LinkedList::getLength ()
{
    return listLength;
}

//------------------------------------------------------------/
// Function to display the main menu:                         /  
//------------------------------------------------------------/

void displayMenu ()
{
    cout << "                   Main Menu:                    "        << endl << endl;
    cout << "1. Add a task at a particular position p in the task list"        << endl;
    cout << "2. Delete the task at position q from the task list"              << endl;
    cout << "3. Print the number of tasks in the task list"                    << endl;
    cout << "4. Print all tasks in the task list in the order of position"     << endl;
    cout << "5. Print all tasks in the task list in reverse order of position" << endl;
    cout << "6. Quit"                                                  << endl << endl;
    cout << "Choice → ";
}

//------------------------------------------------------------/
// Function to add a task to the list:                        /  
//------------------------------------------------------------/

void addTask (LinkedList &Task, string taskname, int position)
{
    if (!isValid (taskname)) 
    {
        cout << endl << "Invalid task name!" << endl << endl;
        cin.clear();
        cin.ignore(100, '\n');
        return;
    }

    if (!checkPosition (Task, position-1)) 
    {
        cout << endl << "Invalid position!" << endl << endl;
        cin.clear();
        cin.ignore(100, '\n');
        return;
    }

    else
    {
        Task.insertNode(taskname, position);
        cout << endl << taskname << " added to " << position << "!" << endl << endl;
    }
}

//------------------------------------------------------------/
// Function to delete a task from the list:                   /  
//------------------------------------------------------------/

void deleteTask (LinkedList &Task, int position)
{
    int len = Task.getLength();

    if (position < 1 || position > len) 
    {
        cout << endl << "Invalid position!" << endl << endl;
        cin.clear();
        cin.ignore(100, '\n');
        return;
    }

    Task.deleteNode (position);
}

//------------------------------------------------------------/
// Function to display number of tasks in the list:           /  
//------------------------------------------------------------/

void printCount (LinkedList &Task)
{
    int len = Task.getLength();
    cout << endl <<"There are " << len << " task(s) in the list!" << endl << endl;
}

//------------------------------------------------------------/
// Function to display the tasks in the list:                 /  
//------------------------------------------------------------/

void displayTasks (LinkedList &Task)
{
    int len = Task.getLength();

    if (len > 0)
    {
        Task.displayList();
    }

    else 
    {
        cout << endl << "List is currently empty, add a task to the list!" << endl << endl;
        return;
    }
}

//------------------------------------------------------------/
// Function to display the list in reverse:                   /  
//------------------------------------------------------------/

void displayReverseTasks (LinkedList &Task)
{
    int len = Task.getLength();

    if (len > 0) 
    {
        Task.displayReverseList();
    }

    else 
    {
        cout << endl << "List is currently empty, add a task to the list!" << endl << endl;
        return;
    }
}

//------------------------------------------------------------/
// Function to end the program:                               /  
//------------------------------------------------------------/

void terminateProgram()
{
    cout << endl << "Ending program...Goodbye!" << endl << endl;
}

//------------------------------------------------------------/
// Function to error check task:                              /  
//------------------------------------------------------------/

bool isValid (string task)
{
    if (task.empty ()) 
    {
        return false;
    }

    if (!isalpha (task[0]))
    {
        return false;
    }

    bool hasDigit = false;

    for (int i = 0; i < task.length(); i++) 
    {
        if (isdigit(task[i]))
        {
            hasDigit = true;
        }

        else if (!isalpha(task[i])) 
        {
            hasDigit = false;
        }
    }
    return hasDigit;
}

//------------------------------------------------------------/
// Function to error check position:                          /  
//------------------------------------------------------------/

bool checkPosition ( LinkedList &Task, int position)
{
    int len = Task.getLength();
    
    return (position >= 0 && position <= len);
}

//------------------------------------------------------------/
// Functions to capitalize task name:                         /  
//------------------------------------------------------------/

string capitalize (string task)
{
  string capitalizedTask;

  for (char c: task)
  {
    capitalizedTask += toupper(c);
  }

  return capitalizedTask;
}
