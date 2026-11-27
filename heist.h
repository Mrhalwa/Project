#ifndef HEIST_H
#define HEIST_H
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// making enums based on the data given in the manual with the game rules and the data files provided in the project folder
enum GameState
{
    Menu,
    Playing,
    Won,
    Lost,
    Exit
};
enum MenuChoice
{
    New_Game = 1,
    Leader_Board,
    About,
    Rules,
    Quit
};
enum WordRow
{
    Word_1 = 1,
    Word_2 = 2,
    WORD_ONE = 1,
    WORD_TWO = 2
};

// constants for the game

const int WORD_ONE_LENGTH = 7;
const int WORD_TWO_LENGTH = 8;
const int NAME_SIZE = 40;
const int MESSAGE_SIZE = 100;

// data structures for the game
// Tile structure to represent a letter tile on the board
struct Tile
{
    char tileLetter;
    bool filled;
    char letter;
    int word;
    int position;
    Tile() : tileLetter(' '), filled(false), letter('_'), word(0), position(0) {}
};
// Clue structure to represent a clue collected by the detective
struct Clue
{
    char clueLetter;
    int cluePosition;
    WordRow clueRow;
    char letter;
    int word;
    int position;
    Clue()
        : clueLetter(' '), cluePosition(0), clueRow(Word_1),
          letter('_'), word(1), position(0) {}
    Clue(char let, int pos, WordRow row)
        : clueLetter(let), cluePosition(pos), clueRow(row),
          letter(let), word(row == Word_1 ? 1 : 2), position(pos) {}
};

// Location structure to represent a location in the game

struct Location
{
    string locName;
    char letterClueLoc;
    int boardPosLoc;
    WordRow locRow;
    bool locSearchFlag;
    char name[NAME_SIZE];
    char letter;
    int word;
    int position;
    bool searched;
    Location()
        : locName(""), letterClueLoc('_'), boardPosLoc(0), locRow(Word_1), locSearchFlag(false),
          letter('_'), word(1), position(0), searched(false)
    {
        name[0] = '\0';
    }
};
Clue makeClue(char letter, int word, int position);
Location makeLocation(const char *name, char letter, int word, int position);
ostream &operator<<(ostream &out, const Clue &clue);

// Exception classes for error handling

struct LocationRecord
{
    string placeName;
    int boardPos;
    char letters[7];
};

// CharacterRecord structure to represent a character in the game

struct CharacterRecord
{
    string name;
    string role;
    string nationality;
    int boardPos;
    char letters[7];
};

// ClueRecord structure to represent a clue associated with a character

struct ClueRecord
{
    string culpritRole;
    string word1;
    string word2;
};

//Other functions required for the game engine

int stringLength(const char *text);
void copyString(char *destination, const char *source, int maxSize);
char toUpperCase(char c);
bool isLetter(char c);
bool sameTextIgnoreCase(const char *a, const char *b);

// Exception classes for error handling

class GameException
{
protected:
    string message;
    static int wrongTurnAmount;
    static int wrongWordAmount;
public:
    GameException(string msg);
    GameException(const char *text = "Game error");
    virtual ~GameException();
    virtual string getMessage() const;
    virtual int getPenalty() const;
    virtual bool isFatal() const;
    static void setPenalties(int turnAmount, int wordAmount);
};

// Derived exception classes for specific error types

class InvalidWordException : public GameException
{
public:
    InvalidWordException(string msg);
    virtual int getPenalty() const;
};
class RackFullException : public GameException
{
public:
    RackFullException(string msg);
};
class InvalidPositionException : public GameException
{
public:
    InvalidPositionException(string msg);
};
class InvalidInputException : public GameException
{
public:
    InvalidInputException(string msg);
    virtual int getPenalty() const;
};
class InvalidActionException : public GameException
{
public:
    InvalidActionException(string msg);
};
class DataException : public GameException
{
public:
    DataException(string msg);
    virtual bool isFatal() const;
};
class IndexOutOfRangeException : public GameException
{
public:
    IndexOutOfRangeException(const char *text = "Index is out of range!");
};
class InvalidPlacementException : public InvalidPositionException
{
public:
    InvalidPlacementException(const char *text = "Letter cannot be placed there!");
};
class IncompleteWordException : public GameException
{
public:
    IncompleteWordException(const char *text = "Word is incomplete!");
};

