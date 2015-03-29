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

    /**
     * Iniciliza uma lista com t elementos.
    */
    explicit Lista(int t) {
        tamanho = t;
        indice = -1;
        lista = new T[tamanho];
    }

    /**
     * Retorna o indice atual da lista.
    */
    int getIndice() {
        if (listaVazia()) throw LISTAVAZIA;
        return indice;
    }

    /**
     * Adiciona o elemento no indice ind.
    */
    void adicionaNaPosicao(T elemento, int ind) {
        if (listaCheia()) throw LISTACHEIA;
        if ((ind < 0) || (ind > indice + 1)) throw LIMITEINDICE;
        indice++;
        int i = ind;
        for (; i < indice; i++) lista[i + 1] = lista[i];
        lista[ind] = elemento;
    }

    /**
     * Adiciona o elemento ao final da lista.
    */
    void adiciona(T elemento) {
        adicionaNaPosicao(elemento, indice + 1);
    }

    /**
     * Adiciona o elemento inicio da lista.
    */
    void adicionaNoInicio(T elemento) {
        adicionaNaPosicao(elemento, 0);
    }

    /**
     * Adiciona o elemento ordem crescente.
    */
    void adicionaEmOrdem(T elemento) {
        int i = 0;
        for (; ((i <= indice) && (elemento > lista[i])); i++) {}
        adicionaNaPosicao(elemento, i);
    }

    /**
     * Retorna a posicao do elemento na lista.
    */
    int posicao(T elemento) {
        int ind = 0;
        for (; ((ind <= indice) && (elemento != lista[ind])); ind++) {}
        if (ind > indice) throw ELEMENTONAOENCONTRADO;
        return ind;
    }

    /**
     * Informa se o elemento esta presente na lista.
    */
    bool contem(T elemento) {
        try {
            return posicao(elemento) > -1;
        } catch(int s) {
        }
        return false;
    }

    /**
     * Realiza acessos de consulta ou retirada na lista, no indice ind.
    */
    T acessa(int ind, bool consulta) {
        if ((ind < 0) || (ind > indice)) throw LIMITEINDICE;
        if (listaVazia()) throw LISTAVAZIA;
        if (!consulta) indice--;
        T dado = lista[ind];
        int i = ind;
        for (; i < (indice + 1); i++) lista[i] = lista[i + 1];
        return dado;
    }

    /**
     * Retira o elemento da lista.
    */
    T retiraEspecifico(T elemento) {
        return retiraDaPosicao(posicao(elemento));
    }

    /**
     * Retira o elemento da posicao.
    */
    T retiraDaPosicao(int posicao) {
        return acessa(posicao, false);
    }

    /**
     * Retira o ultimo elemento da lista.
    */
    T retira() {
        return acessa(indice, false);
    }

    /**
     * Retira o primeiro elemento da lista.
    */
    T retiraDoInicio() {
        return acessa(0, false);
    }

    /**
     * Consulta o ultimo elemento da lista.
    */
    T consultaUltimo() {
        return acessa(indice, true);
    }

    /**
     * Consulta o primeiro elemento da lista.
    */
    T consultaPrimeiro() {
        return acessa(0, true);
    }

    /**
     * Destroi a lista (reinicializa).
    */
    void destroiLista() {
        indice = -1;
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

    /**
     * Verifica se a lista esta vazia.
    */
    bool listaVazia() {
        if (indice < 0) return true;
        return false;
    }

    /**
     * Verifica se a lista esta cheia.
    */
    bool listaCheia() {
        if (indice >= (tamanho - 1)) return true;
        return false;
    }
};

