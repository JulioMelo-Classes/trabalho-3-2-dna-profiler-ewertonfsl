#ifndef INTERFACE_USUARIO
#define INTERFACE_USUARIO

#include <string>

class InterfaceUsuario
{
    private:

    public:
        /**
         * Constructor.
         */
        InterfaceUsuario();
        
        /**
         * Imprime a mensagem de leitura de arquivos. 
         * @param arquivo_1 um arquivo de banco de dados ou sequência.
         * @param arquivo_2 um arquivo de banco de dados ou sequência.
         */
        void leArquivos( std::string arquivo_1, std::string arquivo_2 );

        /**
         * Imprime a mensagem de validação de argumentos.
         */
        void erroArgumentos();

        /**
         * Imprime a mensagem de erro em arquivos inseridos.
         * @param arquivo um arquivo inserido na linha de comando.
         */
        void erroArquivo( std::string arquivo );

        /**
         * Imprime a mensagem de processamento de arquivos. 
         */
        void processaArquivos();

        /**
         * Imprime a mensagem de sucesso na leitura de arquivos. 
         * @param arquivo um arquivo inserido na linha de comando.
         */
        void confirmaProcessamento( std::string arquivo );
        
        /**
         * Imprime a mensagem de processamento de arquivos.
         */
        void processaDados();

        /**
         * Imprime mensagem de correspondência encontrada. 
         * @param pessoa um perfil do banco de dados correspondente com a sequência inserida.
         */
        void corresponde( std::string pessoa );

        /**
         * Exibe o perfil de DNA encontrado.
         * @param AGAT Short Tandem Repeats (STR).
         * @param AATG Short Tandem Repeats (STR).
         * @param TATC Short Tandem Repeats (STR).
         */
        void perfil( int AGAT, int AATG, int TATC );

        /**
         * Imprime mensagem de correspondência não encontrada. 
         */
        void naoCorresponde();
};

#endif