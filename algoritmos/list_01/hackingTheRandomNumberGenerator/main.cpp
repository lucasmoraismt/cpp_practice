#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int particionaHoare(vector<int>& arr, int l, int r) {
  int pivo = arr[l + (r - l) / 2];

  int i = l - 1;
  int j = r + 1;

  while(true) {
    do {
      i++;
    } while (arr[i] < pivo);

    do {
      j--;
    } while (arr[j] > pivo);

    if (i >= j) {
      return j;
    }

    swap(arr[i], arr[j]);
  }
}

void quicksortRecursivo(vector<int>& arr, int l, int r) {
  if (l < r) {
    int indice_particao = particionaHoare(arr, l, r);

    quicksortRecursivo(arr, l, indice_particao);
    quicksortRecursivo(arr, indice_particao + 1, r);
  }
}

void quicksort(vector<int>& arr) {
  if (arr.empty()) {
    return;
  }
  quicksortRecursivo(arr, 0, arr.size() - 1);
}

int bsearch(vector<int>& arr, int l, int r, int curr) {
  if(r >= l) {
      int m = (l + r) / 2;
      int ans;
      if(curr == arr[m]) {
          return m;
      } else if(curr < arr[m]) {
          ans = bsearch(arr, l, m - 1, curr);
      } else {
          ans = bsearch(arr, m + 1, r, curr);
      }
      return ans;
  } else {
    return -1;
  }
}

int contaOcorrencias(vector<int>& arr, int k) {
  int contador = 0;

  for(int i = 0; i < arr.size(); i++) {
    int indiceMatch = bsearch(arr, 0, arr.size() - 1, arr[i] + k);

    if(indiceMatch != -1) {
      contador++;
    }
  }
  return contador;
}

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> generatedNumbers;
  for(int i = 0; i < n; i++) {
    int curr;
    cin >> curr;
    generatedNumbers.push_back(curr);
  }

  quicksort(generatedNumbers);

  int ocorrencias = contaOcorrencias(generatedNumbers, k);

  cout << ocorrencias << endl;

  return 0;
}
