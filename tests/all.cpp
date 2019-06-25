#define CATCH_CONFIG_MAIN  // Faz com o que o catch gere o main
#include "catch.hpp"
#include "ContaBancaria.h"

TEST_CASE("Exemplo de Teste com Sucesso", "[exemplo]") {
    REQUIRE(1 == 1);
}

TEST_CASE("Exemplo de Teste com erro", "[exemplo]") {
    REQUIRE(1 == 2);
}
