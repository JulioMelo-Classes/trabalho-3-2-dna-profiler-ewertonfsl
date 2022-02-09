#include "../include/Dados.hpp"
#include "../include/InterfaceUsuario.hpp"

#include <fstream>

using namespace std;

Dados::Dados( string tipo_1, string arquivo_1, string tipo_2, string arquivo_2 )
{
    InterfaceUsuario ui;
    string entrada, dados, sequencia;
    
    if( tipo_1 != "-d" and tipo_1 != "-s" )
        ui.validaArgumentos();

    if( tipo_2 != "-d" and tipo_2 != "-s" )
        ui.validaArgumentos();


    ui.leArquivos( arquivo_1, arquivo_2 );


    if( tipo_1 == "-d" )
    {
        dados = arquivo_1;
        sequencia = arquivo_2;
    }
    else
    {
        sequencia = arquivo_1;
        dados = arquivo_2;
    }


    ifstream arquivo( dados ); //<! Abre o arquivo de dados.
    
    // Confere se arquivo foi aberto.
    if( arquivo.is_open() )
    {
        ui.processaDados();

        getline( arquivo, entrada ); //<! Ignora a primeira linha.
        
        while( getline(arquivo, entrada) ) 
        { dados_dna.push_back( entrada ); }
        
        ui.confirmaProcessamento( dados );

        // Testa carregamento e armazenamento.
        for( auto i = 0; i < dados_dna.size(); i++ )
        { cout << dados_dna.at(i) << endl; }

        cout << endl;
    }

    // Mensagem caso não encontre arquivo de dados.
    else
        ui.validaArquivo( dados );

    arquivo.close(); //<! Fecha o arquivo de dados.
      
    ifstream file( sequencia ); //<! Abre o arquivo de sequência.
    
    // Confere se arquivo foi aberto.
    if( file.is_open() )
    {
        ui.processaDados();

        getline( file, entrada );

        sequencia_dna = entrada;

        ui.confirmaProcessamento( sequencia );
        
        // Testa carregamento e armazenamento.
        cout << sequencia_dna << endl << endl;
    }
    
    // Mensagem caso não encontre arquivo de sequência.
    else
        ui.validaArquivo( sequencia );

    file.close(); //<! Fecha o arquivo de dados.
}