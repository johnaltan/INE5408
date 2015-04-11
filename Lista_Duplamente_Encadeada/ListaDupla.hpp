#include <stdlib.h>
#include "ElementoDuplo.hpp"

#define ERROLISTACHEIA -1
#define ERROLISTAVAZIA -2
#define ERROPOSICAO -3
#define ERROPARAMETRO -4

template<typename T>
class ListaDupla {
 public:
	ListaDupla() {
		this->head = NULL;
		this->size = -1;
	}
	~ListaDupla() {
		while(this->head != NULL) {
			ElementoDuplo<T> *aux = this->head;
			this->head = aux->getProximo();
			delete aux;
		}
	}
	void adicionaNoInicioDuplo(const T& dado) {
		ElementoDuplo<T> *novo = new ElementoDuplo<T>(dado, NULL, this->head);
		if (novo == NULL) throw ERROLISTACHEIA;
		if (this->head != NULL) this->head->setAnterior(novo);
		this->head = novo;
		this->size++;
	}
	T retiraDoInicioDuplo() {
		if (listaVazia()) throw ERROLISTAVAZIA;
		ElementoDuplo<T> *velho = this->head;
		T dado = velho->getInfo();
		head = velho->getProximo();
		head->setAnterior(NULL);
		this->size--;
		delete velho;
		return dado;
	}
	void eliminaDoInicioDuplo() {
		retiraDoInicioDuplo();
	}
	void adicionaNaPosicaoDuplo(const T& dado, int pos) {
		if((pos < 0) || (pos > (this->size + 1))) throw ERROPOSICAO;
		if(pos == 0) {
			adicionaNoInicioDuplo(dado);
			return;
		}
		ElementoDuplo<T> *novo = new ElementoDuplo<T>(dado, NULL, NULL);
		if(novo == NULL) throw ERROLISTACHEIA;
		ElementoDuplo<T> *anterior = head;
		int i;
		for(i = 0; i < pos - 1; i++) anterior = anterior->getProximo();
		novo->setProximo(anterior->getProximo());
		novo->setAnterior(anterior);
		anterior->setProximo(novo);
		this->size++;
	}
	int posicaoDuplo(const T& dado) const {
		if(listaVazia()) throw ERROLISTAVAZIA;
		int pos = 0;
		ElementoDuplo<T> *aux;
		for(aux = this->head; ((aux != NULL) && (aux->getInfo() != dado));
		            pos++, aux = aux->getProximo()) {}
		if(pos > size) throw ERROPOSICAO;
		return pos;
	}
	T* posicaoMemDuplo(const T& dado) const {
		if(listaVazia()) throw ERROLISTAVAZIA;
		if(dado == NULL) throw ERROPARAMETRO;
		ElementoDuplo<T> *aux;
		for(aux = this->head; ((aux != NULL) && (aux->getInfo() != dado));
		aux = aux->getProximo()) {}
		if(aux == NULL) return NULL;
		return &aux->getInfo();
	}
	bool contemDuplo(const T& dado) {
		try {
			return (posicaoDuplo(dado) >= 0);
		}catch(int s) {}
		return false;
	}
	T retiraDaPosicaoDuplo(int pos) {
		if(listaVazia()) throw ERROLISTAVAZIA;
		if((pos < 0) || (pos > this->size)) throw ERROPOSICAO;
		if(pos == 0) {
			return retiraDoInicioDuplo();
		}
		int i = 0;
		ElementoDuplo<T>  *anterior, *velho;
		for(anterior = this->head; i < pos - 1;
		    i++, anterior = anterior->getProximo()) {}
		velho = anterior->getProximo();
		T dado = velho->getInfo();
		anterior->setProximo(velho->getProximo());
		if(velho->getProximo() != NULL) velho->getProximo()->setAnterior(anterior);
		this->size--;
		delete velho;
		return dado;
	}
	void adicionaDuplo(const T& dado) {
		adicionaNaPosicaoDuplo(dado, size + 1);
	}
	T retiraDuplo() {
		return retiraDaPosicaoDuplo(size);
	}
	T retiraEspecificoDuplo(const T& dado) {
		int pos = posicaoDuplo(dado);
		return retiraDaPosicaoDuplo(pos);
	}
	T mostra(int pos) {
		if(listaVazia()) throw ERROLISTAVAZIA;
		if((pos < 0) || (pos > this->size)) throw ERROPOSICAO;
		int i = 0;
		ElementoDuplo<T>  *aux;
		for(aux = this->head; i < pos;
		    i++, aux = aux->getProximo()) {}
		return aux->getInfo();
	}
	void adicionaEmOrdem(const T& data) {
		int pos = 0;
		ElementoDuplo<T> *aux;
		for(aux = this->head; ((aux != NULL) && (aux->getInfo() < data));
		pos++, aux = aux->getProximo()) {}
		adicionaNaPosicaoDuplo(data, pos);
	}
	int verUltimo() {
		return posicaoDuplo(mostra(size));
	}
	bool listaVazia() const {
		if (this->size < 0) return true;
		return false;
	}
	/**
	 * Compara se um elemento e maior do que outro.
	*/
	bool maior(T dado1, T dado2) {
		if (dado1 > dado2) return true;
		return false;
	}

	/**
	 * Compara se um elemento e menor do que outro.
	*/
	bool menor(T dado1, T dado2) {
		if (dado1 < dado2) return true;
		return false;
	}

	/**
	 * Compara se um elemento e igual do que outro.
	*/
	bool igual(T dado1, T dado2) {
	   return ((!maior(dado1, dado2)) && (!menor(dado1, dado2)));
	}
	void destroiListaDuplo() {
		ListaDupla<T>::~ListaDupla<T>();
		size = -1;
	}

 private:
	ElementoDuplo<T> *head;
	int size;
};


