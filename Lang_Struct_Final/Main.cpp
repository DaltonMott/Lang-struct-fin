#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>
using namespace std;



double Calculator(const string& expr) {
	istringstream iss(expr);
	vector<double> stack;
	string token;
	while (iss >> token) {
		double tokenNum;
		if (istringstream(token) >> tokenNum) {
			stack.push_back(tokenNum);
		}
		else {
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
				cerr << "Error" << endl;
				exit(1);
			}
		}
	}
	return stack.back();
}

int main() {
	string input;
	cout << "Please enter compuation in RPN." << endl;
	cin >> input;
	//cout << input;
	cout << Calculator(input) << endl;

	return 0;
}

//vector<double> stack;
////if statement parentheses
//for (char& c : input)
//{
//	double secondOperand = stack.back();
//	stack.pop_back();
//	double firstOperand = stack.back();
//	stack.pop_back();
//	switch (c)
//	{
//	case '-':
//		stack.push_back(firstOperand - secondOperand);
//		break;
//	case '+':
//		stack.push_back(firstOperand + secondOperand);
//		break;
//	case '*':
//		stack.push_back(firstOperand * secondOperand);
//		break;
//	case '/':
//		stack.push_back(firstOperand / secondOperand);
//		break;
//	case 's'://sin
//		if (i - 1 != 'o')
//		{
//
//		}
//		break;
//	case 'c'://cos
//
//		break;
//	case 't'://tan
//
//		break;
//	case '(':
//
//		break;
//	case ')':
//
//		break;
//	case " ":
//
//	default:
//		if (isdigit(c))
//		{
//
//		}
//		else
//			cout << "error" << endl;
//		break;
//	}
//	i++;
//}
//return stack.back();