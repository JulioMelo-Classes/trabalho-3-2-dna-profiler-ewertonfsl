## Como compilar o projeto (em ambiente Linux)
1. Pelo terminal, vá até a pasta do projeto, por exemplo:
```
cd Downloads/trabalho-3-2-autocomplete-ewertonfsl-main
```
2. Crie e entre na pasta build:
```
mkdir build
cd build
```
3. Execute os comandos do `cmake`:
```
cmake ..
cmake --build .
```
## Para executar
Você deve executar o programa da seguinte forma:
```
% ./dna_profiler -d <arquivo_dados> -s <arquivo_sequencia_dna>
```
Onde os argumentos são:

```
        <arquivo_dados> O arquivo de banco de dados com perfis de DNA.
        <arquivo_sequencia_dna> O arquivo de sequência de DNA a ser analisado.
```

Os arquivos da base de dados e dos segmentos de DNA estão disponíveis [aqui](data).

## Testes

Foram implementados métodos de validação que podem ser testados da seguinte forma:

Validação de argumentos:
```
./dna_profiler argumentos_faltando
```

Validação de diretivas:
```
./dna_profiler -j ../data/data.csv -s ../data/sequence_bob.txt
./dna_profiler -d ../data/data.csv -k ../data/sequence_bob.txt
```

Validação de arquivos:
```
./dna_profiler -d data_inexistente.csv -s ../data/sequence_alice.txt
./dna_profiler -d ../data/data.csv -s sequencia_inexistente.txt
```

Esses exemplos de testes também podem ser encontrados [aqui](data/testes.txt).

# Avaliação

1. Ler e validar os argumentos da linha de comando | 10 / 10
- ok

2. Ler e validar os dados da base de dados e armazená-los em uma classe apropriada | 5 / 10
- vou considerar 50%, pois sua base de dados não suporta mais de 3 diferentes strs.

3. Separar a interface textual das demais classes do sistema concentrando os couts e cins em um único objeto | 10 / 10
- muito boa implementação da interface!

4. Implementação de uma classe para armazenar e validar o DNA de um indivíduo bem como realizar as operações de perfil | 5 / 10
- Vou considerar apenas metade uma vez que seu algoritmo apenas encontra o primeiro conjunto de strs

5. Implementação eficiente através do uso de referencias, quando você  julgar necessário | 10 / 10
- acabou não sendo aplicável

## Demais quesitos (Critério | Peso)

1. Organização do código em src, include, data | 5 / 5

2. Documentação do código usando o padrão doxygen | 5 / 5

3. Implementação e documentação de arquivos de teste | 10 / 15
- Faltou o caso de teste com diferentes strs (mais que 3)