/*
    La classe Set ha un rapporto di tipo "HAS A" con la classe RBTree, infatti è presente tra gli
    attributi privati della classe un vector di puntatori a RBTree di int. Questo ha la funzione
    di contenere tutti gli insiemi non solo letti dal file ma anche quelli creati tramite le operazioni
    concesse dal programma. Per selezionare gli insiemi su cui l'utente vuole operare dovra valorizzare
    i due attributi int firstSet e seconSet. Verranno scelti infatti gli insiemi alla posizione firstSet-1
    e seconSet-1 rispetto ad i valori immessi da tastiera. Questa classe permetterà quindi non solo 
    all'utente di interagire con il programma, ma anche di impedirgli di modificare la struttura degli
    insiemi letti dal file e creati dalle operazioni su questi. Infatti l'utente non avrà la possibilità
    di accedere ai metodi della classe RBTree in modo da non poter modificare gli alberi di cui 
    si dispone. Al costruttore della classe viene passato la stringa contenente il nome del file da 
    leggere. Ciò è svolto tramite l'uso dell'attributo in della classe ifstream. Tramite il metodo open 
    viene aperto il file in questione, il metodo fail invece controlla se ciò avviene a buon fine 
    altrimenti viene restituito un messaggio diagnostico di errore. Tramite la funzione getline viene 
    lette una per una le righe del file, le quali vengono bufferizzate all'interno della variabile 
    string line. Ad ogni riga letta viene istanziato una variabile di tipo puntatore alla classe RBTree 
    di interi. Tramite un while si scorre la stringa line, mentre questa viene visitata si inseriscono i
    caratteri incontrati in un'altra stringa word. Arrivati ad un carattere rappresentante lo spazio la 
    stringa word avrà letto un intero numero sotto forma di stringa. Il valore numero viene estratto 
    tramite la funzione stoi ed inserita nel nuovo insieme precedentemente istanziato. L'implementazione
    dei metodi della classe Set differenzia molto da come vengono descritti dalla relazione. 
    In particolare si può sottolineare che invece degli array viene scelto di usare la classe vector più
    orientata verso una programmazione ad oggetti. Motivo per cui la merge invece di scorrere i tre 
    array tramite due indici, confronta il front di left e right, ovvero il metodo che restituisce 
    l'elemento in prima posizione nel vector, eliminando tramite il metodo erase il front più piccolo dei
    due.
*/

#ifndef Set_hpp
#define Set_hpp

#include "RBTree.hpp"
#include <stack>
#include <fstream> 
#include <vector>
#include <string>

class Set {
    private:
        int firstSet;
        int secondSet;
        ifstream in;
        vector<RBTree<int>*> vettSet;        
    /*
        Metodo usato per operare l'intersezione su due elementi senza eliminare i duplicati.
    */
        vector<int> intersectionElem();
    /*
        Metodo che serve per fondere due vector dando origine ad un terzo vector.
    */
        vector<int> merge(vector<int> left, vector<int> right);
    /*
        Metodo che serve per eliminare l'intersezione tra due insiemi all'interno di un insieme.
    */
        RBTree<int> *deleteInt(vector<int> duplicate);
    /*
        Metodo che permette di salvare i nodi di un albero in un vettore tramite una visita inorder.
    */
        void inorder(Node<int> *x, vector<int> *vett);
    /*
        Metodo che elimina i duplicati all'interno di un vettore.
    */
        RBTree<int> *deleteDuplicate(vector<int> duplicate);
    public:
    /*
        Costruttore della classe Set.
    */
        Set(string nameFile);
    /*
        Distruttore della classe Set.
    */
        ~Set(){};
    /*
        Metodo che serve per valorizzare l'attributo firstSet.
    */
        bool setFirstSet(int firstSet) {
            if (firstSet < 0 || firstSet > vettSet.size()) {
                cout << "Invalid data" << endl;
                return false;
            } else {
                this->firstSet = firstSet-1;
                return true;
            }
        };
    /*
        Metodo che serve per valorizzare l'attributo secondSet.
    */
        bool setSecondSet(int secondSet){
            if (secondSet < 0 || secondSet > vettSet.size()) {
                cout << "Invalid data" << endl;
                return false;
            } else { 
                this->secondSet = secondSet-1;
                return true;
            }
        }
    /*
        Metodo che richiama tutte le funzioni per compiere l'operazione di intersezione.
    */
        void intersectionSet();  
    /*
        Metodo che richiama tutte le funzioni per compiere l'operazione di intersezione.
    */
        void unionSet();
    /*
        Metodo che richiama tutte le funzioni per compiere l'operazione di differenza.
    */
        void differenceSet();
    /*
        Metodo che serve per stampare tutti gli insiemi salvati in vettSet.
    */
        void printSets();
};

#endif /* Set_hpp */