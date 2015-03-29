#define LISTACHEIA -1
#define LISTAVAZIA -2
#define LIMITEINDICE -3
#define ELEMENTONAOENCONTRADO -4

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
        if (listaVazia()) throw LISTAVAZIA;
        return indice;
    }

    void adicionaNaPosicao(T elemento, int ind) {
        if (listaCheia()) throw LISTACHEIA;
        if ((ind < 0) || (ind > indice + 1)) throw LIMITEINDICE;
        indice++;
        int i = ind;
        for (; i < indice; i++) lista[i + 1] = lista[i];
        lista[ind] = elemento;
    }

    void adiciona(T elemento) {
        adicionaNaPosicao(elemento, indice + 1);
    }

    void adicionaNoInicio(T elemento) {
        adicionaNaPosicao(elemento, 0);
    }

    void adicionaEmOrdem(T elemento) {
        int i = 0;
        for (; ((i <= indice) && (elemento > lista[i])); i++) {}
        adicionaNaPosicao(elemento, i);
    }

    int posicao(T elemento) {
        int ind = 0;
        for (; ((ind <= indice) && (elemento != lista[ind])); ind++) {}
        if (ind > indice) throw ELEMENTONAOENCONTRADO;
        return ind;
    }

    bool contem(T elemento) {
        try {
            return posicao(elemento) > -1;
        } catch(int s) {
        }
        return false;
    }

    T acessa(int ind, bool consulta) {
        if ((ind < 0) || (ind > indice)) throw LIMITEINDICE;
        if (listaVazia()) throw LISTAVAZIA;
        if (!consulta) indice--;
        T dado = lista[ind];
        int i = ind;
        for (; i < (indice + 1); i++) lista[i] = lista[i + 1];
        return dado;
    }

    T retiraEspecifico(T elemento) {
        return retiraDaPosicao(posicao(elemento));
    }

    T retiraDaPosicao(int posicao) {
        return acessa(posicao, false);
    }

    T retira() {
        return acessa(indice, false);
    }

    T retiraDoInicio() {
        return acessa(0, false);
    }

    T consultaUltimo() {
        return acessa(indice, true);
    }

    T consultaPrimeiro() {
        return acessa(0, true);
    }

    void destroiLista() {
        indice = -1;
    }

    bool maior(T dado1, T dado2) {
        if (dado1 > dado2) return true;
        return false;
    }

    bool menor(T dado1, T dado2) {
        if (dado1 < dado2) return true;
        return false;
    }

    bool igual(T dado1, T dado2) {
       return ((!maior(dado1, dado2)) && (!menor(dado1, dado2)));
    }

    bool listaVazia() {
        if (indice < 0) return true;
        return false;
    }
    bool listaCheia() {
        if (indice >= (tamanho - 1)) return true;
        return false;
    }
};

