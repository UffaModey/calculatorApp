// calculatorProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//include the required c++ libraries
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//create a function for performing the arithmetic calculations
double calculate(char arithmetic, double value1, double value2) {
    switch (arithmetic) {
    case '+':
        return value1 + value2;
    case '-':
        return value1 - value2;
    case '*':
        return value1 * value2;
    case '/':
        return value1 / value2;
    default:
        return 0.0;
  }  
}

int main(){

    //initialise the vectors to store the values input by the users
    vector<double> numbers;
    vector<char> math;

    //initialise variables
    string userResponse;
    double result;
    double num;
    char operand; /*
    + = Addition
    - = Substraction
    * = Multiplication
    / = Division 
    */

    cout << "HBK Calculator Project - Uffa Modey" << endl << endl;
    
    //Collect the user input to form the equation for calculation
    cout << "Enter a value:";
    cin >> num;
    numbers.push_back(num);

    do {
        cout << "Enter (+ - * /) for the calculation operation: \n + = Addition \n - = Substraction \n * = Multiplication \n / = Division " << endl;
        cin >> operand;
        math.push_back(operand);

        cout << "Enter next value: ";
        cin >> num;
        numbers.push_back(num);

        cout << "Enter another operation? Enter 'y' or 'n': " << endl ;
        cin >> userResponse;
    } while (userResponse == "y");

    //Calculation computation and data rearrangement in vectors
    for (int i = 0; i < math.size(); i++) {
        if (math[i] == '/') {
            double calculation = calculate(math[i], numbers[i], numbers[i + 1]);
            numbers[i] = calculation;
            numbers.erase(numbers.begin() + (i+1));
            math.erase(math.begin() + (i));
        }
    }
    for (int i = 0; i < math.size(); i++) {
        if (math[i] == '*') {
            double calculation = calculate(math[i], numbers[i], numbers[i + 1]);
            numbers[i] = calculation;
            numbers.erase(numbers.begin() + (i + 1));
            math.erase(math.begin() + (i));
        }
    }
    for (int i = 0; i < math.size(); i++) {
        if (math[i] == '+') {
            double calculation = calculate(math[i], numbers[i], numbers[i + 1]);
            numbers[i] = calculation;
            numbers.erase(numbers.begin() + (i + 1));
            math.erase(math.begin() + (i));
        }
    }
    for (int i = 0; i < math.size(); i++) {
        if (math[i] == '-') {
            double calculation = calculate(math[i], numbers[i], numbers[i + 1]);
            numbers[i] = calculation;
            numbers.erase(numbers.begin() + (i + 1));
            math.erase(math.begin() + (i));
        }
    }
    
    //define result
    for (int i = 0; i < numbers.size(); i++) {
        result = numbers[i];
    }

    //display result
    cout << "The result is: ";
    cout << result << endl ;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
