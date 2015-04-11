#ifndef ELEMENTO_DUPLO_HPP
#define ELEMENTO_DUPLO_HPP

template<typename T>
class ElementoDuplo {
 private:
	T *info;
	ElementoDuplo<T> *_prev, *_next;

 public:
	ElementoDuplo(const T& info, ElementoDuplo<T>* prev, ElementoDuplo<T>* next) :
	                                info(new T(info)), _prev(prev), _next(next) {}

	~ElementoDuplo() {
		delete info;
	}

	ElementoDuplo<T>* getAnterior() const {
		return _prev;
	}

	ElementoDuplo<T>* getProximo() const {
		return _next;
	}

	T getInfo() const {
		return *info;
	}

	void setProximo(ElementoDuplo<T>* next) {
		_next = next;
	}

	void setAnterior(ElementoDuplo<T>* prev) {
		_prev = prev;
	}
};

#endif

