# 🎮 C Game Hub

A comprehensive collection of interactive console-based games built entirely in C, demonstrating core programming concepts including control structures, functions, data structures, input validation, and string manipulation.

---

## 📋 Project Overview

*C Game Hub* is a menu-driven gaming platform featuring four classic games, all implemented using fundamental C programming concepts. This project showcases why C is considered the "mother of all programming languages" through practical, engaging examples.

### Featured Games

1. *Number Guessing Game* - Test your intuition with strategic guessing
2. *Quiz Game* - Challenge your knowledge across multiple domains
3. *Hangman* - Classic word-guessing puzzle
4. *Rock Paper Scissors* - Best-of-three match against the computer

---

## ✨ Key Features

### Game Mechanics
- *Unified Scoring System*: Accumulate points across all games
- *Color-Coded Interface*: ANSI color codes for enhanced user experience
- *Input Validation*: Robust error handling for all user inputs
- *Replay Options*: Play any game multiple times without restarting

### Technical Highlights
- Modular function-based architecture
- Random number generation using srand() and rand()
- Dynamic string manipulation and character handling
- Buffer management to prevent input overflow
- Array-based data structures for quiz questions and hangman words

---

## 🎯 Game Details

### 1. Number Guessing Game
- *Objective*: Guess a random number between 0-500
- *Attempts*: 10 tries with intelligent hints
- *Scoring*: +10 points for correct guess
- *Features*: 
  - Range validation
  - Progressive hints (higher/lower)
  - Out-of-bounds detection

### 2. Quiz Game
- *Objective*: Answer 5 randomly selected questions
- *Question Pool*: 80+ questions covering technology, science, and general knowledge
- *Scoring*: +5 points per correct answer
- *Features*:
  - Duplicate question prevention
  - Multiple-choice format
  - Instant feedback

### 3. Hangman
- *Objective*: Guess the word letter by letter
- *Attempts*: 6 wrong guesses allowed
- *Scoring*: +15 points for complete word
- *Word Bank*: 70+ programming and technology terms
- *Features*:
  - Case-insensitive input
  - Duplicate guess detection (no penalty)
  - Visual word progress display

### 4. Rock Paper Scissors
- *Objective*: Win best-of-3 rounds against computer
- *Scoring*: +10 points for match victory
- *Features*:
  - Live score tracking
  - Round-by-round results
  - Tie handling

---

## 🚀 Getting Started

### Prerequisites
- GCC compiler (or any C compiler)
- Terminal with ANSI color support (Linux/macOS/Windows Terminal)

### Installation

1. *Clone or Download* the project files

2. *Compile the program*:
   bash
   gcc -o game_hub game_hub.c
   

3. *Run the executable*:
   bash
   ./game_hub
   

### For Windows Users
If colors don't display properly in Command Prompt, use:
- Windows Terminal (recommended)
- PowerShell
- Git Bash
- Or compile without color codes

---

## 🎮 How to Play

1. Launch the program
2. View your current score in the main menu
3. Select a game (1-4) or exit (0)
4. Follow on-screen instructions for each game
5. Choose to replay or return to main menu after each game
6. View final score upon exit

### Input Guidelines
- *Numbers Only*: Where numeric input is required
- *Single Letters*: For Hangman (alphabets only)
- *Menu Choices*: Enter the corresponding number
- *Invalid Input*: The program will prompt you to re-enter

---

## 🛠️ Technical Implementation

### Code Structure

├── Main Function
│   ├── Menu Loop
│   ├── Input Handling
│   └── Game Selection
│
├── Game Functions
│   ├── numberGuessingGame()
│   ├── quizGame()
│   ├── hangmanGame()
│   └── rockPaperScissors()
│
└── Utility
    ├── showMenu()
    └── Global Score Tracking


### Key Concepts Demonstrated

#### Control Structures
- do-while loops for game replay
- switch-case for menu navigation
- while loops for game logic
- Nested conditionals for validation

#### Input Validation Techniques
c
// Numeric validation
if (scanf("%d", &input) != 1) {
    // Handle non-numeric input
}

// Range validation
if (input < min || input > max) {
    // Handle out-of-range input
}

// Buffer clearing
while (getchar() != '\n');


#### String Handling
- strlen() for length calculation
- strcmp() for comparison
- strcspn() for newline removal
- toupper() for case normalization
- isalpha() for character validation

#### Arrays and Data Structures
- 2D arrays for quiz options
- Parallel arrays for questions/answers
- String arrays for word banks
- Boolean arrays for tracking used items

---

## 📊 Scoring System

| Game | Points | Condition |
|------|--------|-----------|
| Number Guessing | +10 | Correct guess within 10 attempts |
| Quiz Game | +5 | Per correct answer (max 25) |
| Hangman | +15 | Complete word guessed |
| Rock Paper Scissors | +10 | Win best-of-3 match |

---

