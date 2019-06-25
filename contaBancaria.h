#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

#include <string>

class ContaBancaria {
    private:
        std::string nome_;
        unsigned int numero_;
        double saldo_;

    public:
        ContaBancaria(std::string nome, unsigned int numero, double saldo);
};

#endif