// Character classes for the game

class Character
{
protected:
    string char_name;
    string char_role;
    string nationality;
    bool is_culprit;
    char letter;
    int boardPos;
    bool interviewedFlag;
public:
    Character(const string& n, const string& r, const string& nat, bool cul = false);
    Character(const string& n, const string& r, const string& nat, char let, int pos, bool cul = false);
    virtual ~Character();
    virtual void display() const = 0;
    string get_name() const;
    string get_role() const;
    string get_nationality() const;
    bool get_culprit() const;
    string getName() const;
    string getRole() const;
    string getNationality() const;
    bool isCulprit() const;
    void setCulprit(bool value);
    bool isInterviewed() const;
    Clue interview();
    Clue showClueAgain() const;
    virtual void checkAllowed(int credibility) const;
    virtual bool isSuspect() const;
};

// Derived classes for specific character types

class Victim : public Character
{
public:
    Victim(const string& n, const string& nat);
    Victim(const string& n, const string& r, const string& nat, char let, int pos);
    virtual void display() const;
    virtual void checkAllowed(int credibility) const;
    virtual bool isSuspect() const;
};
class Detective : public Character
{
private:
    int cred;
    int turnsUsed;
public:
    Detective(const string& n, int start_cred);
    virtual void display() const;
    int get_cred() const;
    void set_cred(int new_cred);
    int getCredibility() const;
    void loseCredibility(int amount);
    void useTurn();
    int getTurnsUsed() const;
};

// Suspect class representing a suspect character in the game

class Suspect : public Character
{
public:
    Suspect(const string& n, const string& r, const string& nat, bool cul = false);
    Suspect(const string& n, const string& r, const string& nat, char let, int pos, bool cul = false);
    virtual void display() const;
    virtual bool isSuspect() const;
};
class BusinessRelations : virtual public Suspect
{
public:
    BusinessRelations(const string& n, const string& r, const string& nat, bool cul = false);
    BusinessRelations(const string& n, const string& r, const string& nat, char let, int pos, bool cul = false);
    virtual void display() const;
};

// Househelp class representing a house help character in the game

class Househelp : public Suspect
{
public:
    Househelp(const string& n, const string& r, const string& nat, bool cul = false);
    Househelp(const string& n, const string& r, const string& nat, char let, int pos, bool cul = false);
    virtual void display() const;
    virtual void checkAllowed(int credibility) const;
};

// Closerelations class representing a character with close relations in the game

class Closerelations : virtual public Suspect
{
public:
    Closerelations(const string& n, const string& r, const string& nat, bool cul = false);
    Closerelations(const string& n, const string& r, const string& nat, char let, int pos, bool cul = false);
    virtual void display() const;
};

// Partner class representing a business partner character in the game

class Partner : public BusinessRelations
{
public:
    Partner(const string& n, const string& nat, bool cul = false);
    Partner(const string& n, const string& r, const string& nat, char let, int pos);
    virtual void display() const;
    virtual void checkAllowed(int credibility) const;
};

// PA class representing a cook in the game

class Cook : public Househelp
{
public:
    Cook(const string& n, const string& nat, bool cul = false);
    Cook(const string& n, const string& r, const string& nat, char let, int pos);
    virtual void display() const;
};

// Guard class representing a guard in the game

class Guard : public Househelp
{
public:
    Guard(const string& n, const string& nat, bool cul = false);
    Guard(const string& n, const string& r, const string& nat, char let, int pos);
    virtual void display() const;
};

// Servant class representing a servant in the game

class Servant : public Househelp
{
public:
    Servant(const string& n, const string& nat, bool cul = false);
    Servant(const string& n, const string& r, const string& nat, char let, int pos);
    virtual void display() const;
};

