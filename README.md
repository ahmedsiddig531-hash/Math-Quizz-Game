 # C++ Math Quiz Game 🎮

A simple console-based **Math Quiz Game** developed in C++. The game generates random arithmetic questions based on the selected difficulty level and operation type, checks the player's answers, and displays the final result.

## 🎯 Features

* Choose the number of questions
* Choose a question difficulty:

  * Easy
  * Medium
  * Hard
  * Mixed
* Choose an operation:

  * Addition `+`
  * Subtraction `-`
  * Multiplication `x`
  * Division `/`
  * Mixed operations
* Generate random questions
* Automatically calculate correct answers
* Check player answers
* Count correct and incorrect answers
* Display the correct answer when the player makes a mistake
* Determine whether the player passed or failed
* Option to play the game again
* Console-based interface

## 🧩 Difficulty Levels

| Level  | Number Range      |
| ------ | ----------------- |
| Easy   | 1 – 10            |
| Medium | 10 – 50           |
| Hard   | 50 – 100          |
| Mixed  | Random difficulty |

## ➕ Supported Operations

| Operation      | Symbol           |
| -------------- | ---------------- |
| Addition       | `+`              |
| Subtraction    | `-`              |
| Multiplication | `x`              |
| Division       | `/`              |
| Mixed          | Random operation |

## 🎮 How the Game Works

1. The player chooses how many questions to answer.
2. The player selects the difficulty level.
3. The player selects the mathematical operation.
4. The program generates random questions.
5. The player enters an answer for each question.
6. The program checks the answer.
7. Correct and incorrect answers are counted.
8. The final result is displayed.
9. The player can choose to play again.

## 🏗️ Main Structures

### `stQuestion`

Stores information about one question:

```cpp
struct stQuestion
{
    int Number1;
    int Number2;
    int CorrectAnswer;
    int PlayerAnswer;
    bool AnswerResult;
    enOperationType OperationType;
    enQuestionLevel QuestionLevel;
};
```

### `stQuizz`

Stores information about the complete quiz:

```cpp
struct stQuizz
{
    stQuestion QuestionList[100];
    short NumberOfQuestions;
    enOperationType OpType;
    enQuestionLevel QuesLevel;
    short NumberOfWrongAnswers;
    short NumberOfRightAnswers;
    bool IsPass;
};
```

## 🧠 C++ Concepts Used

This project demonstrates:

* `struct`
* `enum`
* Functions
* Arrays
* `switch` statements
* Loops
* Conditional statements
* Random number generation
* References
* Type casting
* `rand()` and `srand()`
* Object-like data organization using structures
* Basic input/output
* Function decomposition

## 📂 Project Structure

```text
Math-Quiz-Game/
│
├── main.cpp
└── README.md
```

## ▶️ How to Run

### Using Visual Studio

1. Create a C++ Console Application.
2. Add the source code to `main.cpp`.
3. Build the project.
4. Run the program.
5. Follow the instructions displayed in the console.

### Example

```text
Enter How Many Questions ? 5

Enter Question Level ,[1] Easy ,[2] Mid ,[3] Hard ,[4] MixOp ? 2

Enter Question Type ,[1] Add,[2] Sub,[3] Mul,[4] Div,[5] MixOp ? 5
```

The game will then generate questions and ask the player to enter the answers.

## 📊 Final Result

After completing the quiz, the program displays:

* Pass / Fail result
* Number of questions
* Question level
* Operation type
* Number of right answers
* Number of wrong answers

Example:

```text
----------------------------------

Final Result Is Pass (-:

----------------------------------

Number Of Quesions = 5
Number Level = Midium
Operation Type = Mix
Number Of Right Answers = 4
Number Of Wrong Answers = 1

----------------------------------
```

## 🔄 Play Again

After finishing a quiz, the player can choose whether to start another game:

```text
Do You Want To Play Again(Y/N)?
```

Entering `Y` or `y` starts a new quiz.

## 📚 Purpose

This project was created as a C++ programming practice project to improve understanding of:

* Problem solving
* Functions
* Structures
* Enumerations
* Random data generation
* Control flow
* Modular programming

## 👨‍💻 Author

**Ahmed**

C++ Programming Practice Project
