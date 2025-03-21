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
  Stack() {
    tip = nullptr;
    size = 0;
  };
  ~Stack() {
    while(size != 0) {
      pop();
    }
  };

  void push(int value) {
    element* new_element = new element;
    new_element->value = value;
    new_element->previous = tip;
    tip = new_element;
    size++;
  };
  void pop() {
    if(size > 0) {
      element* temp = tip;
      tip = tip->previous;
      delete temp;
      size--;
    } else {
      tip = nullptr;
    }
  };
};

int main() {
  const Stack pilha;

  int instructionsNumber = 0;
  cin >> instructionsNumber;

  for(int i = 0; i < instructionsNumber; i++){
    string line;
    getline(cin, line);
    stringstream ss(line);

    char instruction;
    while (ss >> instruction) {
      if (instruction == '1') {
        pilha.push(1);
      } else if (instruction == 'd') {
        element top = pilha.tip;
        if (top != nullptr) {
          pilha.pop();
          pilha.push(top * 2);
        }
      } else if (instruction == '+') {
        element top = pilha.tip;

        if (top != nullptr && top.previous != nullptr) {
          int previous = top.previous;
          pilha.pop();
          pilha.pop();
          pilha.push(top.value + previous.value);
        };
      };
    };
  };

  return 0;
};
