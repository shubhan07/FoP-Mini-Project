#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

/* ANSI COLORS */
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

int totalScore = 0;

/* Function Declarations */
void showMenu();
void numberGuessingGame();
void quizGame();
void hangmanGame();
void rockPaperScissors();

/* ================= MAIN ================= */
int main()
{
  int choice;
  srand(time(0));

  do
  {
    showMenu();
    printf(YELLOW "\nEnter your choice (0-4): " RESET);

    if (scanf("%d", &choice) != 1)
    {
      printf(RED "Invalid input!\n" RESET);
      while (getchar() != '\n')
        ;
      continue;
    }
    while (getchar() != '\n')
      ; // CLEAR BUFFER

    switch (choice)
    {
    case 1:
      numberGuessingGame();
      break;
    case 2:
      quizGame();
      break;
    case 3:
      hangmanGame();
      break;
    case 4:
      rockPaperScissors();
      break;
    case 0:
      printf(MAGENTA "\nFINAL SCORE: %d\n" RESET, totalScore);
      printf(GREEN "Thank you for playing!\n" RESET);
      break;
    default:
      printf(RED "Invalid choice.\n" RESET);
    }

  } while (choice != 0);

  return 0;
}

/* ================= MENU ================= */
void showMenu()
{
  printf(CYAN "\n+--------------------------------------------+\n");
  printf("|                 GAME HUB                   |\n");
  printf("+--------------------------------------------+\n");
  printf("| Current Score : %-24d   |\n", totalScore);
  printf("+--------------------------------------------+\n");
  printf("| 1 | Number Guessing Game                   |\n");
  printf("| 2 | Quiz Game                              |\n");
  printf("| 3 | Hangman Game                           |\n");
  printf("| 4 | Rock Paper Scissors                    |\n");
  printf("| 0 | Exit                                   |\n");
  printf("+--------------------------------------------+\n" RESET);
}

/* ================= GAME 1 ================= */
void numberGuessingGame()
{
  int again;

  do
  {
    int target = rand() % 501; // Range: 0–500
    int guess;
    int attempts = 0;

    printf(CYAN "\nNUMBER GUESSING GAME\n" RESET);
    printf("Guess a number between 0 and 500\n");
    printf("You have 10 attempts\n\n");

    while (attempts < 10)
    {
      printf(YELLOW "Attempt %d: " RESET, attempts + 1);

      /* Validate numeric input */
      if (scanf("%d", &guess) != 1)
      {
        printf(RED "Invalid input! Enter a number only.\n" RESET);
        while (getchar() != '\n')
          ; // clear buffer
        continue;
      }

      /* Validate range */
      if (guess < 0 || guess > 500)
      {
        printf(RED "Out of range! Enter a number between 0 and 500.\n" RESET);
        continue;
      }

      attempts++;

      if (guess == target)
      {
        printf(GREEN "Correct! You guessed the number.\n" RESET);
        totalScore += 10;
        break;
      }
      else if (guess > target)
        printf("Hint: Guess lower\n");
      else
        printf("Hint: Guess higher\n");
    }

    if (guess != target)
      printf(RED "Game Over! The number was %d\n" RESET, target);

    printf("\n1. Play Again\n0. Main Menu\nEnter choice: ");
    while (scanf("%d", &again) != 1)
    {
      printf(RED "Enter 1 or 0 only: " RESET);
      while (getchar() != '\n')
        ;
    }
    while (getchar() != '\n')
      ; // clear buffer

  } while (again == 1);
}

