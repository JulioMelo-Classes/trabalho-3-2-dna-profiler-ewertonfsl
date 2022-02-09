#include <iostream>
#include <string>

#include "../include/InterfaceUsuario.hpp"

using namespace std;

InterfaceUsuario::InterfaceUsuario()
{
    cout << endl << "=================================================================" << endl;
    cout << "               Bem vindo ao DNA Profiler, v1.0" << endl;
    cout << "               Copyright (C) 2022, Ewerton Fernandes";
    cout << endl << "=================================================================" << endl << endl;

    cout << "Este programa carrega um banco de dados de DNA e uma sequência " << endl;
    cout << "de DNA desconhecida e tenta encontrar uma corresponcência entre ambos." << endl << endl;
}

void InterfaceUsuario::leArquivos( string arquivo_1, string arquivo_2 )
{
    cout << "[+] Lendo o arquivo [" << arquivo_1 << "]" << endl;
    cout << "[+] Lendo o arquivo [" << arquivo_2 << "]" << endl << endl;       
}

void InterfaceUsuario::validaArgumentos()
{
    cout << "[!] Argumento inválido..." << endl; 
    cout << "Use -d para o arquivo de banco de dados e -s para o de sequência" << endl;
    exit(1);
}

void InterfaceUsuario::validaArquivo( string arquivo )
{
    cout << "[!] Arquivo [" << arquivo << "] não existe" << endl;
    exit(1);
}

void InterfaceUsuario::processaDados() {
    cout << "[+] Processando dados, por favor aguarde..." << endl;
}
    
void InterfaceUsuario::confirmaProcessamento( string arquivo ) {
    cout << "[+] Arquivo [" << arquivo << "] lido com sucesso!" << endl << endl;
}
    
//void InterfaceUsuario::busca(){}