#include <iostream>
#include <sstream>
#include <optional>

using namespace std;

struct element {
  int value = 0;
  element* previous = nullptr;
};

class Stack {
private:
  element* tip;
  int size;
public:
  Stack();
  ~Stack();
  void push(int value);
  void pop();
  optional<int> top();

  int getSize() {return size;}
  int getHeight();
};
Stack::Stack() {
  tip = nullptr;
  size = 0;
}
Stack::~Stack() {
  while(size != 0) {
    pop();
  }
}
void Stack::push(int value) {
  element* new_element = new element;
  new_element->value = value;
  new_element->previous = tip;
  tip = new_element;
  size++;
}
void Stack::pop() {
  if(size > 0) {
    element* temp = tip;
    tip = tip->previous;
    delete temp;
    size--;
  } else {
    tip = nullptr;
  }
}
optional<int> Stack::top() {
  if (size == 0) {
    return nullopt;
  } else {
    return tip->value;
  }
}
int Stack::getHeight() {
  int sum = 0;
  element* current = tip;

  while (current != nullptr) {
    sum += current->value;
    current = current->previous;
  }

  return sum;
}

int equalStacks(Stack* h1, Stack* h2, Stack* h3) {
  int n1 = h1->getHeight();
  int n2 = h2->getHeight();
  int n3 = h3->getHeight();

  while (n1 != n2 || n2 != n3) {
    if (n1 >= n2 && n1 >= n3) {
      n1 = n1 - h1->top().value();
      h1->pop();
    } else if (n2 >= n1 && n2 >= n3) {
      n2 = n2 - h2->top().value();
      h2->pop();
    } else {
      n3 = n3 - h3->top().value();
      h3->pop();
    }
  }

  return n1;
}

int main() {
  int n1, n2, n3;
  cin >> n1 >> n2 >> n3;
  cin.ignore();

  Stack h1, h2, h3;
  Stack* stacks0 = &h1;
  Stack* stacks1 = &h2;
  Stack* stacks2 = &h3;

  string line;
  for (int i = 0; i < 3; i++) {
    Stack* tempStack;
    if (i == 0) tempStack = stacks0;
    else if (i == 1) tempStack = stacks1;
    else tempStack = stacks2;

    getline(cin, line);
    stringstream ss(line);
    int element;

    Stack tempReverse;
    while (ss >> element) {
      tempReverse.push(element);
    }

    while (tempReverse.getSize() > 0) {
      tempStack->push(tempReverse.top().value());
      tempReverse.pop();
    }
  }

  int height = equalStacks(&h1, &h2, &h3);
  cout << height;

  return 0;
}
