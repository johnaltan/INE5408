#include <stdlib.h>
#include "Elemento.hpp"
#include "ListaEnc.hpp"

#define ERROLISTACHEIA -1
#define ERROLISTAVAZIA -2
#define ERROPOSICAO -3
#define ERROPARAMETRO -4

template<typename T>
class ListaCirc : public ListaEnc<T>{
 public:
	ListaCirc() {}
	~ListaCirc() {}
	void fechaLista() {
		if (this->getHead() != NULL) {
			int i;
			Elemento<T> *ultimo = this->getHead();
			for(i = 0; i < this->getSize(); i++, ultimo = ultimo->getProximo()) {}
			ultimo->setProximo(this->getHead());
		}
	}
	void adicionaNoInicio(const T& dado) {
		ListaEnc<T>::adicionaNoInicio(dado);
		fechaLista();
	}
	T retiraDoInicio() {
		T ret = ListaEnc<T>::retiraDoInicio();
		fechaLista();
		return ret;
	}
	void eliminaDoInicio() {
		this->retiraDoInicio();
	}
    /* void adicionaNaPosicao(const T& dado, int pos) {}
	int posicao(const T& dado) const {}
	T* posicaoMem(const T& dado) const
	bool contem(const T& dado)
	T retiraDaPosicao(int pos)
	void adiciona(const T& dado)
	T retira()
	T retiraEspecifico(const T& dado) */
	T mostra(int pos) {
		if(this->listaVazia()) throw ERROLISTAVAZIA;
		if((pos < 0) || (pos > this->size)) throw ERROPOSICAO;
		int i = 0;
		Elemento<T>  *aux;
		for(aux = this->head; i < pos;
		    i++, aux = aux->getProximo()) {}
		return aux->getInfo();
	}
//  void adicionaEmOrdem(const T& data)
	int verUltimo() {
		return posicao(mostra(this->size));
	}
    /* bool listaVazia() const
	bool igual(T dado1, T dado2)
	bool maior(T dado1, T dado2)
	bool menor(T dado1, T dado2)
	void destroiLista() */
};

