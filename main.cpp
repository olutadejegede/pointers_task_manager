#include <iostream>
#include <string>

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
            void insertNode (std::string addData, int pos);
            void deleteNode (int pos);
            void displayList ();
            void displayReverseList ();
            int getLength();
            
    protected:
        private:
                struct Node
                {
                    std::string data;
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
void addTask (LinkedList &Task, std::string taskname, int position);
void deleteTask (LinkedList &Task, int position);
void printCount (LinkedList &Task);
void displayTasks (LinkedList &Task);
void displayReverseTasks (LinkedList &Task);
void terminateProgram ();
bool checkPosition ( LinkedList &Task, int position);
bool isValid (std::string task);
std::string capitalize(std::string task);

//-----------------------------------------------------/
// Main function:                                      /  
//-----------------------------------------------------/

int main ()
{
    LinkedList Task;
    int choice;
    std::string taskname;
    int position;

    do 
    {
        displayMenu ();
        std::cin >> choice;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << std::endl << "Enter a digit 1 - 6!" << std::endl << std::endl;
            continue;
        }

        switch(choice)
        {
            case 1:
                    std::cout << std::endl << "Enter task name and its position (seperate with one space) ->";
                    std::cin >> taskname >> position;
                    addTask (Task, capitalize(taskname), position);
                    break;

            case 2:
                    std::cout << std::endl << "Enter a position to delete ->";
                    std::cin >> position;
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
                    std::cout << std::endl << "Enter a digit 1 - 6!" << std::endl;
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

 void LinkedList::insertNode (std::string addData, int pos)
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
        std::cout << "Position is not in the list!" << std::endl << std::endl;
        delete delPtr;
    }

    else if (count == pos)
    {
        std::cout << current->data << " has been deleted!" << std::endl << std::endl;
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
    std::cout << std::endl << std::endl;
    std::cout << "          List:            " << std::endl << std::endl;

    while (current != NULL) 
    {
        std::cout << current->data;

        if (current->next != NULL) 
        {
            std::cout << " ---> ";
        }

        current = current->next;
    }
    std::cout << std::endl << std::endl;
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
    std::cout << std::endl << std::endl;
    std::cout << "          Reverse List:    " << std::endl << std::endl;

     while (current != NULL) 
    {
        std::cout << current->data;

        if (current->next != NULL) 
        {
            std::cout << " ---> ";
        }

        current = current->next;
    }

    std::cout << std::endl << std::endl;

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
    std::cout << "                   Main Menu:                    "        << std::endl << std::endl;
    std::cout << "1. Add a task at a particular position p in the task list"             << std::endl;
    std::cout << "2. Delete the task at position q from the task list"                   << std::endl;
    std::cout << "3. Print the number of tasks in the task list"                         << std::endl;
    std::cout << "4. Print all tasks in the task list in the order of position"          << std::endl;
    std::cout << "5. Print all tasks in the task list in reverse order of position"      << std::endl;
    std::cout << "6. Quit"                                                  << std::endl << std::endl;
    std::cout << "Choice → ";
}

//------------------------------------------------------------/
// Function to add a task to the list:                        /  
//------------------------------------------------------------/

void addTask (LinkedList &Task, std::string taskname, int position)
{
    if (!isValid (taskname)) 
    {
        std::cout << std::endl << "Invalid task name!" << std::endl << std::endl;
        std::cin.clear();
        std::cin.ignore(100, '\n');
        return;
    }

    if (!checkPosition (Task, position-1)) 
    {
        std::cout << std::endl << "Invalid position!" << std::endl << std::endl;
        std::cin.clear();
        std::cin.ignore(100, '\n');
        return;
    }

    else
    {
        Task.insertNode(taskname, position);
        std::cout << std::endl << taskname << " added to " << position << "!" << std::endl << std::endl;
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
        std::cout << std::endl << "Invalid position!" << std::endl << std::endl;
        std::cin.clear();
        std::cin.ignore(100, '\n');
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
    std::cout << std::endl <<"There are " << len << " task(s) in the list!" << std::endl << std::endl;
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
        std::cout << std::endl << "List is currently empty, add a task to the list!" << std::endl << std::endl;
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
        std::cout << std::endl << "List is currently empty, add a task to the list!" << std::endl << std::endl;
        return;
    }
}

//------------------------------------------------------------/
// Function to end the program:                               /  
//------------------------------------------------------------/

void terminateProgram()
{
    std::cout << std::endl << "Ending program...Goodbye!" << std::endl << std::endl;
}

//------------------------------------------------------------/
// Function to error check task:                              /  
//------------------------------------------------------------/

bool isValid (std::string task)
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

std::string capitalize (std::string task)
{
  std::string capitalizedTask;

  for (char c: task)
  {
    capitalizedTask += toupper(c);
  }

  return capitalizedTask;
}
