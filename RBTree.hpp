#ifndef RBTree_hpp
#define RBTree_hpp

/*
  La classe RBTree è la classe che va ad implementare l'effettiva struttura dati dell'albero red-black
  ovvero un albero binario di ricerca bilanciato tramite l'uso del parametro colore nei nodi che lo 
  compongono. Essendo quindi un albero binario di ricerca di base ogni nodo avrà al massimo due figli e
  il figlio destro di uno nodo ha una chiave maggiore del nodo mentre il figlio sinistro una chiave 
  minore. Le caratteristiche che lo differenziano da un albero binario di ricerca sono:
  -Ogni nodo è colorato o di rosso o di nero.
  -I nodi foglia sono neri, anche se per risparmiare spazio in memoria si fa in modo di far puntare tutti
   i nodi che dovrebbero puntare ad un nodo nullo (nullptr) ad un unico nodo nil nero.
  -Se un nodo è rosso, allora entrambi i suoi figli sono neri.
  -Ogni percorso da un nodo interno ad una foglia ha lo stesso numero di nodi neri.
  -La radice è nero.
  La classe RBTree ha una relazione del tipo "HAS-A" con la classe Node. Tra gli attributi privati si 
  trova infatti due parametri di tipo Node che sono la radice a partire della quale viene memorizzato il
  restante dell'albero e un nodo nil il quale va a sostituire tutti i nodi "nulli" per risparmiare spazio
  in memoria. La classe viene resa templata per rendere più generico l'insieme in modo da poter essere
  riutilizzata in futuro. 
*/

#include "Node.hpp"

template <typename T> 
class RBTree {
  private:
    Node<T> *root;
    Node<T> *nil;
  
  /*
    Metodo che permette di effettuare una visita ricorsiva in ordine anticipato dell'albero a partire da
    un nodo passato al metodo nell'argomento.
  */

    void preorder(Node<T> *x);
  
  /*
    Metdo che permette di effettuare una visita ricorsiva in ordine simmetrico dell'albero a partire da
    un nodo passato al metodo nell'argomento..
  */

    void inorder(Node<T> *x);

  /*
    Metodo che permette di effettuare una visita ricorsiva in ordine posticipato dell'albero a partire da
    un nodo passato al metodo nell'argomento.
  */

    void postorder(Node<T> *x);
  
  /*
    Metodo che effettua una ricerca ricorsiva di un nodo nell'albero tramite una chiave passata come 
    argomento al metodo scegliendo il ramo in cui scendere basandosi sulla chiave del nodo passato 
    anch'esso come argomento .
  */
    
    Node<T> *search(Node<T> *x, T key);
  
  /*
    Metodo che permette di ripristinare le proprietà dell'albero red and black dopo l'eliminazione di un 
    nodo che viene ad attivarsi nel caso in cui il nodo ad essere eliminato sia un nodo nero visto che 
    se venisse eliminato un nodo rosso non ci sarebbe il rischio di alterare le proprietà dell'albero 
    red-black. Essendo quindi un metodo che potrebbe modificare l'albero senza che effettivamente ce ne
    sia bisogno si trova fra i metodi privati.
  */
    
    void delete_FixUp(Node<T> *x);
  
  /*
    Metodo che serve a spostare i sottoalberi all'interno di un albero binario di ricerca o red-black. 
    Questa operazione viene fatta per risistemare i "rami" di un albero binario di ricerca e quindi anche
    per i red-black in seguito all'eliminazione di un nodo. Viene sostituito il sottoalbero con il nodo 
    u con il sottoalbero con il nodo v, passati entrambi nell'argomento del metodo. Essendo quindi un 
    metodo che potrebbe modificare l'albero senza che effettivamente ce ne sia bisogno si trova fra i 
    metodi privati. 
  */
    
    void transplant(Node<T> *u, Node<T> *v);
  
  /*
    Il metodo insert_FixUp viene richiamato in seguito all'inserimento di un nodo (quello nell'argomento
    del metodo). L'inserimmento di un nodo potrebbe alterare le proprietà dell'albero red-black per cui
    tale funzione ristabilisce le proprietà di quest'ultimo a seguito di tale operazione, all'interno di
    questo metodo vengono richiamate all'occorrenza i metodi leftRotate e rightRotate. Essendo quindi 
    un metodo che potrebbe modificare l'albero senza che effettivamente ce ne sia bisogno si trova fra i 
    metodi privati. 
  */
    
