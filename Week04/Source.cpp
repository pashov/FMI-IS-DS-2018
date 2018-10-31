#include<iostream>
#include<stack>
#include<string>
using namespace std;

int ermit(int x, int n) {
	if (n == 0)
		return 1;
	if (n == 1)
		return 2*x;

	return 2 * x*ermit(x, n - 1) + 2 * (n - 1)*ermit(x, n - 2);
}
int ermitWithStack(int x, int n) {
	stack<int> stack;
	stack.push(1);
	stack.push(2*x);

	for (int i = 2; i <= n; i++) {
		int prev1 = stack.top();
		stack.pop();
		int prev2=stack.top();
		stack.pop();
		
		stack.push(prev1);
		int newOne = 2 * x*prev1 + 2 * (i - 1)*prev2;

		stack.push(newOne);
	}
	return stack.top();
}

void insertBottom(stack<int> & s,int current) {
	int curr;
	if (s.empty()) s.push(current);
	else {
		curr = s.top();
		s.pop();
		insertBottom(s, current);
		s.push(curr);
	}
	
}

void insertElement(stack<int> & s, int current) {
	int curr;
	if (s.empty()) { 
		s.push(current); 
	}
	else {
		curr = s.top();
		if (curr > current) {
			s.push(current);
		}
		else {
			s.pop();
			insertElement(s, current);
			s.push(curr);
		}
	}

}

void iterStack(stack<int> & s){
	if (s.empty()) return;
	int current = s.top();
	s.pop();

	iterStack(s);

	//insertBottom(s, current);   //reverse
	insertElement(s, current);    //sort
}

void print(stack<int>  s) {
	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}
}
struct MyStack {
	 stack<int> stack;
	 string name;
};
void moveDisk(int n, MyStack & s, MyStack & h, MyStack & d)
{
	if (n < 1) return;
	moveDisk(n - 1, s, d, h);
	cout << "Element:" << s.stack.top()<<" From "<<s.name<<" To "<<d.name << endl;
	int curr = s.stack.top();
	s.stack.pop();
	d.stack.push(curr);
	moveDisk(n - 1, h, s, d);
}

int main() {

	//stack<int> s;
	//s.push(5);
	//s.push(8);
	//s.push(3);
	//print(s);
	//cout << endl;
	//iterStack(s);
	//print(s);
	stack<int> source;
	source.push(4);
	source.push(3);
	source.push(2);
	source.push(1);

	stack<int> helper;
	stack<int> destination;

	MyStack a{ source,"1" }, b{ helper, "2" }, c{ destination,"3" };

	moveDisk(4, a, b, c);
	print(a.stack);
	cout << endl;
	print(b.stack);
	cout << endl;
	print(c.stack);


	system("pause");
	return 0;
}