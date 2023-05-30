#include <iostream>
#include <cstdlib>

struct Element {
    int data;
    Element* next;
    Element* prev;
};

struct Double_Cyclic_List {
    Element* head;
    int counter;
};

bool is_empty(Double_Cyclic_List* list) {
    return list->head == nullptr;
}

void display_message(bool condition, const std::string& message) {
    if (condition) {
        std::cout << message << std::endl;
    }
    else {
        std::cout << "Lista nie jest pusta." << std::endl;
    }
}

void add_to_end(Double_Cyclic_List* list, int value) {
    Element* new_element = new Element;
    new_element->data = value;
    new_element->next = nullptr;
    new_element->prev = nullptr;

    if (is_empty(list)) {
        list->head = new_element;
        new_element->next = new_element;
        new_element->prev = new_element;
    }
    else {
        new_element->prev = list->head->prev;
        new_element->next = list->head;
        list->head->prev->next = new_element;
        list->head->prev = new_element;
    }

    list->counter++;
}

void add_to_beginning(Double_Cyclic_List* list, int value) {
    Element* new_element = new Element;
    new_element->data = value;
    new_element->next = nullptr;
    new_element->prev = nullptr;

    if (is_empty(list)) {
        list->head = new_element;
        new_element->next = new_element;
        new_element->prev = new_element;
    }
    else {
        new_element->prev = list->head->prev;
        new_element->next = list->head;
        list->head->prev->next = new_element;
        list->head->prev = new_element;
        list->head = new_element;
    }

    list->counter++;
}

void add_at_position(Double_Cyclic_List* list, int value, int position) {
    if (position < 1 || position > list->counter + 1) {
        std::cout << "Nieprawidlowa pozycja." << std::endl;
        return;
    }

    if (position == 1) {
        add_to_beginning(list, value);
    }
    else if (position == list->counter + 1) {
        add_to_end(list, value);
    }
    else {
        Element* new_element = new Element;
        new_element->data = value;

        Element* current = list->head;
        for (int i = 1; i < position; i++) {
            current = current->next;
        }

        new_element->prev = current->prev;
        new_element->next = current;
        current->prev->next = new_element;
        current->prev = new_element;

        list->counter++;
    }
}

void remove_from_end(Double_Cyclic_List* list) {
    if (is_empty(list)) {
        std::cout << "Lista jest pusta." << std::endl;
        return;
    }

    Element* removed_element = list->head->prev;

    if (list->head == list->head->prev) {
        list->head = nullptr;
    }
    else {
        list->head->prev = removed_element->prev;
        removed_element->prev->next = list->head;
    }

    delete removed_element;
    list->counter--;
}

void remove_from_beginning(Double_Cyclic_List* list) {
    if (is_empty(list)) {
        std::cout << "Lista jest pusta." << std::endl;
        return;
    }

    Element* removed_element = list->head;

    if (list->head == list->head->prev) {
        list->head = nullptr;
    }
    else {
        list->head->prev->next = removed_element->next;
        removed_element->next->prev = list->head->prev;
        list->head = removed_element->next;
    }

    delete removed_element;
    list->counter--;
}

void remove_at_position(Double_Cyclic_List* list, int position) {
    if (position < 1 || position > list->counter) {
        std::cout << "Nieprawidlowa pozycja." << std::endl;
        return;
    }

    if (position == 1) {
        remove_from_beginning(list);
    }
    else if (position == list->counter) {
        remove_from_end(list);
    }
    else {
        Element* current = list->head;
        for (int i = 1; i < position; i++) {
            current = current->next;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;

        delete current;
        list->counter--;
    }
}

void display_forward(Double_Cyclic_List* list) {
    if (is_empty(list)) {
        std::cout << "Lista jest pusta." << std::endl;
        return;
    }

    Element* current = list->head;
    do {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != list->head);

    std::cout << std::endl;
}

void display_backward(Double_Cyclic_List* list) {
    if (is_empty(list)) {
        std::cout << "Lista jest pusta." << std::endl;
        return;
    }

    Element* current = list->head->prev;
    do {
        std::cout << current->data << " ";
        current = current->prev;
    } while (current != list->head->prev);

    std::cout << std::endl;
}

void find_minimum(Double_Cyclic_List* list) {
    if (is_empty(list)) {
        std::cout << "Lista jest pusta." << std::endl;
        return;
    }

    Element* current = list->head;
    int min_value = current->data;
    int min_position = 1;
    int position = 1;

    do {
        if (current->data < min_value) {
            min_value = current->data;
            min_position = position;
        }

        current = current->next;
        position++;
    } while (current != list->head);

    std::cout << "Element minimalny: " << min_value << " na pozycji: " << min_position << std::endl;
}

void clear_list(Double_Cyclic_List* list) {
    if (is_empty(list)) {
        std::cout << "Lista jest pusta." << std::endl;
        return;
    }

    Element* current = list->head;
    do {
        Element* next = current->next;
        delete current;
        current = next;
    } while (current != list->head);

    list->head = nullptr;
    list->counter = 0;
}

int main() {
    Double_Cyclic_List list;
    list.head = nullptr;
    list.counter = 0;

    int choice;
    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Sprawdz, czy lista jest pusta" << std::endl;
        std::cout << "2. Dodaj element na koniec listy" << std::endl;
        std::cout << "3. Dodaj element na poczatek listy" << std::endl;
        std::cout << "4. Dodaj element na pozycje o podanym numerze" << std::endl;
        std::cout << "5. Usun element z konca listy" << std::endl;
        std::cout << "6. Usun element z poczatku listy" << std::endl;
        std::cout << "7. Usun element z okreslonej pozycji" << std::endl;
        std::cout << "8. Wyswietl elementy od poczatku do konca" << std::endl;
        std::cout << "9. Wyswietl elementy od konca do poczatku" << std::endl;
        std::cout << "10. Znajdz element minimalny w liscie" << std::endl;
        std::cout << "11. Usun cala liste" << std::endl;
        std::cout << "12. Wyjscie" << std::endl;
        std::cout << "Wybierz opcje: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            display_message(is_empty(&list), "Lista jest pusta.");
            break;
        case 2:
            add_to_end(&list, rand() % 50 + 1);
            break;
        case 3:
            add_to_beginning(&list, rand() % 50 + 1);
            break;
        case 4: {
            int position;
            std::cout << "Podaj pozycje: ";
            std::cin >> position;
            add_at_position(&list, rand() % 50 + 1, position);
            break;
        }
        case 5:
            remove_from_end(&list);
            break;
        case 6:
            remove_from_beginning(&list);
            break;
        case 7: {
            int position;
            std::cout << "Podaj pozycje: ";
            std::cin >> position;
            remove_at_position(&list, position);
            break;
        }
        case 8:
            display_forward(&list);
            break;
        case 9:
            display_backward(&list);
            break;
        case 10:
            find_minimum(&list);
            break;
        case 11:
            clear_list(&list);
            std::cout << "Lista usunieta." << std::endl;
            break;
        case 12:
            std::cout << "Zamykanie programu." << std::endl;
            break;
        default:
            std::cout << "Nieprawidlowy wybór." << std::endl;
            break;
        }

        std::cout << std::endl;

    } while (choice != 12);

    return 0;
}
