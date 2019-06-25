#ifndef OPERACOES_H
#define OPERACOES_H

#include <fstream>
#include <iostream> 

class Operacoes {
    public:
        Operacoes();

        void criarConta();
        void listarContas();
        void detalharConta();
        void alterarConta();
        void excluirConta();
        void tranferir();
        void depositar();
        void sacar();

    private:
        std::fstream contas;
};

#endif