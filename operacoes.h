#ifndef OPERACOES_H
#define OPERACOES_H

#include <fstream>
#include <iostream> 
#include <cstdlib> 
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
        std::fstream visualizarConta(unsigned int numero, int op);

    private:
        std::fstream contas;
};

#endif