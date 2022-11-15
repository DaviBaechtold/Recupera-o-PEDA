/*
Davi Baechtold Campos
*/

#include "minhaNovaFila.hpp"
#include "mt19937.hpp"
#include "randomString.hpp"
#include <bits/stdc++.h>
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
  ofstream outFile;

  outFile.open("resultado.txt");

  if (!outFile) {
    cout << "erro test.txt" << endl;
    abort();
  }

  int aleatorioUm, aleatorioDois;
  minhaNovaFila *fila = new minhaNovaFila();

  // Gerando 2 números aleatórios para buscar futuramente
  aleatorioUm = (rand() % 100);
  aleatorioDois = (rand() % 100);

  while (aleatorioUm == aleatorioDois) {
    aleatorioDois = (rand() % 100);
  }

  // Mersenne Twister para gerar os números
  // OBS: implementei esse algoritmo de forma local
  MT19937 mt(time(NULL));
  int numero;
  string mensagem;
  Registro *r1 = new Registro();
  Registro *r2 = new Registro();

  // Looping para gerar os registros
  for (int i = 0; i < 100; i++) {
    // mt.random utiliza o mt implementado por mim.
    numero = mt.random();

    // random_string é baseado no Mersenne Twister, porém,
    // utiliza o mt existente na linguagem c++
    mensagem = random_string(100);

    // Inclui o novo registro na fila
    fila->incluir(numero, mensagem);

    // Se o registro for o número igual ao escolhido, guardamos o resultado
    if (i == aleatorioUm) {
      r1 = fila->buscar(numero);
    }

    if (i == aleatorioDois) {
      r2 = fila->buscar(numero);
    }
  }
  Registro *aux = new Registro();

  for (int i = 0; i < 25; i++) {
    for (int j = 0; j < 4; j++) {
      aux = fila->buscarPorPosicao((j + 1) * (i + 1) - 1);
      outFile << aux->getNumero() << ", " << aux->getMensagem() << " | ";
    }

    outFile << endl;
  }

  outFile << endl;

  cout << "Iniciando busca dos registros" << endl;
  double tempo;

  auto inicio = chrono::high_resolution_clock::now();
  ios_base::sync_with_stdio(false);
  aux = fila->buscar(r1->getNumero());
  auto fim = chrono::high_resolution_clock::now();

  tempo = chrono::duration_cast<chrono::nanoseconds>(fim - inicio).count();
  tempo *= 1e-9;

  outFile << "O programa levou : " << fixed << tempo << setprecision(9);
  outFile << " segundos para encontrar o registro 1 " << endl;

  inicio = chrono::high_resolution_clock::now();
  ios_base::sync_with_stdio(false);
  aux = fila->buscar(r2->getNumero());
  fim = chrono::high_resolution_clock::now();

  tempo = chrono::duration_cast<chrono::nanoseconds>(fim - inicio).count();
  tempo *= 1e-9;

  outFile << "O programa levou : " << fixed << tempo << setprecision(9);
  outFile << " segundos para encontrar o registro 2 " << endl;

  cout << "Iniciando remoção de 20% da lista" << endl;

  inicio = chrono::high_resolution_clock::now();
  ios_base::sync_with_stdio(false);

  for (int i = 0; i < 20; i++) {
    double t;
    auto ini = chrono::high_resolution_clock::now();

    fila->removerPrimeiroDaFila();

    auto f = chrono::high_resolution_clock::now();

    t = chrono::duration_cast<chrono::nanoseconds>(f - ini).count();
    t *= 1e-9;

    outFile << "O programa levou : " << fixed << t << setprecision(9);
    outFile << " segundos para remover o registro número " << i + 1 << endl;
  }

  fim = chrono::high_resolution_clock::now();

  tempo = chrono::duration_cast<chrono::nanoseconds>(fim - inicio).count();
  tempo *= 1e-9;

  outFile << "O programa levou : " << fixed << tempo << setprecision(9);
  outFile << " segundos para remover 20% (20) dos registros" << endl;

  outFile.close();

  return 0;
}