#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
  static const int MOD = 100003;

  struct Node {
    long long key;
    int count;
    Node* next;

    Node(long long k, Node* n) : key(k), count(1), next(n) {}
  };
  vector<Node*> buckets;

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

  //Insert a key or increment its count if it already exists.
  void insert(long long key) {
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

  //Get the frequency count for a key.
  int get(long long key) {
    int bucket = (key % MOD + MOD) % MOD;
    Node* curr = buckets[bucket];
    while (curr) {
      if (curr->key == key) return curr->count;
      curr = curr->next;
    }
    return 0;
  }
};

int main() {
  vector<int> letterValues(26);
  for (int i = 0; i < 26; ++i) {
    cin >> letterValues[i];
  }

  string s;
  cin >> s;

  long long totalSubstrings = 0;
  long long prefixSum = 0;

  //Create an array of hash tables, one for each letter.
  HashTable charHashTables[26];

  for (char c : s) {
    int letterIndex = c - 'a';

    totalSubstrings += charHashTables[letterIndex].get(prefixSum);

    long long updatedPrefixSum = prefixSum + letterValues[letterIndex];

    charHashTables[letterIndex].insert(updatedPrefixSum);

    prefixSum = updatedPrefixSum;
  }

  cout << totalSubstrings << "\n";
  return 0;
}
