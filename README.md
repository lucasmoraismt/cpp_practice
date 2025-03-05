# Praticando C++

Repositório para armazenar exercícios desenvolvidos durante a disciplina de EDOO (Estrutura de Dados Orientada a Objetos) no CIn - UFPE em 2024.2.

## 📌 Objetivo

Cada lista de exercícios foca em conceitos fundamentais de estruturas de dados e algoritmos.

### 🔹 Lista 01

O objetivo desta primeira lista de exercícios foi implementar manualmente classes das seguintes estruturas de dados:

- ✔ Listas encadeadas (simplesmente e duplamente encadeadas)
- ✔ Pilhas
- ✔ Filas

Cada estrutura foi utilizada na resolução de diferentes desafios de programação.

#### ⚠ Observação: O repositório será atualizado com novas listas de exercícios, cada uma com seus objetivos específicos.

### 📂 Estrutura do Repositório

Os exercícios estão organizados em pastas, conforme a lista de exercícios à qual pertencem:

```
│list_01/
│-- exerciseName/
│   │-- exerciseName.cpp
│   │-- input.txt
│   │-- README.md
```

Cada pasta de exercício contém:

- Um arquivo .cpp com a implementação do desafio.
- Um arquivo input.txt com um caso de teste de exemplo para rodar a solução.
- Um arquivo README.md com a descrição do problema.

### ▶ Como Rodar os Testes

Para testar a solução de um exercício, compile e execute o código redirecionando o arquivo input.txt como entrada:

```bash
cd list_XX/exercicio
g++ exercicio.cpp -o run && ./run < input.txt
```

Por exemplo, para rodar o exercício Tea Queue:

```bash
cd list_01/teaQueue
g++ teaQueue.cpp -o run && ./run < input.txt
```

### 📌 Expansão do Repositório

Novas listas de exercícios serão adicionadas ao longo do curso, cada uma com objetivos e desafios distintos. O README será atualizado para refletir essas novas adições.