// Child class representing a child character in the game

class Child : public Closerelations
{
private:
    int age;
public:
    Child(const string& n, const string& nat, bool cul, int childage);
    Child(const string& n, const string& r, const string& nat, char let, int pos, int childage = 12);
    virtual void display() const;
    int get_age() const;
    virtual void checkAllowed(int credibility) const;
};
class PA : public BusinessRelations, public Closerelations
{
public:
    PA(const string& n, const string& nat, bool cul = false);
    PA(const string& n, const string& r, const string& nat, char let, int pos);
    virtual void display() const;
    virtual void checkAllowed(int credibility) const;
};

// DynamicArray class template for dynamic array implementation

template <class T>
class DynamicArray
{
private:
    T *data;
    int size;
    int capacity;
    void grow()
    {
        int newCapacity = capacity * 2;
        T *bigger = new T[newCapacity];
        for (int i = 0; i < size; i++)
        {
            bigger[i] = data[i];
        }
        delete[] data;
        data = bigger;
        capacity = newCapacity;
    }
public:
    DynamicArray(int startCapacity = 4)
    {
        if (startCapacity < 1)
        {
            startCapacity = 1;
        }
        capacity = startCapacity;
        size = 0;
        data = new T[capacity];
    }
    DynamicArray(const DynamicArray<T> &other)
    {
        capacity = other.capacity;
        size = other.size;
        data = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }
    DynamicArray<T> &operator=(const DynamicArray<T> &other)
    {
        if (this == &other)
        {
            return *this;
        }
        delete[] data;
        capacity = other.capacity;
        size = other.size;
        data = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
        return *this;
    }
    ~DynamicArray()
    {
        delete[] data;
        data = NULL;
    }
    void add(const T &item)
    {
        if (size == capacity)
        {
            grow();
        }
        data[size] = item;
        size++;
    }
    T &operator[](int index)
    {
        if (index < 0 || index >= size)
        {
            throw IndexOutOfRangeException();
        }
        return data[index];
    }
    const T &operator[](int index) const
    {
        if (index < 0 || index >= size)
        {
            throw IndexOutOfRangeException();
        }
        return data[index];
    }
    int getSize() const
    {
        return size;
    }
    bool isEmpty() const
    {
        return size == 0;
    }
    void clear()
    {
        size = 0;
    }
};

// TileRack class representing a rack of letter tiles for the detective

