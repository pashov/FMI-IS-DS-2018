#include<iostream>
using namespace std;

struct Node {
	Node(Node* to, int info) {
		this->info = info;
		this->next = to;
	}
	Node * next;
	int info;
};


Node * merge(Node * firstArr, Node * secondArr) {
	Node * start =nullptr, *current =nullptr;
	bool isFirstIteration = true;

	while (firstArr && secondArr) {

		if (isFirstIteration) {
			if (firstArr->info< secondArr->info) {
				current = new Node(nullptr, firstArr->info);
				firstArr = firstArr->next;
			}
			else {
				current = new Node(nullptr, secondArr->info);
				secondArr = secondArr->next;
			}
			start = current;
			isFirstIteration = false;
		}
		else {
			if (firstArr->info< secondArr->info) {
				current->next = new Node(nullptr, firstArr->info);
				firstArr = firstArr->next;
			}
			else {
				current->next = new Node(nullptr, secondArr->info);
				secondArr = secondArr->next;
			}
           current= current->next; 
		}
	}

	while (firstArr ) {
		if (isFirstIteration) {
	    	current=  new Node(nullptr, firstArr->info);;
		    firstArr = firstArr->next;
            start = current;
			isFirstIteration = false;
        }else{
	        current->next =  new Node(nullptr, firstArr->info);;
	    	firstArr = firstArr->next;
	    	current = current->next;
        }
	}
	
	while (secondArr) {
			if (isFirstIteration) {
	    	current=  new Node(nullptr, secondArr->info);;
		    secondArr = secondArr->next;
            start = current;
			isFirstIteration = false;
        }else{
	        current->next =  new Node(nullptr, secondArr->info);;
	    	secondArr = secondArr->next;
	    	current = current->next;
        }
	}

	return start;
}


void print(Node * s){
    while(s){
        cout<<s->info<<"  ";
        s=s->next;
    }
}



int main() {

	Node a3(nullptr, 4);
	Node a2(&a3, 3);
	Node a1(&a2, 1);

	Node b2(nullptr, 6);
	Node b1(&b2, 2);

	Node * result = merge(&a1, &b1);
    print(result);

	system("pause");
	return 0;
}