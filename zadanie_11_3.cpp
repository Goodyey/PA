#include <iostream>
#include <cstdlib>

struct Element {
    int data;
    Element* next;
};

struct SingleList {
    Element* head;
    Element* tail;
    int counter;
};

bool is_empty(const SingleList& list) {
    return list.head == nullptr;
}

void display_message(bool condition, const std::string& message) {
    if (condition) {
        std::cout << message << std::endl;
    }
    else {
        std::cout << "Lista nie jest pusta." << std::endl;
    }
}

void add_to_end(SingleList& list, int data) {
    Element* new_element = new Element;
    new_element->data = data;
    new_element->next = list.head;

    if (is_empty(list)) {
        list.head = new_element;
    }
    else {
        list.tail->next = new_element;
    }

    list.tail = new_element;
    list.counter++;
}

void add_to_beginning(SingleList& list, int data) {
    Element* new_element = new Element;
    new_element->data = data;
    new_element->next = list.head;

    if (is_empty(list)) {
        list.tail = new_element;
    }

    list.head = new_element;
    list.counter++;
}

void add_at_position(SingleList& list, int data, int position) {
    if (position < 1 || position > list.counter + 1) {
        std::cout << "Nieprawidlowa pozycja." << std::endl;
        return;
    }

    if (position == 1) {
        add_to_beginning(list, data);
        return;
    }

    if (position == list.counter + 1) {
        add_to_end(list, data);
        return;
    }

    Element* new_element = new Element;
    new_element->data = data;

    Element* current = list.head;
    int count = 1;

    while (count < position - 1) {
        current = current->next;
        count++;
    }

    new_element->next = current->next;
    current->next = new_element;

    list.counter++;
}

void remove_from_end(SingleList& list) {
    if (is_empty(list)) {
        std::cout << "Lista jest pusta." << std::endl;
        return;
    }

    if (list.head == list.tail) {
        delete list.head;
        list.head = nullptr;
        list.tail = nullptr;
        list.counter = 0;
        return;
    }

    Element* current = list.head;
    while (current->next != list.tail) {
        current = current->next;
    }

    delete list.tail;
    current->next = list.head;
    list.tail = current;

    list.counter--;
}

void remove_from_beginning(SingleList& list) {
    if (is_empty(list)) {
        std::cout << "Lista jest pusta." << std::endl;
        return;
    }

    Element* temp = list.head;
    list.head = list.head->next;

    delete temp;

    if (list.head == nullptr) {
        list.tail = nullptr;
    }

    list.counter--;
}

void remove_at_position(SingleList& list, int position) {
    if (is_empty(list)) {
        std::cout << "Lista jest pusta." << std::endl;
        return;
    }

    if (position < 1 || position > list.counter) {
        std::cout << "Nieprawidlowa pozycja." << std::endl;
        return;
    }

    if (position == 1) {
        remove_from_beginning(list);
        return;
    }

    if (position == list.counter) {
        remove_from_end(list);
        return;
    }

    Element* current = list.head;
    int count = 1;

    while (count < position - 1) {
        current = current->next;
        count++;
    }

    Element* temp = current->next;
    current->next = temp->next;

    delete temp;

    list.counter--;
}

int get_first_element(const SingleList& list) {
    if (is_empty(list)) {
        std::cout << "Lista jest pusta." << std::endl;
        return -1;
    }

    return list.head->data;
}

int get_last_element(const SingleList& list) {
    if (is_empty(list)) {
        std::cout << "Lista jest pusta." << std::endl;
        return -1;
    }

    return list.tail->data;
}

double calculate_average(const SingleList& list) {
    if (is_empty(list)) {
        std::cout << "Lista jest pusta." << std::endl;
        return 0.0;
    }

    double sum = 0.0;
    Element* current = list.head;

    while (current != nullptr) {
        sum += current->data;
        current = current->next;
    }

    return sum / list.counter;
}

void find_maximum(const SingleList& list) {
    if (is_empty(list)) {
        std::cout << "Lista jest pusta." << std::endl;
        return;
    }

    Element* current = list.head;
    int max_value = current->data;
    int position = 1;
    int max_position = 1;

    while (current != nullptr) {
        if (current->data > max_value) {
            max_value = current->data;
            max_position = position;
        }

        current = current->next;
        position++;
    }

    std::cout << "Najwiekszy element: " << max_value << ", na pozycji: " << max_position << std::endl;
}

void display_list(const SingleList& list) {
    if (is_empty(list)) {
        std::cout << "Lista jest pusta." << std::endl;
        return;
    }

    Element* current = list.head;

    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;

        if (current == list.head) {
            break;
        }
    }

    std::cout << std::endl;
}

void clear_list(SingleList& list) {
    Element* current = list.head;
    while (current != nullptr) {
        Element* temp = current;
        current = current->next;
        delete temp;
    }

    list.head = nullptr;
    list.tail = nullptr;
    list.counter = 0;
}

int main() {
    SingleList list;
    list.head = nullptr;
    list.tail = nullptr;
    list.counter = 0;

    int choice;
    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Sprawdz, czy lista jest pusta" << std::endl;
        std::cout << "2. Dodaj element na koniec listy" << std::endl;
        std::cout << "3. Dodaj element na poczatek listy" << std::endl;
        std::cout << "4. Dodaj element na okreslona pozycje w liscie" << std::endl;
        std::cout << "5. Usun element z konca listy" << std::endl;
        std::cout << "6. Usun element z poczatku listy" << std::endl;
        std::cout << "7. Usun element z okreslonej pozycji w liscie" << std::endl;
        std::cout << "8. Pobierz pierwszy element z listy" << std::endl;
        std::cout << "9. Pobierz ostatni element z listy" << std::endl;
        std::cout << "10. Oblicz srednia elementow w liscie" << std::endl;
        std::cout << "11. Znajdz maksymalny element w liscie" << std::endl;
        std::cout << "12. Wyswietl cala liste" << std::endl;
        std::cout << "13. Usun cala liste" << std::endl;
        std::cout << "14. Wyjscie" << std::endl;
        std::cout << "Wybierz opcje: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            display_message(is_empty(list), "Lista jest pusta.");
            break;
        case 2:
            add_to_end(list, rand() % 50 + 1);
            break;
        case 3:
            add_to_beginning(list, rand() % 50 + 1);
            break;
        case 4: {
            int position;
            std::cout << "Podaj pozycje: ";
            std::cin >> position;
            add_at_position(list, rand() % 50 + 1, position);
            break;
        }
        case 5:
            remove_from_end(list);
            break;
        case 6:
            remove_from_beginning(list);
            break;
        case 7: {
            int position;
            std::cout << "Podaj pozycje: ";
            std::cin >> position;
            remove_at_position(list, position);
            break;
        }
        case 8:
            std::cout << "Pierwszy element: " << get_first_element(list) << std::endl;
            break;
        case 9:
            std::cout << "Ostatni element: " << get_last_element(list) << std::endl;
            break;
        case 10:
            std::cout << "srednia: " << calculate_average(list) << std::endl;
            break;
        case 11:
            find_maximum(list);
            break;
        case 12:
            display_list(list);
            break;
        case 13:
            clear_list(list);
            std::cout << "Lista usunieta." << std::endl;
            break;
        case 14:
            std::cout << "Zamykanie programu." << std::endl;
            break;
        default:
            std::cout << "Nieprawidlowy wybor." << std::endl;
            break;
        }

        std::cout << std::endl;

    } while (choice != 14);

    return 0;
}
