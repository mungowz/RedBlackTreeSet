/*
La classe Node è la base su cui si poggia interamente il programma. Infatti i nodi andranno a
rappresentare gli elementi dell'albero red-black che in realtà sono utilizzati per rappresentare degli
insiemi. Ad essere inclusa ovviamente è la libreria iostream che ci permette di interagire con la gran 
parte dell'IO del nostro device tramite programma. La classe Node viene creata come template per
renderlo il più etergoneo. Un oggetto di classe Node è composto da 7 attributi privati e 17 pubblici. 
Tra gli attributi privati troviamo:
-key di tipo templato T che indica l'effettivo dato contenuto dal nodo. 
-color di tipo bool che indicherà il colore del nodo che potrà essere, RED (true) o BLACK (false), per
 facilitare la lettura e l'inserimento di tali valori vengono applicate due define nella parte del 
 precompilatore che affibia a RED il valore di true e Black il valore di false, viene inizializzato a 
 BLACK dai costruttori.
-isNil di tipo bool che ci permette di capire se il nodo che stiamo tenendo in considerazione sia il
 nodo Nil(che verrà spiegato nella classe RBTree) se come valore avrà true altrimenti false, viene 
 inizializzato a false dai costruttori.
-isInt di tipo bool (che verrà spiegato nella classe RBTree) che può assumere il valore di true o false. 
-left di tipo puntatore alla classe nodo che tiene traccia del collegamento del nodo corrente al suo
 figlio sinistro, viene inizializzato a nullptr dai construttori.
-right di tipo puntatore alla classe nodo che tiene traccia del collegamento del nodo corrente al suo
 figlio destro, viene inizializzato a nullptr dai construttori.
-parent di tipo puntatore alla classe nodo che tiene traccia del collegamento del nodo corrente al nodo
 padre, viene inizializzato a nullptr dai construttori.
*/

#ifndef Node_hpp
#define Node_hpp

#include <iostream>

using namespace std;

#define BLACK false
#define RED true

template <typename T> 
class Node {
    private:
        T key;
        bool color;
        bool isNil;
        Node<T> *left;
        Node<T> *right;
        Node<T> *parent;
    public:
    /* 
        Costruttore creato tramite member inizialized list, dove viene assegnato all'attributo privato
        key il valore passato al metodo e vengono inizializzati gli altri attributi.
    */
        Node(T Key) : key(Key), color(BLACK), left(nullptr), right(nullptr), parent(nullptr), isNil(false){};
    /* 
        Secondo costruttore anch'esso creato tramite member inizialized list, dove non viene
        inizializzato il valore dell'attributo key e vengono inizializzati gli altri attributi.
    */
        Node() : color(BLACK), left(nullptr), right(nullptr), parent(nullptr), isNil(false){};
    /* 
        Distruttore della classe nodo.
    */
        ~Node(){}; 
    /*
        Metodo che assegna il valore passatogli all'attributo key.
    */
        void setKey(T key){this->key = key;};
    /*
        Metodo che restituisce il valore dell'attributo key.
    */
        T getKey(){return key;};
    /*
        Metodo che assegna il valore passatogli all'attributo isNil.
    */
        void setIsNil(bool isNil){this->isNil = isNil;};
    /*
        Metodo che restituisce il valore dell'attributo isNil.
    */
        bool getIsNil(){return isNil;};
    /*
        Metodo che assegna il valore passatogli all'attributo color.
    */
        void setColor(bool color){this->color = color;};
    /*
        Metodo che restituisce il valore dell'attributo color.
    */
        bool getColor(){return color;};
    /*
        Metodo che assegna il valore passatogli all'attributo left.
    */
        void setLeft(Node<T> *left){this->left = left;};
    /*
        Metodo che restituisce il valore dell'attributo left.
    */
        Node<T> *getLeft(){return left;};
    /*
        Metodo che assegna il valore passatogli all'attributo right.
    */
        void setRight(Node<T> *right){this->right = right;};
    /*
        Metodo che assegna il valore passatogli all'attributo right.
    */
        Node<T> *getRight(){return right;};
    /*
        Metodo che assegna il valore passatogli all'attributo parent.
    */
        void setParent(Node<T> *parent){this->parent = parent;};
    /*
        Metodo che restituisce il valore dell'attributo parent.
    */
        Node<T> *getParent(){return parent;};
};

#endif /* Node_hpp */