    void insert_FixUp(Node<T> *x);
  
  /*
    Metodo che applica una rotazione verso sinistra sinistra del sottoalbero avente radice il nodo x 
    nell'argomento del metodo verso sinistra, utilizzato all'interno della funzione insert_fixUp per 
    ristabilire la proprietà dell'albero red-black. Essendo quindi un metodo che potrebbe modificare 
    l'albero senza che effettivamente ce ne sia bisogno si trova fra i metodi privati. 
  */
    
    void leftRotate(Node<T> *x);
  
  /*
    Metodo che applica una rotazione verso sinistra destra del sottoalbero avente radice il nodo x 
    nell'argomento del metodo verso sinistra, utilizzato all'interno della funzione insert_fixUp per 
    ristabilire la proprietà dell'albero red-black. Essendo quindi un metodo che potrebbe modificare 
    l'albero senza che effettivamente ce ne sia bisogno si trova fra i metodi privati. 
  */
    
    void rightRotate(Node<T> *x);

  public:
  
  /*
    Costruttore della classe RBTree che inizializza la radice root ed il nodo nil, inizializzando la 
    radice prorpio al valore del nodo nil. 
  */
    
    RBTree(){nil = new Node<T>(); nil->setIsNil(true); root = nil;};
  
  /*
    Distruttore della classe RBTree.
  */
    
    ~RBTree(){};
  
  /*
    Metodo che serve per restituire il nodo radice dell'albero red-black alla funzione chiamante.
  */
    
    Node<T> *getRoot(){return root;};
  
  /*
    Metodo che serve per restituire il nodo nil dell'albero red-black alla funzione chiamante.
  */
    
    Node<T> *getNil(){return nil;};
  
  /*
    Metodo che passa in la radice alla funzione preorder in modo da far partire in automatico la
    ricorsione che permette di effettuare la visita in ordine anticipato dell'albero. Giustificando
    il fatto che il metodo preorder sia privata.
  */
    
    void preorderVisit(){preorder(root);};
  
  /*
    Metodo che passa in la radice alla funzione inorder in modo da far partire in automatico la
    ricorsione che permette di effettuare la visita in ordine simmetrico dell'albero. Giustificando
    il fatto che la funzione inorder sia privata.
  */
  
    void inorderVisit(){inorder(root);};
  
  /*
    Metodo che passa in la radice alla funzione postorder in modo da far partire in automatico la
    ricorsione che permette di effettuare la visita in ordine posticipato dell'albero, giustificando
    il fatto che la funzione postorder sia privata.
  */
  
    void postorderVisit(){postorder(root);};
  
  /*
    Metodo che passa il valore key del nodo da cercare nell'albero e la radice alla funzione search in
    modo da far partire la ricerca ricorsiva dalla radice, giustificando il fatto che la funzione 
    search sia privata.
  */
  
    Node<T> *searchNode(T key){return search(root, key);};
  
  /*
    Questo metodo serve a cercare il nodo di chiave minima a partire di un sottoalbero che ha per radice 
    il nodo presente nell'argomento del metodo.                          
  */
  
    Node<T> *minimum(Node<T> *x);
  
  /*
    Questo metodo serve a cercare il nodo di chiave minima a partire di un sottoalbero che ha per radice 
    il nodo presente nell'argomento del metodo.
  */
  
    Node<T> *maximum(Node<T> *x);
  
  /*
    Questo metodo serve a cercare il successore del nodo dell'albero red-black presente nell'argomento
    del metodo, ovvero il più piccolo dei nodi avente  chiave più grande del nodo preso in esame. 
  */
  
    Node<T> *successor(Node<T> *x);
  
  /*
    Questo metodo serve a cercare il predecessore del nodo dell'albero red-black presente nell'argomento
    del metodo, ovvero il più grande dei nodi avente chiave più piccolo del nodo preso in esame. 
  */
  
    Node<T> *predecessor(Node<T> *x);
  
  /*
    Metodo che implementa l'inserimento di un nuovo nodo all'interno dell'albero red-black attraverso la 
    sola chiave di questo nuovo nodo. Ad essere richiamato in questo metodo può essere il metodo 
    insert_fixUp.
  */

    void insertNode(T key);
  
