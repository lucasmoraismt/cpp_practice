#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int particionaHoareReverso(vector<int>& arr, int l, int r) {
  int pivo = arr[l + (r - l) / 2];

  int i = l - 1;
  int j = r + 1;

  while (true) {
    do {
      i++;
    } while (arr[i] > pivo);

    do {
      j--;
    } while (arr[j] < pivo);

    if (i >= j) {
      return j;
    }

    swap(arr[i], arr[j]);
  }
}

void quicksortReversoRecursivo(vector<int>& arr, int l, int r) {
  if (l < r) {
    int indice_particao = particionaHoareReverso(arr, l, r);

    quicksortReversoRecursivo(arr, l, indice_particao);
    quicksortReversoRecursivo(arr, indice_particao + 1, r);
  }
}

void quicksortReverso(vector<int>& arr) {
  if (arr.empty()) {
    return;
  }
  quicksortReversoRecursivo(arr, 0, arr.size() - 1);
}

int contaPontos(vector<int>& arr) {
  int pontos = 0;
  for(int i = 0; i < arr.size(); i = i + 2) {
    pontos += arr[i + 1];
  }
  return pontos;
}

int main() {
  int t;
  cin >> t;

  for(int i = 0; i < t; i++) {
    int n;
    cin >> n;

    vector<int> caseNumbers;
    for(int j = 0; j < 2 * n; j++) {
      int a;
      cin >> a;
      caseNumbers.push_back(a);
    }

    quicksortReverso(caseNumbers);

    int pontos = contaPontos(caseNumbers);
    cout << pontos << endl;
  }

  return 0;
}
