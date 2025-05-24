#include <iostream>
#include <string>

using namespace std;

struct Node {
  string data;
  Node* next;
  Node* prev;
  Node(const string& s) : data(s), next(nullptr), prev(nullptr) {}
};

class Deque {
private:
  Node* head;
  Node* tail;

public:
  Deque();
  ~Deque();
  void push_front(const string& s);
  void push_back(const string& s);
  string concatenate();
};
Deque::Deque() : head(nullptr), tail(nullptr) {}
Deque::~Deque() {
  Node* current = head;
  while (current != nullptr) {
    Node* next = current->next;
    delete current;
    current = next;
  }
}
void Deque::push_front(const string& s) {
  Node* newNode = new Node(s);
  if (head == nullptr) {
    head = tail = newNode;
  } else {
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
}
void Deque::push_back(const string& s) {
  Node* newNode = new Node(s);
  if (tail == nullptr) {
    head = tail = newNode;
  } else {
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }
}
string Deque::concatenate() {
  string result;
  Node* current = head;
  while (current != nullptr) {
    result += current->data;
    current = current->next;
  }
  return result;
}

int main() {
  string line;
  while (getline(cin, line)) {
    Deque buffers;
    string current_buffer;
    bool is_home = false;

    for (char c : line) {
      if (c == '[' || c == ']') {
        if (!current_buffer.empty()) {
          if (is_home) {
            buffers.push_front(current_buffer);
          } else {
            buffers.push_back(current_buffer);
          }
          current_buffer.clear();
        }
        is_home = (c == '[');
      } else {
        current_buffer += c;
      }
    }

    if (!current_buffer.empty()) {
      if (is_home) {
        buffers.push_front(current_buffer);
      } else {
        buffers.push_back(current_buffer);
      }
    }

    cout << buffers.concatenate() << endl;
  }
  return 0;
}
