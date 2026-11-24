#include <stdio.h>
#include <string.h>

#define MAX_PATIENTS 100
#define NAME_LENGTH 60

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int age;
    int priority;
    int arrivalOrder;
} Patient;

Patient heap[MAX_PATIENTS];
int count = 0;
int nextId = 1;
int nextArrival = 1;

// Compare patients by priority, then arrival order
int comesBefore(Patient a, Patient b) {
    if (a.priority != b.priority)
        return a.priority < b.priority;

    return a.arrivalOrder < b.arrivalOrder;
}

// Exchange two patients in the heap
void swapPatients(int a, int b) {
    Patient temp = heap[a];
    heap[a] = heap[b];
    heap[b] = temp;
}

// Move newly inserted patient upward
void heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (!comesBefore(heap[index], heap[parent]))
            break;

        swapPatients(index, parent);
        index = parent;
    }
}

// Restore heap after removing the root
void heapifyDown(int index) {
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int best = index;

        if (left < count &&
            comesBefore(heap[left], heap[best]))
            best = left;

        if (right < count &&
            comesBefore(heap[right], heap[best]))
            best = right;

        if (best == index)
            break;

        swapPatients(index, best);
        index = best;
    }
}

// Read an integer safely
int readInt(const char *prompt, int *value) {
    char line[128];
    char extra;

    printf("%s", prompt);

    if (!fgets(line, sizeof(line), stdin))
        return 0;

    return sscanf(line, " %d %c",
                  value, &extra) == 1;
}

// Read patient's name
int readName(char *name, int size) {
    printf("Patient name: ");

    if (!fgets(name, size, stdin))
        return 0;

    size_t length = strlen(name);

    if (length > 0 && name[length - 1] == '\n') {
        name[length - 1] = '\0';
    } else if (length == (size_t)size - 1) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {
        }
        return 0;
    }

    return name[0] != '\0';
}

// Convert priority number into text
const char *priorityText(int priority) {
    if (priority == 1) return "Critical";
    if (priority == 2) return "Urgent";
    return "Less urgent";
}

// Display one patient
void printPatient(Patient p) {
    printf("ID: %d | Name: %s | Age: %d | "
           "Priority: %d (%s)\n",
           p.id, p.name, p.age,
           p.priority, priorityText(p.priority));
}

// Insert patient into priority queue
void addPatient(void) {
    if (count == MAX_PATIENTS) {
        puts("Waiting list is full.");
        return;
    }

    Patient p;

    if (!readName(p.name, NAME_LENGTH)) {
        puts("Invalid name.");
        return;
    }

    if (!readInt("Age: ", &p.age) ||
        p.age < 0 || p.age > 120) {
        puts("Invalid age.");
        return;
    }

    if (!readInt("Priority (1=Critical, "
                 "2=Urgent, 3=Less urgent): ",
                 &p.priority) ||
        p.priority < 1 || p.priority > 3) {
        puts("Invalid priority.");
        return;
    }

    p.id = nextId++;
    p.arrivalOrder = nextArrival++;

    heap[count] = p;
    heapifyUp(count);
    count++;

    printf("Patient added successfully. ID: %d\n",
           p.id);
}

// Remove highest-priority patient
void treatNext(void) {
    if (count == 0) {
        puts("No patients waiting.");
        return;
    }

    Patient p = heap[0];
    count--;

    if (count > 0) {
        heap[0] = heap[count];
        heapifyDown(0);
    }

    puts("Patient selected for treatment:");
    printPatient(p);
}

// View highest-priority patient
void viewNext(void) {
    if (count == 0) {
        puts("No patients waiting.");
        return;
    }

    puts("Next patient:");
    printPatient(heap[0]);
}

// Display all waiting patients
void displayPatients(void) {
    if (count == 0) {
        puts("No patients waiting.");
        return;
    }

    puts("Patients in heap-array order:");
    for (int i = 0; i < count; i++) {
        printPatient(heap[i]);
    }
}

// Search for patient by ID
void searchPatient(void) {
    int id;

    if (!readInt("Enter patient ID: ", &id) ||
        id <= 0) {
        puts("Invalid patient ID.");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (heap[i].id == id) {
            puts("Patient found:");
            printPatient(heap[i]);
            return;
        }
    }

    puts("Patient not found.");
}

// Main menu
int main(void) {
    int choice;

    while (1) {
        puts("\n===== HOSPITAL EMERGENCY TRIAGE =====");
        puts("1. Add Patient");
        puts("2. Treat Next Patient");
        puts("3. View Next Patient");
        puts("4. Display Waiting Patients");
        puts("5. Search Patient by ID");
        puts("6. Exit");

        if (!readInt("Enter choice: ", &choice)) {
            if (feof(stdin))
                break;

            puts("Invalid input. Enter 1 to 6.");
            continue;
        }

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                treatNext();
                break;
            case 3:
                viewNext();
                break;
            case 4:
                displayPatients();
                break;
            case 5:
                searchPatient();
                break;
            case 6:
                puts("Goodbye!");
                return 0;
            default:
                puts("Invalid choice.");
        }
    }

    return 0;
}
