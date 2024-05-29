#include <iostream>
#include <thread>
#include <limits>

class Calculator
{
public:
    void addition();
    void subtraction();
    void multiplication();
    void division();
};

// Exit Program Function
void exitProgram()
{
    std::cout << "Exiting... \n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    exit(0);
}

// Introduction Function
void intro()
{
    system("cls");
    Calculator calc;

    char option;

    // Introduction
    std::cout << "\n\n\tCalculator \n";

    // Menu
    std::cout << "\n\t 01. Addition";
    std::cout << "\n\t 02. Subtraction";
    std::cout << "\n\t 03. Multiplication";
    std::cout << "\n\t 04. Division";
    std::cout << "\n\t 05. Exit";

    std::cout << "\n\n\t Please Select An Option: ";
    std::cin >> option;

    switch (option)
    {

    case '1':
        // Addition
        system("cls");
        calc.addition();
        break;
    case '2':
        // Subtraction
        system("cls");
        calc.subtraction();
        break;
    case '3':
        // Multiplication
        system("cls");
        calc.multiplication();
        break;
    case '4':
        // Division
        system("cls");
        calc.division();
        break;
    case '5':
        exitProgram();

        // Invalid Option Selected
    default:
        std::cout << "Invalid Option \n";
        // Clears the input stream
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::this_thread::sleep_for(std::chrono::seconds(1));
        intro();
        break;
    }
}

// Restart Program Function
void restartProgram()
{
    char choice;

    std::cout << "\n\n\tWould you like to perform another operation? (Y/N): ";
    std::cin >> choice;
    choice = toupper(choice);

    if (choice == 'Y')
    {
        system("cls");
        intro();
    }
    else
    {
        exitProgram();
    }
}

// Validation Function
void validation()
{
    std::cout << "\n\n\tInvalid input. Please enter a number: ";
    std::cin.clear();
    // Clears the input stream
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Addition Function
void Calculator::addition()
{
    float num1, num2, result;
    char choice;

    std::cout << "\n\n\tEnter the first number: ";
    // Checks if the input is a number
    while (!(std::cin >> num1))
    {
        validation();
    }

    std::cout << "\n\tEnter the second number: ";
    // Checks if the input is a number
    while (!(std::cin >> num2))
    {
        validation();
    }

    result = num1 + num2;

    std::cout << "\n\n\tThe sum of " << num1 << " and " << num2 << " is " << result << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));

    restartProgram();
}

// Subtraction Function
void Calculator::subtraction()
{
    float num1, num2, result;
    char choice;

    std::cout << "\n\n\tEnter the first number: ";
    while (!(std::cin >> num1))
    {
        validation();
    }

    std::cout << "\n\tEnter the second number: ";
    while (!(std::cin >> num2))
    {
        validation();
    }

    result = num1 - num2;

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "\n\n\tThe difference of " << num1 << " and " << num2 << " is " << result << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));

    restartProgram();
}

// Multiplication Function
void Calculator::multiplication()
{
    float num1, num2, result;
    char choice;

    std::cout << "\n\n\tEnter the first number: ";
    while (!(std::cin >> num1))
    {
        validation();
    }

    std::cout << "\n\tEnter the second number: ";
    while (!(std::cin >> num2))
    {
        validation();
    }

    result = num1 * num2;

    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "\n\n\tThe product of " << num1 << " and " << num2 << " is " << result << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));

    restartProgram();
}

// Division Function
void Calculator::division()
{
    float num1, num2, result;
    char choice;

    std::cout << "\n\n\tEnter the first number: ";
    while (!(std::cin >> num1))
    {
        validation();
    }

    std::cout << "\n\tEnter the second number: ";
    while (!(std::cin >> num2))
    {
        validation();
    }

    if (num2 == 0)
    {
        std::cout << "\n\n\tDivision by zero is not allowed \n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        division();
    }

    result = num1 / num2;

    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "\n\n\tThe division of " << num1 << " and " << num2 << " is " << result << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));

    restartProgram();
}

// Main Function

int main()
{
    intro();
    return 0;
}
