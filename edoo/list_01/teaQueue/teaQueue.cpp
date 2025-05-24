#include <iostream>

using namespace std;

struct Student {
  int li;
  int ri;
  int index;
  int second;
};

struct StudentNode {
  Student student;
  StudentNode* next;
};

class StudentList {
private:
  StudentNode* head;
  StudentNode* tail;
public:
  StudentList() : head(nullptr), tail(nullptr) { }
  ~StudentList() {
    while (head != nullptr) {
      StudentNode* tempNodePtr = head;
      head = head->next;
      delete tempNodePtr;
    }
  }
  void push_back(const Student &s) {
    StudentNode* nodePtr = new StudentNode;
    nodePtr->student = s;
    nodePtr->next = nullptr;
    if (head == nullptr) {
      head = tail = nodePtr;
    } else {
      tail->next = nodePtr;
      tail = nodePtr;
    }
  }
  StudentNode* getHead() { return head; }
};

struct QueueNode {
  Student* studentPtr;
  QueueNode* next;
};

class Queue {
private:
  QueueNode* head;
  QueueNode* tail;
public:
  Queue() : head(nullptr), tail(nullptr) { }
  ~Queue() {
    while (head != nullptr) {
      QueueNode* tempNodePtr = head;
      head = head->next;
      delete tempNodePtr;
    }
  }
  void push(Student* s) {
    QueueNode* nodePtr = new QueueNode;
    nodePtr->studentPtr = s;
    nodePtr->next = nullptr;
    if (head == nullptr) {
      head = tail = nodePtr;
    } else {
      tail->next = nodePtr;
      tail = nodePtr;
    }
  }
  void pop() {
    if (head != nullptr) {
      QueueNode* tempNodePtr = head;
      head = head->next;
      if (head == nullptr)
        tail = nullptr;
      delete tempNodePtr;
    }
  }
  Student* front() {
    if (head != nullptr)
      return head->studentPtr;
    return nullptr;
  }
  bool empty() {
    return head == nullptr;
  }
  void removeDeadline(int currentTime) {
    if (head == nullptr)
      return;
    QueueNode* previousNode = head;
    QueueNode* currentNode = head->next;
    while (currentNode != nullptr) {
      if (currentNode->studentPtr->ri == currentTime) {
        previousNode->next = currentNode->next;
        if (currentNode == tail)
          tail = previousNode;
        QueueNode* temp = currentNode;
        currentNode = currentNode->next;
        delete temp;
      } else {
        previousNode = currentNode;
        currentNode = currentNode->next;
      }
    }
  }
};

int main() {
  int testCases;
  cin >> testCases;

  for (int t = 0; t < testCases; t++) {
    int studentsAmount;
    cin >> studentsAmount;

    StudentList sList;
    int maxTime = 0;
    for (int i = 0; i < studentsAmount; i++) {
      Student s;
      cin >> s.li >> s.ri;
      s.index = i;
      s.second = 0;
      if (s.ri > maxTime)
        maxTime = s.ri;
      sList.push_back(s);
    }

    Queue q;

    StudentNode* currentNodePtr = sList.getHead();

    for (int time = 1; time <= maxTime; time++) {
      while (currentNodePtr != nullptr && currentNodePtr->student.li == time) {
        q.push(&(currentNodePtr->student));
        currentNodePtr = currentNodePtr->next;
      }

      q.removeDeadline(time);

      if (!q.empty()) {
        Student* frontStudentPtr = q.front();
        if (frontStudentPtr->ri >= time) {
          frontStudentPtr->second = time;
          q.pop();
        }
      }
    }

    StudentNode* nodePtr = sList.getHead();
    while (nodePtr != nullptr) {
      cout << nodePtr->student.second << " ";
      nodePtr = nodePtr->next;
    }
    cout << "\n";
  }

  return 0;
}
