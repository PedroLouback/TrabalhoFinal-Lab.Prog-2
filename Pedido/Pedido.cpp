#include "Pedido.h"

using namespace std;

Pedido::Pedido() {
	this->num_pedido=0;
}

Pedido::Pedido(int num_pedido, string dataPedido, Vendedor vendedor, Cliente cliente, string observacoes) {
	this->num_pedido = num_pedido;
	this->dataPedido = dataPedido;
	this->vendedor = vendedor;
	this->cliente = cliente;
	this->observacoes = observacoes;
	this->proxPedido = NULL;
}

//Gets
int Pedido::getNumPedido() {
	return num_pedido;
}
string Pedido::getDataPedido() {
	return dataPedido;
}
Vendedor Pedido::getVendedor() {
	return vendedor;
}
Cliente Pedido::getCliente() {
	return cliente;
}
string Pedido::getObservacoes() {
	return observacoes;
}
Pedido* Pedido::getProxPedido() {
	return proxPedido;
}

//Sets
void Pedido::setNumPedido(int num_pedido) {
	this->num_pedido = num_pedido;
}
void Pedido::setDataPedido(string dataPedido) {
	this->dataPedido = dataPedido;
}
void Pedido::setObersevacoes(string observacoes) {
	this->observacoes = observacoes;
}
void Pedido::setVendedor(Vendedor vendedor) {
	this->vendedor = vendedor;
}
void Pedido::setCliente(Cliente cliente) {
	this->cliente = cliente;
}
void Pedido::setProxPedido(Pedido* proxPedido) {
	this->proxPedido = proxPedido;
}