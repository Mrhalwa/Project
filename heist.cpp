#include "heist.h"

// Implementation of the Character class and its derived classes

Character::Character(const string& n, const string& r, const string& nat, bool cul)
    : char_name(n), char_role(r), nationality(nat), is_culprit(cul),
      letter(' '), boardPos(0), interviewedFlag(false)
{
}
Character::Character(const string& n, const string& r, const string& nat, char let, int pos, bool cul)
    : char_name(n), char_role(r), nationality(nat), is_culprit(cul),
      letter(let), boardPos(pos), interviewedFlag(false)
{
}

//==============Implementation of the Character class methods==================

Character::~Character()
{
}
string Character::get_name() const
{
    return char_name;
}
string Character::get_role() const
{
    return char_role;
}
string Character::get_nationality() const
{
    return nationality;
}
bool Character::get_culprit() const
{
    return is_culprit;
}
string Character::getName() const
{
    return char_name;
}
string Character::getRole() const
{
    return char_role;
}
string Character::getNationality() const
{
    return nationality;
}
bool Character::isCulprit() const
{
    return is_culprit;
}
void Character::setCulprit(bool value)
{
    is_culprit = value;
}
bool Character::isInterviewed() const
{
    return interviewedFlag;
}

// =================Implementation of the Clue structure=================

Clue Character::interview()
{
    interviewedFlag = true;
    Clue c;
    c.clueLetter = letter;
    c.letter = letter;
    c.cluePosition = boardPos;
    c.position = boardPos;
    c.clueRow = Word_2;
    c.word = 2;
    return c;
}
Clue Character::showClueAgain() const
{
    Clue c;
    c.clueLetter = letter;
    c.letter = letter;
    c.cluePosition = boardPos;
    c.position = boardPos;
    c.clueRow = Word_2;
    c.word = 2;
    return c;
}

//Implementation of different functions of character class

void Character::checkAllowed(int) const
{
}
bool Character::isSuspect() const
{
    return false;
}

// =================Implementation of the Victim class==================

Victim::Victim(const string& n, const string& nat)
    : Character(n, "Victim", nat, false)
{
}
Victim::Victim(const string& n, const string& r, const string& nat, char let, int pos)
    : Character(n, r, nat, let, pos, false)
{
}

// Display method for Victim class

void Victim::display() const
{
    cout << char_name << " (" << char_role << ") - " << (interviewedFlag ? "Interviewed" : "NOT Interviewed");
}
void Victim::checkAllowed(int credibility) const
{
    if (credibility < 80)
    {
        throw InvalidActionException("Mr. Leonardo will only talk to you if your credibility is at least 80.");
    }
}
bool Victim::isSuspect() const
{
    return false;
}

// =============Implementation of the Detective class==============

Detective::Detective(const string& n, int start_cred)
    : Character(n, "Detective", "", false), cred(100), turnsUsed(0)
{
    set_cred(start_cred);
}

//Displaying detective information and credibility

void Detective::display() const
{
    cout << "\n--- Detective Information ---" << endl;
    cout << "Name: " << char_name << endl;
    cout << "Role: " << char_role << endl;
    cout << "Credibility: " << cred << endl;
}
int Detective::get_cred() const
{
    return cred;
}
void Detective::set_cred(int new_cred)
{
    if (new_cred < 0)
    {
        cred = 0;
    }
    else if (new_cred > 100)
    {
        cred = 100;
    }
    else
    {
        cred = new_cred;
    }
}

//Implementation of credibility and turns used by detectice

int Detective::getCredibility() const
{
    return cred;
}
void Detective::loseCredibility(int amount)
{
    set_cred(cred - amount);
}
void Detective::useTurn()
{
    turnsUsed++;
}
int Detective::getTurnsUsed() const
{
    return turnsUsed;
}

// ===========Implementation of the Suspect class==========

Suspect::Suspect(const string& n, const string& r, const string& nat, bool cul)
    : Character(n, r, nat, cul)
{
}
Suspect::Suspect(const string& n, const string& r, const string& nat, char let, int pos, bool cul)
    : Character(n, r, nat, let, pos, cul)
{
}
void Suspect::display() const
{
    cout << char_name << " (" << char_role << ") - " << (interviewedFlag ? "Interviewed" : "NOT Interviewed");
}
bool Suspect::isSuspect() const
{
    return true;
}

// ===========Implementation of the BusinessRelations class==========

BusinessRelations::BusinessRelations(const string& n, const string& r, const string& nat, bool cul)
    : Suspect(n, r, nat, cul)
{
}
BusinessRelations::BusinessRelations(const string& n, const string& r, const string& nat, char let, int pos, bool cul)
    : Suspect(n, r, nat, let, pos, cul)
{
}
void BusinessRelations::display() const
{
    cout << char_name << " (" << char_role << ") - " << (interviewedFlag ? "Interviewed" : "NOT Interviewed");
}
Househelp::Househelp(const string& n, const string& r, const string& nat, bool cul)
    : Suspect(n, r, nat, cul)
{
}

// ===========Implementation of the Househelp class==========

Househelp::Househelp(const string& n, const string& r, const string& nat, char let, int pos, bool cul)
    : Suspect(n, r, nat, let, pos, cul)
{
}
void Househelp::display() const
{
    cout << char_name << " (" << char_role << ") - " << (interviewedFlag ? "Interviewed" : "NOT Interviewed");
}
void Househelp::checkAllowed(int) const
{
}

// ===========Implementation of the Closerelations class==========

Closerelations::Closerelations(const string& n, const string& r, const string& nat, bool cul)
    : Suspect(n, r, nat, cul)
{
}
Closerelations::Closerelations(const string& n, const string& r, const string& nat, char let, int pos, bool cul)
    : Suspect(n, r, nat, let, pos, cul)
{
}
void Closerelations::display() const
{
    cout << char_name << " (" << char_role << ") - " << (interviewedFlag ? "Interviewed" : "NOT Interviewed");
}

// ===========Implementation of the Partner class==========

Partner::Partner(const string& n, const string& nat, bool cul)
    : Suspect(n, "Partner", nat, cul),
      BusinessRelations(n, "Partner", nat, cul)
{
}
Partner::Partner(const string& n, const string& r, const string& nat, char let, int pos)
    : Suspect(n, r, nat, let, pos, false),
      BusinessRelations(n, r, nat, let, pos, false)
{
}
void Partner::display() const
{
    cout << char_name << " (" << char_role << ") - " << (interviewedFlag ? "Interviewed" : "NOT Interviewed");
}
void Partner::checkAllowed(int credibility) const
{
    if (credibility < 50)
    {
        throw InvalidActionException("Partners will only talk to you if your credibility is at least 50.");
    }
}

// ===========Implementation of the cook class==========

Cook::Cook(const string& n, const string& nat, bool cul)
    : Househelp(n, "Cook", nat, cul)
{
}
Cook::Cook(const string& n, const string& r, const string& nat, char let, int pos)
    : Househelp(n, r, nat, let, pos, false)
{
}
void Cook::display() const
{
    cout << char_name << " (" << char_role << ") - " << (interviewedFlag ? "Interviewed" : "NOT Interviewed");
}


// ===========Implementation of the guard class==========

Guard::Guard(const string& n, const string& nat, bool cul)
    : Househelp(n, "Guard", nat, cul)
{
}
Guard::Guard(const string& n, const string& r, const string& nat, char let, int pos)
    : Househelp(n, r, nat, let, pos, false)
{
}
void Guard::display() const
{
    cout << char_name << " (" << char_role << ") - " << (interviewedFlag ? "Interviewed" : "NOT Interviewed");
}

// ===========Implementation of the servant class==========


Servant::Servant(const string& n, const string& nat, bool cul)
    : Househelp(n, "Servant", nat, cul)
{
}
Servant::Servant(const string& n, const string& r, const string& nat, char let, int pos)
    : Househelp(n, r, nat, let, pos, false)
{
}
void Servant::display() const
{
    cout << char_name << " (" << char_role << ") - " << (interviewedFlag ? "Interviewed" : "NOT Interviewed");
}

// ===========Implementation of the child class==========

