# Skin Condition Screening System

A console based C++ project that uses a symptom questionnaire and object-oriented programming to identify a **possible** skin condition and display associated nutritional information and food recommendations.

> **Disclaimer:** This is an educational, rule-based prototype. It does not provide medical diagnosis or treatment and should not replace advice from a qualified healthcare professional.

## Overview

The program asks the user a series of Yes/No questions about common skin symptoms. Based on the answers, a simple pattern-matching system attempts to identify one of several skin conditions:

- Acne
- Dermatitis
- Rosacea
- Vitiligo
- Psoriasis
- Eczema

When a condition is identified, the program displays:

- The possible skin condition
- Associated nutritional deficiencies listed by the project
- Recommended fruits
- Recommended vegetables

If no rule is matched, the program recommends consulting a dermatologist.

## Features

- Interactive command-line questionnaire
- Yes/No input validation
- Rule-based symptom matching
- Six condition-specific classes
- Abstract base class for common skin-condition behavior
- Runtime polymorphism through virtual functions
- Encapsulation and inheritance
- Modern C++ memory management using `std::unique_ptr`
- Simple, dependency-free implementation

## OOP Concepts Demonstrated

### Abstraction

`SkinIssue` is an abstract base class containing pure virtual functions that define the common interface for every skin condition.

### Inheritance

`Acne`, `Dermatitis`, `Rosacea`, `Vitiligo`, `Psoriasis`, and `Eczema` inherit from `SkinIssue`.

### Polymorphism

A `SkinIssue` pointer/interface can refer to any derived condition. The appropriate overridden methods are selected at runtime.

### Encapsulation

Condition-specific nutritional information and food recommendations are implemented inside their respective classes and exposed through member functions.

### Dynamic Binding

Virtual functions allow the program to resolve the appropriate derived-class behavior at runtime.

## Project Structure

```text
skin-condition-diagnosis/
├── main.cpp
├── README.md
├── DESCRIPTION.md
└── .gitignore
```

## Requirements

- C++14 or later
- GCC, Clang, or another C++ compiler

No external libraries are required.

## Compile and Run

### GCC / MinGW

```bash
g++ -std=c++14 -Wall -Wextra -pedantic main.cpp -o skin_diagnosis
```

Run:

```bash
./skin_diagnosis
```

On Windows:

```powershell
.\skin_diagnosis.exe
```

### Example

The program presents questions such as:

```text
1. Do you experience frequent breakouts?
Answer: 1

2. Do you have patches of dry, flaky skin?
Answer: 0
```

Enter `1` for **Yes** and `0` for **No**.

## How the Diagnosis Works

The project uses fixed rule-based conditions rather than machine learning.

For example, a positive answer to the frequent-breakouts question maps to the Acne class. Other conditions are identified through combinations of symptom answers.

The diagnosis flow is:

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
  +----> Matching condition found
  |             |
  |             v
  |       Condition object
  |             |
  |             v
  |       Recommendations
  |
  +----> No strong match
                |
                v
       Consult a dermatologist
```

## Limitations

- The diagnosis rules are simplified and deterministic.
- The program does not use a medical dataset or machine-learning model.
- It does not account for medical history, physical examination, medications, allergies, or other clinical factors.
- Nutritional associations shown by the program are simplified project-level recommendations.
- A real medical application would require clinically validated rules, expert review, appropriate datasets, privacy safeguards, and regulatory consideration.

## Future Improvements

Possible extensions include:

- More skin conditions and symptoms
- Weighted symptom scoring instead of first-match rules
- A graphical user interface
- Persistent user profiles
- A database for symptoms and recommendations
- Unit tests for diagnosis rules
- Configuration-driven condition data
- A validated machine-learning model trained on appropriate clinical data
- Better accessibility and multilingual support

## Project Context

This project was originally developed as a C++ object-oriented programming project. The repository version keeps the original core concept and rule-based approach while cleaning up the implementation for standalone use and improving input handling and memory management.

## License

This project is provided for educational and portfolio purposes.
