#ifndef LISTAPEDIDO_H
#define LISTAPEDIDO_H
#include "Pedido.h"

using namespace std;

class ListaPedido
{
private:
	Pedido* cabeca;
	Pedido* cauda;

public:

	ListaPedido();
	ListaPedido(int num_pedido,string dataPedido, Vendedor vendedor, Cliente cliente, string observacoes);

	Pedido* getCabeca();
	void setCabeca(Pedido* cabeca);

	void mostrar(int cpf);

	void mostrar_vendedor(int matricula);

	bool vazia();

	void inserir_inicio(Pedido p);

	// insere no final (semelhante a push_back da list)
	void inserir_final(Pedido p);

	int size();

	bool existe(int num_pedido);

	int remover(int num_pedido);

	bool verificaPedido_Cliente(int cpf);
	bool verificaPedido_Vendedor(int cpf);

	int removerPedido_Cliente(int cpf);
	int removerPedido_Vendedor(int cpf);

};
#endif
