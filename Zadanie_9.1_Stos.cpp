#include <iostream>
#include <cstdlib> // zawiera funkcję rand()

using namespace std;

// struktura zawierająca wskaźnik na kolejny element stosu oraz liczbę całkowitą
struct StackNode {
    int data;
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
void push(StackNode*& top) {
    int randomNum = rand() % 10 + 1;
    StackNode* newNode = new StackNode;
    newNode->data = randomNum;
    newNode->next = top;
    top = newNode;
    cout << "Dodano element " << randomNum << " na stos." << endl;
}

// funkcja, która usuwa element ze stosu
void pop(StackNode*& top) {
    if (isEmpty(top)) {
        return;
    }
    StackNode* temp = top;
    top = top->next;
    cout << "Usunięto element " << temp->data << " ze stosu." << endl;
    delete temp;
}

// funkcja, która pobiera element ze stosu
void peek(StackNode* top) {
    if (isEmpty(top)) {
        return;
    }
    cout << "Ostatni element na stosie to " << top->data << "." << endl;
}

// funkcja, która usuwa wszystkie elementy ze stosu
void clear(StackNode*& top) {
    while (top != NULL) {
        StackNode* temp = top;
        top = top->next;
        delete temp;
    }
    cout << "Wszystkie elementy zostały usunięte ze stosu." << endl;
}

// funkcja, która wyświetla menu wielokrotnego wyboru
void displayMenu() {
    cout << "MENU:" << endl;
    cout << "1. Sprawdź, czy stos jest pusty" << endl;
    cout << "2. Dodaj element na stos" << endl;
    cout << "3. Usuń element ze stosu" << endl;
    cout << "4. Pobierz element ze stosu" << endl;
    cout << "5. Usuń wszystkie elementy ze stosu" << endl;
    cout << "6. Wyjście z programu" << endl;
    cout << "Wybierz opcję: ";
}

int main() {
    StackNode* top = NULL;
    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                isEmpty(top);
                break;
            case 2:
                push(top);
                break;
            case 3:
                pop(top);
                break;
            case 4:
                peek(top);
                break;
            case 5:
                clear(top);
                break;
            case 6:
                cout << "Koniec programu." << endl;
                break;
            default:
                cout << "Nieprawidłowy wybór. Spróbuj ponownie." << endl;
                break;
            }
    } while (choice != 6);

    return 0;
}