  /*
    Metodo che implementa l'eliminazione di un nodo in un albero binario di ricerca, riconosciuto tramite
    il nodo è riconosciuto tramite il valore della variabile key dell'argomento del metodo. Al suo
    interno vengono richiamati all'occorrenza il metodo transplant e la delete_FixUp.   
  */
    
    void deleteNode(T key);

};

template <typename T> void RBTree<T>::insertNode(T key) {
  Node<T> *newNode = new Node<T>(key);
  newNode->setParent(nil);
  newNode->setLeft(nil);
  newNode->setRight(nil);
  newNode->setColor(RED);
  auto *y = nil;
  auto *x = root;
  while (x != nil) {
    y = x;
    if (newNode->getKey() < x->getKey()) x = x->getLeft();
    else x = x->getRight();
  }
  newNode->setParent(y);
  if (y == nil) root = newNode;
  else if (newNode->getKey() < y->getKey()) y->setLeft(newNode);
  else y->setRight(newNode);
  if (newNode->getParent() == nil) {
    newNode->setColor(BLACK);
    return;
  }
  if (newNode->getParent()->getParent() == nil) return;
  insert_FixUp(newNode);
}

template <typename T> void RBTree<T>::rightRotate(Node<T> *x) {
    auto *y = x->getLeft();
    x->setLeft(y->getRight());
    if (y->getRight() != nil) y->getRight()->setParent(x);
    y->setParent(x->getParent());
    if (x->getParent() == nil) root = y;
    else if (x == x->getParent()->getRight()) x->getParent()->setRight(y);
    else x->getParent()->setLeft(y);
    y->setRight(x);
    x->setParent(y);
  }

template <typename T> void RBTree<T>::leftRotate(Node<T> *x) {
  auto *y = x->getRight();
  x->setRight(y->getLeft());
  if (y->getLeft() != nil) y->getLeft()->setParent(x);
  y->setParent(x->getParent());
  if (x->getParent() == nil) root = y;
  else if (x == x->getParent()->getLeft()) x->getParent()->setLeft(y);
  else x->getParent()->setRight(y);
  y->setLeft(x);
  x->setParent(y);
}

template <typename T> Node<T> *RBTree<T>::predecessor(Node<T> *x) {
  if (x->getLeft() != nil) return minimum(x->getLeft());
  auto *y = x->getParent();
  while (y != nil && x == y->getLeft()) {
    x = y;
    y = y->getParent();
  }
  return y;
}

template <typename T> Node<T> *RBTree<T>::successor(Node<T> *x) {
  if (x->getRight() != nil) return minimum(x->getRight());
  auto *y = x->getParent();
  while (y != nil && x == y->getRight()) {
    x = y;
    y = y->getParent();
  }
  return y;
}

template <typename T> Node<T> *RBTree<T>::maximum(Node<T> *x) {
  while (x->getRight() != nil) x = x->getRight();
  return x;
}

template <typename T> Node<T> *RBTree<T>::minimum(Node<T> *x) {
  while (x->getLeft() != nil) x = x->getLeft();
  return x;
}

template <typename T> void RBTree<T>::insert_FixUp(Node<T> *x) {
  Node<T> *y;
  while (x->getParent()->getColor() == RED) {
    if (x->getParent() == x->getParent()->getParent()->getRight()) {
      y = x->getParent()->getParent()->getLeft();
      if (y->getColor() == RED) {
        y->setColor(BLACK);
        x->getParent()->setColor(BLACK);
        x->getParent()->getParent()->setColor(RED);
        x = x->getParent()->getParent();
      } else {
        if (x == x->getParent()->getLeft()) {
          x = x->getParent();
          rightRotate(x);
        }
        x->getParent()->setColor(BLACK);
        x->getParent()->getParent()->setColor(RED);
        leftRotate(x->getParent()->getParent());
      }
    } else {
      y = x->getParent()->getParent()->getRight();
      if (y->getColor() == RED) {
        y->setColor(BLACK);
        x->getParent()->setColor(BLACK);
        x->getParent()->getParent()->setColor(RED);
        x = x->getParent()->getParent();
      } else {
        if (x == x->getParent()->getRight()) {
          x = x->getParent();
          leftRotate(x);
        }
        x->getParent()->setColor(BLACK);
        x->getParent()->getParent()->setColor(RED);
        rightRotate(x->getParent()->getParent());
      }
    }
    if (x == root) break;
  }
  root->setColor(BLACK);
}

