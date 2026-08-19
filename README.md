# Skin Condition Screening System

A C++ based skin condition screening system that uses a symptom questionnaire and Object Oriented Programming to suggest possible skin conditions and provide general dietary recommendations.

> **Disclaimer:** This is an educational, rule based prototype. It is not a medical diagnostic or treatment tool and should not replace advice from a qualified healthcare professional.

## Overview

The program asks the user a series of Yes/No questions about common skin symptoms. Based on the responses, a simple rule-based system attempts to identify one of several skin conditions:

- Acne
- Dermatitis
- Rosacea
- Vitiligo
- Psoriasis
- Eczema

When a condition is identified, the program displays:

- The possible skin condition
- Associated nutritional information
- Recommended fruits
- Recommended vegetables

If no clear condition is identified, the program recommends consulting a dermatologist.

## Features

- Interactive command line questionnaire
- Yes/No input validation
- Rule-based symptom matching
- Six condition specific classes
- Object-Oriented Programming concepts
- Abstraction and inheritance
- Polymorphism and dynamic binding
- Encapsulation
- Modern C++ memory management using `std::unique_ptr`
- No external libraries required

## OOP Concepts Demonstrated

### Abstraction

`SkinIssue` is an abstract base class that defines common functions for all skin conditions.

### Inheritance

`Acne`, `Dermatitis`, `Rosacea`, `Vitiligo`, `Psoriasis`, and `Eczema` inherit from `SkinIssue`.

### Polymorphism

The program uses virtual functions so that the appropriate condition specific implementation is selected at runtime.

### Encapsulation

Condition-specific nutritional information and food recommendations are contained within their respective classes.

### Dynamic Binding

Virtual functions allow the program to determine the appropriate derived class behavior at runtime.

## Project Structure

```text
skin-condition-diagnosis/
├── main.cpp
├── README.md
└── .gitignore
```

## Requirements

- C++14 or later
- GCC, MinGW, Clang, or another compatible C++ compiler

No external libraries are required.

## Compile and Run

### Using GCC / MinGW

```bash
g++ -std=c++14 -Wall -Wextra -pedantic main.cpp -o skin_diagnosis
```

Run the program on Windows:

```powershell
.\skin_diagnosis.exe
```

On macOS/Linux:

```bash
./skin_diagnosis
```

## How It Works

The application follows a simple workflow:

```text
User
  |
  v
Symptom Questionnaire
  |
  v
Collected Answers
  |
  v
Rule-Based Matching
  |
  +----> Possible condition found
  |             |
  |             v
  |       Recommendations
  |
  +----> No clear match
                |
                v
       Consult a dermatologist
```

The system uses predefined combinations of symptom responses rather than machine learning. For example, a positive response to the frequent-breakouts question can result in an Acne classification.

## Limitations

- The diagnosis logic is simplified and rule based.
- The system does not use a clinical dataset or machine learning model.
- It does not consider medical history, medications, allergies, or physical examination.
- The nutritional information is simplified for the purpose of this educational project.
- The results should not be interpreted as a medical diagnosis.

## Future Improvements

- Add more skin conditions and symptoms
- Introduce weighted symptom scoring
- Add a graphical user interface
- Store user data using a database
- Add automated unit tests
- Make condition data configurable
- Improve accessibility and multilingual support
- Explore clinically validated approaches for future versions

## License

This project is provided for educational and portfolio purposes.
