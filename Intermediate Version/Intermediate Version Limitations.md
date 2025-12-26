# ⚠️ Snake Game (C++) — Limitations & Problems

This document explains the **current limitations, design issues, and technical problems** present in the **object-oriented Snake game implementation**.

The goal of this section is **not to criticize the code**, but to:

* Show awareness of trade-offs
* Demonstrate engineering maturity
* Clearly explain *why* these issues exist

---

## 1️⃣ Platform Dependency (Windows-only)

### ❌ Problem

The code relies heavily on:

* `<windows.h>`
* `<conio.h>`

Key Windows-specific functions used:

* `SetConsoleCursorPosition`
* `Sleep()`
* `_kbhit()`, `_getch()`
* `Beep()`

### ⚠️ Why this is a limitation

* The game **will not compile or run** on:

  * Linux
  * macOS
* Console behavior differs across platforms

### 🧠 Root Cause

Direct dependency on **Windows Console API**.

### ✅ Possible Improvement

* Replace with cross-platform libraries:

  * SDL / SFML (graphics)
  * ncurses (terminal)
  * C++ `<thread>` + `<chrono>` for sleep

---

## 2️⃣ Rendering Still Uses Full Redraw Per Frame

### ❌ Problem

Even though flickering is removed, the game:

* Redraws the **entire grid every frame**

### ⚠️ Why this matters

* Inefficient for large grids
* Scales poorly if resolution increases

### 🧠 Root Cause

No frame-diffing or partial redraw system.

### ✅ Possible Improvement

* Track changed cells only
* Use double buffering (graphics libraries)

---

## 7️⃣ No Intro / Menu Screen

### ❌ Problem

* Game starts immediately
* No instructions shown inside game

### ⚠️ Why this matters

* Poor user onboarding
* Less polished experience

### 🧠 Root Cause

Focus on core mechanics only.

### ✅ Possible Improvement

* Add start menu
* Difficulty selection
* Pause screen

---

## 8️⃣ No Separation Between Game Logic & Rendering

### ❌ Problem

* Game logic and rendering are tightly coupled

### ⚠️ Why this matters

* Hard to port to GUI
* Hard to test logic independently

### 🧠 Root Cause

Single-file, console-focused design.

### ✅ Possible Improvement

* Separate:

  * `Game` (logic)
  * `Renderer`
  * `InputHandler`

---

## 🔟 Limited Error Handling & Validation

### ❌ Problem

* No validation for window size
* No bounds checking for extreme values

### ⚠️ Why this matters

* Undefined behavior if parameters change

---
