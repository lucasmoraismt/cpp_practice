# Problem A: Maximise The Score

## 📝 Enunciado do Problema

Existem <span class="math-inline">2n</span> inteiros positivos escritos em um quadro branco. Entediado, você decidiu jogar um jogo de um jogador com os números no quadro.

Você começa com uma pontuação de 0. Você aumentará sua pontuação realizando o seguinte movimento exatamente <span class="math-inline">n</span> vezes:

1. Escolha dois inteiros <span class="math-inline">x</span> e <span class="math-inline">y</span> que estão escritos no quadro branco.
2. Adicione <span class="math-inline">min\(x, y\)</span> à sua pontuação.
3. Apague <span class="math-inline">x</span> e <span class="math-inline">y</span> do quadro branco.

Note que após realizar o movimento <span class="math-inline">n</span> vezes, não haverá mais inteiros escritos no quadro branco.
Encontre a pontuação final máxima que você pode alcançar se realizar os <span class="math-inline">n</span> movimentos de forma ótima.

---

## 📥 Formato da Entrada

Cada teste contém múltiplos casos de teste. A primeira linha contém um único inteiro <span class="math-inline">t</span> (<span class="math-inline">1 \\le t \\le 5000</span>) — o número de casos de teste. A descrição dos casos de teste segue.

A primeira linha de cada caso de teste contém um único inteiro <span class="math-inline">n</span> (<span class="math-inline">1 \\le n \\le 50</span>) — o número de inteiros escritos no quadro branco é <span class="math-inline">2n</span>.
A segunda linha de cada caso de teste contém <span class="math-inline">2n</span> inteiros <span class="math-inline">a\_1, a\_2, \\dots, a\_\{2n\}</span> (<span class="math-inline">1 \\le a\_i \\le 10^7</span>) — os números escritos no quadro branco.

```text
t
n
a1 a2 ... a2n
n
b1 b2 ... b2n
... (mais t casos de teste)
```

---

## 📤 Formato da Saída

Para cada caso de teste, imprima um único inteiro informando a pontuação final máxima que você pode alcançar.

```text
resultado_caso1
resultado_caso2
...
```

---

## (Exemplos)

**Entrada:**

```text
3
1
2 3
2
1 1 2 1
3
1 1 1 1 1 1
```

**Saída:**

```text
2
2
3
```

---

## 💡 Nota sobre os Exemplos

* **Primeiro caso de teste:** Você só pode fazer um movimento. Você seleciona <span class="math-inline">x\=2</span> e <span class="math-inline">y\=3</span>, e sua pontuação será <span class="math-inline">min\(x, y\) \= 2</span>.
* **Segundo caso de teste:** A seguinte sequência de movimentos alcança uma pontuação final de 2:
    1.  No primeiro movimento, selecione <span class="math-inline">x \= 1</span> e <span class="math-inline">y \= 1</span>. Adicione <span class="math-inline">min\(x, y\) \= 1</span> à pontuação. Restam no quadro: <span class="math-inline">1, 2</span>.
    2.  No segundo movimento, selecione <span class="math-inline">x \= 1</span> e <span class="math-inline">y \= 2</span>. Adicione <span class="math-inline">min\(x, y\) \= 1</span> à pontuação. Nenhum inteiro resta.
    Pode-se provar que não é possível obter uma pontuação maior que 2.
* **Terceiro caso de teste:** Você realizará o movimento três vezes, adicionando 1 à pontuação a cada vez.

---

## 🧠 Raciocínio da Solução (Spoiler Alert!)

Para maximizar a soma dos mínimos de cada par, a intuição sugere que devemos tentar "sacrificar" os menores números possíveis em cada par para que o valor adicionado à pontuação (<span class="math-inline">min\(x,y\)</span>) seja o maior possível entre as opções.

Se ordenarmos todos os <span class="math-inline">2n</span> números em ordem crescente, <span class="math-inline">a\_1 \\le a\_2 \\le \\dots \\le a\_\{2n\}</span>:
Ao formar pares <span class="math-inline">\(x,y\)</span> e pegar <span class="math-inline">min\(x,y\)</span>, para maximizar a soma desses mínimos, queremos que os valores de <span class="math-inline">min\(x,y\)</span> sejam os maiores possíveis.

Considerando a lista ordenada: <span class="math-inline">a\_1, a\_2, a\_3, a\_4, \\dots, a\_\{2n\-1\}, a\_\{2n\}</span>.
Se pegarmos o par <span class="math-inline">\(a\_1, a\_2\)</span>, o <span class="math-inline">min\(a\_1, a\_2\) \= a\_1</span>.
Se pegarmos o par <span class="math-inline">\(a\_1, a\_\{2n\}\)</span>, o <span class="math-inline">min\(a\_1, a\_\{2n\}\) \= a\_1</span>.

Parece que, não importa com quem <span class="math-inline">a\_1</span> (o menor de todos) forme par, o valor adicionado por esse par será <span class="math-inline">a\_1</span>. Para maximizar o restante, devemos então tentar fazer com que <span class="math-inline">a\_1</span> forme par com um número que "não fará muita falta" para os outros mínimos, ou seja, um número que não seja ele mesmo um mínimo desejável em outro par.

A estratégia ótima é ordenar os <span class="math-inline">2n</span> números e, em seguida, formar <span class="math-inline">n</span> pares pegando os elementos alternados: <span class="math-inline">\(a\_1, a\_2\), \(a\_3, a\_4\), \\dots, \(a\_\{2n\-1\}, a\_\{2n\}\)</span>.
O mínimo de cada um desses pares será <span class="math-inline">a\_1, a\_3, \\dots, a\_\{2n\-1\}</span>.
A soma total será <span class="math-inline">a\_1 \+ a\_3 \+ \\dots \+ a\_\{2n\-1\}</span>.

**Por quê?**
Qualquer outro pareamento envolveria usar um <span class="math-inline">a\_\{2k\}</span> como o mínimo de um par. Mas <span class="math-inline">a\_\{2k\}</span> é sempre maior ou igual a <span class="math-inline">a\_\{2k\-1\}</span>. Se <span class="math-inline">a\_\{2k\}</span> for usado como <span class="math-inline">min\(x,y\)</span>, então <span class="math-inline">y</span> teria que ser <span class="math-inline">\\ge a\_\{2k\}</span>. Se, em vez disso, <span class="math-inline">a\_\{2k\-1\}</span> for usado como <span class="math-inline">min\(a\_\{2k\-1\}, a\_\{2k\}\)</span>, obtemos <span class="math-inline">a\_\{2k\-1\}</span>.
A soma dos elementos nas posições ímpares (0-indexado: <span class="math-inline">a\_0, a\_2, a\_4, \\dots</span>) da lista ordenada dá a pontuação máxima.

**Exemplo 1:** `2 3` -> ordenado `2 3`. Pares: `(2,3)`. Mínimo: 2. Soma: 2.
**Exemplo 2:** `1 1 2 1` -> ordenado `1 1 1 2`. Pares: `(1,1), (1,2)`. Mínimos: 1, 1. Soma: 2.
**Exemplo 3:** `1 1 1 1 1 1` -> ordenado `1 1 1 1 1 1`. Pares: `(1,1), (1,1), (1,1)`. Mínimos: 1, 1, 1. Soma: 3.

A solução, portanto, envolve:

1. Ler os <span class="math-inline">2n</span> números.
2. Ordená-los.
3. Somar os elementos nas posições de índice par (0, 2, 4, ..., 2n-2).
