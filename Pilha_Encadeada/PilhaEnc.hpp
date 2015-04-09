#include "ListaEnc.hpp"
template<typename T>
class PilhaEnc : private ListaEnc<T>{
 public:
    PilhaEnc() {}
    ~PilhaEnc() {}
    void empilha(const T& dado) {
        this->adicionaNoInicio(dado);
    }
    T desempilha() {
        return this->retiraDoInicio();
    }
    T topo() {
        if (PilhaVazia()) throw ERROLISTAVAZIA;
        return this->getHead()->getInfo();
    }
    void limparPilha() {
        this->destroiLista();
    }
    bool PilhaVazia() {
        return this->listaVazia();
    }
};

