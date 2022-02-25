#include "ListaPedido.h"
#include <iostream>

using namespace std;

ListaPedido::ListaPedido()
{
	// se não passar elemento, então cabeca e cauda são NULL
	cabeca = NULL;
	cauda = NULL;
}

Pedido* ListaPedido::getCabeca() {
	return this->cabeca;
}
void ListaPedido::setCabeca(Pedido* cabeca) {
	this->cabeca = cabeca;
}

ListaPedido::ListaPedido(int num_pedido,string dataPedido, Vendedor vendedor, Cliente cliente, string observacoes)
{
	// se passar elemento, então cria novo No
	cabeca = new Pedido(num_pedido, dataPedido, vendedor, cliente, observacoes);
	cauda = cabeca;
}

// mostra todos os elementos da lista
void ListaPedido::mostrar(int cpf)
{
	int i = 0;
	Pedido* c = cabeca;

	if (vazia())
		cout << "ERRO: A lista não possui pedidos!\n";
	else
	{
		cout << "\n|| Impressão de pedidos ||\n";
		while (c) // percorre a lista
		{
			if (c->getCliente().getCpf() == cpf) {
				cout << "\nPEDIDO " << i + 1 << endl;
				i++;
				cout << "Número de identificação do pedido: " << c->getNumPedido() << endl;
				cout << "Vendedor: " << c->getVendedor().getNome() << endl;
				cout << "Data do pedido: " << c->getDataPedido() << endl;
				cout << "Observações: " << c->getObservacoes() << endl;
			}
			c = c->getProxPedido();
		}
	}
}

void ListaPedido::mostrar_vendedor(int matricula)
{
	int i = 0;
	
	Pedido* c = cabeca;

	if (vazia())
		cout << "ERRO: A lista não possui pedidos!\n";
	else
	{
		cout << "\n|| Impressão de pedidos do vendedor de matrícula " << matricula << " || \n";
		while (c) // percorre a lista
		{
			if (c->getVendedor().getMatricula() == matricula) {
				cout << "\nPEDIDO " << i + 1 << endl;
				i++;
				cout << "Número de identificação do pedido: " << c->getNumPedido() << endl;
				cout << "Cliente: " << c->getCliente().getNome() << endl;
				cout << "Data do pedido: " << c->getDataPedido() << endl;
				cout << "Observações: " << c->getObservacoes() << endl;
			}
			c = c->getProxPedido();
		}
	}
}

bool ListaPedido::vazia() // verifica se a lista está vazia
{
	return (cabeca == NULL);
}

// insere no início (semelhante a push_front da list)
void ListaPedido::inserir_inicio(Pedido p)
{
	Pedido* novo_pedido = new Pedido(p.getNumPedido(), p.getDataPedido(), p.getVendedor(), p.getCliente(), p.getObservacoes());

	if (vazia())
	{
		cabeca = novo_pedido;
		cauda = novo_pedido;
	}
	else
	{
		novo_pedido->setProxPedido(cabeca);
		cabeca = novo_pedido;
	}
}

// insere no final (semelhante a push_back)
void ListaPedido::inserir_final(Pedido p)
{
	Pedido* novo_pedido = new Pedido(p.getNumPedido(), p.getDataPedido(), p.getVendedor(), p.getCliente(), p.getObservacoes());

	if (vazia())
	{
		cabeca = novo_pedido;
		cauda = novo_pedido;
	}
	else
	{
		cauda->setProxPedido(novo_pedido);
		cauda = novo_pedido;
	}
}


// retorna o tamanho da lista
int ListaPedido::size()
{
	if (vazia()) // se for vazia, entã retorna 0
		return 0;

	Pedido* c = cabeca;
	int tam = 0;

	// percorre a lista
	do
	{
		c = c->getProxPedido();
		tam++;
	} while (c);

	return tam;
}

// verifica se um elemento existe na lista
bool ListaPedido::existe(int num_pedido)
{
	Pedido* c = cabeca;

	while (c)
	{
		if (c->getNumPedido() == num_pedido)
			return true;
		c = c->getProxPedido();
	}
	return false;
}

// remove da lista
int ListaPedido::remover(int num_pedido){

	Pedido* ant_ant = cabeca;
	Pedido* ant = cabeca->getProxPedido();

	if (ant_ant->getNumPedido() == num_pedido) {
		cabeca = ant_ant->getProxPedido();
		ant_ant->getProxPedido() == NULL;
		cout << "\nO pedido com número de indentificação  '" << num_pedido << "' foi encontrado e excluído com sucesso!\n";
		return num_pedido;
	}
	while (ant != NULL && ant->getNumPedido() != num_pedido)
	{
		ant_ant = ant;
		ant = ant->getProxPedido();
	}

	if (ant != NULL) {
		ant_ant->setProxPedido(ant->getProxPedido());
		ant == NULL;
		cout << "\nO pedido com número de indentificação  '" << num_pedido << "' foi encontrado e excluído com sucesso!\n";
		return num_pedido;
	}
}

int ListaPedido::removerPedido_Cliente(int cpf) {
	Pedido* ant_ant = cabeca;
	Pedido* ant = cabeca->getProxPedido();

	if (ant_ant->getCliente().getCpf() == cpf) {
		cabeca = ant_ant->getProxPedido();
		ant_ant->getProxPedido() == NULL;
		return cpf;
	}
	while (ant != NULL && ant->getCliente().getCpf() != cpf)
	{
		ant_ant = ant;
		ant = ant->getProxPedido();
	}

	if (ant != NULL) {
		ant_ant->setProxPedido(ant->getProxPedido());
		ant == NULL;
		return cpf;
	}
}

int ListaPedido::removerPedido_Vendedor(int cpf) {
	Pedido* ant_ant = cabeca;
	Pedido* ant = cabeca->getProxPedido();

	if (ant_ant->getVendedor().getCpf() == cpf) {
		cabeca = ant_ant->getProxPedido();
		ant_ant->getProxPedido() == NULL;
		return cpf;
	}
	while (ant != NULL && ant->getVendedor().getCpf() != cpf)
	{
		ant_ant = ant;
		ant = ant->getProxPedido();
	}

	if (ant != NULL) {
		ant_ant->setProxPedido(ant->getProxPedido());
		ant == NULL;
		return cpf;
	}
}

bool ListaPedido::verificaPedido_Cliente(int cpf) {

	Pedido* c = cabeca;

	while (c) {
		if (c->getCliente().getCpf() == cpf) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool ListaPedido::verificaPedido_Vendedor(int cpf) {

	Pedido* c = cabeca;

	while (c) {
		if (c->getVendedor().getCpf() == cpf) {
			return true;
		}
		else {
			return false;
		}
	}
}