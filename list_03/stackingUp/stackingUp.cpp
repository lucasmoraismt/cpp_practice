#include <iostream>
#include <variant>
#include <string>

using namespace std;

struct Element {
  variant<int, char> value;
  Element* previous = nullptr;
};

class Stack {
private:
  Element* head;
  int size;
public:
  Stack() : head(nullptr), size(0) {}
  ~Stack() {
    while (head != nullptr) {
      pop();
    }
  }

  Element* getHead() { return head; }
  int getSize() { return size; }
  void push(variant<int, char> value) {
    Element* newElement = new Element;
    newElement->value = value;
    newElement->previous = head;
    head = newElement;
    size++;
  }
  void pop() {
    if (size == 0) return;
    Element* temp = head;
    head = head->previous;
    delete temp;
    size--;
  }
};

void incrementStack(Stack &s) {
  for (Element* current = s.getHead(); current != nullptr; current = current->previous) {
    current->value = get<int>(current->value) + 1;
  }
}

int main() {
  Stack inputStack;
  Stack commands;

  int intStackElements = 0;
  cin >> intStackElements;
  cin.ignore();

  for (int i = 0; i < intStackElements; i++) {
    int currentNumber;
    cin >> currentNumber;
    inputStack.push(currentNumber);
  }

  while (inputStack.getSize() != 0) {
    //Case 1: If top two numbers are equal, push 'd'.
    if (inputStack.getSize() >= 2) {
      int topVal = get<int>(inputStack.getHead()->value);
      int secondVal = get<int>(inputStack.getHead()->previous->value);
      if (topVal == secondVal) {
        commands.push('d');
        inputStack.pop();
        continue;
      }
    }

    int currentVal = get<int>(inputStack.getHead()->value);
    //Case 2: A lone 1 = push '1'.
    if (currentVal == 1) {
      commands.push('1');
      inputStack.pop();
      continue;
    }

    //Case 3: Reverse a plus operation.
    //First, remove the top element and increment all remaining values.
    inputStack.pop();
    incrementStack(inputStack);
    commands.push('+');

    //For even numbers, assume it was a doubling (push "d+").
    if (currentVal % 2 == 0) {
      int half = currentVal / 2;
      inputStack.push(half);
      commands.push('d');
    } else {
      //Otherwise, reverse the generic plus: push (currentVal - 1) then 1.
      inputStack.push(currentVal - 1);
      inputStack.push(1);
    }
  }

  string commandString = "";
  while (commands.getSize() > 0) {
    char c = get<char>(commands.getHead()->value);
    commandString += c;
    commands.pop();
  }

  cout << commandString << endl;

  return 0;
}
