#include<iostream>
#include<cstdlib>
using namespace std;

enum enThreeChoice { Stone = 1, Paper = 2, Scissors = 3 };


struct stFinalDataWinner
{
    int RoundsNum = 0;
    int RoundWinPlayer = 0;
    int RoundWinCompeter = 0;
    int DrewTimes = 0;
    string FinalWinner;

};
struct stRoundData
{
    enThreeChoice PlayerChoice;
    enThreeChoice CompeterChoice;
    string Winner;
    string ArrWin[3] = { "No Winner","Player","Competer" };
    string ArrThreeChoice[3] = { "Stone","Paper","Scissors" };

};

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;  
}

enThreeChoice EnCompeterChoice()
{
    return enThreeChoice(RandomNumber(1, 3));
}

int ReadPositiveNumber(string Message)
{
    int Number = 0;  
    do
    {
        cout << Message ; 
        cin >> Number;            
    } while (Number < 0);        

    return Number;  
}

int DeterminningTheprofitForTheRounds(stRoundData &RoundData)
{
    int Player = int(RoundData.PlayerChoice);
    int Competer = int(RoundData.CompeterChoice);
    int NumberWin = ((Player - Competer + 3) % 3);

    RoundData.Winner= RoundData.ArrWin[NumberWin];

    return NumberWin;
}

string ReadString(string Massage)
{
    cout << Massage << endl;
    cin >> Massage;
    return Massage;
}

void DataRound(stRoundData& RoundData)
{
    RoundData.PlayerChoice = enThreeChoice(ReadPositiveNumber("Your Choice : [1]Stone ,[2]Paper ,[3]Scissors : "));
    RoundData.CompeterChoice = EnCompeterChoice();

}

void ColorWiNScreen(stRoundData RoundData)
{
    if (RoundData.Winner == "No Winner")
    {
        system("color 67");
        return;
    }
    if (RoundData.Winner == "Competer")
    {
        cout << "\a";
        system("color 47");
        return;
    }
    if(RoundData.Winner == "Player")
        system("color 27");
   
}

void PrintRoundData(stRoundData RoundData)
{
    ColorWiNScreen(RoundData);
    int Player = int(RoundData.PlayerChoice);
    int Competer = int(RoundData.CompeterChoice);
    cout << "Player Choice : " << RoundData.ArrThreeChoice[Player - 1] << endl;
    cout << "Cometer Choice : " << RoundData.ArrThreeChoice[Competer - 1] << endl;
    cout << "Round Winner : " << RoundData.Winner << endl;
    
    cout << "________________________________\n";

}

void StructDataFinalGame(stFinalDataWinner &FinalDataWinner,int NumberWin)
{
    //Counter++
    switch (NumberWin)
    {
    case 0:FinalDataWinner.DrewTimes++;
        break;
    case 1:FinalDataWinner.RoundWinPlayer++;
        break;
    case 2:FinalDataWinner.RoundWinCompeter++;
        break;
    }
    //WinnerName
    if (FinalDataWinner.RoundWinPlayer > FinalDataWinner.RoundWinCompeter)
        FinalDataWinner.FinalWinner = "Player";
    else if (FinalDataWinner.RoundWinCompeter > FinalDataWinner.RoundWinPlayer)
        FinalDataWinner.FinalWinner = "Competer";
    else
        FinalDataWinner.FinalWinner = "Now Winner";
   
}

void PrintBasicUX()
{
    cout << "\n \t\t _________________________________________\n" << endl;
    cout << " \t\t \t  *** G A M E  O V E R ***\n" << endl;
    cout << " \t\t _________________________________________\n" << endl;
    cout << "\n \t\t ______________[GAME RESULT]_____________\n" << endl;

}

void ColorWiNScreenFinal(stFinalDataWinner Final)
{
    if (Final.FinalWinner == "No Winner")
    {
        system("color 67");
        return;
    }
    if (Final.FinalWinner == "Competer")
    {
        cout << "\a";
        system("color 47");
        return;
    }
    if (Final.FinalWinner == "Player")
        system("color 27");

}

void PrintDataFinalGame(stFinalDataWinner FinalWinner)
{
    PrintBasicUX();
    cout << "\t\tGame Rounds : " << FinalWinner.RoundsNum << endl;
    cout << "\t\tPlayer Won Times : " << FinalWinner.RoundWinPlayer << endl;
    cout << "\t\tCompeter Won Times : " << FinalWinner.RoundWinCompeter << endl;
    cout << "\t\tDrew Times : " << FinalWinner.DrewTimes << endl;
    ColorWiNScreenFinal(FinalWinner);
    cout << "\t\tFinal Result : " << FinalWinner.FinalWinner << endl;
    cout << "\t\t___________________________________________" << endl;
}

void StartGame ()
{
    do
    {
        stFinalDataWinner FinalWinner;

        cout << "\033[0m";
        cout << "\033[2j";

        system("cls");

        int NumberWinToStruct;

        FinalWinner.RoundsNum = ReadPositiveNumber("How Many Rounds You Want :  ");


        for (int RoundsCounter = 1; RoundsCounter <= FinalWinner.RoundsNum; RoundsCounter++)
        {

            cout << " Round [" << RoundsCounter << "] Begin\n";

            stRoundData RoundData;
            DataRound(RoundData);

          NumberWinToStruct =  DeterminningTheprofitForTheRounds(RoundData);

          StructDataFinalGame(FinalWinner, NumberWinToStruct);

            cout << "__________Round [" << RoundsCounter << "] __________\n";
            PrintRoundData(RoundData);


        }
        PrintDataFinalGame(FinalWinner);
    } while (ReadString("Enter (y) if you want to Reset And Try Again (Y,N) ") == "Yes");
}

int main()
{
    srand((unsigned)time(NULL));
    StartGame();
}