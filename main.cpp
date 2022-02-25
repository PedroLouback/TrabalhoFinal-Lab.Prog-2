#include <iostream>
#include <string>
#include <locale>
#include "ListaCliente.h"
#include "ListaVendedor.h"
#include "ListaPedido.h"

using namespace std;

int main()
{
	
    ListaCliente lc;
    ListaVendedor lv;
	ListaPedido lp;
	Pessoa contato;
	Vendedor vendedor;
	Cliente cliente;
	char opcao;
    string nome, endereco, dataNasc, dataPedido, observacoes;
	string nome_contato, endereco_contato, dataNasc_contato;
	int telefone_contato, cpf_contato;
    int telefone, cpf, matricula, escolha, qtd_contato, num_pedido, i=0;
	double limiteCredito;
	//Pessoa pes();
	//Cliente c();
	//Vendedor v();
	//Pedido p();

	setlocale(LC_ALL, "Portuguese");

	while (1) {
		cout << "\n|------------------- > CADASTRO DE PEDIDOS < ------------------------|";
		cout << "\n|   Selecione uma das alternativas abaixos conforme sua descri��o!   |";
		cout << "\n|1. Cadastrar um cliente;                                            |";
		cout << "\n|2. Excluir cliente;                                                 |";
		cout << "\n|3. Cadastrar um vendedor;                                           |";
		cout << "\n|4. Excluir vendedor;                                                |";
		cout << "\n|5. Realizar um pedido;                                              |";
		cout << "\n|6. Excluir pedido;                                                  |";
		cout << "\n|7. Imprimir lista de clientes;                                      |";
		cout << "\n|8. Imprimir pedidos de um determinado cliente;                      |";
		cout << "\n|9. Imprimir lista de vendedores;                                    |";
		cout << "\n|10. Imprimir pedidos efetivados de um determinado vendedor;         |";
		cout << "\n|11. Para encerrar o programa;                                       |";
		cout << "\n|--------------------------------------------------------------------|";
		cout << ("\n\nInforme a op��o em que deseja fazer: ");
		cin >> escolha;


		switch (escolha) {
			case 1:
			{
				cout << "\n||CADASTRO CLIENTE|| \n";
				cout << "\nInforme o nome do cliente: ";
				cin.ignore();
				getline(cin, nome);
				cout << "Informe o endere�o do cliente: ";
				getline(cin, endereco);
				cout << "Informe a data de nascimento: ";
				getline(cin, dataNasc);
				cout << "Informe o telefone do cliente: ";
				cin >> telefone;
				cout << "Informe o CPF do cliente: ";
				cin >> cpf;
				cout << "Informe o limite de cr�dito do cliente (em reais): ";
				cin >> limiteCredito;
				cout << "Informe o nome do contato: ";
				cin.ignore();
				getline(cin, nome_contato);
				cout << "Informe o endereco do contato: ";
				getline(cin, endereco_contato);
				cout << "Informe o telefone do contato: ";
				cin >> telefone_contato;
				cout << "Informe a data de nascimento do contato: ";
				cin >> dataNasc_contato;
				cout << "Informe o CPF do contato: ";
				cin >> cpf_contato;
				contato.setNome(nome_contato);
				contato.setEndereco(endereco_contato);
				contato.setDataNasc(dataNasc_contato);
				contato.setTelefone(telefone_contato);
				contato.setCpf(cpf_contato);
				Cliente c(nome, endereco, telefone, dataNasc, cpf, limiteCredito, contato);

				lc.inserir_final(c);
				cout << "\nCliente cadastrado com sucesso!\n";
				break;
			}
			case 2:
			{
				cout << "\nInforme o CPF do cliente que deseja excluir: ";
				cin >> cpf;
				if (lc.existe(cpf)) {
					if (lp.verificaPedido_Cliente(cpf) == true) {
						cout << "\nO cliente possui pedidos cadastrados, deseja proseguir e remover todos seus pedidos juntos? (S - Sim) e (N - N�o): ";
						cin >> opcao;
						if (opcao == 'S' || opcao == 's') {
							do {
								lp.removerPedido_Cliente(cpf);
								i++;
							}while (i == lp.size());
						}
						else {
							cout << "\nOk, remova pedido por pedido associado a esse cliente para prosseguir!\n";
							break;
						}
					}
					lc.remover(cpf);
					break;
				}
				else {
					cout << "\nERRO: Cliente n�o foi encontrado!\n";
					break;
				}
				break;
			}
			case 3:
			{
				cout << "\n||CADASTRO VENDEDOR|| \n";
				cout << "\nInforme o nome do vendedor: ";
				cin.ignore();
				getline(cin, nome);
				cout << "Informe o endere�o do vendedor: ";
				getline(cin, endereco);
				cout << "Informe a data de nascimento: ";
				getline(cin, dataNasc);
				cout << "Informe o telefone do vendedor: ";
				cin >> telefone;
				cout << "Informe o CPF do vendedor: ";
				cin >> cpf;
				cout << "Informe a matr�cula do vendedor: ";
				cin >> matricula;
				Vendedor v(nome, endereco, telefone, dataNasc, cpf, matricula);
				lv.inserir_final(v);
				cout << "\nVendedor cadastrado com sucesso!\n";
				break;
			}
			case 4:
			{
				cout << "\nInforme o CPF do vendedor que deseja excluir: ";
				cin >> cpf;
				if (lv.existe(cpf)) {
					if (lp.verificaPedido_Vendedor(cpf) == true) {
						cout << "\nO vendedor possui pedidos efetivados, deseja proseguir e remover todos seus pedidos juntos? (S - Sim) e (N - N�o): ";
						cin >> opcao;
						if (opcao == 'S' || opcao == 's') {
							do {
								lp.removerPedido_Vendedor(cpf);
								i++;
							} while (i == lp.size());
						}
						else {
							cout << "\nOk, remova ent�o pedido por pedido associado a esse vendedor para prosseguir!\n";
							break;
						}
					}
					lv.remover(cpf);
					break;
				}
				else {
					cout << "\nERRO: Vendedor n�o foi encontrado!\n";
					break;
				}
				break;
			}
			case 5:
			{
				cout << "\nInforme o n�mero de identificacao do pedido: ";
				cin >> num_pedido;
				cout << "Informe o cpf do vendedor respons�vel pelo pedido: ";
				cin >> cpf;
				if (lv.existe(cpf) == false) {
					cout << "\nERRO: Vendedor n�o encontrado!";
					break;
				}
				Vendedor* v = lv.getCabeca();
				while (v) {
					if (cpf == v->getCpf()) {
						vendedor.setNome(v->getNome());
						vendedor.setEndereco(v->getEndereco());
						vendedor.setTelefone(v->getTelefone());
						vendedor.setDataNasc(v->getDataNasc());
						vendedor.setCpf(v->getCpf());
						vendedor.setMatricula(v->getMatricula());
						break;
					}
					v = v->getProxVendedor();
				}
				cout << "Informe o cpf do cliente que vai efetuar a compra: ";
				cin >> cpf;
				if (lc.existe(cpf) == false) {
					cout << "\nERRO: Cliente n�o encontrado!";
					break;
				}
				Cliente* c = lc.getCabeca();
				while (c) {
					if (cpf == c->getCpf()) {
						cliente.setNome(c->getNome());
						cliente.setEndereco(c->getEndereco());
						cliente.setTelefone(c->getTelefone());
						cliente.setDataNasc(c->getDataNasc());
						cliente.setCpf(c->getCpf());
						cliente.setLimiteCredito(c->getLimiteCredito());
						break;
					}
					c = c->getProxCliente();
				}
				cout << "Informe a data do pedido: ";
				cin.ignore();
				getline(cin, dataPedido);
				cout << "Observa��es referente ao pedido: ";
				getline(cin, observacoes);

				Pedido p(num_pedido, dataPedido, vendedor, cliente, observacoes);

				lp.inserir_final(p);
				cout << "\nPedido n� " << num_pedido << " cadastrado com sucesso!\n";
				break;
			}
			case 6: 
				cout << "\nInforme o n�mero de identifica��o do pedido que deseja remover: ";
				cin >> num_pedido;
				if (lp.existe(num_pedido)==true) {
					lp.remover(num_pedido);
					break;
				}
				else {
					cout << "\nERRO: Pedido n�o foi encontrado!\n";
					break;
				}
				break;

			case 7:

				lc.mostrarTodos();
				break;

			case 8:

				cout << "\nInforme o cpf do cliente em que deseja ver os pedidos: ";
				cin >> cpf;
				if (lc.existe(cpf) == false) {
					cout << "\nERRO: Cliente n�o encontrado!";
					break;
				}
				lp.mostrar(cpf);
				break;

			case 9 : 

				lv.mostrarTodos();
				break;

			case 10:

				cout << "\nInforme a matr�cula do vendedor que deseja ver os pedidos: ";
				cin >> matricula;
				if (lv.existeMatricula(matricula) == false) {
					cout << "\nERRO: Vendedor n�o encontrado!";
					break;
				}
				lp.mostrar_vendedor(matricula);
				break;

			case 11:

				cout << "\nOp��o de encerramento escolhida!";
				cout << "\nENCERRANDO...";
				return 0;
		}
	}
}

