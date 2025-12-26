# 🐍 Retro Snake Game (C++)

A console-based **Retro Snake Game written in C++**, designed to demonstrate the **evolution of programming style and game design** — from a **basic procedural approach** to an **object-oriented (OOP) implementation**.

This repository is intentionally structured to help learners, reviewers, and interviewers **compare two versions of the same game**, understand design trade-offs, and see how software improves step-by-step.

---

## 📂 Repository Structure

```
Retro-Snake-Game/
│
├── Basic Version/
│   ├── Basic-Version.cpp
│   ├── Basic Version Code Explanation.md
│   └── Basic Version Limitations.md
│
├── Intermediate Version/   (Object-Oriented Version)
│   ├── Intermediate-Version.cpp
│   ├── Intermediate Version Code Explanation.md
│   └── Intermediate Version Limitations.md
│
└── README.md
```

Each folder is **self-contained**, meaning:

* You can run the code independently
* You can read the explanation without looking elsewhere
* You can understand its limitations clearly

---

## 🧩 Versions Overview

### 1️⃣ Basic Version (Procedural)

This version focuses on **simplicity and fundamentals**.

**Key Characteristics:**

* Procedural programming style
* Global variables and functions
* `system("cls")` based screen clearing (causes flickering)
* Basic keyboard input handling
* Minimal game feedback

📄 Includes:

* **Code file** – core logic
* **Explanation file** – line-by-line understanding
* **Limitations file** – known issues and why they exist

👉 Ideal for beginners learning:

* Loops, conditionals
* Arrays / deque basics
* Console I/O

---

### 2️⃣ Intermediate Version (Object-Oriented)

This is a **clean, structured, and extensible** version of the same game using **OOP principles**.

**Major Improvements:**

* Object-Oriented design (`Snake`, `Food` classes)
* Encapsulation of game logic
* Enum-based direction handling
* Smooth rendering using cursor repositioning (no flicker)
* Directional snake head (`^ < > v`)
* Reverse-movement bug fixed
* Dynamic speed scaling with score
* **Sound effects added** (food eaten, game over)

📄 Includes:

* **Code file** – improved architecture
* **Explanation file** – detailed design walkthrough
* **Limitations file** – honest technical constraints & future scope

👉 Ideal for demonstrating:

* OOP concepts in C++
* Clean code practices
* Game-loop design
* Interview-level reasoning

---

## 🔍 Comparison Summary

| Aspect                | Basic Version             | Intermediate Version          |
| --------------------- | ------------------------- | ----------------------------- |
| Programming Style     | Procedural                | Object-Oriented               |
| Architecture          | Global logic              | Encapsulated classes          |
| Screen Rendering      | `system("cls")` (flicker) | Cursor repositioning (smooth) |
| Direction Handling    | Character-based           | Enum-based                    |
| Snake Head            | Static                    | Directional (`^ v < >`)       |
| Reverse Direction Bug | Present                   | Fixed                         |
| Sound Effects         | ❌ No                      | ✅ Yes                         |
| Code Maintainability  | Low                       | High                          |

---

## 🎯 Purpose of This Repository

This project is **not just a game**, but a **learning artifact**:

* Shows **progression in coding skills**
* Demonstrates how to **refactor procedural code into OOP**

---

## 🛠 Platform & Requirements

* **OS:** Windows (uses `windows.h`, `conio.h`)
* **Compiler:** GCC / MinGW / MSVC
* **Language:** C++

> ⚠️ Platform dependency is discussed in detail inside the *Limitations* files.

---

## 🚀 How to Run

1. Navigate to either version folder
2. Compile the `.cpp` file using a Windows-compatible compiler
3. Run the executable in a console window

Example:

```bash
g++ Intermediate-Version.cpp -o snake
snake
```

---

## 📌 Final Note

Each version is intentionally preserved instead of replaced.

> This allows readers to **see growth, not just results**.

If you are reviewing this repository — start with the **Basic Version**, then move to the **Intermediate Version** to fully appreciate the improvements.

Happy Coding 🐍✨
