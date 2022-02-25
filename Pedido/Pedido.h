#ifndef PEDIDO_H
#define PEDIDO_H
#include <iostream>
#include <string>
#include "Cliente.h"
#include "Vendedor.h"

using namespace std;

class Pedido
{
private:

	int num_pedido;
	string dataPedido;
	Vendedor vendedor;
	Cliente cliente;
	string observacoes;
	Pedido* proxPedido;

public:
	Pedido();
	Pedido(int num_pedido, string dataPedido, Vendedor vendedor, Cliente cliente, string observacoes);

	//Gets
	int getNumPedido();
	string getDataPedido();
	Vendedor getVendedor();
	Cliente getCliente();
	string getObservacoes();
	Pedido* getProxPedido();

	//Sets
	void setNumPedido(int num_pedido);
	void setDataPedido(string dataPedido);
	void setVendedor(Vendedor vendedor);
	void setCliente(Cliente cliente);
	void setObersevacoes(string observacoes);
	void setProxPedido(Pedido* proxPedido);

};
#endif
