# Hospital-Triage
 Hospital Emergency Triage System

 Project Description

The Hospital Emergency Triage System is a menu-driven application developed using the C programming language. It is designed to manage patients in a hospital emergency department based on the severity of their medical condition.

The project uses a **Priority Queue implemented using a Min Heap** to prioritize patients for treatment. Patients with critical conditions are treated before urgent and less urgent patients. If two patients have the same priority, the patient who arrived first is selected.

Objectives

- To implement a Priority Queue using a Min Heap.
- To prioritize patients based on the severity of their condition.
- To manage patient records efficiently.
- To implement insertion, deletion, searching and display operations.
- To understand the practical application of Heap data structures.

 Features

1. **Add Patient:** Registers a new patient with an automatically generated ID, name, age and priority.
2. **Treat Next Patient:** Selects and removes the highest-priority patient from the waiting list.
3. **View Next Patient:** Displays the next patient to be treated without removing them.
4. **Display Waiting Patients:** Displays all patients currently waiting for treatment.
5. **Search Patient:** Searches for a patient using their unique ID.
6. **Exit:** Terminates the application.

Priority Levels

| Priority | Category | Description |
| 1 | Critical | Requires immediate medical attention |
| 2 | Urgent | Requires prompt medical attention |
| 3 | Less Urgent | Can wait until higher-priority patients are treated |

**Note:** A smaller priority number represents a higher medical priority.

Data Structures Used

- **Structure:** Stores patient details such as ID, name, age, priority and arrival order.
- **Array:** Stores patient records.
- **Min Heap:** Maintains patients according to their priority.
- **Priority Queue:** Ensures that the highest-priority patient is selected first.

Algorithms and Operations

- **Heapify Up:** Maintains the Min Heap property after inserting a patient.
- **Heapify Down:** Restores the Min Heap property after removing a patient.
- **Insertion:** Adds a new patient to the priority queue.
- **Deletion:** Removes the highest-priority patient from the queue.
- **Linear Search:** Searches for a patient using their ID.
- **Comparison:** Compares patients using priority and arrival order.

 Time Complexity Analysis

| Operation | Time Complexity |
|---|---|
| Add Patient | O(log n) |
| Treat Next Patient | O(log n) |
| View Next Patient | O(1) |
| Display Waiting Patients | O(n) |
| Search Patient by ID | O(n) |

##  Technologies Used

- **Programming Language:** C
- **Compiler:** GCC
- **Data Structure:** Priority Queue
- **Heap Type:** Min Heap
- **Concepts:** Structures, Arrays, Functions and Heap Operations
