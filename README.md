# Praticando C++

Repositório para armazenar exercícios desenvolvidos durante a disciplina de **EDOO (Estrutura de Dados Orientada a Objetos)** no **CIn - UFPE** em 2024.2.

## 🎯 Objetivo

Este repositório tem como objetivo consolidar conhecimentos sobre **estruturas de dados e algoritmos**, através da implementação manual de conceitos fundamentais abordados em sala de aula.

## 📚 Listas de Exercícios

Cada lista de exercícios foca em um conjunto específico de estruturas de dados e desafios computacionais.

### 🔹 Lista 01 - Estruturas Básicas

O objetivo desta primeira lista foi implementar manualmente classes das seguintes **estruturas de dados**:

- ✔ **Listas** (simplesmente e duplamente encadeadas)
- ✔ **Pilhas**
- ✔ **Filas**

Cada estrutura foi utilizada na resolução de diferentes desafios de programação.

### 🔹 Lista 02 - Tabelas Hash e Árvores Binárias

Nesta lista, foram implementadas **estruturas mais avançadas**, incluindo:

- ✔ **Tabelas Hash** com tratamento de colisão
- ✔ **Árvores Binárias de Busca (BST)** e seus percursos

### 🔹 Lista 03 - Exercícios avançacos

Nesta lista, foram explorados problemas mais específicos utilizando **hash tables e pilhas**, incluindo:

- ✔ **Otimização de tempo e espaço** através de análises de complexidade

⚠ **Observação**: O repositório será atualizado com novas listas de exercícios conforme avançamos na disciplina.

## 📂 Estrutura do Repositório

Os exercícios estão organizados em pastas, conforme a lista de exercícios à qual pertencem:

```txt
│list_01/
│-- exerciseName/
│   │-- exerciseName.cpp
│   │-- input.txt
│   │-- README.md
│
│list_02/
│-- exerciseName/
│   │-- exerciseName.cpp
│   │-- input.txt
│   │-- README.md
.
.
.
```

Cada pasta de exercício contém:

- Um arquivo **.cpp** com a implementação do desafio.
- Um arquivo **input.txt** com um caso de teste de exemplo para rodar a solução.
- Um arquivo **README.md** com a descrição do problema, formato de entrada/saída e exemplo de uso.

## ▶ Como Rodar os Testes

Para testar a solução de um exercício, compile e execute o código redirecionando o arquivo **input.txt** como entrada:

```bash
cd list_XX/exercicio
g++ exercicio.cpp -o run && ./run < input.txt
```

Por exemplo, para rodar o exercício **Tea Queue**:

```bash
cd list_01/teaQueue
g++ teaQueue.cpp -o run && ./run < input.txt
```

## 🚀 Expansão do Repositório

Novas listas de exercícios serão adicionadas ao longo do curso, abrangendo mais estruturas complexas, algoritmos de ordenação e busca, e desafios de programação.

🔄 O **README** será atualizado conforme novas listas forem incluídas.
