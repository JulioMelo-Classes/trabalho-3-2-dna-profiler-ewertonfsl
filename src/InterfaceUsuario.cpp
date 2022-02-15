#include "../include/InterfaceUsuario.hpp"

#include <iostream>

// Define as configurações de cores e estilos.
#define ESC "\033[;"
#define RESET "\033[m"
#define ESC_BOLD "\033[01;"
#define BOLD "01;"
#define RESET_BOLD "\033[01;m"
#define VERMELHO "31m"
#define VERDE "32m"
#define AMARELO "33m"
#define AZUL "34m"
#define CIANO "36m"

using namespace std;

/**
 * Constructor.
 */
InterfaceUsuario::InterfaceUsuario()
{
    cout << endl << "=================================================================" << endl;
    cout << "               Bem vindo ao DNA Profiler, v1.0" << endl;
    cout << "               Copyright (C) 2022, Ewerton Fernandes";
    cout << endl << "=================================================================" << endl << endl;

    cout << ESC_BOLD << CIANO << "Este programa carrega um banco de dados de DNA e uma sequência " << endl;
    cout << "de DNA desconhecida e tenta encontrar uma corresponcência entre ambos." << RESET_BOLD << endl << endl;
}

/**
 * Imprime a mensagem de leitura de arquivos. 
 * @param arquivo_1 um arquivo de banco de dados ou sequência.
 * @param arquivo_2 um arquivo de banco de dados ou sequência.
 */
void InterfaceUsuario::leArquivos( string arquivo_1, string arquivo_2 )
{
    cout << "[+] Lendo o arquivo [" << ESC_BOLD << AZUL << arquivo_1 << RESET_BOLD << "]" << endl;
    cout << "[+] Lendo o arquivo [" << ESC_BOLD << AZUL << arquivo_2 << RESET_BOLD << "]" << endl << endl;       
}

/**
 * Imprime a mensagem de validação de argumentos.
 */
void InterfaceUsuario::erroArgumentos()
{
    cout << ESC_BOLD << VERMELHO << "[!] Argumento inválido..." << RESET_BOLD << endl; 
    cout << "Use -d para o arquivo de banco de dados e -s para o de sequência" << endl << endl;
    exit(1);
}

/**
 * Imprime a mensagem de erro em arquivos inseridos.
 * @param arquivo um arquivo inserido na linha de comando.
 */
void InterfaceUsuario::erroArquivo( string arquivo )
{
    cout << ESC << VERMELHO << "[!] Arquivo [" << ESC_BOLD << VERMELHO << arquivo << RESET_BOLD;
    cout << ESC << VERMELHO << "] não existe" << RESET << endl << endl;
    exit(1);
}

/**
 * Imprime a mensagem de processamento de arquivos. 
 */
void InterfaceUsuario::processaArquivos() {
    cout << "[+] Processando arquivos, por favor aguarde..." << endl;
}

/**
 * Imprime a mensagem de sucesso na leitura de arquivos. 
 * @param arquivo um arquivo inserido na linha de comando.
 */
void InterfaceUsuario::confirmaProcessamento( string arquivo ) 
{
    cout << ESC << VERDE << "[+] Arquivo [" << ESC_BOLD << VERDE << arquivo << RESET_BOLD;
    cout << ESC << VERDE << "] lido com sucesso!" << RESET << endl;
}

/**
 * Imprime a mensagem de processamento de arquivos.
 */
void InterfaceUsuario::processaDados() {
    cout << endl << "[+] Procurando por uma correspondência no banco de dados..." << endl << endl << endl;
}

/**
 * Imprime mensagem de correspondência encontrada. 
 * @param pessoa um perfil do banco de dados correspondente com a sequência inserida.
 */
void InterfaceUsuario::corresponde( string pessoa )
{
    cout << "Correspondência encontrada: " << pessoa << endl;   
}

/**
 * Exibe o perfil de DNA encontrado.
 * @param AGAT Short Tandem Repeats (STR).
 * @param AATG Short Tandem Repeats (STR).
 * @param TATC Short Tandem Repeats (STR).
 */
void InterfaceUsuario::perfil( int AGAT, int AATG, int TATC )
{
    cout << "Perfil de DNA:" << endl << endl;
    cout << "       AGAT [x" << AGAT << "]      ";
    cout << "       AATG [x" << AATG << "]      ";
    cout << "       TATC [x" << TATC << "]      " << endl << endl;
    exit(0);  
}

/**
 * Imprime mensagem de correspondência não encontrada. 
 */
void InterfaceUsuario::naoCorresponde()
{
    cout << "Nenhum resultado encontrado no banco de dados." << endl << endl;
    exit(1);    
}
