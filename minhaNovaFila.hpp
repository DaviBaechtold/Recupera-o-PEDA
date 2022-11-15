#pragma once

#include <string>
#include "registro.hpp"
using namespace std;

class minhaNovaFila
{
private:
    int tamanho;
    Registro *primeiro;

public:
    minhaNovaFila();
    minhaNovaFila(Registro *p);
    virtual ~minhaNovaFila();

    void incluir(int numero, string mensagem) throw();
    void excluir(Registro *n);
    void removerPrimeiroDaFila();
    Registro *buscar(int numero);
    Registro *buscarPorPosicao(int pos);
};