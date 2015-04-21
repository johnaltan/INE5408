#include <stdlib.h>
#include "ElementoDuplo.hpp"

#define ERROLISTACHEIA -1
#define ERROLISTAVAZIA -2
#define ERROPOSICAO -3
#define ERROPARAMETRO -4

template<typename T>
class ListaDupla {
 public:
	/**
	 * Construtor padrao, inicializa lista.
	*/
	ListaDupla() {
		this->head = NULL;
		this->size = -1;
	}
	/**
	 * Destrutor padrao, elimina todos os elementos da lista.
	*/
	~ListaDupla() {
		for(; this->size > -1; this->size--) {
			ElementoDuplo<T> *aux = this->head;
			this->head = aux->getProximo();
			delete aux;
		}
	}

	ElementoDuplo<T> *getHead() {
		return this->head;
	}

	int getSize() {
		return this->size;
	}

	void setSize(int vSize) {
	    this->size = vSize;
	}
	/**
	 * Adiciona o dado no inicio da lista.
	*/
	void adicionaNoInicioDuplo(const T& dado) {
		ElementoDuplo<T> *novo = new ElementoDuplo<T>(dado, NULL, this->head);
		if (novo == NULL) throw ERROLISTACHEIA;
		if (this->head != NULL) this->head->setAnterior(novo);
		this->head = novo;
		this->size++;
	}
	/**
	 * Retira o dado do primeiro elemento da lista e o remove.
	*/
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
	/**
	 * Remove o primeiro elemento da lista.
	*/
	void eliminaDoInicioDuplo() {
		retiraDoInicioDuplo();
	}
	/**
	 * Adiciona o dado na posicao.
	*/
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
	/**
	 * Retorna a posicao do dado na lista.
	*/
	int posicaoDuplo(const T& dado) const {
		if(listaVazia()) throw ERROLISTAVAZIA;
		int pos = 0;
		ElementoDuplo<T> *aux;
		for(aux = this->head; ((pos <= this->size) && (aux->getInfo() != dado));
		            pos++, aux = aux->getProximo()) {}
		if(pos > size) throw ERROPOSICAO;
		return pos;
	}
	/**
	 * Retorna o endereco de memoria do dado.
	*/
	T* posicaoMemDuplo(const T& dado) const {
		if(listaVazia()) throw ERROLISTAVAZIA;
		if(dado == NULL) throw ERROPARAMETRO;
		int i = 0;
		ElementoDuplo<T> *aux;
		for(aux = this->head; ((i <= this->size) && (aux->getInfo() != dado));
		aux = aux->getProximo()) {}
		if(aux == NULL) return NULL;
		return &aux->getInfo();
	}
	/**
	 * Verifica se a lista contem o dado.
	*/
	bool contemDuplo(const T& dado) {
		try {
			return (posicaoDuplo(dado) >= 0);
		}catch(int s) {}
		return false;
	}
	/**
	 * Retorna o dado da posicao e remove o respectivo elemento da lista.
	*/
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
	/**
	 * Adiciona o dado no final da lista.
	*/
	void adicionaDuplo(const T& dado) {
		adicionaNaPosicaoDuplo(dado, size + 1);
	}
	/**
	 * Retorna o ultimo dado da lista e remove o elemento.
	*/
	T retiraDuplo() {
		return retiraDaPosicaoDuplo(size);
	}
	/**
	 * Remove o dado da lista, e retorna o dado removido.
	*/
	T retiraEspecificoDuplo(const T& dado) {
		int pos = posicaoDuplo(dado);
		return retiraDaPosicaoDuplo(pos);
	}
	/**
	 * Retorna o dado da posicao, sem remover o elemento.
	*/
	T mostra(int pos) {
		if(listaVazia()) throw ERROLISTAVAZIA;
		if((pos < 0) || (pos > this->size)) throw ERROPOSICAO;
		int i = 0;
		ElementoDuplo<T>  *aux;
		for(aux = this->head; i < pos;
		    i++, aux = aux->getProximo()) {}
		return aux->getInfo();
	}
	/**
	 * Adiciona os elementos em ordem crescente.
	*/
	void adicionaEmOrdem(const T& data) {
		int pos = 0;
		ElementoDuplo<T> *aux;
		for(aux = this->head; ((pos <= this->size) && (aux->getInfo() < data));
		pos++, aux = aux->getProximo()) {}
		adicionaNaPosicaoDuplo(data, pos);
	}
	/**
	 * Retorna a posicao do ultimo elemento.
	*/
	int verUltimo() {
		return posicaoDuplo(mostra(size));
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
	void destroiListaDuplo() {
		ListaDupla<T>::~ListaDupla<T>();
		size = -1;
	}

 private:
	ElementoDuplo<T> *head;
	int size;
};


