#include "../include/Dados.hpp"
#include "../include/InterfaceUsuario.hpp"

using namespace std;

int main( int argc, char *argv[] ) 
{
  InterfaceUsuario ui();
  Dados input( argv[1], argv[2], argv[3], argv[4] );
}