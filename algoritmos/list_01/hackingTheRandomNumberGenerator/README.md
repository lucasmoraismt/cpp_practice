# Problem B: Hacking the Random Number Generator

## 📝 Enunciado do Problema

Você escreveu recentemente um código gerador de números aleatórios para uma aplicação web e agora percebe que algum cracker o invadiu. Ele agora está fornecendo números com uma diferença predominante de um determinado valor <span class="math-inline">k</span>. Sendo um hacker, você decide escrever um código que receberá <span class="math-inline">n</span> números como entrada e um valor <span class="math-inline">k</span>, e encontrará o número total de pares de números cuja diferença absoluta é igual a <span class="math-inline">k</span>. Isso irá auxiliá-lo nos testes do seu gerador de números aleatórios.

**Nota:** Todos os valores se encaixam no intervalo de um inteiro com sinal. <span class="math-inline">n, k \\ge 1</span>. Todos os <span class="math-inline">n</span> números fornecidos são distintos.

---

## 📥 Formato da Entrada

A primeira linha contém <span class="math-inline">n</span> e <span class="math-inline">k</span>. (<span class="math-inline">n ≤ 10^5</span>)
A segunda linha contém <span class="math-inline">n</span> números do conjunto.

```text
n k
num1 num2 ... numN
```

---

## 📤 Formato da Saída

Um único inteiro informando o número de pares de números que têm uma diferença absoluta de <span class="math-inline">k</span>.

```text
total_de_pares
```

---

## (Exemplo)

**Entrada:**
```text
5 2
1 5 3 4 2
```

**Saída:**
```text
3
```

**Explicação do Exemplo:**
Os pares com diferença absoluta de 2 são:

* <span class="math-inline">\(1, 3\) → \|3\-1\| \= 2</span>
* <span class="math-inline">\(5, 3\) → \|3\-5\| \= 2</span>
* <span class="math-inline">\(4, 2\) → \|2\-4\| \= 2</span>
* Total: 3 pares.

---
## 🧠 Raciocínio da Solução (Spoiler Alert!)

O problema pede para encontrar o número de pares <span class="math-inline">\(a, b\)</span> no conjunto de <span class="math-inline">n</span> números distintos tal que <span class="math-inline">\|a \- b\| \= k</span>.

1. **Ordenação:** A primeira etapa crucial é ordenar o array de <span class="math-inline">n</span> números em ordem crescente. Isso facilitará a busca por pares, pois se <span class="math-inline">a < b</span>, então <span class="math-inline">\|a \- b\| \= b \- a</span>. Assim, procuramos por <span class="math-inline">b \- a \= k</span>, ou seja, <span class="math-inline">b \= a \+ k</span>.

2. **Contagem de Pares após Ordenação:**

  * Depois que o array está ordenado:

    * **Para cada elemento, Busca Binária:** Para cada elemento `arr[i]` no array ordenado, podemos procurar por `arr[i] + k` no restante do array (de `arr[i+1]` até `arr[n-1]`) usando busca binária. Se encontrado, incrementamos o contador. A complexidade seria O(N log N).

---

## ⚙️ Detalhes da Implementação

* A primeira etapa é ler `n` e `k`.
* Ler os `n` números para um `std::vector`.
* Ordenar o vetor (implementando por exemplo, quicksort manualmente).
* Implementar o método de contagem de pares que utiliza de uma implementação manual de binary search.
