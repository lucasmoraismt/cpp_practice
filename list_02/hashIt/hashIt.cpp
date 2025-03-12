#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class HashTable {
private:
  struct TableEntry {
    string key;
    bool used = false;
  };

  static const int TABLE_SIZE = 101;
  TableEntry* hashTable;

  int computeHash(const string &key) {
    long long sum = 0;
    for (int i = 0; i < (int)key.size(); i++) {
      sum += ((int)key[i]) * (i + 1);
    }
    sum = 19 * sum;
    return sum % TABLE_SIZE;
  }

public:
  HashTable() {
    hashTable = new TableEntry[TABLE_SIZE];
  }

  ~HashTable() {
    delete[] hashTable;
  }

  int findIndex(const string &key) {
    int initialPosition = computeHash(key);

    for (int probe = 0; probe < 20; probe++) {
      int currentPosition = (initialPosition + probe * probe + 23 * probe) % TABLE_SIZE;

      if (hashTable[currentPosition].used && hashTable[currentPosition].key == key) {
        return currentPosition;
      }
    }
    return -1;
  }

  void insertKey(const string &key) {
    if (findIndex(key) != -1)
        return;

    int initialPosition = computeHash(key);

    for (int probe = 0; probe < 20; probe++) {
      int currentPosition = (initialPosition + probe * probe + 23 * probe) % TABLE_SIZE;
      if (!hashTable[currentPosition].used) {
        hashTable[currentPosition].key = key;
        hashTable[currentPosition].used = true;
        break;
      }
    }
  }

  void removeKey(const string &key) {
    int pos = findIndex(key);
    if (pos != -1) {
      hashTable[pos].key.clear();
      hashTable[pos].used = false;
    }
  }

  void printTable() {
    int keysCount = 0;

    for (int i = 0; i < TABLE_SIZE; i++) {
      if (hashTable[i].used)
        keysCount++;
    }

    cout << keysCount << "\n";

    for (int i = 0; i < TABLE_SIZE; i++) {
      if (hashTable[i].used)
        cout << i << ":" << hashTable[i].key << "\n";
    }
  }
};

int main(){
  int testCaseCount;
  cin >> testCaseCount;

  for (int i = 0; i < testCaseCount; i++){
    int numberOfOperations;
    cin >> numberOfOperations;

    HashTable hashDictionary;

    string operationLine;
    getline(cin, operationLine);

    for (int opIndex = 0; opIndex < numberOfOperations; opIndex++){
      getline(cin, operationLine);

      if (operationLine.substr(0, 4) == "ADD:") {
        string keyToAdd = operationLine.substr(4);
        hashDictionary.insertKey(keyToAdd);
      } else if (operationLine.substr(0, 4) == "DEL:") {
        string keyToDelete = operationLine.substr(4);
        hashDictionary.removeKey(keyToDelete);
      }
    }

    hashDictionary.printTable();

  }
  return 0;
}
