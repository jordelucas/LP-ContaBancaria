#ifndef OPERACOES_H
#define OPERACOES_H

#include <fstream>
#include <iostream> 
#include "contaBancaria.h"

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
        bool verificarContas(unsigned int numero);

    private:
        std::fstream contas;
};

#endif