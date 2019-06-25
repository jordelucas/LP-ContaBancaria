#ifndef OPERACOES_H
#define OPERACOES_H

#include <fstream>
#include <iostream> 
#include <cstdlib> 
#include "contaBancaria.h"

/**
 * Classe com funções que simulam as operações realizadas no banco  
 * @author Jordeva Lucas
 */

class Operacoes {
    public:
        Operacoes();
        void criarConta();
        void listarContas();  
        unsigned int detalharConta();
        void alterarConta();
        void excluirConta();
        void tranferir();
        void depositar();
        void sacar();
        bool verificarContas(unsigned int numero);
        std::fstream visualizarConta(unsigned int numero, int op);
        void carrecarConta(ContaBancaria * conta, unsigned int numero);

    private:
        std::fstream contas;
};

#endif