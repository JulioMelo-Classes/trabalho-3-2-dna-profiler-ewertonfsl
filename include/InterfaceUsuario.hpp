#ifndef INTERFACE_USUARIO
#define INTERFACE_USUARIO

#include <string>

class InterfaceUsuario
{
    private:

    public:
        InterfaceUsuario();
        void leArquivos( std::string arquivo_1, std::string arquivo_2 );
        void validaArgumentos();
        void validaArquivo( std::string arquivo );
        void processaDados();
        void confirmaProcessamento( std::string arquivo );
        //void busca();
};

#endif