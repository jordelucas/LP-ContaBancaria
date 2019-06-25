#include "contaBancaria.h"

/**
 * Implementa método construtor, onde os atributos da conta bancária são inicializados com valores default
 */
ContaBancaria::ContaBancaria() 
    : nome_(""), numero_(0), saldo_(0.0) {}

/**
 * Altera o valor do atributo numero_ 
 */
void ContaBancaria::setNumero(unsigned int numero){
    numero_ = numero;
}

/**
 * Altera o valor do atributo nome_ 
 */
void ContaBancaria::setNome(std::string nome){
    nome_ = nome;
}

/**
 * Altera o valor do atributo saldo_ 
 */
void ContaBancaria::setSaldo(double saldo){
    saldo_ = saldo;
}

/**
 * Retorna o valor do atributo numero_ 
 */
unsigned int ContaBancaria::getNumero() {
    return numero_;
}

/**
 * Retorna o valor do atributo nome_ 
 */
std::string ContaBancaria::getNome() {
    return nome_;
}

/**
 * Retorna o valor do atributo saldo_ 
 */
double ContaBancaria::getSaldo() {
    return saldo_;
}

