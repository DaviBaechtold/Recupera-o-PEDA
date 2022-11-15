#pragma once

#include <string>
using namespace std;

class Registro
{
private:
    int numero;
    string mensagem;
    Registro *prox;

public:
    Registro();
    Registro(int numero, string mensagem);
    virtual ~Registro();

    int getNumero();
    void setNumero(int numero);

    string getMensagem();
    void setMensagem(string mensagem);

    Registro *getProx();
    void setProx(Registro *p);
};