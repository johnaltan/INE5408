#ifndef ELEMENTO_DUPLO_HPP
#define ELEMENTO_DUPLO_HPP

template<typename T>
class ElementoDuplo {
 private:
	T *info;
	ElementoDuplo<T> *_prev, *_next;

 public:
	/**
	 * Construtor padrao, inicializa o elemento com o endereco do dado, ponteiro para o elemento anterior e ponteiro para o proximo elemento.
	*/
	ElementoDuplo(const T& info, ElementoDuplo<T>* prev, ElementoDuplo<T>* next) :
	                                info(new T(info)), _prev(prev), _next(next) {}

	/**
	 * Destrutor padrao, remove o dado do elemento.
	*/
	~ElementoDuplo() {
		delete info;
	}

	/**
	 * Retorna o ponteiro para o elemento anterior.
	*/
	ElementoDuplo<T>* getAnterior() const {
		return _prev;
	}

	/**
	 * Retorna o ponteiro para o proximo elemento.
	*/
	ElementoDuplo<T>* getProximo() const {
		return _next;
	}

	/**
	 * Retorna o dado do elemento.
	*/
	T getInfo() const {
		return *info;
	}

	/**
	 * Define o ponteiro para o proximo elemento.
	*/
	void setProximo(ElementoDuplo<T>* next) {
		_next = next;
	}

	/**
	 * Defina o ponteiro para o elemento anterior.
	*/
	void setAnterior(ElementoDuplo<T>* prev) {
		_prev = prev;
	}
};

#endif