template <typename T> void RBTree<T>::deleteNode(T key) {
  auto *z = searchNode(key);
  if (z == nil) {
    cout << "Key not found in the tree" << endl;
    return;
  }
  Node<T> *x = new Node<T>();
  auto *y = z;
  auto y_original_color = y->getColor();
  if (z->getLeft() == nil) {
    x = z->getRight();
    transplant(z, z->getRight());
  } else if (z->getRight() == nil) {
    x = z->getLeft();
    transplant(z, z->getLeft());
  } else {
    y = minimum(z->getRight());
    y_original_color = y->getColor();
    x = y->getRight();
    if (y->getParent() == z) x->setParent(y);
    else {
      transplant(y, y->getRight());
      y->setRight(z->getRight());
      y->getRight()->setParent(y);
    }
    transplant(z, y);
    y->setLeft(z->getLeft());
    y->getLeft()->setParent(y);
    y->setColor(z->getColor());
  }
  delete z;
  if (y_original_color == BLACK) delete_FixUp(x);
}

template <typename T> void RBTree<T>::delete_FixUp(Node<T> *x) {
    Node<T> *y = new Node<T>();
    while (x != root && x->getColor() == BLACK) {
      if (x == x->getParent()->getLeft()) {
        y = x->getParent()->getRight();
        if (y->getColor() == RED) {
          y->setColor(BLACK);
          x->getParent()->setColor(RED);
          leftRotate(x->getParent());
          y = x->getParent()->getRight();
        }
        if (y->getLeft()->getColor() == BLACK && y->getRight()->getColor() == BLACK) {
          y->setColor(RED);
          x = x->getParent();
        } else {
          if (y->getRight()->getColor() == BLACK) {
            y->getLeft()->setColor(BLACK);
            y->setColor(RED);
            rightRotate(y);
            y = x->getParent()->getRight();
          }
          y->setColor(x->getParent()->getColor());
          x->getParent()->setColor(BLACK);
          y->getRight()->setColor(BLACK);
          leftRotate(x->getParent());
          x = root;
        }
      } else {
        y = x->getParent()->getLeft();
        if (y->getColor() == RED) {
          y->setColor(BLACK);
          x->getParent()->setColor(RED);
          rightRotate(x->getParent());
          y = x->getParent()->getLeft();
        }
        if (y->getRight()->getColor() == BLACK && y->getLeft()->getColor() == BLACK) {
          y->setColor(RED);
          x = x->getParent();
        } else {
          if (y->getLeft()->getColor() == BLACK) {
            y->getRight()->setColor(BLACK);
            y->setColor(RED);
            leftRotate(y);
            y = x->getParent()->getLeft();
          }
          y->setColor(x->getParent()->getColor());
          x->getParent()->setColor(BLACK);
          y->getLeft()->setColor(BLACK);
          rightRotate(x->getParent());
          x = root;
        }
      }
    }
    x->setColor(BLACK);
}


template <typename T> void RBTree<T>::transplant(Node<T> *u, Node<T> *v) {
  if (u->getParent() == nil) root = v;
  else if (u == u->getParent()->getLeft()) u->getParent()->setLeft(v);
  else u->getParent()->setRight(v);
  if (v != nil) v->setParent(u->getParent());
}

template <typename T> void RBTree<T>::preorder(Node<T> *x) {
  if (x != nil) {
    cout << x->getKey() << " ";
    preorder(x->getLeft());
    preorder(x->getRight());
  }
}

template <typename T> void RBTree<T>::inorder(Node<T> *x) {
  if (x != nil) {
    inorder(x->getLeft());
    cout << x->getKey() << " ";
    inorder(x->getRight());
  }
}

template <typename T> void RBTree<T>::postorder(Node<T> *x) {
  if (x != nil) {
    postorder(x->getLeft());
    postorder(x->getRight());
    cout << x->getKey() << " ";
  }
}

template <typename T> Node<T> *RBTree<T>::search(Node<T> *x, T key) {
  if (x == nil || key == x->getKey()) return x;
  else if (key < x->getKey()) return search(x->getLeft(), key);
  else return search(x->getRight(), key);
}

#endif /* RBTree.hpp */