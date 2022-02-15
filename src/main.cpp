#include "../include/Dados.hpp"
#include "../include/InterfaceUsuario.hpp"

using namespace std;


int main( int argc, char *argv[] ) 
{
  if( argc < 5 )
  {
    cout << endl << "Poucos argumentos..." << endl << endl;
    cout << "Uso: dna_profiler -d <arquivo_dados> -s <arquivo_sequencia_dna>" << endl;
    cout << "  Onde os argumentos são:" << endl;
    cout << "    <arquivo_dados> O arquivo de banco de dados com perfis de DNA." << endl;
    cout << "    <arquivo_sequencia_dna> O arquivo de sequência de DNA a ser analisado." << endl << endl;

    exit(1);
  }

  InterfaceUsuario ui();
  Dados entrada( argv[1], argv[2], argv[3], argv[4] );

  return 0;
}