#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

#include <string>

/**
 * Classe do objeto ContaBancaria, contendo como atributos: Nome, Saldo e Número, além das funções que 
auxiliam no funcionamento da Classe Operacoes 
 * @author Jordeva Lucas
 */

class ContaBancaria {
    private:
        std::string nome_;
        unsigned int numero_;
        double saldo_;

    public:
        ContaBancaria();
        
        void setNome(std::string nome);
        void setNumero(unsigned int numero);
        void setSaldo(double saldo);
        std::string getNome();
        unsigned int getNumero();
        double getSaldo();
};

#endif