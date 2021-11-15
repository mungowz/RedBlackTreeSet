/*
Traccia 1
Quesito 1
Si vuole realizzare una struttura dati per insiemi generici basata su alberi Red Black.
La struttura dati deve consentire di eseguire le operazioni canoniche di unione,
intersezione e differenza tra due insiemi. Progettare ed implementare una struttura
dati basata su alberi Red Black in cui ogni albero rappresenta un insieme e consenta
di effettuare le seguenti operazioni: UNION(), INTERSECT() e DIFFERENCE(). Gli
elementi degli insiemi (numeri interi) sono memorizzati all’interno di un file di testo.
Gli elementi appartenenti ad uno stesso insieme si trovano su una stessa riga separati
da uno spazio (righe successive corrispondono ai diversi insiemi). Dotare il
programma di un menu da cui sia possibile richiamare le suddette operazioni.
*/

/*
Il main è il blocco del programma che permette all'utente di interagire con il menù del nostro programma
prendendo in input il file di testo e le scelte dell'utente tramite tastiera. Ad essere inclusa è la 
classe Set tramite la quale si riesce ad includere anche tutte le classi che vanno a formare il programma
e viene istanziato un oggetto obj della suddetta classe attraverso il quale vengono richiamati i vari
metodi della classe.
Questo menù viene realizzato tramite un while ed il costrutto switch a 5 scelte. A seconda della scelta
che avviene tramite l'inserimento del valore della variabile operation da tastiera l'utente decide il va 
a richiamare una delle operazione che possono essere compiute sui nostri insiemi di partenza letti dal 
file, ai quali verranno aggiunti insiemi derivanti dalle operazioni fatte su quest'ultimi. 
Per facilitare la scelta all'utente viengono mostrati con l'avvio del programma gli gli alberi red-black 
che vanno a rappresentare gli insiemi letti dal file, operazione compiuta dal costruttore della classe 
Set e le operazioni possibili su questi, ovvero unione (richiamando il metodo unionSet della classe Set), 
intersezione (richiamando il metodo intersectionSet della classe Set) e differenza (richiamando il metodo 
subtractionSet della classe Set).
Viene inoltre data la possibilità ad ogni fine operazione di continuare ad usare il programma o di uscire
da questo tramite il settaggio della variabile stop a 0 che contraddice il predicato del ciclo while e 
comporta l'uscita dal programma. Nel caso verrà digitata un comando che non fa parte di quelli
disponibili nel menù verrà riproposto quest'ultimo finchè non verra digitato un comando corretto.
*/

#include "Set.cpp"

int main() {
    char operation;
    char stop = '1';
    int firstSet, secondSet;
    Set obj("set.txt");
    while (stop != '0') {
        cout << "Choose an action:" << endl;
        cout << "Type 1 for union" << endl;
        cout << "Type 2 for intersection" << endl;
        cout << "Type 3 for subtraction" << endl;
        cout << "Type 4 to show the sets" << endl;
        cout << "Type 0 to exit" << endl;
        cin >> operation;
        switch (operation) {
            case ('1') :
                cout << "Choose the sets number you want to operate on:" << endl;
                cin >> firstSet;
                cin >> secondSet;
                if (obj.setFirstSet(firstSet)){
                    if (obj.setSecondSet(secondSet)) {
                        cout << "union:" << endl;
                        obj.unionSet();
                    }
                }
                cout << "Type 0 to exit otherwise type any other simbol to continue ";
                cin >> stop;
                cout << endl << endl;
            break;
            case ('2') :
                cout << "Choose the sets number you want to operate on:" << endl;
                cin >> firstSet;
                cin >> secondSet;
                if (obj.setFirstSet(firstSet)){
                    if (obj.setSecondSet(secondSet)) {
                        cout << "intersection:" << endl;
                        obj.intersectionSet();
                    }
                }
                cout << "Type 0 to exit otherwise type any other simbol to continue ";
                cin >> stop;
                cout << endl << endl;
            break;
            case ('3') :
                cout << "Choose the sets number you want to operate on:" << endl;
                cin >> firstSet;
                cin >> secondSet;
               if (obj.setFirstSet(firstSet)){
                    if (obj.setSecondSet(secondSet)) {
                        cout << "difference:" << endl;
                        obj.differenceSet();
                    }
                }
                cout << "Type 0 to exit otherwise type any other simbol to continue ";
                cin >> stop;
                cout << endl << endl;
            break;
            case ('4') :
                obj.printSets();
                cout << "Type 0 to exit otherwise type any other simbol to continue ";
                cin >> stop;
                cout << endl << endl;
            break;
            case ('0') :
                stop = '0';
                cout << endl << endl;
            break;
        }
    }
    return 0;
}