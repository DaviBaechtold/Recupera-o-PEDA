#include "registro.hpp"
#include <cstddef>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Registro::Registro()
{
}

Registro::Registro(int numero, string mensagem)
{
    this->numero = numero;
    this->mensagem = mensagem;
}

Registro::~Registro()
{
    this->prox = NULL;
    this->numero = NULL;
    this->mensagem = "";
}

int Registro::getNumero()
{
    return this->numero;
}

void Registro::setNumero(int numero)
{
    this->numero = numero;
}

string Registro::getMensagem()
{
    return this->mensagem;
}

void Registro::setMensagem(string mensagem)
{
    this->mensagem = mensagem;
}

Registro *Registro::getProx()
{
    return this->prox;
}

void Registro::setProx(Registro *p)
{
    this->prox = p;
}