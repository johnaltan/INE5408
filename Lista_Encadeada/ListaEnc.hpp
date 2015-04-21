#include <stdlib.h>
#include "Elemento.hpp"

#define ERROLISTACHEIA -1
#define ERROLISTAVAZIA -2
#define ERROPOSICAO -3
#define ERROPARAMETRO -4

template<typename T>
class ListaEnc {
 public:
	ListaEnc() {
		this->head = NULL;
		this->size = -1;
	}
	~ListaEnc() {
		for(; this->size > -1; this->size--) {
			Elemento<T> *aux = this->head;
			this->head = aux->getProximo();
			delete aux;
		}
	}
	// inicio
	void adicionaNoInicio(const T& dado) {
		Elemento<T> *novo = new Elemento<T>(dado, this->head);
	    if (novo == NULL) throw ERROLISTACHEIA;
		this->head = novo;
		this->size++;
	}

	Elemento<T> *getHead() {
		return this->head;
	}

	int getSize() {
		return this->size;
	}

	void setSize(int vSize) {
	    this->size = vSize;
	}

	T retiraDoInicio() {
		if (listaVazia()) throw ERROLISTAVAZIA;
		Elemento<T> *velho = this->head;
		T dado = velho->getInfo();
		head = velho->getProximo();
		this->size--;
		delete velho;
		return dado;
	}
	void eliminaDoInicio() {
		retiraDoInicio();
	}
	// posicao
	void adicionaNaPosicao(const T& dado, int pos) {
		if((pos < 0) || (pos > (this->size + 1))) throw ERROPOSICAO;
		if(pos == 0) {
			adicionaNoInicio(dado);
			return;
		}
		Elemento<T> *novo = new Elemento<T>(dado, NULL);
		if(novo == NULL) throw ERROLISTACHEIA;
		Elemento<T> *anterior = head;
		int i;
		for(i = 0; i < pos - 1; i++) anterior = anterior->getProximo();
		novo->setProximo(anterior->getProximo());
		anterior->setProximo(novo);
		this->size++;
	}

	int posicao(const T& dado) const {
		if(listaVazia()) throw ERROLISTAVAZIA;
		int pos = 0;
		Elemento<T> *aux;
		for(aux = this->head; ((pos <= this->size) && (aux->getInfo() != dado));
		            pos++, aux = aux->getProximo()) {}
		if(pos > size) throw ERROPOSICAO;
		return pos;
	}

	T* posicaoMem(const T& dado) const {
		if(listaVazia()) throw ERROLISTAVAZIA;
		if(dado == NULL) throw ERROPARAMETRO;
		int i = 0;
		Elemento<T> *aux;
		for(aux = this->head; ((i <= this->size) && (aux->getInfo() != dado));
		aux = aux->getProximo()) {}
		if(aux == NULL) return NULL;
		return &aux->getInfo();
	}
	bool contem(const T& dado) {
		try {
			return (posicao(dado) >= 0);
		}catch(int s) {}
		return false;
	}

	T retiraDaPosicao(int pos) {
		if(listaVazia()) throw ERROLISTAVAZIA;
		if((pos < 0) || (pos > this->size)) throw ERROPOSICAO;
		if(pos == 0) {
			return retiraDoInicio();
		}
		int i = 0;
		Elemento<T>  *anterior, *velho;
		for(anterior = this->head; i < (pos - 1);
		    i++, anterior = anterior->getProximo()) {}
		velho = anterior->getProximo();
		T dado = velho->getInfo();
		anterior->setProximo(velho->getProximo());
		this->size--;
		delete velho;
		return dado;
	}

	// fim
	void adiciona(const T& dado) {
		adicionaNaPosicao(dado, size + 1);
	}

	T retira() {
		return retiraDaPosicao(size);
	}
	// especifico
	T retiraEspecifico(const T& dado) {
		int pos = posicao(dado);
		return retiraDaPosicao(pos);
	}

	/**
	 * Adiciona o elemento ordem crescente.
	*/
	void adicionaEmOrdem(const T& data) {
		int pos = 0;
		Elemento<T> *aux;
		for(aux = this->head; ((pos <= this->size) && (aux->getInfo() < data));
		pos++, aux = aux->getProximo()) {}
		adicionaNaPosicao(data, pos);
	}

	/**
	 * Verifica se a lista esta vazia.
	*/
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
	void destroiLista() {
		ListaEnc<T>::~ListaEnc<T>();
		size = -1;
	}

 private:
	Elemento<T>* head;
	int size;
};

