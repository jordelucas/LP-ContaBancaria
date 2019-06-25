#include "contaBancaria.h"

ContaBancaria::ContaBancaria() 
    : nome_(""), numero_(0), saldo_(0.0) {}

void ContaBancaria::setNumero(unsigned int numero){
    numero_ = numero;
}

void ContaBancaria::setNome(std::string nome){
    nome_ = nome;
}

void ContaBancaria::setSaldo(double saldo){
    saldo_ = saldo;
}

unsigned int ContaBancaria::getNumero() {
    return numero_;
}

std::string ContaBancaria::getNome() {
    return nome_;
}

double ContaBancaria::getSaldo() {
    return saldo_;
}

