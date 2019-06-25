#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

#include <string>

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