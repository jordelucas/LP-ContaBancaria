#define CATCH_CONFIG_MAIN  // Faz com o que o catch gere o main
#include "catch.hpp"
#include "ContaBancaria.h"
#include "Operacoes.h"

TEST_CASE("Teste para set número", "[Set]"){
    ContaBancaria c1;
    unsigned int n1 = 13;
    c1.setNumero(n1);
    REQUIRE(n1 == c1.getNumero());
}

TEST_CASE("Teste para set nome", "[Set]"){
    ContaBancaria c1;
    std::string nome = "Waldson";
    c1.setNome(nome);
    REQUIRE(nome == c1.getNome());
}

TEST_CASE("Teste para set saldo", "[Set]"){
    ContaBancaria c1;
    double saldo = 10.20;
    c1.setSaldo(saldo);
    REQUIRE(saldo == c1.getSaldo());
}

TEST_CASE("Teste para get número", "[Get]"){
    ContaBancaria c1, c2;
    unsigned int num = 10;
    c1.setNumero(num);
    c2.setNumero(num);
    num = c1.getNumero()+1;
    REQUIRE(c1.getNumero() == c2.getNumero());
}

TEST_CASE("Teste para get nome", "[Get]"){
    ContaBancaria c1, c2;
    std::string nome = "Maria";
    c1.setNome(nome);
    c2.setNome(nome);
    nome = "Marta";

    REQUIRE(c1.getNome() == c2.getNome());
}

TEST_CASE("Teste para get saldo", "[Get]"){
    ContaBancaria c1, c2;
    std::string nome = "Maria";
    c1.setNome(nome);
    c1.setNumero(10);
    c1.setSaldo(10.0);
    c2 = c1;
    REQUIRE(c2.getNome() == nome);
}