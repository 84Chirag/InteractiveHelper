#include <iostream>
#include <string>
#include <windows.h>
#include <shellapi.h>
using namespace std;

void greetings()
{
    cout << "Hello\n";
    cout << "What do you want to do today?\n";
    string x;
    cin >> x;
    cout << "Ok, we will start with " << x << endl;
}

// Function to ask user what they want to do
char ask()
{
    cout << "Do you want to use Your Calculator? (y/n): ";
    char choice;
    cin >> choice;
    return choice;
}

// Function to perform calculator operations
void calculator()
{
    double num1, num2;
    char operation;
    double result;

    cout << "\nEnter the first number: ";
    cin >> num1;

    cout << "What operation do you want to perform? (+, -, *, /): ";
    cin >> operation;

    cout << "Enter the second number: ";
    cin >> num2;

    switch (operation)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '/':
        if (num2 != 0)
        {
            result = num1 / num2;
        }
        else
        {
            cout << "Error: Division by zero is not allowed." << endl;
            return;
        }
        break;
    case '*':
        result = num1 * num2;
        break;
    default:
        cout << "Error: Invalid operation." << endl;
        return;
    }
    cout << "The result of the calculation is: " << result << endl;
}

// Function to open Google search
void openGoogle()
{
    cout << "What do you want to search on Google? ";
    string site;
    cin.ignore(); // Ignore newline character left in buffer
    getline(cin, site);

    if (site.empty())
    {
        cout << "Please enter what you want to search!" << endl;
    }
    else
    {
        wstring wideSite(site.begin(), site.end());
        wstring url = L"https://www.google.com/search?q=" + wideSite;

        ShellExecuteW(NULL, L"open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
    }
}

void performAction(const string& userChoice)
{
    if (userChoice == "calculator")
    {
        cout << "Oh sure, let's do that!\n";
        calculator();
        cout << "Done!\n";
    }
    else if (userChoice == "google")
    {
        cout << "Oh sure, let's do that!\n";
        openGoogle();
        cout << "Done!\n";
    }
    else if (userChoice == "exit")
    {
        cout << "Well, it's your wish. Exiting program. Goodbye!" << endl;
        exit(0);
    }
    else
    {
        cout << "Invalid command. Exiting program. Goodbye!" << endl;
        exit(0);
    }
}

int main()
{
    greetings();

    char choice = ask(); // Ask user for initial choice
    if (choice == 'y')
    {
        calculator(); // Perform calculator function
    }
    else if (choice == 'n')
    {
        cout << "Ok, let's do something else." << endl;
    }
    else
    {
        cout << "Invalid choice. Re-run the program to see me again. Bye!" << endl;
        return 0;
    }

    string option;
    cout << "Do you want to use Google? (yes/no): ";
    cin >> option;

    if (option == "yes")
    {
        openGoogle(); // Open Google function
    }
    else if (option == "no")
    {
        cout << "Oh sure." << endl;
    }
    else
    {
        cout << "Invalid option. Please enter 'yes' or 'no'." << endl;
        return 0;
    }

    cout << "Do you even want to do something? (yes/no): ";
    string continueChoice;
    cin >> continueChoice;

    if (continueChoice != "yes")
    {
        cout << "Well, it's your wish. Exiting program. Goodbye!" << endl;
        return 0;
    }

    while (true)
    {
        cout << "If you want to run something, tell me or if you want to exit, enter 'exit': ";
        string userChoice;
        cin >> userChoice;
        performAction(userChoice);
    }

    return 0;
}
