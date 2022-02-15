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