Child::Child(const string& n, const string& nat, bool cul, int childage)
    : Suspect(n, "Child", nat, cul),
      Closerelations(n, "Child", nat, cul),
      age(childage)
{
}
Child::Child(const string& n, const string& r, const string& nat, char let, int pos, int childage)
    : Suspect(n, r, nat, let, pos, false),
      Closerelations(n, r, nat, let, pos, false),
      age(childage)
{
}
void Child::display() const
{
    cout << char_name << " (" << char_role << ") - " << (interviewedFlag ? "Interviewed" : "NOT Interviewed");
}
int Child::get_age() const
{
    return age;
}
void Child::checkAllowed(int credibility) const
{
    if (credibility < 75)
    {
        throw InvalidActionException("Ms. Celine will only talk to you if your credibility is at least 75.");
    }
}

// ===========Implementation of the PA class==========

PA::PA(const string& n, const string& nat, bool cul)
    : Suspect(n, "PA", nat, cul),
      BusinessRelations(n, "PA", nat, cul),
      Closerelations(n, "PA", nat, cul)
{
}
PA::PA(const string& n, const string& r, const string& nat, char let, int pos)
    : Suspect(n, r, nat, let, pos, false),
      BusinessRelations(n, r, nat, let, pos, false),
      Closerelations(n, r, nat, let, pos, false)
{
}
void PA::display() const
{
    cout << char_name << " (" << char_role << ") - " << (interviewedFlag ? "Interviewed" : "NOT Interviewed");
}

// Checking if the detective has enough credibility to interview the PA

void PA::checkAllowed(int credibility) const
{
    if (credibility < 35)
    {
        throw InvalidActionException("Mr. Jad will only talk to you if your credibility is at least 35.");
    }
}

int stringLength(const char *text)
{
    int count = 0;
    while (text[count] != '\0')
    {
        count++;
    }
    return count;
}
void copyString(char *destination, const char *source, int maxSize)
{
    int i = 0;
    while (source[i] != '\0' && i < maxSize - 1)
    {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}
char toUpperCase(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return (char)(c - 'a' + 'A');
    }
    return c;
}
bool isLetter(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
bool sameTextIgnoreCase(const char *a, const char *b)
{
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0')
    {
        if (toUpperCase(a[i]) != toUpperCase(b[i]))
        {
            return false;
        }
        i++;
    }
    return a[i] == '\0' && b[i] == '\0';
}

// ===Implementation of the Clue and Location structures, and related functions===

Clue makeClue(char letter, int word, int position)
{
    Clue c;
    c.letter = letter;
    c.clueLetter = letter;
    c.word = word;
    c.clueRow = (word == 1 ? Word_1 : Word_2);
    c.position = position;
    c.cluePosition = position;
    return c;
}
Location makeLocation(const char *name, char letter, int word, int position)
{
    Location l;
    l.locName = name;
    copyString(l.name, name, NAME_SIZE);
    l.letter = letter;
    l.letterClueLoc = letter;
    l.word = word;
    l.locRow = (word == 1 ? Word_1 : Word_2);
    l.position = position;
    l.boardPosLoc = position;
    l.searched = false;
    l.locSearchFlag = false;
    return l;
}

//using ostream to display the clue information

ostream &operator<<(ostream &out, const Clue &clue)
{
    out << "Letter " << (clue.letter != '_' && clue.letter != ' ' ? clue.letter : clue.clueLetter)
        << " collected at position " << (clue.position != 0 ? clue.position : clue.cluePosition)
        << " of Word " << (clue.word != 0 ? clue.word : (clue.clueRow == Word_1 ? 1 : 2)) << ".";
    return out;
}
IndexOutOfRangeException::IndexOutOfRangeException(const char *text)
    : GameException(text)
{
}
InvalidPlacementException::InvalidPlacementException(const char *text)
    : InvalidPositionException(text)
{
}
IncompleteWordException::IncompleteWordException(const char *text)
    : GameException(text)
{
}

// ===========Implementation of the TileRack class==========

TileRack::TileRack(int cap)
{
    capacity = cap;
}
bool TileRack::add(const Clue &clue)
{
    int w = (clue.word != 0 ? clue.word : (clue.clueRow == Word_1 ? 1 : 2));
    int pos = (clue.position != 0 ? clue.position : clue.cluePosition);
    char let = (clue.letter != '_' && clue.letter != ' ' ? clue.letter : clue.clueLetter);
    for (int i = 0; i < tiles.getSize(); i++)
    {
        if (tiles[i].word == w && tiles[i].position == pos)
        {
            return false;
        }
    }
    if (capacity > 0 && tiles.getSize() >= capacity)
    {
        throw RackFullException("The rack is full.");
    }
    Tile t;
    t.letter = toUpperCase(let);
    t.tileLetter = t.letter;
    t.word = w;
    t.position = pos;
    t.filled = true;
    tiles.add(t);
    return true;
}
TileRack &TileRack::operator+=(const Clue &clue)
{
    add(clue);
    return *this;
}
bool TileRack::contains(char letter) const
{
    char wanted = toUpperCase(letter);
    for (int i = 0; i < tiles.getSize(); i++)
    {
        if (tiles[i].letter == wanted)
        {
            return true;
        }
    }
    return false;
}
int TileRack::getCount() const
{
    return tiles.getSize();
}
const Tile &TileRack::operator[](int index) const
{
    return tiles[index];
}
void TileRack::clear()
{
    tiles.clear();
}
void TileRack::display() const
{
    cout << *this;
}

// Overloaded operator<< to display the contents of the TileRack

ostream &operator<<(ostream &out, const TileRack &rack)
{
    if (rack.tiles.isEmpty())
    {
        out << "Rack: (empty)" << endl;
    }
    else
    {
        out << "Rack: ";
        for (int i = 0; i < rack.tiles.getSize(); i++)
        {
            out << rack.tiles[i].letter << ' ';
        }
        out << endl;
    }
    return out;
}

// ===========Implementation of the Scrabble class==========

Scrabble::Scrabble()
{
    row1 = new Tile[WORD_ONE_LENGTH];
    row2 = new Tile[WORD_TWO_LENGTH];
    targetWord1 = "";
    targetWord2 = "";
    row1Solved = false;
    row2Solved = false;
    resetRows();
}
Scrabble::Scrabble(const Scrabble &other)
{
    row1 = new Tile[WORD_ONE_LENGTH];
    row2 = new Tile[WORD_TWO_LENGTH];
    targetWord1 = other.targetWord1;
    targetWord2 = other.targetWord2;
    row1Solved = other.row1Solved;
    row2Solved = other.row2Solved;
    copyRowsFrom(other);
}
Scrabble &Scrabble::operator=(const Scrabble &other)
{
    if (this == &other)
    {
        return *this;
    }
    targetWord1 = other.targetWord1;
    targetWord2 = other.targetWord2;
    row1Solved = other.row1Solved;
    row2Solved = other.row2Solved;
    copyRowsFrom(other);
    return *this;
}
Scrabble::~Scrabble()
{
    delete[] row1;
    delete[] row2;
    row1 = NULL;
    row2 = NULL;
}
void Scrabble::resetRows()
{
    for (int i = 0; i < WORD_ONE_LENGTH; i++)
    {
        row1[i].letter = '_';
        row1[i].tileLetter = ' ';
        row1[i].word = 1;
        row1[i].position = i + 1;
        row1[i].filled = false;
    }
    for (int i = 0; i < WORD_TWO_LENGTH; i++)
    {
        row2[i].letter = '_';
        row2[i].tileLetter = ' ';
        row2[i].word = 2;
        row2[i].position = i + 1;
        row2[i].filled = false;
    }
}
void Scrabble::copyRowsFrom(const Scrabble &other)
{
    for (int i = 0; i < WORD_ONE_LENGTH; i++)
    {
        row1[i] = other.row1[i];
    }
    for (int i = 0; i < WORD_TWO_LENGTH; i++)
    {
        row2[i] = other.row2[i];
    }
}
Tile *Scrabble::rowPointer(int word) const
{
    if (word == WORD_ONE || word == 1)
    {
        return row1;
    }
    if (word == WORD_TWO || word == 2)
    {
        return row2;
    }
    throw InvalidPlacementException("Word number must be 1 or 2!");
}
int Scrabble::rowLength(int word) const
{
    if (word == WORD_ONE || word == 1)
    {
        return WORD_ONE_LENGTH;
    }
    if (word == WORD_TWO || word == 2)
    {
        return WORD_TWO_LENGTH;
    }
    throw InvalidPlacementException("Word number must be 1 or 2!");
}

// Implementation of the Scrabble class methods for placing clues, checking completion, and forming words

void Scrabble::place(const Clue &clue)
{
    int w = (clue.word != 0 ? clue.word : (clue.clueRow == Word_1 ? 1 : 2));
    int pos = (clue.position != 0 ? clue.position : clue.cluePosition);
    char let = (clue.letter != '_' && clue.letter != ' ' ? clue.letter : clue.clueLetter);
    int length = rowLength(w);
    Tile *row = rowPointer(w);
    if (pos < 1 || pos > length)
    {
        throw InvalidPlacementException("Position is outside the board!");
    }
    if (!isLetter(let))
    {
        throw InvalidPlacementException("Only letters can be placed!");
    }
    Tile &square = row[pos - 1];
    char upper = toUpperCase(let);
    if (square.filled && square.letter != upper)
    {
        throw InvalidPlacementException("That square already holds a different letter!");
    }
    square.letter = upper;
    square.tileLetter = upper;
    square.filled = true;
}
Scrabble &Scrabble::operator+=(const Clue &clue)
{
    place(clue);
    return *this;
}
int Scrabble::filledCount(WordRow row) const
{
    int length = rowLength(row);
    Tile *tiles = rowPointer(row);
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (tiles[i].filled)
        {
            count++;
        }
    }
    return count;
}
bool Scrabble::isRowComplete(WordRow row) const
{
    return filledCount(row) == rowLength(row);
}
bool Scrabble::isBoardComplete() const
{
    return isRowComplete(Word_1) && isRowComplete(Word_2);
}
void Scrabble::formWord(WordRow row, char *out, int outSize) const
{
    int length = rowLength(row);
    Tile *tiles = rowPointer(row);
    if (outSize < length + 1)
    {
        throw InvalidPlacementException("Output buffer is too small!");
    }
    if (!isRowComplete(row))
    {
        throw IncompleteWordException("Word is incomplete!");
    }
    for (int i = 0; i < length; i++)
    {
        out[i] = tiles[i].letter;
    }
    out[length] = '\0';
}
bool Scrabble::matchesWord(WordRow row, const char *expected) const
{
    char built[WORD_TWO_LENGTH + 1];
    formWord(row, built, WORD_TWO_LENGTH + 1);
    return sameTextIgnoreCase(built, expected);
}
void Scrabble::setTargetWords(string word1, string word2)
{
    targetWord1 = word1;
    targetWord2 = word2;
    row1Solved = false;
    row2Solved = false;
}
bool Scrabble::isRowSolved(WordRow row) const
{
    if (row == Word_1)
    {
        return row1Solved;
    }
    return row2Solved;
}
void Scrabble::checkWord(WordRow row, string guess) const
{
    string target = (row == Word_1 ? targetWord1 : targetWord2);
    if (!matchesWord(row, target.c_str()) || guess != target)
    {
        throw InvalidWordException("Wrong word!");
    }
}
void Scrabble::markRowSolved(WordRow row)
{
    if (row == Word_1)
    {
        row1Solved = true;
    }
    else
    {
        row2Solved = true;
    }
}
void Scrabble::reset()
{
    resetRows();
}
void Scrabble::display() const
{
    cout << *this;
}

