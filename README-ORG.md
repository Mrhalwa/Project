# The Locker Heist

## Course Project

**Course:** CL1004 - Object Oriented Programming  
**Project:** The Locker Heist  
**Semester:** Fall 2026

## Team

Add each registered team member, roll number, and GitHub account before submission.

| Name | Roll Number | Work Description |
|---|---|---|
| [Student 1 Name] | [25F-XXXX] | Modules and testing |
| [Student 2 Name] | [25F-XXXX] | Modules and testing |

The team is limited to 2 members. GitHub commit history must be preserved by each member.

## Build and Run

Open a terminal in this project folder and compile with:

```text
g++ main.cpp heist.cpp -o heist.exe
```

Run the executable:

```text
heist.exe
```

The project can also be added to a Visual Studio C++ console project with `main.cpp` and `heist.cpp`, and `heist.h` included from the header.

## Required Files

- `heist.h` contains enums, structs, constants, exception classes, and class declarations.
- `heist.cpp` contains all class implementations and file-handling logic.
- `main.cpp` contains only the main loop and top-level exception handling.
- `characters.txt` stores the eight character profiles.
- `locations.txt` stores the seven cottage locations.
- `clue.txt` stores the culprit-role word pairs.
- `rules.txt` stores the turn and credibility rules.
- `about.txt` stores the project and team description.
- `leader/scoreBoard.txt` stores completed games.

Keep all text files in the same folder as the executable.

## Implemented Features

- Menu-driven detective game.
- Random culprit selection.
- Seven-location and eight-character investigation.
- Dynamic Scrabble board and tile rack.
- Abstract character hierarchy and polymorphism.
- Single, multiple, virtual, composition, aggregation, and association relationships.
- Dynamic arrays implemented with templates.
- Custom exception handling.
- Persistent win and lose results.
- File-based game data and score board.

## Submission Notes

Before submission:

1. Replace all `[Student]`, `[25F-XXXX]`, and `[Instructor Name]` placeholders.
2. Add the actual GitHub repository URL to the report and title page.
3. Add the report class diagram and output screenshots.
4. Make meaningful commits from each registered team member.

## Known Limitations

- The interface is a Windows-style console interface.
- Screen clearing depends on `system("cls")`.
- The score board is plain text rather than a database.
- All file locations are relative to the executable folder.
