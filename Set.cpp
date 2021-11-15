
#ifndef Set_cpp
#define Set_cpp

#include "Set.hpp"

Set::Set(string namefile) {
    string word = "";
    string line;
    int num;
    int i;
    int j = 0;
    in.open(namefile.c_str());
    if(in.fail()) {
        cout << "Error opening file " << namefile << endl;
        return;
    }
    while(getline(in, line)) {
        RBTree<int> *newSet = new RBTree<int>();
        i = 0;
        cout << word;
        while (i != line.size()) {
            if (line.at(i) == ' ' && i != line.size()-1) {
                num = stoi(word);
                newSet->insertNode(num);
                word = "";
            }
            word += line.at(i);
            i++;
        }
        num = stoi(word);
        word = "";
        newSet->insertNode(num);
        vettSet.push_back(newSet);
        j++;
    }
    i = 1;
    cout << endl;
    cout << j << " sets were produced from the file" << endl << endl;
    printSets();
}

void Set::intersectionSet() {
    auto intersect = intersectionElem();
    auto newSet = deleteDuplicate(intersect);
    newSet->inorderVisit();
    cout << endl;
    vettSet.push_back(newSet);
    cout << "New set was add at number " << vettSet.size() << endl;
};

vector<int> Set::intersectionElem() {
    auto node1 = vettSet.at(firstSet)->getRoot();
    auto node2 = vettSet.at(secondSet)->getRoot();
    auto nil1 = vettSet.at(firstSet)->getNil();
    auto nil2 = vettSet.at(secondSet)->getNil();
    stack<Node<int>*> s1;
    stack<Node<int>*> s2;
    vector<int> intersect;
    while ((!s1.empty() && !s2.empty()) || (node1 != nil1 || node2 != nil2)) {
        if (node1 != nil1){
            s1.push(node1);
            node1 = node1->getLeft();
        } else if (node2 != nil2) {
            s2.push(node2);
            node2 = node2->getLeft();
        } else {
            node1 = s1.top();
            node2 = s2.top();
            if (node1->getKey() == node2->getKey()) {
                intersect.push_back(node1->getKey());
                s1.pop();
                s2.pop();
                node1 = node1->getRight();
                node2 = node2->getRight();
            } else if (node1->getKey() < node2->getKey()) {
                s1.pop();
                node1 = node1->getRight();
                node2 = nil2;
            } else {
                s2.pop();
                node2 = node2->getRight();
                node1 = nil1;
            }
        }
    }
    return intersect;
}

void Set::unionSet() {
    vector<int> left; 
    vector<int> right;
    inorder(vettSet.at(firstSet)->getRoot(), &left);
    inorder(vettSet.at(secondSet)->getRoot(), &right);
    auto unionVet = merge(left, right);
    auto newSet = deleteDuplicate(unionVet);
    newSet->inorderVisit();
    cout << endl;
    vettSet.push_back(newSet);
    cout << "New set was add at number " << vettSet.size() << endl;
}

vector<int> Set::merge(vector<int> left, vector<int> right) {
    vector<int> merge;
    while (left.size() > 0 && right.size() > 0) {
        if (left.front() < right.front()) {
            merge.push_back(left.front());
            left.erase(left.begin());
        } else {
            merge.push_back(right.front());
            right.erase(right.begin());
        }
    }
    while (left.size() > 0) {
        merge.push_back(left.front());
        left.erase(left.begin());
    }
    while (right.size() > 0) {
        merge.push_back(right.front());
        right.erase(right.begin());
    }
    return merge;
}

void Set::differenceSet() {
    vector<int> vett;
    inorder(vettSet.at(firstSet)->getRoot(), &vett);
    auto intVet = intersectionElem();
    auto mergeVet = merge(vett, intVet);
    auto newSet = deleteInt(mergeVet);
    newSet->inorderVisit();
    cout << endl;
    vettSet.push_back(newSet);
    cout << "New set was add at number " << vettSet.size() << endl;
}

RBTree<int> *Set::deleteInt(vector<int> duplicate) {
    RBTree<int> *newSet = new RBTree<int>(); 
    for (auto it = duplicate.begin(); it != duplicate.end(); it++) 
        if (*it != *(it-1) && *it != *(it+1)) newSet->insertNode(*it);
    return newSet;
}

void Set::inorder(Node<int> *x, vector<int> *vett) {
    if (!x->getIsNil()) {
        inorder(x->getLeft(), vett);
        vett->push_back(x->getKey());
        inorder(x->getRight(), vett);    
    }
}

RBTree<int> *Set::deleteDuplicate(vector<int> duplicate) {
    RBTree<int> *newSet = new RBTree<int>(); 
    for (auto it = duplicate.begin(); it != duplicate.end(); it++) 
        if (*it != *(it-1)) newSet->insertNode(*it); 
    return newSet;
}

void Set::printSets() {
    auto i = 1;
    for (auto it = vettSet.begin(); it != vettSet.end(); it++) {
        cout << "Set number: " << i << endl << endl;
        i++;
        (*it)->inorderVisit();
        cout << endl << endl;
    }
}

#endif /* Set_cpp */