// Overloaded operator<< to display the contents of the Scrabble board

ostream &operator<<(ostream &out, const Scrabble &board)
{
    out << "Scrabble Board:" << endl;
    out << "Word 1: ";
    for (int i = 0; i < WORD_ONE_LENGTH; i++)
    {
        if (board.row1[i].filled)
        {
            out << '[' << board.row1[i].letter << "] ";
        }
        else
        {
            out << "[ ] ";
        }
    }
    out << endl;
    out << "Word 2: ";
    for (int i = 0; i < WORD_TWO_LENGTH; i++)
    {
        if (board.row2[i].filled)
        {
            out << '[' << board.row2[i].letter << "] ";
        }
        else
        {
            out << "[ ] ";
        }
    }
    out << endl;
    return out;
}

// ===========Implementation of the Cottage class==========

Cottage::Cottage()
{
}
void Cottage::addLocation(const Location &place)
{
    locations.add(place);
}
int Cottage::getCount() const
{
    return locations.getSize();
}
const Location &Cottage::getLocation(int index) const
{
    return locations[index];
}
bool Cottage::isSearched(int index) const
{
    return locations[index].searched || locations[index].locSearchFlag;
}
Clue Cottage::search(int index)
{
    if (index < 0 || index >= locations.getSize())
    {
        throw IndexOutOfRangeException("Invalid location index.");
    }
    Location &place = locations[index];
    place.searched = true;
    place.locSearchFlag = true;
    return makeClue(place.letter, place.word, place.position);
}
bool Cottage::allSearched() const
{
    for (int i = 0; i < locations.getSize(); i++)
    {
        if (!locations[i].searched && !locations[i].locSearchFlag)
        {
            return false;
        }
    }
    return true;
}
void Cottage::resetSearched()
{
    for (int i = 0; i < locations.getSize(); i++)
    {
        locations[i].searched = false;
        locations[i].locSearchFlag = false;
    }
}
void Cottage::display() const
{
    cout << *this;
}
int Cottage::getLocationCount() const
{
    return locations.getSize();
}
string Cottage::getLocationName(int index) const
{
    if (index >= 0 && index < locations.getSize())
    {
        if (locations[index].locName.length() > 0)
        {
            return locations[index].locName;
        }
        return string(locations[index].name);
    }
    return "";
}
void Cottage::showMenu() const
{
    cout << "====== Location Menu ======" << endl;
    for (int i = 0; i < locations.getSize(); i++)
    {
        string name = (locations[i].locName.length() > 0 ? locations[i].locName : string(locations[i].name));
        cout << "[" << (i + 1) << "] " << name << " - "
             << (locations[i].searched || locations[i].locSearchFlag ? "Searched" : "NOT Searched") << endl;
    }
    cout << "[0] Back" << endl;
}
Clue Cottage::showClueAgain(int index) const
{
    if (index < 0 || index >= locations.getSize())
    {
        throw IndexOutOfRangeException("Invalid location index.");
    }
    const Location &place = locations[index];
    return makeClue(place.letter, place.word, place.position);
}
ostream &operator<<(ostream &out, const Cottage &cottage)
{
    out << "Locations:" << endl;
    for (int i = 0; i < cottage.locations.getSize(); i++)
    {
        string name = (cottage.locations[i].locName.length() > 0 ? cottage.locations[i].locName : string(cottage.locations[i].name));
        out << "  " << (i + 1) << ". " << name;
        if (cottage.locations[i].searched || cottage.locations[i].locSearchFlag)
        {
            out << "  (searched)";
        }
        out << endl;
    }
    return out;
}
int GameException::wrongTurnAmount = 5;
int GameException::wrongWordAmount = 10;
GameException::GameException(string msg)
{
    message = msg;
}
GameException::GameException(const char *text)
{
    message = string(text);
}
GameException::~GameException()
{
}
string GameException::getMessage() const
{
    return message;
}
int GameException::getPenalty() const
{
    return 0;
}
bool GameException::isFatal() const
{
    return false;
}
void GameException::setPenalties(int turnAmount, int wordAmount)
{
    wrongTurnAmount = turnAmount;
    wrongWordAmount = wordAmount;
}
InvalidWordException::InvalidWordException(string msg)
    : GameException(msg)
{
}
int InvalidWordException::getPenalty() const
{
    return wrongWordAmount;
}
RackFullException::RackFullException(string msg)
    : GameException(msg)
{
}
InvalidPositionException::InvalidPositionException(string msg)
    : GameException(msg)
{
}
InvalidInputException::InvalidInputException(string msg)
    : GameException(msg)
{
}
int InvalidInputException::getPenalty() const
{
    return wrongTurnAmount;
}
InvalidActionException::InvalidActionException(string msg)
    : GameException(msg)
{
}
DataException::DataException(string msg)
    : GameException(msg)
{
}
bool DataException::isFatal() const
{
    return true;
}
const string GameEngine::ROLE_NAMES[7] = {
    "Cook",
    "Guard",
    "Servant",
    "Partner 1",
    "Partner 2",
    "PA",
    "Child"
};
ScoreBoard::ScoreBoard()
{
}
void ScoreBoard::append(string name, string result, int credibility, int turnsLeft, string culpritRole, string date)
{
    bool hasHeader = false;
    ifstream checkFile("leader/scoreBoard.txt");
    if (checkFile.is_open())
    {
        string headerLine;
        if (getline(checkFile, headerLine))
        {
            if (TextUtil::trimText(headerLine).length() > 0)
            {
                hasHeader = true;
            }
        }
        checkFile.close();
    }
    ofstream outFile("leader/scoreBoard.txt", ios::app);
    if (!outFile.is_open())
    {
        throw DataException("Cannot write the score board.");
    }
    if (!hasHeader)
    {
        outFile << "Detective|Result|Credibility|Turns_Left|Culprit|Date\n";
    }
    string underscoredRole = "";
    for (int i = 0; i < (int)culpritRole.length(); i++)
    {
        if (culpritRole[i] == ' ')
        {
            underscoredRole = underscoredRole + '_';
        }
        else
        {
            underscoredRole = underscoredRole + culpritRole[i];
        }
    }
    outFile << name << "|" << result << "|" << credibility << "|";
    if (turnsLeft < 10)
    {
        outFile << "0";
    }
    outFile << turnsLeft << "|" << underscoredRole << "|" << date << "\n";
    outFile.close();
}
void ScoreBoard::display() const
{
    ifstream inFile("leader/scoreBoard.txt");
    if (!inFile.is_open())
    {
        cout << "No scores yet." << endl;
        return;
    }
    string line;
    if (!getline(inFile, line))
    {
        cout << "No scores yet." << endl;
        inFile.close();
        return;
    }
    int validRows = 0;
    string parts[7];
    while (getline(inFile, line))
    {
        line = TextUtil::trimText(line);
        if (line.length() == 0)
        {
            continue;
        }
                int count = TextUtil::splitLine(line, '|', parts, 6);
        if (count != 6)
        {
            continue;
        }
        if (validRows == 0)
        {
            cout << "Detective\tResult\tCredibility\tTurns_Left\tCulprit\tDate" << endl;
            cout << "------------------------------------------------------------------" << endl;
        }
        cout << parts[0] << "\t" << parts[1] << "\t" << parts[2] << "\t\t"
             << parts[3] << "\t\t" << parts[4] << "\t" << parts[5] << endl;
        validRows++;
    }
    inFile.close();
    if (validRows == 0)
    {
        cout << "No scores yet." << endl;
    }
}
string ScoreBoard::getTodayDate() const
{
    time_t now = time(NULL);
    tm* ltm = localtime(&now);
    int day = ltm->tm_mday;
    int month = ltm->tm_mon + 1;
    int year = (ltm->tm_year + 1900) % 100;
    string dateStr = "";
    dateStr = dateStr + (char)('0' + (day / 10)) + (char)('0' + (day % 10));
    dateStr = dateStr + '-';
    dateStr = dateStr + (char)('0' + (month / 10)) + (char)('0' + (month % 10));
    dateStr = dateStr + '-';
    dateStr = dateStr + (char)('0' + (year / 10)) + (char)('0' + (year % 10));
    return dateStr;
}
GameEngine::GameEngine()
{
    state = Menu;
    dataLoaded = false;
    culpritIndex = -1;
    culpritRole = "";
    maxTurns = DEFAULT_MAX_TURNS;
    startCredibility = DEFAULT_CREDIBILITY;
    wrongTurnAmount = DEFAULT_WRONG_TURN;
    wrongWordAmount = DEFAULT_WRONG_WORD;
    winText = "Accuse_Correct_Culprit";
    loseText = "Credibility_Zero_Or_Turns_Exhausted";
    aboutText = "";
    detective = NULL;
    cottage = NULL;
    scrabble = NULL;
    rack = NULL;
    for (int i = 0; i < CHARACTER_COUNT; i++)
    {
        characters[i] = NULL;
    }
    scoreBoard = NULL;
}
GameEngine::~GameEngine()
{
    clearGame();
}
GameEngine& GameEngine::getInstance()
{
    static GameEngine instance;
    return instance;
}
void GameEngine::attachScoreBoard(ScoreBoard* board)
{
    scoreBoard = board;
}
void GameEngine::handleException(GameException& e)
{
    cout << e.getMessage() << endl;
    if (e.isFatal())
    {
        cout << "The game cannot continue." << endl;
        state = Exit;
        return;
    }
    if (state == Playing && e.getPenalty() > 0)
    {
        if (detective != NULL)
        {
            detective->loseCredibility(e.getPenalty());
            cout << "Credibility -" << e.getPenalty()
                 << " (now " << detective->getCredibility() << ")" << endl;
        }
    }
    if (state == Playing)
    {
        checkLoseConditions();
    }
}
GameState GameEngine::getState() const
{
    return state;
}
void GameEngine::setState(GameState s)
{
    state = s;
}
void GameEngine::ensureDataLoaded()
{
    if (!dataLoaded)
    {
        loadAllData();
    }
}
void GameEngine::runStep()
{
    if (!dataLoaded)
    {
        loadAllData();
        showTitle();
    }
    else if (state == Menu)
    {
        mainMenuStep();
    }
    else if (state == Playing)
    {
        gameMenuStep();
    }
    else if (state == Won || state == Lost)
    {
        endGame();
    }
}
string GameEngine::readLine()
{
    string line;
    if (!getline(cin, line))
    {
        state = Exit;
        throw InvalidInputException("Input closed.");
    }
    return TextUtil::trimText(line);
}
int GameEngine::readNumber(int min, int max)
{
    string line = readLine();
    if (!TextUtil::isAllDigits(line) || line.length() > 3)
    {
        throw InvalidInputException("Invalid choice.");
    }
    int num = TextUtil::digitsToNumber(line);
    if (num < min || num > max)
    {
        throw InvalidInputException("Invalid choice.");
    }
    return num;
}
bool GameEngine::readYesNo()
{
    string line = readLine();
    if (line == "Y" || line == "y")
    {
        return true;
    }
    if (line == "N" || line == "n")
    {
        return false;
    }
    throw InvalidInputException("Please answer Y or N.");
}
void GameEngine::clearScreen()
{
    system("cls");
}
void GameEngine::pause()
{
    cout << "Press Enter to continue...";
    readLine();
}
void GameEngine::showTitle()
{
    cout << aboutText << endl;
}
void GameEngine::showRules()
{
    cout << "====== THE LOCKER HEIST - RULES ======" << endl;
    cout << "Maximum Turns: " << maxTurns << endl;
    cout << "Starting Credibility: " << startCredibility << endl;
    cout << "Wrong Turn Penalty: -" << wrongTurnAmount << " Credibility" << endl;
    cout << "Wrong Word Penalty: -" << wrongWordAmount << " Credibility" << endl;
    cout << "Win Condition: " << winText << endl;
    cout << "Lose Condition: " << loseText << endl;
    cout << "======================================" << endl;
}
void GameEngine::mainMenuStep()
{
    cout << "\n=== THE LOCKER HEIST - MAIN MENU ===" << endl;
    cout << "[1] New Game" << endl;
    cout << "[2] View Leader/Score Board" << endl;
    cout << "[3] About" << endl;
    cout << "[4] Rules" << endl;
    cout << "[5] Exit" << endl;
    cout << "Choice: ";
    int choice = readNumber(1, 5);
    MenuChoice menuChoice = (MenuChoice)choice;
    switch (menuChoice)
    {
    case New_Game:
        startNewGame();
        break;
    case Leader_Board:
        if (scoreBoard != NULL)
        {
            scoreBoard->display();
        }
        else
        {
            cout << "No scores yet." << endl;
        }
        pause();
        break;
    case About:
        cout << aboutText << endl;
        pause();
        break;
    case Rules:
        showRules();
        pause();
        break;
    case Quit:
        state = Exit;
        break;
    }
}
string GameEngine::askDetectiveName()
{
    while (true)
    {
        cout << "Enter detective name: ";
        string name = readLine();
        if (name.length() == 0)
        {
            cout << "Name cannot be empty. Please try again." << endl;
            continue;
        }
        bool hasSpace = false;
        bool hasPipe = false;
        for (int i = 0; i < (int)name.length(); i++)
        {
            if (name[i] == ' ')
            {
                hasSpace = true;
            }
            if (name[i] == '|')
            {
                hasPipe = true;
            }
        }
        if (hasSpace)
        {
            cout << "Use _ or . instead of spaces" << endl;
            continue;
        }
        if (hasPipe)
        {
            cout << "Name cannot contain '|'. Please try again." << endl;
            continue;
        }
        return name;
    }
}
int GameEngine::findClueRecord(string role)
{
    string target = TextUtil::normalizeRole(role);
    for (int i = 0; i < 7; i++)
    {
        if (TextUtil::normalizeRole(clueTable[i].culpritRole) == target)
        {
            return i;
        }
    }
    throw DataException("Clue record not found for culprit role.");
}
void GameEngine::createCharacters()
{
    string normCulprit = TextUtil::normalizeRole(culpritRole);
    bool culpritAssigned = false;
    for (int i = 0; i < CHARACTER_COUNT; i++)
    {
        const CharacterRecord& rec = characterTable[i];
        string name = rec.name;
        string role = rec.role;
        string nationality = rec.nationality;
        char letter = rec.letters[culpritIndex];
        int boardPos = rec.boardPos;
        string normRole = TextUtil::normalizeRole(role);
        if (normRole == "VICTIM")
        {
            characters[i] = new Victim(name, role, nationality, letter, boardPos);
        }
        else if (normRole == "COOK")
        {
            characters[i] = new Cook(name, role, nationality, letter, boardPos);
        }
        else if (normRole == "GUARD")
        {
            characters[i] = new Guard(name, role, nationality, letter, boardPos);
        }
        else if (normRole == "SERVANT")
        {
            characters[i] = new Servant(name, role, nationality, letter, boardPos);
        }
        else if (normRole == "PARTNER 1" || normRole == "PARTNER 2")
        {
            characters[i] = new Partner(name, role, nationality, letter, boardPos);
        }
        else if (normRole == "PA")
        {
            characters[i] = new PA(name, role, nationality, letter, boardPos);
        }
        else if (normRole == "CHILD")
        {
            characters[i] = new Child(name, role, nationality, letter, boardPos);
        }
        else
        {
            throw DataException("characters.txt: unknown character role.");
        }
        if (normRole == normCulprit)
        {
            characters[i]->setCulprit(true);
            culpritAssigned = true;
        }
    }
    if (!culpritAssigned)
    {
        throw DataException("Failed to assign culprit character.");
    }
}
void GameEngine::clearGame()
{
    if (detective != NULL)
    {
        delete detective;
        detective = NULL;
    }
    if (cottage != NULL)
    {
        delete cottage;
        cottage = NULL;
    }
    if (scrabble != NULL)
    {
        delete scrabble;
        scrabble = NULL;
    }
    if (rack != NULL)
    {
        delete rack;
        rack = NULL;
    }
    for (int i = 0; i < CHARACTER_COUNT; i++)
    {
        if (characters[i] != NULL)
        {
            delete characters[i];
            characters[i] = NULL;
        }
    }
}
void GameEngine::startNewGame()
{
    clearGame();
    string detName = askDetectiveName();
    culpritIndex = rand() % 7;
    culpritRole = ROLE_NAMES[culpritIndex];
    int clueIdx = findClueRecord(culpritRole);
    detective = new Detective(detName, startCredibility);
    cottage = new Cottage();
    for (int i = 0; i < LOCATION_COUNT; i++)
    {
        Location loc;
        loc.locName = locationTable[i].placeName;
        copyString(loc.name, locationTable[i].placeName.c_str(), NAME_SIZE);
        loc.letterClueLoc = locationTable[i].letters[culpritIndex];
        loc.letter = locationTable[i].letters[culpritIndex];
        loc.boardPosLoc = locationTable[i].boardPos;
        loc.position = locationTable[i].boardPos;
        loc.locRow = Word_1;
        loc.word = 1;
        loc.locSearchFlag = false;
        loc.searched = false;
        cottage->addLocation(loc);
    }
    createCharacters();
    scrabble = new Scrabble();
    scrabble->setTargetWords(clueTable[clueIdx].word1, clueTable[clueIdx].word2);
    rack = new TileRack(15);
    state = Playing;
    cout << "A culprit has been secretly chosen. The game begins!" << endl;
}
void GameEngine::placeClue(Clue c)
{
    if (rack != NULL)
    {
        rack->add(c);
    }
    if (scrabble != NULL)
    {
        scrabble->place(c);
    }
}
void GameEngine::visitLocation()
{
    if (cottage == NULL)
    {
        return;
    }
    cottage->showMenu();
    cout << "Choice: ";
    int choice = readNumber(0, cottage->getLocationCount());
    if (choice == 0)
    {
        return;
    }
    int index = choice - 1;
    string placeName = cottage->getLocationName(index);
    if (!cottage->isSearched(index))
    {
        cout << "You have NOT searched " << placeName << ". Search? (Y/N): ";
        if (readYesNo())
        {
            Clue c = cottage->search(index);
            placeClue(c);
            cout << "Letter " << (c.letter != '_' && c.letter != ' ' ? c.letter : c.clueLetter)
                 << " collected at position " << (c.position != 0 ? c.position : c.cluePosition)
                 << " of Word 1. Letter has been placed." << endl;
            if (detective != NULL)
            {
                detective->useTurn();
            }
        }
    }
    else
    {
        cout << placeName << " has been searched. Search again? (Y/N): ";
        if (readYesNo())
        {
            Clue c = cottage->showClueAgain(index);
            cout << "Letter " << (c.letter != '_' && c.letter != ' ' ? c.letter : c.clueLetter)
                 << " is at position " << (c.position != 0 ? c.position : c.cluePosition)
                 << " of Word 1 (already placed)." << endl;
            if (detective != NULL)
            {
                detective->useTurn();
            }
        }
    }
}
void GameEngine::interviewPerson()
{
    cout << "====== Character Menu ======" << endl;
    for (int i = 0; i < CHARACTER_COUNT; i++)
    {
        cout << "[" << (i + 1) << "] ";
        if (characters[i] != NULL)
        {
            characters[i]->display();
        }
        cout << endl;
    }
    cout << "[0] Back" << endl;
    cout << "Choice: ";
    int choice = readNumber(0, CHARACTER_COUNT);
    if (choice == 0)
    {
        return;
    }
    int index = choice - 1;
    Character* ch = characters[index];
    if (ch == NULL)
    {
        return;
    }
    if (!ch->isInterviewed())
    {
        int cred = (detective != NULL ? detective->getCredibility() : 100);
        ch->checkAllowed(cred);
        cout << "You have NOT interviewed " << ch->getName() << " yet. Interview? (Y/N): ";
        if (readYesNo())
        {
            Clue c = ch->interview();
            placeClue(c);
            cout << "Letter " << (c.letter != '_' && c.letter != ' ' ? c.letter : c.clueLetter)
                 << " collected at position " << (c.position != 0 ? c.position : c.cluePosition)
                 << " of Word 2. Placed." << endl;
            if (detective != NULL)
            {
                detective->useTurn();
            }
        }
    }
    else
    {
        cout << ch->getName() << " has been interviewed. Interview again? (Y/N): ";
        if (readYesNo())
        {
            Clue c = ch->showClueAgain();
            cout << "Letter " << (c.letter != '_' && c.letter != ' ' ? c.letter : c.clueLetter)
                 << " is at position " << (c.position != 0 ? c.position : c.cluePosition)
                 << " of Word 2 (already placed)." << endl;
            if (detective != NULL)
            {
                detective->useTurn();
            }
        }
    }
}
void GameEngine::viewBoard()
{
    if (scrabble != NULL)
    {
        scrabble->display();
    }
    pause();
}
void GameEngine::gameMenuStep()
{
    showStatus();
    cout << "\n=== Game Menu ===" << endl;
    cout << "[1] Visit a Location" << endl;
    cout << "[2] Interview a Person" << endl;
    cout << "[3] View Scrabble Board (free)" << endl;
    cout << "[4] Form a Word" << endl;
    cout << "[5] Accuse a Suspect" << endl;
    cout << "[6] Quit" << endl;
    cout << "\n--- TURN " << (detective != NULL ? detective->getTurnsUsed() + 1 : 1) << " ---" << endl;
    cout << "Choice: ";
    int choice = readNumber(1, 6);
    switch (choice)
    {
    case 1:
        visitLocation();
        break;
    case 2:
        interviewPerson();
        break;
    case 3:
        viewBoard();
        break;
    case 4:
        formWord();
        break;
    case 5:
        accuse();
        break;
    case 6:
        state = Menu;
        clearScreen();
        break;
    }
    checkLoseConditions();
}
void GameEngine::showStatus()
{
    if (detective != NULL)
    {
        cout << "Credibility: " << detective->getCredibility()
             << " | Turns used: " << detective->getTurnsUsed() << endl;
    }
    if (rack != NULL)
    {
        rack->display();
    }
    if (scrabble != NULL)
    {
        scrabble->display();
    }
}
void GameEngine::formWord()
{
    if (scrabble == NULL)
    {
        return;
    }
    bool r1Complete = scrabble->isRowComplete(Word_1);
    bool r2Complete = scrabble->isRowComplete(Word_2);
    bool r1Solved = scrabble->isRowSolved(Word_1);
    bool r2Solved = scrabble->isRowSolved(Word_2);
    if (r1Solved && r2Solved)
    {
        throw InvalidInputException("Both words are already solved.");
    }
    bool r1Ready = (r1Complete && !r1Solved);
    bool r2Ready = (r2Complete && !r2Solved);
    if (!r1Ready && !r2Ready)
    {
        throw InvalidInputException("No row is complete yet.");
    }
    cout << "Which row? [1] Word 1  [2] Word 2  [0] Back" << endl;
    cout << "Choice: ";
    int choice = readNumber(0, 2);
    if (choice == 0)
    {
        return;
    }
    WordRow row = (choice == 1 ? Word_1 : Word_2);
    int expectedLen = (row == Word_1 ? WORD1_LENGTH : WORD2_LENGTH);
    if ((row == Word_1 && !r1Ready) || (row == Word_2 && !r2Ready))
    {
        throw InvalidInputException("That row is not ready.");
    }
    cout << "Type the word (0 to cancel): ";
    string guess = readLine();
    if (guess == "0")
    {
        return;
    }
    if (!TextUtil::isAllLetters(guess) || (int)guess.length() != expectedLen)
    {
        if (expectedLen == 7)
        {
            throw InvalidInputException("The word must have 7 letters.");
        }
        else
        {
            throw InvalidInputException("The word must have 8 letters.");
        }
    }
    guess = TextUtil::toUpperText(guess);
    if (detective != NULL)
    {
        detective->useTurn();
    }
    scrabble->checkWord(row, guess);
    scrabble->markRowSolved(row);
    cout << "Word " << (row == Word_1 ? 1 : 2) << " solved" << endl;
    if (scrabble->isRowSolved(Word_1) && scrabble->isRowSolved(Word_2))
    {
        revealCulprit();
    }
}
void GameEngine::revealCulprit()
{
    int clueIdx = findClueRecord(culpritRole);
    string w1 = clueTable[clueIdx].word1;
    string w2 = clueTable[clueIdx].word2;
    string nationality = "";
    for (int i = 0; i < CHARACTER_COUNT; i++)
    {
        if (characters[i] != NULL && characters[i]->isCulprit())
        {
            nationality = characters[i]->getNationality();
            break;
        }
    }
    cout << "\n" << w1 << " + " << w2 << " = " << nationality
         << " -> " << culpritRole << " is the Culprit!\n" << endl;
}
void GameEngine::accuse()
{
    if (scrabble == NULL || !scrabble->isRowSolved(Word_1) || !scrabble->isRowSolved(Word_2))
    {
        throw InvalidInputException("Solve both words first.");
    }
    int suspectIndices[SUSPECT_COUNT];
    int count = 0;
    cout << "====== Suspect Menu ======" << endl;
    for (int i = 0; i < CHARACTER_COUNT; i++)
    {
        if (characters[i] != NULL && characters[i]->isSuspect())
        {
            suspectIndices[count] = i;
            cout << "[" << (count + 1) << "] " << characters[i]->getName()
                 << " (" << characters[i]->getRole() << ")" << endl;
            count++;
        }
    }
    cout << "[0] Back" << endl;
    cout << "Choice: ";
    int choice = readNumber(0, count);
    if (choice == 0)
    {
        return;
    }
    if (detective != NULL)
    {
        detective->useTurn();
    }
    int chosenIdx = suspectIndices[choice - 1];
    Character* ch = characters[chosenIdx];
    if (ch != NULL && ch->isCulprit())
    {
        cout << "Correct!" << endl;
        state = Won;
    }
    else
    {
        if (detective != NULL)
        {
            detective->loseCredibility(wrongTurnAmount);
            cout << "Wrong accusation! Credibility -" << wrongTurnAmount
                 << " (now " << detective->getCredibility() << ")" << endl;
        }
    }
}
void GameEngine::checkLoseConditions()
{
    if (state != Playing)
    {
        return;
    }
    if (detective != NULL)
    {
        if (detective->getCredibility() <= 0)
        {
            state = Lost;
        }
        else if (detective->getTurnsUsed() >= maxTurns)
        {
            state = Lost;
        }
    }
}
void GameEngine::endGame()
{
    if (detective == NULL)
    {
        state = Menu;
        return;
    }
    string culpritInfo = "";
    for (int i = 0; i < CHARACTER_COUNT; i++)
    {
        if (characters[i] != NULL && characters[i]->isCulprit())
        {
            culpritInfo = characters[i]->getRole() + " " + characters[i]->getName();
            break;
        }
    }
    string resStr = (state == Won ? "WIN" : "LOSE");
    int turnsLeft = maxTurns - detective->getTurnsUsed();
    if (turnsLeft < 0)
    {
        turnsLeft = 0;
    }
    cout << "\n========================================" << endl;
    cout << detective->getName() << " " << resStr << "!" << endl;
    cout << "Final credibility: " << detective->getCredibility()
         << " | Turns used: " << detective->getTurnsUsed()
         << " | Culprit: " << culpritInfo << endl;
    cout << "========================================" << endl;
    if (scoreBoard != NULL)
    {
        scoreBoard->append(detective->getName(), resStr, detective->getCredibility(),
                           turnsLeft, culpritRole, scoreBoard->getTodayDate());
    }
    pause();
    clearScreen();
    state = Menu;
}
void GameEngine::loadRules()
{
    maxTurns = DEFAULT_MAX_TURNS;
    startCredibility = DEFAULT_CREDIBILITY;
    wrongTurnAmount = DEFAULT_WRONG_TURN;
    wrongWordAmount = DEFAULT_WRONG_WORD;
    winText = "Accuse_Correct_Culprit";
    loseText = "Credibility_Zero_Or_Turns_Exhausted";
    ifstream fin("rules.txt");
    if (fin.is_open())
    {
        string line;
        while (getline(fin, line))
        {
            line = TextUtil::trimText(line);
            if (line.length() == 0)
            {
                continue;
            }
            int eqPos = -1;
            for (int i = 0; i < (int)line.length(); i++)
            {
                if (line[i] == '=')
                {
                    eqPos = i;
                    break;
                }
            }
            if (eqPos == -1)
            {
                continue;
            }
            string key = "";
            for (int i = 0; i < eqPos; i++)
            {
                key = key + line[i];
            }
            key = TextUtil::trimText(key);
            string val = "";
            for (int i = eqPos + 1; i < (int)line.length(); i++)
            {
                val = val + line[i];
            }
            val = TextUtil::trimText(val);
            if (key == "Max_Turns")
            {
                if (TextUtil::isAllDigits(val))
                {
                    int num = TextUtil::digitsToNumber(val);
                    if (num > 0)
                    {
                        maxTurns = num;
                    }
                }
            }
            else if (key == "Starting_Credibility")
            {
                if (TextUtil::isAllDigits(val))
                {
                    int num = TextUtil::digitsToNumber(val);
                    if (num > 0)
                    {
                        startCredibility = num;
                    }
                }
            }
            else if (key == "Every_Wrong_Turn")
            {
                if (val.length() > 1 && val[0] == '-')
                {
                    string rest = "";
                    for (int i = 1; i < (int)val.length(); i++)
                    {
                        rest = rest + val[i];
                    }
                    if (TextUtil::isAllDigits(rest))
                    {
                        wrongTurnAmount = TextUtil::digitsToNumber(rest);
                    }
                }
                else if (TextUtil::isAllDigits(val))
                {
                    wrongTurnAmount = TextUtil::digitsToNumber(val);
                }
            }
            else if (key == "Every_Wrong_Word")
            {
                if (val.length() > 1 && val[0] == '-')
                {
                    string rest = "";
                    for (int i = 1; i < (int)val.length(); i++)
                    {
                        rest = rest + val[i];
                    }
                    if (TextUtil::isAllDigits(rest))
                    {
                        wrongWordAmount = TextUtil::digitsToNumber(rest);
                    }
                }
                else if (TextUtil::isAllDigits(val))
                {
                    wrongWordAmount = TextUtil::digitsToNumber(val);
                }
            }
            else if (key == "Win_Condition")
            {
                if (val.length() > 0)
                {
                    winText = val;
                }
            }
            else if (key == "Lose_Condition")
            {
                if (val.length() > 0)
                {
                    loseText = val;
                }
            }
        }
        fin.close();
    }
    GameException::setPenalties(wrongTurnAmount, wrongWordAmount);
}
void GameEngine::loadCharacters()
{
    ifstream fin("characters.txt");
    if (!fin.is_open())
    {
        throw DataException("File missing: characters.txt");
    }
    string line;
    bool headerRead = false;
    string parts[13];
    while (!headerRead && getline(fin, line))
    {
        line = TextUtil::trimText(line);
        if (line.length() > 0)
        {
            int count = TextUtil::splitLine(line, '|', parts, 12);
            if (count != 12)
            {
                fin.close();
                throw DataException("characters.txt: invalid header");
            }
            headerRead = true;
        }
    }
    if (!headerRead)
    {
        fin.close();
        throw DataException("characters.txt: missing header");
    }
    int rowCount = 0;
    bool usedPositions[9] = { false, false, false, false, false, false, false, false, false };
    bool roleFound[7] = { false, false, false, false, false, false, false };
    bool victimFound = false;
    while (getline(fin, line))
    {
        line = TextUtil::trimText(line);
        if (line.length() == 0)
        {
            continue;
        }
        if (rowCount >= CHARACTER_COUNT)
        {
            fin.close();
            throw DataException("characters.txt: too many rows");
        }
        int count = TextUtil::splitLine(line, '|', parts, 12);
        if (count != 12)
        {
            fin.close();
            throw DataException("characters.txt: wrong field count");
        }
        if (parts[0].length() == 0 || parts[1].length() == 0 || parts[2].length() == 0)
        {
            fin.close();
            throw DataException("characters.txt: empty name, role, or nationality");
        }
        if (!TextUtil::isAllDigits(parts[3]))
        {
            fin.close();
            throw DataException("characters.txt: invalid board position");
        }
        int pos = TextUtil::digitsToNumber(parts[3]);
        if (pos < 1 || pos > 8 || usedPositions[pos])
        {
            fin.close();
            throw DataException("characters.txt: duplicate board position");
        }
        usedPositions[pos] = true;
        for (int k = 0; k < 7; k++)
        {
            if (parts[4 + k].length() != 1 || !TextUtil::isLetter(parts[4 + k][0]))
            {
                fin.close();
                throw DataException("characters.txt: invalid letter");
            }
            characterTable[rowCount].letters[k] = TextUtil::toUpperChar(parts[4 + k][0]);
        }
        characterTable[rowCount].name = TextUtil::underscoresToSpaces(parts[0]);
        characterTable[rowCount].role = TextUtil::underscoresToSpaces(parts[1]);
        characterTable[rowCount].nationality = TextUtil::underscoresToSpaces(parts[2]);
        characterTable[rowCount].boardPos = pos;
        string normRole = TextUtil::normalizeRole(parts[1]);
        if (normRole == "VICTIM")
        {
            if (victimFound)
            {
                fin.close();
                throw DataException("characters.txt: duplicate victim");
            }
            victimFound = true;
        }
        else
        {
            int roleIdx = -1;
            for (int r = 0; r < 7; r++)
            {
                if (normRole == TextUtil::normalizeRole(ROLE_NAMES[r]))
                {
                    roleIdx = r;
                    break;
                }
            }
            if (roleIdx == -1 || roleFound[roleIdx])
            {
                fin.close();
                throw DataException("characters.txt: invalid or duplicate role");
            }
            roleFound[roleIdx] = true;
        }
        rowCount++;
    }
    fin.close();
    if (rowCount != CHARACTER_COUNT || !victimFound)
    {
        throw DataException("characters.txt: wrong row count");
    }
    for (int r = 0; r < 7; r++)
    {
        if (!roleFound[r])
        {
            throw DataException("characters.txt: missing role");
        }
    }
}
void GameEngine::loadLocations()
{
    ifstream fin("locations.txt");
    if (!fin.is_open())
    {
        throw DataException("File missing: locations.txt");
    }
    string line;
    bool headerRead = false;
    string parts[10];
    while (!headerRead && getline(fin, line))
    {
        line = TextUtil::trimText(line);
        if (line.length() > 0)
        {
            int count = TextUtil::splitLine(line, '|', parts, 9);
            if (count != 9)
            {
                fin.close();
                throw DataException("locations.txt: invalid header");
            }
            headerRead = true;
        }
    }
    if (!headerRead)
    {
        fin.close();
        throw DataException("locations.txt: missing header");
    }
    int rowCount = 0;
    bool usedPositions[8] = { false, false, false, false, false, false, false, false };
    while (getline(fin, line))
    {
        line = TextUtil::trimText(line);
        if (line.length() == 0)
        {
            continue;
        }
        if (rowCount >= LOCATION_COUNT)
        {
            fin.close();
            throw DataException("locations.txt: too many rows");
        }
        int count = TextUtil::splitLine(line, '|', parts, 9);
        if (count != 9)
        {
            fin.close();
            throw DataException("locations.txt: wrong field count");
        }
        if (parts[0].length() == 0)
        {
            fin.close();
            throw DataException("locations.txt: empty location name");
        }
        if (!TextUtil::isAllDigits(parts[1]))
        {
            fin.close();
            throw DataException("locations.txt: invalid board position");
        }
        int pos = TextUtil::digitsToNumber(parts[1]);
        if (pos < 1 || pos > 7 || usedPositions[pos])
        {
            fin.close();
            throw DataException("locations.txt: duplicate board position");
        }
        usedPositions[pos] = true;
        for (int k = 0; k < 7; k++)
        {
            if (parts[2 + k].length() != 1 || !TextUtil::isLetter(parts[2 + k][0]))
            {
                fin.close();
                throw DataException("locations.txt: invalid letter");
            }
            locationTable[rowCount].letters[k] = TextUtil::toUpperChar(parts[2 + k][0]);
        }
        locationTable[rowCount].placeName = TextUtil::underscoresToSpaces(parts[0]);
        locationTable[rowCount].boardPos = pos;
        rowCount++;
    }
    fin.close();
    if (rowCount != LOCATION_COUNT)
    {
        throw DataException("locations.txt: wrong row count");
    }
    for (int p = 1; p <= 7; p++)
    {
        if (!usedPositions[p])
        {
            throw DataException("locations.txt: missing board position");
        }
    }
}
void GameEngine::loadClues()
{
    ifstream fin("clue.txt");
    if (!fin.is_open())
    {
        throw DataException("File missing: clue.txt");
    }
    string line;
    bool headerRead = false;
    string parts[4];
    while (!headerRead && getline(fin, line))
    {
        line = TextUtil::trimText(line);
        if (line.length() > 0)
        {
            int count = TextUtil::splitLine(line, '|', parts, 3);
            if (count != 3)
            {
                fin.close();
                throw DataException("clue.txt: invalid header");
            }
            headerRead = true;
        }
    }
    if (!headerRead)
    {
        fin.close();
        throw DataException("clue.txt: missing header");
    }
    int rowCount = 0;
    bool roleFound[7] = { false, false, false, false, false, false, false };
    while (getline(fin, line))
    {
        line = TextUtil::trimText(line);
        if (line.length() == 0)
        {
            continue;
        }
        if (rowCount >= 7)
        {
            fin.close();
            throw DataException("clue.txt: too many rows");
        }
        int count = TextUtil::splitLine(line, '|', parts, 3);
        if (count != 3)
        {
            fin.close();
            throw DataException("clue.txt: wrong field count");
        }
        string normRole = TextUtil::normalizeRole(parts[0]);
        int roleIdx = -1;
        for (int r = 0; r < 7; r++)
        {
            if (normRole == TextUtil::normalizeRole(ROLE_NAMES[r]))
            {
                roleIdx = r;
                break;
            }
        }
        if (roleIdx == -1 || roleFound[roleIdx])
        {
            fin.close();
            throw DataException("clue.txt: invalid or duplicate role");
        }
        roleFound[roleIdx] = true;
        if (parts[1].length() != 7 || !TextUtil::isAllLetters(parts[1]))
        {
            fin.close();
            throw DataException("clue.txt: invalid Word 1 length or letters");
        }
        if (parts[2].length() != 8 || !TextUtil::isAllLetters(parts[2]))
        {
            fin.close();
            throw DataException("clue.txt: invalid Word 2 length or letters");
        }
        clueTable[rowCount].culpritRole = TextUtil::underscoresToSpaces(parts[0]);
        clueTable[rowCount].word1 = TextUtil::toUpperText(parts[1]);
        clueTable[rowCount].word2 = TextUtil::toUpperText(parts[2]);
        rowCount++;
    }
    fin.close();
    if (rowCount != 7)
    {
        throw DataException("clue.txt: wrong row count");
    }
    for (int r = 0; r < 7; r++)
    {
        if (!roleFound[r])
        {
            throw DataException("clue.txt: missing clue role");
        }
    }
}
void GameEngine::loadAbout()
{
    ifstream fin("about.txt");
    if (!fin.is_open())
    {
        throw DataException("File missing: about.txt");
    }
    aboutText = "";
    string line;
    while (getline(fin, line))
    {
        aboutText = aboutText + line + "\n";
    }
    fin.close();
    if (aboutText.length() == 0)
    {
        throw DataException("about.txt: empty file");
    }
}
void GameEngine::loadAllData()
{
    loadRules();
    loadCharacters();
    loadLocations();
    loadClues();
    loadAbout();
    srand((unsigned int)time(NULL));
    dataLoaded = true;
}
bool GameEngine::isDataLoaded() const
{
    return dataLoaded;
}
int GameEngine::getMaxTurns() const
{
    return maxTurns;
}
int GameEngine::getStartCredibility() const
{
    return startCredibility;
}
int GameEngine::getWrongTurnAmount() const
{
    return wrongTurnAmount;
}
int GameEngine::getWrongWordAmount() const
{
    return wrongWordAmount;
}
string GameEngine::getWinText() const
{
    return winText;
}
string GameEngine::getLoseText() const
{
    return loseText;
}
string GameEngine::getAboutText() const
{
    return aboutText;
}
const LocationRecord& GameEngine::getLocationRecord(int index) const
{
    return locationTable[index];
}
const CharacterRecord& GameEngine::getCharacterRecord(int index) const
{
    return characterTable[index];
}
const ClueRecord& GameEngine::getClueRecord(int index) const
{
    return clueTable[index];
}
int GameEngine::getCulpritIndex() const
{
    return culpritIndex;
}
string GameEngine::getCulpritRole() const
{
    return culpritRole;
}
Detective* GameEngine::getDetective() const
{
    return detective;
}
Cottage* GameEngine::getCottage() const
{
    return cottage;
}
Scrabble* GameEngine::getScrabble() const
{
    return scrabble;
}
TileRack* GameEngine::getRack() const
{
    return rack;
}
Character* GameEngine::getCharacter(int index) const
{
    if (index >= 0 && index < CHARACTER_COUNT)
    {
        return characters[index];
    }
    return NULL;
}
bool TextUtil::isLetter(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    {
        return true;
    }
    return false;
}
bool TextUtil::isDigit(char c)
{
    if (c >= '0' && c <= '9')
    {
        return true;
    }
    return false;
}
char TextUtil::toUpperChar(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return (char)(c - 'a' + 'A');
    }
    return c;
}
string TextUtil::toUpperText(string text)
{
    string result = "";
    for (int i = 0; i < (int)text.length(); i++)
    {
        result = result + toUpperChar(text[i]);
    }
    return result;
}
string TextUtil::trimText(string text)
{
    int start = 0;
    int len = (int)text.length();
    while (start < len && (text[start] == ' ' || text[start] == '\t' || text[start] == '\r' || text[start] == '\n'))
    {
        start++;
    }
    int end = len - 1;
    while (end >= start && (text[end] == ' ' || text[end] == '\t' || text[end] == '\r' || text[end] == '\n'))
    {
        end--;
    }
    string result = "";
    for (int i = start; i <= end; i++)
    {
        result = result + text[i];
    }
    return result;
}
bool TextUtil::isAllLetters(string text)
{
    if (text.length() == 0)
    {
        return false;
    }
    for (int i = 0; i < (int)text.length(); i++)
    {
        if (!isLetter(text[i]))
        {
            return false;
        }
    }
    return true;
}
bool TextUtil::isAllDigits(string text)
{
    if (text.length() == 0)
    {
        return false;
    }
    for (int i = 0; i < (int)text.length(); i++)
    {
        if (!isDigit(text[i]))
        {
            return false;
        }
    }
    return true;
}
int TextUtil::digitsToNumber(string text)
{
    int value = 0;
    for (int i = 0; i < (int)text.length(); i++)
    {
        value = value * 10 + (text[i] - '0');
    }
    return value;
}
bool TextUtil::sameIgnoreCase(string a, string b)
{
    if (a.length() != b.length())
    {
        return false;
    }
    for (int i = 0; i < (int)a.length(); i++)
    {
        if (toUpperChar(a[i]) != toUpperChar(b[i]))
        {
            return false;
        }
    }
    return true;
}
string TextUtil::normalizeRole(string role)
{
    string result = "";
    for (int i = 0; i < (int)role.length(); i++)
    {
        char ch = role[i];
        if (ch == '_')
        {
            result = result + ' ';
        }
        else
        {
            result = result + toUpperChar(ch);
        }
    }
    return trimText(result);
}
string TextUtil::underscoresToSpaces(string text)
{
    string result = "";
    for (int i = 0; i < (int)text.length(); i++)
    {
        if (text[i] == '_')
        {
            result = result + ' ';
        }
        else
        {
            result = result + text[i];
        }
    }
    return result;
}
int TextUtil::splitLine(string line, char separator, string parts[], int maxParts)
{
    if (line.length() == 0)
    {
        return 0;
    }
    int count = 0;
    string current = "";
    for (int i = 0; i < (int)line.length(); i++)
    {
        char ch = line[i];
        if (ch == separator)
        {
            if (count < maxParts)
            {
                parts[count] = trimText(current);
            }
            count++;
            current = "";
        }
        else
        {
            current = current + ch;
        }
    }
    if (count < maxParts)
    {
        parts[count] = trimText(current);
    }
    count++;
    if (count > maxParts)
    {
        return maxParts + 1;
    }
    return count;
}