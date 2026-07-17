# Arduino Uno Q – LED Matrix Digit Display using HTML

## Overview
The **Arduino Uno Q – LED Matrix Digit Display** project demonstrates how to build an interactive web application that controls the built-in LED matrix of the Arduino Uno Q. Users can enter a digit (0–9) through a browser-based interface, and the selected digit is displayed on the LED matrix in real time.
The project showcases communication between a web interface, a Python backend, and the Arduino board using the Arduino App framework.

---

## ✨Features
* Interactive web-based user interface
* Displays digits **0–9** on the Arduino Uno Q LED matrix
* Real-time communication between the browser and the Arduino
* Input validation for valid digits
* Live connection and status updates
* Displays a default **"-1"** pattern when no valid digit is selected

---

## 🏗️Project Structure

```text
Project/
│
├── index.html          # Web interface
├── style.css           # UI styling
├── app.js              # Frontend logic and WebUI communication
├── main.py             # Python backend
├── sketch.ino          # Arduino firmware
├── digits.h            # LED matrix bitmap definitions
└── libs/
    ├── arduino.js
    └── socket.io.min.js
```

---

## 🔄System Architecture

```text
User Browser (HTML/CSS/JS) → app.js → WebUI Message ("display_digit") → Python Backend (main.py) → Bridge.provide() → Arduino Router Bridge → Arduino Sketch (sketch.ino) → Arduino Uno Q LED Matrix
```
---

## ⚙️How It Works
1. The user opens the web application.
2. A single digit (0–9) is entered into the input box.
3. Clicking **Display Digit** sends the digit to the Python backend using WebUI.
4. The backend validates and stores the selected digit.
5. The Arduino sketch continuously requests the current digit through the Bridge API.
6. The corresponding bitmap is loaded from `digits.h`.
7. The LED matrix displays the selected digit.
8. The webpage displays status messages such as connection status and the currently displayed digit.

---

## 📁 omponents

## Frontend

### `index.html`
Provides the graphical user interface containing:

* Title
* Digit input field
* Display button
* Status indicator

### `style.css`
Defines the appearance of the application using a modern dark theme with responsive layout and styled controls.

### `app.js`
Handles:

* WebUI connection
* Sending digits to the backend
* Receiving status updates
* Input validation
* Enter key support
* Connection/disconnection handling

---

## Backend

### `main.py`
The Python backend performs the following tasks:

* Creates the WebUI server
* Receives digits from the webpage
* Validates user input
* Stores the currently selected digit
* Exposes the digit through the Arduino Bridge
* Sends status messages back to the browser

---

## Arduino Firmware

### `sketch.ino`
The Arduino program:

* Initializes the LED matrix
* Connects to the Python Bridge
* Requests the current digit periodically
* Displays the corresponding bitmap on the LED matrix
* Shows a default "-1" pattern when no valid digit is available

---

## LED Matrix Patterns

### `digits.h`
Contains predefined bitmap arrays for:

* Digit 0
* Digit 1
* Digit 2
* Digit 3
* Digit 4
* Digit 5
* Digit 6
* Digit 7
* Digit 8
* Digit 9
* Default "-1" pattern

---

# Technologies Used
* Arduino Uno Q
* Arduino App Framework
* Arduino Router Bridge
* Arduino LED Matrix Library
* Python
* HTML
* CSS
* JavaScript
* WebUI
* Socket.IO

---

# Communication Flow

```text
User enters a digit → index.html → app.js → display_digit message → main.py → Stores current digit → Bridge.provide("get_digit") → sketch.ino → Loads bitmap → Arduino LED Matrix
```
---

# Input Validation
The application accepts only digits between **0** and **9**.

If an invalid value is entered:

* The webpage displays an error message.
* The previous valid digit remains unchanged.

---

# Status Messages
The web interface displays useful information, including:
* Waiting for input...
* Connected
* Disconnected
* Displaying digit X
* Invalid input
* Enter a digit between 0 and 9

---

## 📌Future Improvements
Possible enhancements include:
* Draw digits using a canvas instead of numeric input
* AI-based handwritten digit recognition (MNIST)
* Display confidence score of predictions
* Animation effects on the LED matrix
* Custom LED brightness control
* Digit history
* Mobile-friendly interface
* Additional symbols and characters
* Automatic clearing after a timeout

---

# Learning Outcomes
This project demonstrates:
* Web-to-hardware communication
* Browser-based control of embedded devices
* Python–Arduino integration
* Event-driven programming
* Client-server communication using WebUI
* Use of the Arduino Bridge API
* LED matrix graphics programming

---

# 📜License
This project is intended for educational and learning purposes. Feel free to modify and extend it for your own experiments with the Arduino Uno Q platform.
