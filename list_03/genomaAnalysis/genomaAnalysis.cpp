#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class HashTable {
private:
  static const int MOD = 6151; //Prime for bucket count

  struct Node {
    unsigned int key;
    int count;
    Node* next;

    Node(unsigned int k, Node* n) : key(k), count(1), next(n) {}
  };

  vector<Node*> buckets;

  //Encode a 6-letter string into an unsigned int (base-4).
  unsigned int encodeString(const string &s) {
    unsigned int encoded = 0;
    for (char c : s) {
      encoded *= 4;
      switch (c) {
        case 'A': encoded += 0; break;
        case 'C': encoded += 1; break;
        case 'G': encoded += 2; break;
        case 'T': encoded += 3; break;
        default: break;
      }
    }
    return encoded;
  }

  //Decode base-4 encoded key to 6-letter string (A, C, G, T).
  static string decodeKey(unsigned int key) {
    string result(6, 'A');
    for (int i = 5; i >= 0; --i) {
      unsigned int digit = key % 4;
      key /= 4;
      switch (digit) {
        case 0: result[i] = 'A'; break;
        case 1: result[i] = 'C'; break;
        case 2: result[i] = 'G'; break;
        case 3: result[i] = 'T'; break;
      }
    }
    return result;
  }

public:
  HashTable() : buckets(MOD, nullptr) {}
  ~HashTable() {
    for (int i = 0; i < MOD; ++i) {
      Node* curr = buckets[i];
      while (curr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
      }
    }
  }

  //Insert key or increment count if exists.
  void insert(string base) {
    unsigned int key = encodeString(base);
    int bucket = (key % MOD + MOD) % MOD;
    Node* curr = buckets[bucket];
    while (curr) {
      if (curr->key == key) {
        curr->count++;
        return;
      }
      curr = curr->next;
    }
    buckets[bucket] = new Node(key, buckets[bucket]);
  }

  //Get frequency count for a key.
  int get(unsigned int key) {
    int bucket = (key % MOD + MOD) % MOD;
    Node* curr = buckets[bucket];
    while (curr) {
      if (curr->key == key) return curr->count;
      curr = curr->next;
    }
    return 0;
  }

  //Return all entries as pairs (decoded key, count).
  vector<pair<string, int>> getEntries() const {
    vector<pair<string, int>> entries;
    for (int i = 0; i < MOD; ++i) {
      Node* curr = buckets[i];
      while (curr) {
        entries.push_back({decodeKey(curr->key), curr->count});
        curr = curr->next;
      }
    }
    return entries;
  }
};

int main() {
  ifstream inputFile("input.txt");
  if (!inputFile) {
    cerr << "Error opening input.txt" << endl;
    return 1;
  }

  //Read description (first line)
  string description;
  getline(inputFile, description);

  HashTable hashTable;
  string line;
  //Process each 60-char line; split into 10 substrings of 6 chars.
  while (getline(inputFile, line)) {
    if (line.length() < 60) continue;
    for (int i = 0; i < 60; i += 6) {
      string base = line.substr(i, 6);
      hashTable.insert(base);
    }
  }
  inputFile.close();

  //Write description and entries to output.txt
  ofstream outputFile("output.txt");
  if (!outputFile) {
    cerr << "Error opening output.txt" << endl;
    return 1;
  }
  outputFile << description << "\n";
  vector<pair<string, int>> entries = hashTable.getEntries();
  for (const auto &entry : entries) {
    outputFile << entry.first << ": " << entry.second << "\n";
  }
  outputFile.close();
  return 0;
}
