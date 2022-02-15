#include "../include/Dados.hpp"
#include "../include/InterfaceUsuario.hpp"

#include <fstream>
#include <cstring>
#include <sstream>

using namespace std;


/**
 * Busca STRs na sequência inserida. 
 * @param sequencia sequência de DNA a ser analisada.
 * @param padrao padrão de STR a ser encontrado: AGAT, AATG, TATC.
 * @return contagem de repetições. 
 */
int buscaSTR( string sequencia, string padrao )
{
    int tamanhoSequencia  = sequencia.length();
	int tamanhoPadrao = padrao.length();
	int contador = 0;
    int diferentes = 0;
    int j;

	for( auto i = 0; i <= tamanhoSequencia; i++ )
	{
		for( j = 0; j <= tamanhoPadrao; j++ )
		{
            /**
             * Compara as letras da sequência com as do padrão, caso sejam diferentes.
             * Caso sejam diferentes, incrementa a variável 'diferentes', que será uma condição de parada
             * mais adiante, e interrompe o laço.
             */
			if( sequencia[i + j] != padrao[j] )
            {
                diferentes++;
				break;
            }
		}

        /**
         * Caso tenha completado o laço anterior e o iterador 'j' tenha valor igual ao tamanho do padrão inserido, 
         * uma sequência foi encontrada.
         * Zera a variável 'diferentes' e incrementa a variável 'contador'.
         */
		if( j >= tamanhoPadrao )
        {
            diferentes = 0;
            contador++;
        }

        /**
         * Se o contador for maior ou igual a 1 e as diferentes maior que 4, 
         * a sequência foi interrompida. É encerrado o laço principal. 
         */
        if( (contador >= 1) and (diferentes > 4) )
            break;
	}
	
    return contador;
}


Dados::Dados( string tipo_1, string arquivo_1, string tipo_2, string arquivo_2 )
{
    InterfaceUsuario ui;
    string entrada, dados, sequencia;

    // Validação dos argumentos de entrada.
    if( tipo_1 != "-d" and tipo_1 != "-s" )
        ui.erroArgumentos();

    if( tipo_2 != "-d" and tipo_2 != "-s" )
        ui.erroArgumentos();


    ui.leArquivos( arquivo_1, arquivo_2 );

    // Atribuição dos arquivos de acordo com as diretivas.
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
        ui.processaArquivos();

        getline( arquivo, entrada ); //<! Ignora a primeira linha.
        
        while( getline(arquivo, entrada) ) 
        { dados_dna.push_back( entrada ); }
        
        ui.confirmaProcessamento( dados );
    }

    // Mensagem caso não encontre arquivo de dados.
    else
        ui.erroArquivo( dados );

    arquivo.close(); //<! Fecha o arquivo de dados.
      
    ifstream file( sequencia ); //<! Abre o arquivo de sequência.
    
    // Confere se arquivo foi aberto.
    if( file.is_open() )
    {
        getline( file, entrada );

        sequencia_dna = entrada;

        ui.confirmaProcessamento( sequencia );

        ui.processaDados();

        // Busca STRs na sequência de entrada e organiza as quantidades no formato dos valores no banco de dados.
        res_AGAT =  buscaSTR( sequencia_dna, "AGAT");
        res_AATG =  buscaSTR( sequencia_dna, "AATG");
        res_TATC =  buscaSTR( sequencia_dna, "TATC");

        resultado_str.append( to_string( res_AGAT ) + "," );
        resultado_str.append( to_string( res_AATG ) + "," );
        resultado_str.append( to_string( res_TATC ) );

        // Percorre o vetor de banco de dados.  
        for( auto i = 0; i < dados_dna.size(); i++ )
        {   
            // Inicializa a variável posicao como o resultado da subtração entre o comprimentos das linhas do banco de dados e do resultado.
            int posicao = dados_dna.at(i).length() - resultado_str.length();
            
            // Se o resultado for substring do dado buscado, existe correspondência.
            if( dados_dna.at(i).substr( posicao, dados_dna.at(i).length() ) == resultado_str )
            {
                pessoa = dados_dna.at(i).substr( 0, posicao - 1 );
                ui.corresponde( pessoa );

                ui.perfil( res_AGAT, res_AATG, res_TATC );
            }
        }
        
        // Caso percorra todo o vetor de dados e não encontre correspondência.
        ui.naoCorresponde();
    }

    // Mensagem caso não encontre arquivo de sequência.
    else
        ui.erroArquivo( sequencia );

    file.close(); //<! Fecha o arquivo de sequência.
}