## 🎨 Color Coding

The program uses ANSI escape codes for visual feedback:

- *🔴 RED*: Errors, wrong answers, game over messages
- *🟢 GREEN*: Correct answers, victories, success messages
- *🟡 YELLOW*: Prompts, warnings, neutral information
- *🔵 CYAN*: Headers, titles, game names
- *🟣 MAGENTA*: Final score, exit messages

---

## 📁 Project Components

This project includes three deliverables:

### 1. Source Code (game_hub.c)
The complete C implementation of all four games with comprehensive comments and modular design.

### 2. Presentation (PPT)
*Topic*: "C Game Hub - Interactive Console Gaming Platform"

The presentation covers:
- Project overview and objectives
- Detailed demonstration of each game
- Technical implementation and code structure
- Key C programming concepts applied
- Input validation and error handling techniques
- Scoring system and user experience design
- Challenges faced and solutions implemented
- Future enhancements and learning outcomes

### 3. Poster
*Topic*: "Why C is the Mother of All Programming Languages"

A visual representation explaining C's fundamental role in programming:
- Language family tree showing C's influence
- Key features that influenced successor languages
- Historical significance (Unix, Linux, Windows kernels)
- Use cases and real-world applications
- Why learning C builds strong programming foundations
- How this Game Hub exemplifies core C concepts

---

## 🧠 Learning Outcomes

By studying this project, you'll understand:

1. *Function Modularity*: Breaking programs into reusable components
2. *Input Validation*: Creating robust, error-resistant programs
3. *Random Number Generation*: Using rand() and srand() effectively
4. *String Manipulation*: Working with character arrays and strings
5. *Array Management*: Implementing parallel arrays and indexing
6. *Control Flow*: Mastering loops and conditional statements
7. *User Experience*: Creating interactive console applications
8. *Buffer Management*: Preventing input overflow and clearing buffers

---

## 🔧 Customization Ideas

### Extending the Game Hub

1. *Add More Games*:
   - Tic-Tac-Toe
   - Word Scramble
   - Math Quiz
   - Memory Game

2. *Enhance Existing Games*:
   - Difficulty levels
   - Leaderboard system (file I/O)
   - Timer-based challenges
   - Multiplayer options

3. *Additional Features*:
   - Save/load game progress
   - Custom word banks (user input)
   - Statistics tracking
   - Achievements system

4. *Code Improvements*:
   - Separate header file for declarations
   - Configuration file for game settings
   - Dynamic memory allocation for scalability
   - Cross-platform color support

---

## 📝 Code Conventions

- *UPPERCASE*: Constants and macros
- *camelCase*: Function names
- *lowercase*: Local variables
- *Comments*: Describe purpose, not obvious syntax
- *Indentation*: 2 spaces for readability

---

## ⚠️ Known Limitations

1. *Platform Dependency*: ANSI colors may not work on older Windows CMD
2. *Input Buffer*: Requires manual buffer clearing after scanf()
3. *Fixed Arrays*: Quiz and Hangman use static arrays (no dynamic allocation)
4. *No Persistence*: Scores reset on program restart
5. *Single User*: No multi-player support

---

## 🐛 Troubleshooting

### Issue: Colors not displaying
*Solution*: Use a modern terminal or remove ANSI codes from source

### Issue: Input repeating unexpectedly
*Solution*: Ensure buffer is cleared after each scanf() with while(getchar() != '\n');

### Issue: Compilation warnings
*Solution*: Add -Wall flag and fix any type mismatches or unused variables

---

## 🤝 Contributing

This is a student project, but suggestions are welcome! Areas for improvement:
- Cross-platform compatibility
- Additional games
- Enhanced UI/UX
- Code optimization
- Documentation improvements

---

## 📚 References

### C Programming Resources
- The C Programming Language by Kernighan & Ritchie
- C Standard Library Documentation
- GCC Compiler Documentation

### Concepts Applied
- Modular Programming
- Input Validation Best Practices
- Random Number Generation
- String Manipulation Techniques
- Array-Based Data Structures

---

## 📄 License

This project is created for educational purposes. Feel free to use, modify, and learn from the code.

---

## 🎓 Educational Context

### Why This Project Matters

This Game Hub demonstrates why *C is the mother of all programming languages*:

1. *Foundation Building*: Understanding pointers, memory, and low-level operations
2. *Syntax Influence*: C's syntax influenced C++, Java, C#, JavaScript, and more
3. *Performance*: Direct hardware access for optimal efficiency
4. *Systems Programming*: Operating systems and embedded systems rely on C
5. *Portability*: Write once, compile anywhere
6. *Control*: Manual memory management teaches resource awareness

### Skills Demonstrated
✅ Control flow mastery  
✅ Function design and modularity  
✅ Input validation and error handling  
✅ String and array manipulation  
✅ Random number generation  
✅ User interface design (console-based)  
✅ Code documentation and readability
