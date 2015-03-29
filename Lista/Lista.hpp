template<typename T>
class Lista{
 private:
    T *lista;
    int indice, tamanho;

 public:
    Lista() {
        indice = -1;
        tamanho = 0;
    }

    explicit Lista(int t) {
        tamanho = t;
        indice = -1;
        lista = new T[tamanho];
    }

    int getIndice() {
        if (estaVazio()) throw "Lista vazia";
        return indice;
    }

    void adicionaPosicao(T elemento, int ind){
        if (estaCheio()) throw "Lista cheia";
        if ((ind < 0) || (ind > indice + 1)) throw "Indice fora dos limites";
        indice++;
        int i = ind;
        for (; i < indice; i++) lista[i + 1] = lista[i];
        lista[ind] = elemento;
    }

    void adiciona(T elemento) {
        adicionaPosicao(elemento, indice + 1);
    }

    void adicionaEmOrdem(T elemento){
        int i = 0;
        for (; i <= indice; i++) if(elemento > lista[i]) break;
        adicionaPosicao(elemento,i);
    }

    T acessa(int ind, bool consulta) {
        if ((ind < 0) || (ind > indice)) throw "Indice fora dos limites";
        if (!consulta) indice--;
        T dado = lista[ind];
        int i = ind;
        for (; i < (indice + 1); i++) lista[i] = lista[i + 1];
        return dado;
    }

    T retiraUltimo() {
        return acessa(indice, false);
    }

    T retiraPrimeiro() {
        return acessa(0, false);
    }

    T consultaUltimo() {
        return acessa(indice, true);
    }

    T consultaPrimeiro() {
        return acessa(0, true);
    }

    void limpa() {
        indice = -1;
    }

    bool estaVazio() {
        if (indice < 0) return true;
        return false;
    }
    bool estaCheio() {
        if (indice >= (tamanho - 1)) return true;
        return false;
    }
};

