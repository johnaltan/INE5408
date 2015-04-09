#include "ListaEnc.hpp"
template<typename T>
class FilaEnc : private ListaEnc<T>{
 public:
    FilaEnc() {
        tail = NULL;
    }
    ~FilaEnc() {
        tail = NULL;
    }
    void inclui(const T& dado) {
        if (this->getSize() < 0) {
            this->adicionaNoInicio(dado);
            this->tail = this->getHead();
            return;
        }
        Elemento<T> *novo = new Elemento<T>(dado, NULL);
        if (novo == NULL) throw ERROLISTACHEIA;
        this->tail->setProximo(novo);
        this->tail = novo;
        this->setSize(this->getSize() + 1);
    }
    T retira() {
        if (this->getSize() == 0) this->tail = NULL;
        return this->retiraDoInicio();
    }
    T ultimo() {
        if (filaVazia()) throw ERROLISTAVAZIA;
        return this->tail->getInfo();
    }
    T primeiro() {
        if (filaVazia()) throw ERROLISTAVAZIA;
        return this->getHead()->getInfo();
    }
    bool filaVazia() {
        return this->listaVazia();
    }
    void limparFila() {
        this->destroiLista();
    }

 private:
    Elemento<T> *tail;
};

