#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>
#include <math.h>
using namespace std;



double Calculator(const string& str)
{
	istringstream expr(str);
	vector<double> stack;
	string token;
	while (expr >> token)
	{
		double tokenNum;
		if (istringstream(token) >> tokenNum)
		{
			stack.push_back(tokenNum);
		}
		else if (token == "(" || token == ")") {}
		else if (stack.size() < 1)
		{
			printf("Error: Not enough inputs.");
			exit(1);
		}
		else if (token == "sin")
		{
			double operand = stack.back();
			stack.pop_back();
			stack.push_back(sin(operand));
		}
		else if (token == "cos")
		{
			double operand = stack.back();
			stack.pop_back();
			stack.push_back(cos(operand));
		}
		else if (token == "tan")
		{

			double operand = stack.back();
			stack.pop_back();
			stack.push_back(tan(operand));
		}
		else
		{
			if (stack.size() < 2)
			{
				printf("Error: Not enough inputs.");
				exit(1);
			}
			double secondOperand = stack.back();
			stack.pop_back();
			double firstOperand = stack.back();
			stack.pop_back();
			if (token == "*")
				stack.push_back(firstOperand * secondOperand);
			else if (token == "/")
				stack.push_back(firstOperand / secondOperand);
			else if (token == "-")
				stack.push_back(firstOperand - secondOperand);
			else if (token == "+")
				stack.push_back(firstOperand + secondOperand);
			else if (token == "^")
				stack.push_back(pow(firstOperand, secondOperand));
			else {
				printf("Error: Invalid input.");
				exit(1);
			}
		}
	}
	if (stack.size() != 1)
	{
		cout << "Error: too many operands. Number of outputs must be ";
		return 1;
	}
	else
		return stack.back();
}

int main()
{
	string input;
	cout << "Please enter compuation in RPN." << endl;
	getline(cin, input);
		while (input != "exit")
		{
			cout << "Answer = ";
			cout << Calculator(input) << endl;
			cout << "Enter another value, or type 'exit' to quit" << endl;
			getline(cin, input);
			system("CLS");
		}

	return 0;
}