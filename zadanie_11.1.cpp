#include <iostream>
#include <cstdlib>

struct Element {
    int data;
    Element* next;
};

struct Single_list {
    Element* head;
    Element* tail;
    int counter;
};

bool is_empty(const Single_list& list) {
    return list.head == nullptr;
}

void display_message(bool condition, const std::string& message) {
    if (condition)
        std::cout << message << std::endl;
}

void add_to_end(Single_list& list, int value) {
    Element* new_element = new Element;
    new_element->data = value;
    new_element->next = nullptr;

    if (is_empty(list)) {
        list.head = new_element;
        list.tail = new_element;
    } else {
        list.tail->next = new_element;
        list.tail = new_element;
    }

    list.counter++;
}

void add_to_beginning(Single_list& list, int value) {
    Element* new_element = new Element;
    new_element->data = value;
    new_element->next = list.head;
    list.head = new_element;

    if (is_empty(list)) {
        list.tail = new_element;
    }

    list.counter++;
}

void add_at_position(Single_list& list, int value, int position) {
    if (position < 0 || position > list.counter) {
        std::cout << "Invalid position." << std::endl;
        return;
    }

    if (position == 0) {
        add_to_beginning(list, value);
        return;
    }

    if (position == list.counter) {
        add_to_end(list, value);
        return;
    }

    Element* new_element = new Element;
    new_element->data = value;

    Element* current = list.head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }

    new_element->next = current->next;
    current->next = new_element;

    list.counter++;
}

void remove_from_end(Single_list& list) {
    if (is_empty(list)) {
        display_message(true, "List is empty.");
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
    current->next = nullptr;
    list.tail = current;

    list.counter--;
}

void remove_from_beginning(Single_list& list) {
    if (is_empty(list)) {
        display_message(true, "List is empty.");
        return;
    }

    Element* temp = list.head;
    list.head = list.head->next;

    delete temp;
    list.counter--;

    if (list.head == nullptr) {
        list.tail = nullptr;
    }
}

void remove_at_position(Single_list& list, int position) {
    if (position < 0 || position >= list.counter) {
        std::cout << "Invalid position." << std::endl;
        return;
    }

    if (position == 0) {
        remove_from_beginning(list);
        return;
    }

    if (position == list.counter - 1) {
        remove_from_end(list);
        return;
    }

    Element* current = list.head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }

    Element* temp = current->next;
    current->next = temp->next;
    delete temp;

    list.counter--;
}

int get_first_element(const Single_list& list) {
    display_message(is_empty(list), "List is empty.");

    return list.head->data;
}

int get_last_element(const Single_list& list) {
    display_message(is_empty(list), "List is empty.");

    return list.tail->data;
}

double calculate_average(const Single_list& list) {
    if (is_empty(list)) {
        display_message(true, "List is empty.");
        return 0.0;
    }

    int sum = 0;
    Element* current = list.head;
    while (current != nullptr) {
        sum += current->data;
        current = current->next;
    }

    return static_cast<double>(sum) / list.counter;
}

void find_maximum(const Single_list& list) {
    if (is_empty(list)) {
        display_message(true, "List is empty.");
        return;
    }

    int max_value = list.head->data;
    int max_position = 0;
    int current_position = 0;

    Element* current = list.head->next;
    while (current != nullptr) {
        if (current->data > max_value) {
            max_value = current->data;
            max_position = current_position;
        }
        current = current->next;
        current_position++;
    }

    std::cout << "Maximum element: " << max_value << " at position: " << max_position << std::endl;
}

void display_list(const Single_list& list) {
    if (is_empty(list)) {
        display_message(true, "List is empty.");
        return;
    }

    Element* current = list.head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void clear_list(Single_list& list) {
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
    srand(time(nullptr));

    Single_list list;
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
            std::cout << "Srednia: " << calculate_average(list) << std::endl;
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
