# copy_password_plugin
快速复制粘贴密码插件
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream> // 解决cin不录入空格问题
#include <conio.h> // 获取键盘点击事件

using namespace std;

class Calculator {
	public:
		string operatorList = "+-*/";
		string formatString(string str) {
			string newStr = str;
			while (1)
			{
				if (newStr.find(" ", 0) > str.size()) {
					break;
				}
				int spaceIndex = newStr.find(" ", 0);
				newStr = newStr.erase(spaceIndex, 1);
			};
			return newStr;
		};
		// 获取最终计算结果
		double getResult(string arithmetic) {
			char currentOperator = this->getCurrentOperator(arithmetic);
			int currentOperatorIndex = arithmetic.find(currentOperator, 0);
			string leftArithmetic(arithmetic, 0, currentOperatorIndex);
			string rightArithmetic(arithmetic, currentOperatorIndex + 1, arithmetic.size());
			double result{};
			if (leftArithmetic.empty() || rightArithmetic.empty()) {
				cout << "算数表达式错误!";
				return {};
			}
			switch (currentOperator) {
				case '+':
					result = stod(leftArithmetic) + stod(rightArithmetic);
					break;
				case '-':
					result = stod(leftArithmetic) - stod(rightArithmetic);
					break;
				case '*':
					result = stod(leftArithmetic) * stod(rightArithmetic);
					break;
				case '/':
					result = stod(leftArithmetic) / stod(rightArithmetic);
					break;
				default:
					break;
			}
			return result;
		};
	private:
		// 获取当前运算符号
		char getCurrentOperator(string operatorStr) {
			char currentOperator{};
			int operatorListSize = operatorList.size();
			bool isError = true;
			for (int i = 0; i < operatorListSize; i++)
			{
				if (operatorStr.find(operatorList[i], 0) != operatorStr.npos) {
					currentOperator = operatorList[i];
					isError = false;
					break;
				}
			}
			if (isError) {
				cout << "算数表达式错误!";
				return {};
			}
			return currentOperator;
		};
};
double compute() {
	cout << "请输入算数表达式, 该版本暂只支持单个运算符运算 例：2 * 123" << endl;
	string inputOperation;
	getline(cin, inputOperation);
	Calculator calculator;
	string replaceSpaceStr = calculator.formatString(inputOperation);
	double result = calculator.getResult(replaceSpaceStr);
	return result;
};
void main() {
	double result;
	int ch = 0;
	while (ch != 27) {
		result = compute();
		cout << result << endl << "点击ESC键退出或者按其他键继续开始:" << endl;
		ch = _getch();
	};
}  
