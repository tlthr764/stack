// stack을 class로 구현 예제

#include <iostream>

using namespace std;

class Stack {
private:
	int top;
	int MAX_SIZE;
	int* stack;
public:
	Stack(int size);
	bool full(), empty();
	int pop();
	void push(int element);
	void print();
};

Stack::Stack(int size) {
	MAX_SIZE = size;
	stack = new int[MAX_SIZE];
	top = -1;
}

bool Stack::full() {
	if (top == MAX_SIZE - 1)
		return 1;
	else
		return 0;
}

bool Stack::empty() {
	if (top == -1)
		return true;
	else
		return false;
}

int Stack::pop() {
	if (empty())
		cout << "Stack is empty\n";
	else
		return stack[top--];
}

void Stack::push(int element) {
	if (full() == 1)
		cout << "Stack is full\n";
	else
		stack[++top] = element;
}

void Stack::print() {
	for (int i = 0; i < top + 1; i++) {
		cout << "[" << stack[i] << "]";
	}
	cout << endl;
}

int main() {
	Stack stack(5);
	for (int i = 0; i < 5; i++) {
		stack.push(i);
	}
	stack.pop();

	if (stack.empty()) {
		cout << "스택이 비었습니다!" << endl;
	}
	else {
		cout << "스택에 원소가 존재합니다!" << endl;
		stack.print();
	}
}