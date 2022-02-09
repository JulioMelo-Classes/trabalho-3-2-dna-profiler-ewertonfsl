#ifndef DADOS_H
#define DADOS_H

#include <iostream>
#include <vector>

class Dados
{
  private:
    std::vector<std::string> dados_dna;
    std::string sequencia_dna;

  public:
    Dados( std::string arquivo_1, std::string arquivo_2 );
    Dados( std::string tipo_1, std::string arquivo_1, std::string tipo_2, std::string arquivo_2 );
};

#endif