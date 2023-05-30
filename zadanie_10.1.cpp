#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

struct QueueNode {
    char data;
    QueueNode* next;
};

struct Queue {
    QueueNode* head;
    QueueNode* tail;
};

bool isEmpty(const Queue& queue) {
    return queue.head == nullptr;
}

void printEmptyMessage() {
    std::cout << "Kolejka jest pusta." << std::endl;
}

void enqueue(Queue& queue, char data) {
    QueueNode* newNode = new QueueNode;
    newNode->data = data;
    newNode->next = nullptr;

    if (isEmpty(queue)) {
        queue.head = newNode;
        queue.tail = newNode;
    }
    else {
        queue.tail->next = newNode;
        queue.tail = newNode;
    }
}

void dequeue(Queue& queue) {
    if (isEmpty(queue)) {
        printEmptyMessage();
    }
    else {
        QueueNode* temp = queue.head;
        queue.head = queue.head->next;
        delete temp;
    }
}

char front(const Queue& queue) {
    if (isEmpty(queue)) {
        printEmptyMessage();
        return '\0';
    }
    else {
        return queue.head->data;
    }
}

void clearQueue(Queue& queue) {
    while (!isEmpty(queue)) {
        std::cout << "Usunięto element: " << front(queue) << std::endl;
        dequeue(queue);
    }
}

void readFromFile(Queue& queue, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Nie można otworzyć pliku." << std::endl;
        return;
    }

    char c;
    while (file.get(c)) {
        if (c >= 'A' && c <= 'Z') {
            enqueue(queue, c);
        }
    }

    file.close();
}

void printMenu() {
    std::cout << "=== Menu ===" << std::endl;
    std::cout << "1. Sprawdź, czy kolejka jest pusta" << std::endl;
    std::cout << "2. Dodaj element do kolejki" << std::endl;
    std::cout << "3. Usuń element z kolejki" << std::endl;
    std::cout << "4. Pobierz element z kolejki" << std::endl;
    std::cout << "5. Usuń wszystkie elementy z kolejki" << std::endl;
    std::cout << "6. Wczytaj duże litery z pliku" << std::endl;
    std::cout << "7. Wyjście" << std::endl;
    std::cout << "Wybierz opcję: ";
}

int main() {
    srand(time(nullptr));

    Queue queue;
    queue.head = nullptr;
    queue.tail = nullptr;

    int choice;
    char randomChar;

    do {
        printMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            if (isEmpty(queue)) {
                std::cout << "Kolejka jest pusta." << std::endl;
            }
            else {
                std::cout << "Kolejka nie jest pusta." << std::endl;
            }
            break;
        case 2:
            randomChar = 'A' + rand() % 26;
            enqueue(queue, randomChar);
            std::cout << "Dodano element do kolejki: " << randomChar << std::endl;
            break;
        case 3:
            dequeue(queue);
            break;
        case 4:
            std::cout << "Pierwszy element w kolejce: " << front(queue) << std::endl;
            break;
        case 5:
            clearQueue(queue);
            break;
        case 6:
            readFromFile(queue, "znaki2.txt");
            std::cout << "Wczytano duże litery z pliku." << std::endl;
            break;
        case 7:
            std::cout << "Program zakończony." << std::endl;
            break;
        default:
            std::cout << "Nieprawidłowy wybór." << std::endl;
            break;
        }

        std::cout << std::endl;
    } while (choice != 7);

    // Zwolnienie pamięci zajmowanej przez elementy kolejki
    clearQueue(queue);

    return 0;
}
