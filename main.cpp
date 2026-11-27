#include "heist.h"
int main()
{
    ScoreBoard board;
    GameEngine& engine = GameEngine::getInstance();
    engine.attachScoreBoard(&board);
    while (engine.getState() != Exit)
    {
        try
        {
            engine.runStep();
        }
        catch (GameException& e)
        {
            engine.handleException(e);
        }
        catch (...)
        {
            cout << "Unexpected error. Closing." << endl;
            break;
        }
    }
    return 0;
}