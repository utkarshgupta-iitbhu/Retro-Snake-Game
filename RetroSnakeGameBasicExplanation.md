# 🐍 Snake Game in C++ — Detailed & Beginner‑Friendly Explanation

This document explains the **Snake Game** C++ code in a clean, structured, and easy‑to‑understand way. The goal is to help **beginners and laymen** understand *what each part does*, *why it is written that way*, and *how the entire game flows internally*.

---

## 1️⃣ Header Files (Preprocessor Directives)

```cpp
#include <iostream>
#include <deque>
#include <windows.h>
#include <ctime>
#include <conio.h>
```

Each header has a **specific role** in making the game work:

### 🔹 `<iostream>`

Used for basic input and output operations like:

* `cout` → printing text on the screen

---

### 🔹 `<deque>`

Provides the **double‑ended queue (deque)** container.

We use `deque` to store the **snake's body**, because:

* We frequently **add a new head** → `push_front()`
* We frequently **remove the tail** → `pop_back()`
* Both operations are **fast (O(1))**

This perfectly matches how a snake behaves in the game.

---

### 🔹 `<windows.h>` (Windows‑only)

Used for:

* `Sleep(milliseconds)` → controls game speed
* `system("cls")` → clears the console screen

⚠️ This makes the game **Windows‑specific**.

---

### 🔹 `<ctime>`

Used to seed the random number generator:

* `srand(time(NULL))`

This ensures food appears at **random positions** every time the game runs.

---

### 🔹 `<conio.h>`

Used for **real‑time keyboard input**:

* `_kbhit()` → checks if a key is pressed (without stopping the game)
* `_getch()` → reads a key instantly

This is crucial for **smooth snake movement**.

---

## 2️⃣ Data Structures & Global Variables

### 🔹 Point Structure

```cpp
struct Point {
    int x, y;
};
```

Represents a **single position on the grid** using `(x, y)` coordinates.

* Used for snake body parts
* Used for food position

---

### 🔹 Global Game State

```cpp
deque<Point> snake;
Point food;
int width = 20, height = 20;
int score = 0;
char direction = 'W';
bool gameOver = false;
```

| Variable          | Purpose                        |
| ----------------- | ------------------------------ |
| `snake`           | Stores all snake body segments |
| `food`            | Stores food position           |
| `width`, `height` | Game boundary size             |
| `score`           | Player score                   |
| `direction`       | Current movement direction     |
| `gameOver`        | Controls game loop             |

Global variables simplify access across all game functions.

---

## 3️⃣ Food Generation Logic

### 🔹 `generateFood()`

**Purpose:** Place food randomly on the grid **without overlapping the snake**.

### How it works:

1. Randomly generate `(x, y)` within boundaries
2. Check if that position overlaps any snake segment
3. If it overlaps → regenerate
4. Otherwise → accept the position

This guarantees **fair gameplay**.

---

## 4️⃣ Drawing the Game Board

### 🔹 `draw()`

**Purpose:** Redraw the entire game screen every frame.

### Workflow:

1. Clear the screen using `system("cls")`
2. Loop row‑by‑row and column‑by‑column
3. Decide what to print at each cell

### Rendering Rules:

| Condition   | Printed Symbol |
| ----------- | -------------- |
| Wall        | `#`            |
| Food        | `@`            |
| Snake Head  | `H`            |
| Snake Body  | `O`            |
| Empty Space | `' '`          |

The grid is visually rebuilt every frame, giving the illusion of motion.

---

## 5️⃣ Handling User Input

### 🔹 `input()`

**Why not `cin`?**

`cin` **pauses the program** and waits for input. A game must:

* Keep running continuously
* React instantly when a key is pressed

### Solution:

* `_kbhit()` → checks if a key was pressed
* `_getch()` → reads the key immediately

### Controls:

* `W` → Up
* `A` → Left
* `S` → Down
* `D` → Right
* `X` → Exit game

This enables **real‑time gameplay**.

---

## 6️⃣ Core Game Logic

### 🔹 `logic()`

This is the **heart of the game**.

---

### 🧭 Movement System

* `(0,0)` is the **top‑left corner**
* Moving right → `x++`
* Moving left → `x--`
* Moving down → `y++`
* Moving up → `y--`

A new head position is calculated based on direction.

---

### 💥 Collision Detection

#### 1️⃣ Wall Collision

If the head touches the boundary → **Game Over**

#### 2️⃣ Self Collision

If the head overlaps any body segment → **Game Over**

---

### 🐍 Snake Growth Logic

1. New head is added using `push_front()`
2. If food is eaten:

   * Increase score by 10
   * Generate new food
   * Do **not** remove tail (snake grows)
3. If food is not eaten:

   * Remove tail using `pop_back()`

This creates smooth snake movement.

---

## 7️⃣ `main()` Function (Program Entry)

### Initial Setup:

* Display instructions
* Wait for ENTER key
* Seed random number generator
* Initialize snake at center
* Generate first food

### Game Loop:

```text
draw → input → logic → sleep
```

This loop runs until `gameOver == true`.

---

## 8️⃣ Game Flow Summary (Beginner View)

1. Game starts
2. Snake moves automatically
3. Player controls direction
4. Snake eats food and grows
5. Collision ends the game
6. Final score is displayed

---

## ✅ Key Learning Outcomes

✔ Real‑time input handling
✔ Use of `deque` for dynamic structures
✔ Game loop architecture
✔ Collision detection
✔ Console‑based rendering

---

✨ **This project is an excellent foundation for understanding game loops, data structures, and real‑time systems in C++.**

If you want, I can:

* Refactor the code into classes (OOP version)
* Make it cross‑platform
* Optimize rendering
* Add levels or speed scaling

Just tell me 👍