/* ================= GAME 2 ================= */
void quizGame()
{
  int again;
  do
  {
    const char *questions[] = {
        "Red Planet?", "Capital of France?", "Largest ocean?",
        "Gas used by plants?", "Fastest land animal?",
        "Inventor of telephone?", "System programming language?",
        "H2O is?", "Number of continents?", "Temperature measured by?",
        "Father of C language?", "Binary of 2?", "Capital of India?",
        "CPU stands for?", "RAM is?", "Smallest prime number?",
        "Speed of light unit?", "Primary color?", "HTML used for?",
        "Internet protocol?",
        "Earth revolves around?", "Largest mammal?",
        "Hard disk is?", "1 byte equals?", "Who invented computer?",
        "Brain of computer?", "Full form of USB?",
        "Keyboard is?", "ALU does?",
        "Gas in air most?",
        "Sun is a?", "Square root of 64?",
        "Which is OS?", "Which is input device?",
        "First programmer?", "Largest planet?",
        "Which is volatile memory?",
        "What is C?", "Number system base of binary?",
        "Monitor is?",
        "URL stands for?", "Shortcut copy?",
        "Fastest memory?", "LAN stands for?",
        "Primary memory?", "Smallest unit of data?",
        "Hard disk stores?",
        "Who invented WWW?",
        "ISP stands for?",
        "Which is not OS?",
        "2+2*2?",
        "Earth shape?",
        "RAM is?",
        "Which is compiler?",
        "Keyboard shortcut paste?",
        "Largest continent?",
        "Linux is?",
        "IP address is?",
        "Which is browser?",
        "C is?",
        "Which is output device?",
        "Binary of 5?",
        "Which is programming language?",
        "Which is secondary memory?",
        "Full form of CPU?",
        "Which stores permanent data?",
        "Which is fastest CPU register?",
        "What is AI?",
        "WWW stands for?",
        "Which is not programming language?",
        "Smallest OS unit?",
        "Which is antivirus?",
        "Which is spreadsheet software?",
        "Capital of Japan?",
        "Largest desert?",
        "Sound unit?",
        "Which is email protocol?",
        "Which is logic gate?",
        "Who is CEO of Microsoft?",
        "Which is cloud service?",
        "Which is mobile OS?",
        "Which is search engine?",
        "Which is C header file?",
        "Which is loop?",
        "Which is conditional?",
        "Which is data type?",
        "Which is operator?",
        "Which is function?"};

    const char *options[][3] = {
        {"Venus", "Mars", "Jupiter"},
        {"Berlin", "Madrid", "Paris"},
        {"Indian", "Pacific", "Atlantic"},
        {"Oxygen", "Carbon Dioxide", "Nitrogen"},
        {"Lion", "Cheetah", "Tiger"},
        {"Newton", "Bell", "Edison"},
        {"Python", "C", "HTML"},
        {"Salt", "Water", "Oxygen"},
        {"5", "6", "7"},
        {"Barometer", "Thermometer", "Hygrometer"},
        {"Dennis Ritchie", "Bjarne", "Jobs"},
        {"10", "01", "11"},
        {"Mumbai", "Delhi", "Chennai"},
        {"Central", "Control", "Computer"},
        {"Memory", "Register", "Disk"},
        {"0", "1", "2"},
        {"m/s", "km/h", "kg"},
        {"Red", "Green", "Blue"},
        {"Design", "Markup", "Compile"},
        {"TCP", "HTTP", "IP"},
        {"Moon", "Sun", "Mars"},
        {"Elephant", "Blue Whale", "Giraffe"},
        {"Primary", "Secondary", "Cache"},
        {"4 bits", "8 bits", "16 bits"},
        {"Charles", "Babbage", "Alan"},
        {"Monitor", "CPU", "Keyboard"},
        {"Universal", "United", "User"},
        {"Input", "Output", "Process"},
        {"Add", "Subtract", "Calculate"},
        {"Oxygen", "Nitrogen", "Carbon"},
        {"Star", "Planet", "Moon"},
        {"6", "7", "8"},
        {"Windows", "HTML", "CPU"},
        {"Mouse", "Monitor", "Printer"},
        {"Ada", "Grace Hopper", "Marie"},
        {"Earth", "Mars", "Jupiter"},
        {"ROM", "RAM", "Cache"},
        {"Language", "Compiler", "OS"},
        {"2", "8", "10"},
        {"Input", "Output", "Process"},
        {"Uniform", "Universal", "Unique"},
        {"Ctrl+C", "Ctrl+V", "Ctrl+X"},
        {"Cache", "RAM", "Disk"},
        {"Local", "Large", "Logical"},
        {"RAM", "ROM", "Cache"},
        {"Bit", "Byte", "Nibble"},
        {"Temp", "Permanent", "Volatile"},
        {"Tim", "Berners-Lee", "Jobs"},
        {"Internet", "Service", "Server"},
        {"Linux", "Windows", "Oracle"},
        {"6", "8", "4"},
        {"Round", "Flat", "Oval"},
        {"Temporary", "Permanent", "Backup"},
        {"GCC", "Linker", "Editor"},
        {"Ctrl+V", "Ctrl+X", "Ctrl+C"},
        {"Asia", "Africa", "Europe"},
        {"Kernel", "OS", "App"},
        {"Logical", "Network", "Device"},
        {"Chrome", "Google", "Yahoo"},
        {"Language", "OS", "Tool"},
        {"Printer", "Scanner", "Mouse"},
        {"101", "110", "111"},
        {"HTML", "Python", "CSS"},
        {"RAM", "ROM", "Register"},
        {"Central", "Control", "Compute"},
        {"RAM", "ROM", "Cache"},
        {"Register", "Cache", "RAM"},
        {"Artificial", "Human", "Logical"},
        {"World", "Wide", "Web"},
        {"HTML", "Python", "Paint"},
        {"Process", "Thread", "Kernel"},
        {"Avast", "Excel", "Chrome"},
        {"Excel", "Word", "Paint"},
        {"Tokyo", "Osaka", "Kyoto"},
        {"Sahara", "Gobi", "Thar"},
        {"Hz", "dB", "Watt"},
        {"SMTP", "FTP", "HTTP"},
        {"AND", "OR", "NOT"},
        {"Satya", "Bill", "Elon"},
        {"AWS", "Windows", "Linux"},
        {"Android", "Linux", "DOS"},
        {"Google", "Chrome", "Edge"},
        {"stdio.h", "math.h", "string.h"},
        {"for", "if", "switch"},
        {"if", "else", "loop"},
        {"int", "float", "print"},
        {"+", "-", "*"},
        {"main", "printf", "scanf"}};

    int answers[100] = {
        2, 3, 2, 2, 2, 2, 2, 2, 3, 2,
        1, 1, 2, 3, 1, 3, 1, 1, 2, 3,
        2, 2, 2, 2, 2, 2, 1, 1, 3, 2,
        1, 1, 1, 1, 3, 1, 1, 2, 1, 1,
        1, 1, 1, 1, 2, 2, 2, 1, 3, 1,
        1, 2, 1, 1, 1, 2, 1, 2, 1, 1,
        1, 2, 1, 1, 1, 2, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    int used[100] = {0};
    int q = rand() % 100;

    printf(CYAN "\nQUIZ GAME\n" RESET);

    for (int i = 0; i < 5; i++)
    {
      int q;
      do
      {
        q = rand() % 10;
      } while (used[q]);
      used[q] = 1;

      int ans;
      printf("\nQ%d. %s\n", i + 1, questions[q]);
      printf("1.%s  2.%s  3.%s\n",
             options[q][0], options[q][1], options[q][2]);

      while (1)
      {
        printf("Answer (1-3): ");
        if (scanf("%d", &ans) != 1)
        {
          printf(RED "Numbers only!\n" RESET);
          while (getchar() != '\n')
            ;
          continue;
        }
        while (getchar() != '\n')
          ;

        if (ans < 1 || ans > 3)
        {
          printf(YELLOW "Choose 1-3 only.\n" RESET);
          continue;
        }
        break;
      }

      if (ans == answers[q])
      {
        printf(GREEN "Correct!\n" RESET);
        totalScore += 5;
      }
      else
        printf(RED "Wrong!\n" RESET);
    }

    printf("\n1. Play Again\n0. Main Menu\nEnter choice: ");
    scanf("%d", &again);
    while (getchar() != '\n')
      ;

  } while (again == 1);
}

/* ================= GAME 3 ================= */
void hangmanGame()
{
  int again;

  do
  {
    const char *words[] = {
        "PROGRAM", "COMPUTER", "SCIENCE", "VARIABLE", "FUNCTION", "COMPILER",
        "KEYBOARD", "MONITOR", "PROCESSOR", "MEMORY", "LANGUAGE", "SOFTWARE",
        "HARDWARE", "ALGORITHM", "DEBUGGER", "OPERATOR", "SYNTAX", "LOGIC",
        "NETWORK", "DATABASE", "INTEGER", "CHARACTER", "POINTER", "STRUCTURE",
        "ARRAY", "LOOP", "CONDITION", "BOOLEAN", "STRING", "FLOAT",
        "DOUBLE", "HEADER", "SOURCE", "OBJECT", "LINKER", "EXECUTION",
        "TERMINAL", "COMMAND", "LINUX", "WINDOWS", "PYTHON", "JAVASCRIPT",
        "DEVELOPER", "ENGINEER", "SECURITY", "ENCRYPTION", "INTERNET",
        "SERVER", "CLIENT", "ROUTER", "SWITCH", "PROTOCOL", "CLOUD",
        "VIRTUAL", "THREAD", "PROCESS", "STACK", "QUEUE", "HEAP",
        "COMPILATION", "INTERPRETER", "BINARY", "DIGITAL", "ANALOG",
        "ELECTRONICS", "MICROCONTROLLER", "ASSEMBLY", "REGISTER",
        "FIRMWARE", "OPERATINGSYSTEM", "KERNEL", "DRIVER", "DEVICE"};

    int wordCount = sizeof(words) / sizeof(words[0]);

    char display[50];
    char buffer[100];
    int attempts = 6;

    int w = rand() % wordCount;
    int len = strlen(words[w]);

    /* Initialize display */
    for (int i = 0; i < len; i++)
      display[i] = '_';
    display[len] = '\0';

    printf(CYAN "\nHANGMAN GAME\n" RESET);
    printf("Rules:\n");
    printf("- Enter ONE letter only\n");
    printf("- Repeating a guessed letter does NOT reduce attempts\n");
    printf("- %d attempts allowed\n\n", attempts);

    while (attempts > 0)
    {
      printf("Word: ");
      for (int i = 0; i < len; i++)
        printf("%c ", display[i]);

      printf("\nEnter a letter: ");

      if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        break;

      buffer[strcspn(buffer, "\n")] = '\0';

      /* Validate input */
      if (strlen(buffer) != 1 || !isalpha(buffer[0]))
      {
        printf(RED "Invalid input! Enter ONE alphabet letter only.\n" RESET);
        continue;
      }

      char guess = toupper(buffer[0]);
      int found = 0;
      int alreadyGuessed = 0;

      /* Check if already guessed */
      for (int i = 0; i < len; i++)
      {
        if (display[i] == guess)
        {
          alreadyGuessed = 1;
          break;
        }
      }

      if (alreadyGuessed)
      {
        printf(YELLOW "You already guessed '%c'. Try another letter.\n" RESET, guess);
        continue;
      }

      /* Reveal guessed letter */
      for (int i = 0; i < len; i++)
      {
        if (words[w][i] == guess)
        {
          display[i] = guess;
          found = 1;
        }
      }

      if (!found)
      {
        attempts--;
        printf(RED "Wrong! Attempts left: %d\n" RESET, attempts);
      }

      /* Win check */
      if (strcmp(display, words[w]) == 0)
      {
        printf(GREEN "You guessed the word: %s\n" RESET, words[w]);
        totalScore += 15;
        break;
      }
    }

    if (attempts == 0)
      printf(RED "Game Over! The word was %s\n" RESET, words[w]);

    printf("\n1. Play Again\n0. Main Menu\nEnter choice: ");
    while (scanf("%d", &again) != 1)
    {
      printf(RED "Enter 1 or 0 only: " RESET);
      while (getchar() != '\n')
        ;
    }
    while (getchar() != '\n')
      ; /* Clear input buffer */

  } while (again == 1);
}

/* ================= GAME 4 ================= */
void rockPaperScissors()
{
  int again;

  do
  {
    int user, comp;
    int userWins = 0, compWins = 0, rounds = 0;
    const char *choices[] = {"Rock", "Paper", "Scissors"};

    printf(CYAN "\nROCK PAPER SCISSORS (BEST OF 3)\n" RESET);
    printf("Rules:\n");
    printf("- First to win 2 rounds wins the match\n");
    printf("- Each round result is shown\n\n");

    while (userWins < 2 && compWins < 2 && rounds < 3)
    {
      rounds++;

      printf(YELLOW "\nRound %d\n" RESET, rounds);
      printf("1. Rock\n2. Paper\n3. Scissors\n");
      printf("Enter choice: ");

      /* Input validation */
      if (scanf("%d", &user) != 1)
      {
        printf(RED "Invalid input! Enter a number.\n" RESET);
        while (getchar() != '\n')
          ;
        rounds--;
        continue;
      }

      if (user < 1 || user > 3)
      {
        printf(RED "Choose only 1, 2, or 3.\n" RESET);
        rounds--;
        continue;
      }

      comp = rand() % 3;

      printf("You chose: %s\n", choices[user - 1]);
      printf("Computer chose: %s\n", choices[comp]);

      /* Decide round winner */
      if (user - 1 == comp)
      {
        printf(YELLOW "Result: Tie\n" RESET);
      }
      else if ((user == 1 && comp == 2) ||
               (user == 2 && comp == 0) ||
               (user == 3 && comp == 1))
      {
        printf(GREEN "Result: You win this round\n" RESET);
        userWins++;
      }
      else
      {
        printf(RED "Result: Computer wins this round\n" RESET);
        compWins++;
      }

      printf("Score → You: %d | Computer: %d\n", userWins, compWins);
    }

    /* Match result */
    if (userWins > compWins)
    {
      printf(GREEN "\nYou win the match!\n" RESET);
      totalScore += 10;
    }
    else if (compWins > userWins)
    {
      printf(RED "\nComputer wins the match!\n" RESET);
    }
    else
    {
      printf(YELLOW "\nMatch tied!\n" RESET);
    }

    printf("\n1. Play Again\n0. Main Menu\nEnter choice: ");
    while (scanf("%d", &again) != 1)
    {
      printf(RED "Enter 1 or 0 only: " RESET);
      while (getchar() != '\n')
        ;
    }
    while (getchar() != '\n')
      ; // clear buffer

  } while (again == 1);
}
