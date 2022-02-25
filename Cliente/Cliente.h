#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <string>
#include "Pessoa.h"

using namespace std;

class Cliente :
    public Pessoa
{
private:

    double limiteCredito;
    Pessoa contato;
    Cliente* proxCliente;

public:

    Cliente();
    Cliente(string nome, string endereco, int telefone, string dataNasc, int cpf, double limiteCredito, Pessoa contato);

    //Gets
    double getLimiteCredito();
    Pessoa getContato();
    Cliente* getProxCliente();

    //Sets
    void setLimiteCredito(double limiteCredito);
    void setContato(Pessoa contato);
    void setProxCliente(Cliente* proxCliente);
    
};
#endif
