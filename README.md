# APC---Arbitrary-Precision-Calculator

## 📌 Project Description
APC (Arbitrary Precision Calculator) is a command-line calculator implemented in **C** that performs arithmetic operations on very large integers beyond the limits of standard C data types.
The calculator stores numbers using a **Doubly Linked List**, where each node represents a single digit. This allows the program to handle integers of **arbitrary length**.

## ⚙️ Features
* Supports very large integers
* Handles **positive and negative numbers**
* Uses **doubly linked lists** to store digits
* Performs basic arithmetic operations:
  * Addition (`+`)
  * Subtraction (`-`)
  * Multiplication (`*`)
  * Division (`/`)
* Command-line based execution
* Input validation for operands and operators

## 🧠 Data Structure Used
The project uses a **Doubly Linked List (DLL)**.
Each node stores:
* A single digit
* Pointer to previous node
* Pointer to next node

Example representation:

Number: 12345
Head → 1 ⇄ 2 ⇄ 3 ⇄ 4 ⇄ 5 ← Tail
This structure allows efficient traversal from both ends while performing arithmetic operations.

## 🛠️ Compilation

Use the **GCC compiler** to compile the project.
gcc *.c
or
gcc main.c operations.c

## ▶️ Execution

Run the program using:
./a.out <operand1> <operator> <operand2>
Example:

./a.out 12345 + 6789
./a.out -500 * 200
./a.out 987654321 / 123

## 📥 Input Format

./a.out <number1> <operator> <number2>
Example:
./a.out -223 - -23
Output:
-200

## 🔎 Operations Implementation

### Addition

Digits are added from **tail to head**, similar to manual addition with carry.

### Subtraction

Digits are subtracted with **borrow handling**.

### Multiplication

Implements multiplication similar to the **traditional paper method**.

### Division

Uses **repeated subtraction** to determine the quotient.

## 📂 Project Structure

APC/
│
├── main.c
├── operations.c
├── main.h
├── README.md

## 🚀 Learning Outcomes

This project demonstrates:

* Dynamic memory management in C
* Implementation of **linked lists**
* Handling large numbers beyond primitive data types
* Algorithm design for arithmetic operations
* Input validation and error handling

## 📚 Applications

Arbitrary precision arithmetic is used in:

* Cryptography
* Scientific computing
* Financial systems
* Big integer libraries
* High precision calculations

