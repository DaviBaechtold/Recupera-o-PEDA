#include "minhaNovaFila.hpp"
#include <cstddef>
#include <iostream>
#include <fstream>
using namespace std;

minhaNovaFila::minhaNovaFila()
{
    this->primeiro = NULL;
    this->tamanho = 0;
}

minhaNovaFila::~minhaNovaFila()
{
    this->primeiro = NULL;
    this->tamanho = 0;
}

void minhaNovaFila::incluir(int numero, string mensagem) throw()
{
    Registro *n = new Registro(numero, mensagem);
  
    n->setNumero(numero);
    n->setMensagem(mensagem);

    Registro *atual = new Registro();
    Registro *prox = new Registro();

    if (this->tamanho == 0)
    {
        this->primeiro = n;
        this->tamanho++;
    }
    else
    {
        atual = this->primeiro;
        prox = atual->getProx();

        while (prox != NULL)
        {
          atual = prox;
          prox = prox->getProx();
        }

        atual->setProx(n);
        this->tamanho++;
        return;
    }

    return;
}

Registro *minhaNovaFila::buscar(int numero)
{
    Registro *aux = this->primeiro;

    if (this->tamanho != 0)
    {
        for (int i = 0; i < this->tamanho; i++)
        {
            if (aux->getNumero() == numero)
            {
                return aux;
            }
          
            if (aux->getProx() != NULL)
            {
                aux = aux->getProx();
            }
        }
    }

    return NULL;
}

Registro *minhaNovaFila::buscarPorPosicao(int pos)
{
    Registro *aux = this->primeiro;

    if (this->tamanho != 0)
    {
        for (int i = 0; i < this->tamanho; i++)
        {
            if (i == pos)
            {
                return aux;
            }
          
            if (aux->getProx() != NULL)
            {
                aux = aux->getProx();
            }
        }
    }

    return NULL;
}

void minhaNovaFila::removerPrimeiroDaFila()
{
  Registro *aux = this->primeiro;

  if (aux != NULL)
  {
    this->primeiro = this->primeiro->getProx();
    delete aux;
    this->tamanho--;
    return;
  }
}