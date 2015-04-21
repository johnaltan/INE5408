#include <stdlib.h>
#include "ElementoDuplo.hpp"
#include "ListaDupla.hpp"

#define ERROLISTACHEIA -1
#define ERROLISTAVAZIA -2
#define ERROPOSICAO -3
#define ERROPARAMETRO -4

template<typename T>
class ListaDuplaCirc : public ListaDupla<T>{
 public:
	ListaDuplaCirc() {}
	~ListaDuplaCirc() {}
	void fechaLista() {
		if (this->getHead() != NULL) {
			int i;
			ElementoDuplo<T> *ultimo = this->getHead();
			for(i = 0; i < this->getSize(); i++, ultimo = ultimo->getProximo()) {}
			ultimo->setProximo(this->getHead());
			this->getHead()->setAnterior(ultimo);
		}
	}
	void adicionaNoInicioDuplo(const T& dado) {
		ListaDupla<T>::adicionaNoInicioDuplo(dado);
		fechaLista();
	}
	T retiraDoInicioDuplo() {
		T ret = ListaDupla<T>::retiraDoInicioDuplo();
		fechaLista();
		return ret;
	}
	void eliminaDoInicioDuplo() {
		this->retiraDoInicioDuplo();
	}
	/*void adicionaNaPosicaoDuplo(const T& dado, int pos)
	int posicaoDuplo(const T& dado) const
	T* posicaoMemDuplo(const T& dado) const
	bool contemDuplo(const T& dado)
	T retiraDaPosicaoDuplo(int pos)
	void adicionaDuplo(const T& dado)
	T retiraDuplo()
	T retiraEspecificoDuplo(const T& dado)
	T mostra(int pos)
	void adicionaEmOrdem(const T& data)
	int verUltimo()
	bool listaVazia() const
	bool igual(T dado1, T dado2)
	bool maior(T dado1, T dado2)
	bool menor(T dado1, T dado2)
	void destroiListaDuplo()*/
};