class TileRack
{
private:
    DynamicArray<Tile> tiles;
    int capacity;
public:
    TileRack(int cap = 15);
    bool add(const Clue &clue);
    TileRack &operator+=(const Clue &clue);
    bool contains(char letter) const;
    int getCount() const;
    const Tile &operator[](int index) const;
    void clear();
    void display() const;
    friend ostream &operator<<(ostream &out, const TileRack &rack);
};
class Scrabble
{
private:
    Tile *row1;
    Tile *row2;
    string targetWord1;
    string targetWord2;
    bool row1Solved;
    bool row2Solved;
    Tile *rowPointer(int word) const;
    int rowLength(int word) const;
    void resetRows();
    void copyRowsFrom(const Scrabble &other);
public:
    Scrabble();
    Scrabble(const Scrabble &other);
    Scrabble &operator=(const Scrabble &other);
    ~Scrabble();
    void place(const Clue &clue);
    Scrabble &operator+=(const Clue &clue);
    int filledCount(WordRow row) const;
    bool isRowComplete(WordRow row) const;
    bool isBoardComplete() const;
    void formWord(WordRow row, char *out, int outSize) const;
    bool matchesWord(WordRow row, const char *expected) const;
    void setTargetWords(string word1, string word2);
    bool isRowSolved(WordRow row) const;
    void checkWord(WordRow row, string guess) const;
    void markRowSolved(WordRow row);
    void reset();
    void display() const;
    friend ostream &operator<<(ostream &out, const Scrabble &board);
};
class Cottage
{
private:
    DynamicArray<Location> locations;
public:
    Cottage();
    void addLocation(const Location &place);
    int getCount() const;
    const Location &getLocation(int index) const;
    bool isSearched(int index) const;
    Clue search(int index);
    bool allSearched() const;
    void resetSearched();
    void display() const;
    int getLocationCount() const;
    string getLocationName(int index) const;
    void showMenu() const;
    Clue showClueAgain(int index) const;
    friend ostream &operator<<(ostream &out, const Cottage &cottage);
};
class TextUtil
{
public:
    static bool isLetter(char c);
    static bool isDigit(char c);
    static char toUpperChar(char c);
    static string toUpperText(string text);
    static string trimText(string text);
    static bool isAllLetters(string text);
    static bool isAllDigits(string text);
    static int digitsToNumber(string text);
    static bool sameIgnoreCase(string a, string b);
    static string normalizeRole(string role);
    static string underscoresToSpaces(string text);
    static int splitLine(string line, char separator, string parts[], int maxParts);
};
class ScoreBoard
{
public:
    ScoreBoard();
    void append(string name, string result, int credibility, int turnsLeft, string culpritRole, string date);
    void display() const;
    string getTodayDate() const;
};
class GameEngine
{
public:
    static const int LOCATION_COUNT = 7;
    static const int CHARACTER_COUNT = 8;
    static const int SUSPECT_COUNT = 7;
    static const int WORD1_LENGTH = 7;
    static const int WORD2_LENGTH = 8;
    static const int DEFAULT_MAX_TURNS = 25;
    static const int DEFAULT_CREDIBILITY = 100;
    static const int DEFAULT_WRONG_TURN = 5;
    static const int DEFAULT_WRONG_WORD = 10;
    static const string ROLE_NAMES[7];
private:
    GameState state;
    bool dataLoaded;
    int culpritIndex;
    string culpritRole;
    int maxTurns;
    int startCredibility;
    int wrongTurnAmount;
    int wrongWordAmount;
    string winText;
    string loseText;
    LocationRecord locationTable[7];
    CharacterRecord characterTable[8];
    ClueRecord clueTable[7];
    string aboutText;
    Detective* detective;
    Cottage* cottage;
    Scrabble* scrabble;
    TileRack* rack;
    Character* characters[8];
    ScoreBoard* scoreBoard;
    GameEngine();
    GameEngine(const GameEngine&);
    GameEngine& operator=(const GameEngine&);
    void loadAllData();
    void loadRules();
    void loadCharacters();
    void loadLocations();
    void loadClues();
    void loadAbout();
    string readLine();
    int readNumber(int min, int max);
    bool readYesNo();
    void clearScreen();
    void pause();
    void showTitle();
    void showRules();
    void mainMenuStep();
    void gameMenuStep();
    void showStatus();
    void visitLocation();
    void interviewPerson();
    void viewBoard();
    void placeClue(Clue c);
    void formWord();
    void revealCulprit();
    void accuse();
    string askDetectiveName();
    void createCharacters();
    int findClueRecord(string role);
    void startNewGame();
    void clearGame();
    void checkLoseConditions();
    void endGame();
public:
    ~GameEngine();
    static GameEngine& getInstance();
    void attachScoreBoard(ScoreBoard* board);
    void handleException(GameException& e);
    GameState getState() const;
    void setState(GameState s);
    void runStep();
    void ensureDataLoaded();
    bool isDataLoaded() const;
    int getMaxTurns() const;
    int getStartCredibility() const;
    int getWrongTurnAmount() const;
    int getWrongWordAmount() const;
    string getWinText() const;
    string getLoseText() const;
    string getAboutText() const;
    const LocationRecord& getLocationRecord(int index) const;
    const CharacterRecord& getCharacterRecord(int index) const;
    const ClueRecord& getClueRecord(int index) const;
    int getCulpritIndex() const;
    string getCulpritRole() const;
    Detective* getDetective() const;
    Cottage* getCottage() const;
    Scrabble* getScrabble() const;
    TileRack* getRack() const;
    Character* getCharacter(int index) const;
    #endif
};