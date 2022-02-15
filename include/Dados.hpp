#ifndef DADOS_H
#define DADOS_H


#include <iostream>
#include <vector>

class Dados
{
  private:
    std::vector<std::string> dados_dna; //<! Informações de perfis de DNA recebidas.
    std::string sequencia_dna; //<! Sequência recebida.

    std::string pessoa; //<! Um perfil do banco de dados correspondente com a sequência inserida.
    int res_AGAT; //<! Contagem de STR do tipo AGAT.
    int res_AATG; //<! Contagem de STR do tipo AATG.
    int res_TATC; //<! Contagem de STR do tipo TATC.

    std::string resultado_str; //<! Resultado da contagem de STRs inseridos em uma única string.

  public:

    /**
     * Constructors.
     */    
    Dados( std::string arquivo_1, std::string arquivo_2 );
    Dados( std::string tipo_1, std::string arquivo_1, std::string tipo_2, std::string arquivo_2 );

};

#endif