# ⚠️ Snake Game (C++) — Limitations & Design Issues Explained

This document discusses the **problems, limitations, and design drawbacks** of the current Snake Game implementation. The purpose is **not to criticize**, but to understand *why these issues occur* and *how they affect gameplay and software quality*.

---

## 1️⃣ Windows‑Specific Implementation (Lack of Portability)

### ❌ Problem

The game runs **only on Windows**.

### 🔍 Why this happens

The code depends on Windows‑only headers and functions:

* `<windows.h>` → `Sleep()`
* `<conio.h>` → `_kbhit()` and `_getch()`
* `system("cls")`

These APIs are **not part of standard C++** and do not exist on Linux or macOS.

### ⚠️ Impact

* The code fails to compile on non‑Windows systems
* Limits usability and sharing of the project

### ✅ Better Conceptual Approach

* Use standard C++ features like `std::this_thread::sleep_for`
* Use cross‑platform libraries (SFML, SDL, ncurses)

---

## 2️⃣ Screen Flickering (Poor Gameplay Experience)

### ❌ Problem

The game screen **flickers continuously**, making gameplay unpleasant.

### 🔍 Why this happens

Each frame:

1. The console is completely cleared using `system("cls")`
2. The entire grid is redrawn from scratch

Console clearing is a **slow system‑level operation**, so the user can visually see the screen refreshing.

### ⚠️ Impact

* Distracting visuals
* Poor user experience
* Unprofessional appearance

### ✅ Better Conceptual Approach

* Use **double buffering**
* Update only changed cells
* Avoid clearing the entire screen

---

## 3️⃣ Instant Reverse Direction Bug

### ❌ Problem

The snake can reverse direction instantly.

Example:

* Moving RIGHT → pressing LEFT → immediate self‑collision

### 🔍 Why this happens

There is **no validation** preventing opposite direction changes.

### ⚠️ Impact

* Unrealistic snake behavior
* Accidental game overs

### ✅ Better Conceptual Approach

* Store previous direction
* Disallow opposite direction input

---

## 🔚 Final Takeaway

This Snake Game implementation is:

* ✅ Excellent for **learning fundamentals**
* ❌ Not suitable for production‑level or commercial games

---
