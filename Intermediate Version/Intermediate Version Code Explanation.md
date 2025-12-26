# 🐍 Snake Game in C++ — Object-Oriented & Optimized Version

This document explains the **upgraded Snake Game implementation** written in C++. This version is a **major improvement over the basic procedural version**, focusing on **object-oriented design, smoother rendering, better performance, and enhanced user experience**.

---

## 📌 High-Level Overview

This Snake game:

* Runs in the **Windows console**
* Uses **real-time keyboard input**
* Has **smooth, flicker-free rendering**
* Is written using **Object-Oriented Programming (OOP)** principles
* Includes **sound effects** and **dynamic speed scaling**

---

## 1️⃣ Header Files Used

```cpp
#include <iostream>
#include <deque>
#include <windows.h>
#include <ctime>
#include <conio.h>
```

### Purpose of Each Header

| Header        | Why it is used                                        |
| ------------- | ----------------------------------------------------- |
| `<iostream>`  | Console input/output (`cout`)                         |
| `<deque>`     | Efficient storage of snake body                       |
| `<windows.h>` | Console control, cursor movement, `Sleep()`, `Beep()` |
| `<ctime>`     | Random seed for food generation                       |
| `<conio.h>`   | Non-blocking keyboard input (`_kbhit`, `_getch`)      |

⚠️ **Note:** Because of `windows.h` and `conio.h`, this game is **Windows-specific**.

---

## 2️⃣ Core Data Structures

### 🔹 `Point` Structure

```cpp
struct Point { int x, y; };
```

* Represents a **single cell** on the game grid
* Used for:

  * Snake body segments
  * Food position

---

### 🔹 `Direction` Enumeration

```cpp
enum Direction { UP, DOWN, LEFT, RIGHT };
```

Why use `enum` instead of characters?

* Prevents invalid directions
* Makes code **readable and safe**
* Avoids magic characters like `'W'`, `'A'`

---

## 3️⃣ Snake Class (Core Game Entity)

The `Snake` class **encapsulates all snake-related logic**.

### Responsibilities of `Snake`

* Store snake body
* Track movement direction
* Calculate next head position
* Handle movement and growth
* Detect self-collision

---

### 🔹 Internal State

```cpp
deque<Point> body;
Direction dir;
```

* `deque<Point>` allows fast:

  * `push_front()` → adding new head
  * `pop_back()` → removing tail

This perfectly matches how a snake behaves.

---

### 🔹 Constructor

```cpp
Snake() {
    body = {{10,10},{10,11},{10,12}};
    dir = Direction::UP;
}
```

* Initializes the snake near the center
* Sets initial movement direction

---

### 🔹 Key Member Functions

| Function          | Purpose                           |
| ----------------- | --------------------------------- |
| `getBody()`       | Provides read-only access to body |
| `getHead()`       | Returns current head position     |
| `getDirection()`  | Returns movement direction        |
| `setDirection()`  | Changes direction safely          |
| `getNextHead()`   | Calculates next position          |
| `move()`          | Moves or grows snake              |
| `selfCollision()` | Detects collision with itself     |

---

### 🔹 Movement Logic

```text
New Head → push_front()
If no food eaten → pop_back()
```

This creates smooth forward motion.

---

## 4️⃣ Food Class

The `Food` class is responsible only for **food-related logic**.

### Responsibilities

* Generate random food positions
* Ensure food does not spawn on the snake

```cpp
void generate(int width, int height, Snake &snake)
```

* Uses random numbers within boundaries
* Repeats generation if food overlaps snake

This guarantees **fair gameplay**.

---

## 5️⃣ Rendering System (No Flickering 🎉)

### 🔹 `draw()` Function

This version **does NOT clear the screen every frame**.

Instead:

```cpp
SetConsoleCursorPosition(...)
```

* Cursor is moved back to `(0,0)`
* Screen is redrawn in-place

✅ Result: **Smooth animation with zero flicker**

---

### 🔹 Dynamic Snake Head Direction

| Direction | Head Symbol |
| --------- | ----------- |
| UP        | `^`         |
| DOWN      | `V`         |
| LEFT      | `<`         |
| RIGHT     | `>`         |

This gives better **visual feedback** to the player.

---

## 6️⃣ Real-Time Input Handling

Why not use `cin`?

* `cin` blocks program execution

Instead:

* `_kbhit()` → checks if a key is pressed
* `_getch()` → reads key instantly

### Controls

* `W A S D` → Movement
* `X` → Quit game

Reverse direction is **intentionally blocked** to avoid instant self-collision.

---

## 7️⃣ Sound Effects 🎵

### When food is eaten

```cpp
Beep(1000, 150);
```

### Game Over melody

```cpp
Beep(330,200);
Beep(294,200);
Beep(262,200);
Beep(220,600);
```

These sounds:

* Improve user feedback
* Make gameplay feel **retro and satisfying**

---

## 8️⃣ Dynamic Difficulty Scaling

```cpp
int delay = max(30, 100 - score);
Sleep(delay);
```

As score increases:

* Delay decreases
* Snake moves faster

This automatically increases **game difficulty**.

---

## 9️⃣ Game Loop Flow

```text
Input → Logic → Render → Sleep
```

The loop continues until:

* Wall collision
* Self collision
* User presses `X`

---

## 🔟 Improvements Over Basic Version

### Comparison Table

| Aspect             | Basic Version             | Improved Version           |
| ------------------ | ------------------------- | -------------------------- |
| Architecture       | Procedural                | Object-Oriented            |
| Snake Storage      | Global `deque`            | Encapsulated `Snake` class |
| Food Logic         | Free function             | `Food` class               |
| Direction Handling | Characters                | `enum Direction`           |
| Rendering          | `system("cls")` (flicker) | Cursor repositioning       |
| Snake Head         | Static `H`                | Directional arrows         |
| Input              | Weak validation           | Reverse blocked            |
| Speed              | Constant                  | Dynamic scaling            |
| Sound              | None                      | Eating + Game Over sounds  |
| Cursor             | Visible                   | Hidden                     |

---

## ✅ Key Learning Outcomes

* Object-Oriented Design in C++
* Real-time game loop architecture
* Efficient use of `deque`
* Console rendering without flicker
* Input handling without blocking
* Basic game physics & collision detection

---
