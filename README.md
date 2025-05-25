# Praticando C++

Bem-vindo ao meu repositório de práticas em C++! Este espaço é dedicado ao armazenamento e documentação dos exercícios de programação desenvolvidos durante minhas disciplinas no **Centro de Informática (CIn) da UFPE**, como **Estrutura de Dados Orientada a Objetos (EDOO)** (cursada em 2024.2) e **Algoritmos** (2025.1).

## 🎯 Objetivo Principal

Este repositório tem como finalidade:

* Consolidar o aprendizado prático em C++.
* Aprofundar o conhecimento sobre **estruturas de dados**, seus funcionamentos internos e aplicações (foco de EDOO).
* Desenvolver habilidades no **projeto e análise de algoritmos**, com ênfase em eficiência, complexidade e técnicas de resolução de problemas (foco de Algoritmos).
* Manter um registro do meu progresso e das soluções implementadas.

## 📚 Disciplinas e Abordagens

O repositório está organizado em seções principais correspondentes às disciplinas, cada uma com suas particularidades e objetivos de aprendizado:

### 🐘 /edoo (Estrutura de Dados Orientada a Objetos)

Nesta seção, você encontrará os exercícios da disciplina de EDOO, onde o foco principal é a compreensão profunda e a implementação manual das estruturas de dados fundamentais.

* **Objetivos de Aprendizagem:**
  * Implementar manualmente estruturas como listas (simplesmente e duplamente encadeadas), pilhas, filas, tabelas hash (com tratamento de colisão) e árvores binárias de busca (BST), incluindo seus percursos e operações.
  * Aplicar conceitos de Programação Orientada a Objetos (POO) na modelagem dessas estruturas.
  * Analisar a complexidade (tempo e espaço) das operações implementadas.
* **Restrições de Implementação (Disciplina EDOO):**
  * **Proibido** o uso de containers ou estruturas de dados prontas da Standard Template Library (STL) do C++, como `std::vector`, `std::list`, `std::map`, `std::stack`, `std::queue`, `std::unordered_map`, etc. O objetivo é construir tudo "do zero".
  * As soluções devem ser implementadas utilizando classes, com devida atenção aos encapsulamentos (campos privados, métodos públicos).
  * Uso restrito de bibliotecas auxiliares (ex: `<algorithm>` geralmente não é permitido para funções que simplifiquem a lógica central da estrutura de dados).

### 🧠 /algoritmos

Esta seção contém os desafios da disciplina de Algoritmos, focada no projeto, eficiência e aplicação de diversas técnicas algorítmicas.

* **Objetivos de Aprendizagem:**
  * Resolver problemas utilizando algoritmos eficientes.
  * Praticar diferentes paradigmas de algoritmos (ex: divisão e conquista, algoritmos gulosos, programação dinâmica, etc.).
  * Analisar a complexidade das soluções propostas.
* **Restrições e Flexibilizações (Disciplina Algoritmos):**
  * Geralmente, **não é necessário** reimplementar estruturas de dados básicas (como listas dinâmicas) do zero, podendo-se utilizar `std::vector` e outras utilidades da STL.
  * O uso de bibliotecas padrão do C++ como `<vector>`, `<string>`, `<iostream>`, `<algorithm>` (para funções como `std::min`, `std::max`, `std::abs`, etc.) é **permitido e encorajado**, *exceto* nos casos em que o exercício visa especificamente treinar a implementação manual de um algoritmo que a biblioteca já oferece.
    * **Exemplo:** Em listas focadas em algoritmos de ordenação (Mergesort, Quicksort) ou busca (Busca Binária), não se deve utilizar `std::sort`, `qsort()`, ou `std::binary_search` diretamente para resolver o núcleo do problema.
    * No entanto, em um problema sobre, digamos, algoritmos gulosos onde uma ordenação é apenas um passo preliminar, o uso de `std::sort` pode ser aceitável. Sempre verifique o objetivo principal do exercício.

## 📂 Estrutura do Repositório

Os exercícios estão organizados da seguinte forma, refletindo a separação por disciplina e, em seguida, por lista de exercícios:

```txt
cpp_practice/
├── algoritmos/
│  └── list_XX/            # Ex: list_01, list_02, ...
│    └── nomeDoDesafio/    # Pasta com o nome do desafio específico
│      ├── main.cpp        # Código fonte da solução
│      ├── input.txt       # Exemplo de entrada para testes locais
│      └── README.md       # Descrição do problema
│
├── edoo/
│  └── list_XX/            # Ex: list_01, list_02, ...
│    └── nomeDoDesafio/    # Pasta com o nome do desafio específico
│      ├── main.cpp        # Código fonte da solução
│      ├── input.txt       # Exemplo de entrada para testes locais
│      └── README.md       # Descrição do problema
```

Cada pasta de um desafio específico (`nomeDoDesafio/`) idealmente contém:

* Um arquivo `main.cpp`: A implementação da solução em C++.
* Um arquivo `input.txt`: Um exemplo de entrada para facilitar testes locais via redirecionamento de terminal (se aplicável).
* Um arquivo `README.md`: Contendo o enunciado do problema, formato de entrada/saída e exemplos (pode ser uma cópia do enunciado original do desafio, se o problema for de algum juiz online).

## ▶ Como Rodar os Testes

Para compilar e executar a solução de um exercício específico, navegue até a pasta do desafio e utilize os seguintes comandos como exemplo. Assumindo que você tem um compilador C++ como o g++ instalado:

1. **Navegue até a pasta do desafio:**

  ```bash
  # Exemplo para um desafio de EDOO
  cd edoo/list_01/NomeDoDesafioEDOO
  ```

  ```bash
  # Ou para um desafio de Algoritmos
  cd algoritmos/list_01/NomeDoDesafioAlgoritmos
  ```

2. **Compile e execute:**

  * Se houver um arquivo `input.txt` para o desafio e o programa lê da entrada padrão:

    ```bash
    g++ main.cpp -o solucao && ./solucao < input.txt
    ```

  * Se o programa for interativo ou não usar redirecionamento de arquivo:

    ```bash
    g++ main.cpp -o solucao && ./solucao
    ```

  (Substitua `solucao` pelo nome que preferir para o executável).

## 🚀 Expansão do Repositório

Novas listas de exercícios e soluções serão adicionadas conforme avanço nas disciplinas e pratico novos desafios.

🔄 O `README.md` principal será atualizado conforme necessário para refletir a evolução e organização do repositório.