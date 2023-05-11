#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // zawiera funkcję rand()

using namespace std;

// struktura zawierająca wskaźnik na kolejny element stosu oraz znak
struct StackNode {
    char data;
    StackNode* next;
};

// funkcja, która sprawdza, czy stos jest pusty
bool isEmpty(StackNode* top) {
    if (top == NULL) {
        cout << "Stos jest pusty." << endl;
        return true;
    }
    return false;
}

// funkcja, która dodaje element na stos
void push(StackNode*& top, char ch) {
    StackNode* newNode = new StackNode;
    newNode->data = ch;
    newNode->next = top;
    top = newNode;
}

// funkcja, która usuwa element ze stosu
void pop(StackNode*& top) {
    if (isEmpty(top)) {
        return;
    }
    StackNode* temp = top;
    top = top->next;
    delete temp;
}

// funkcja, która pobiera element ze stosu
char peek(StackNode* top) {
    if (isEmpty(top)) {
        return '\0';
    }
    return top->data;
}

// funkcja, która usuwa wszystkie elementy ze stosu
void clear(StackNode*& top) {
    while (top != NULL) {
        StackNode* temp = top;
        top = top->next;
        delete temp;
    }
}

int main() {
    ifstream input("znaki1.txt"); // otwarcie pliku do odczytu
    if (!input.is_open()) {
        cout << "Nie udalo sie otworzyc pliku." << endl;
        return 1;
    }

    string line;
    StackNode* top = NULL;

    // odczytanie pliku znak po znaku i dodanie na stos
    while (getline(input, line)) {
        for (char ch : line) {
            push(top, ch);
        }
    }

    input.close(); // zamknięcie pliku

    // otwarcie pliku do zapisu i zapisanie odwróconych znaków
    ofstream output("wynik.txt");
    if (!output.is_open()) {
        cout << "Nie udalo sie otworzyc pliku." << endl;
        clear(top);
        return 1;
    }

    while (!isEmpty(top)) {
        output << peek(top);
        pop(top);
    }

    output.close(); // zamknięcie pliku

    clear(top); // usunięcie elementów ze stosu

    return 0;
}
