// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordList.h"


void UBullCowCartridge::BeginPlay() // When the game starts
{

    Super::BeginPlay();

    Isograms = GetValidWords(Words);
    
    SetupGame();
    
}

void UBullCowCartridge::OnInput(const FString& PlayerInput) // When the player hits enter
{

    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else    // Checking Player Guess
    {
        ProcessGuess(PlayerInput);
    }

}

void UBullCowCartridge::SetupGame()
{

    // Sets HiddenWord
    HiddenWord = Isograms[FMath::RandRange(0, Isograms.Num() - 1)];
    // Set up lives
    Lives = HiddenWord.Len();
    
    bGameOver = false;

    // Welcomes the player
    PrintLine(TEXT("Welcome to The Bull Cow Game!!")); // TEXT is used so Unreal can encode the string
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives."), Lives);
    PrintLine(TEXT("Enter your guess..."));
    // PrintLine(TEXT("The HiddenWord is: %s."), *HiddenWord); // Displays hiddenword (debug line)


}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("\nPress enter to Play Again."));
}

void UBullCowCartridge::ProcessGuess(const FString& Guess)
{
    if(Guess == HiddenWord)
    {
        PrintLine(TEXT("You WIN!"));
        EndGame();
        return;
    }
        
    // Prompt to guess again
    // Check if right number of characters
    if (Guess.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("Guess Again. \nYou have %i Lives left."), Lives);
        PrintLine(TEXT("The Hidden Word is %i letters long"), HiddenWord.Len());
        PrintLine(TEXT("You have %i lives remaining"), Lives);
        return;
    }

    //Check if word is isogram
    if (!IsIsogram(Guess))
    {    
        PrintLine(TEXT("No repeating letters, guess again"));
        return;
    }

    // Remove life if wrong guess
    PrintLine(TEXT("You have lost a life"));
    PrintLine(TEXT("%i"), --Lives);

    // Check to see if Lives > 0
    if (Lives <= 0)
    {
        PrintLine(TEXT("You have no lives left!"));
        PrintLine(TEXT("The Hidden Word was : %s"), *HiddenWord);

        EndGame();
        return;
    }

    // Show the player the Bulls and the Cows
    FBullCowCount Score = GetBullsCows(Guess);
    PrintLine(TEXT("You have %i Bulls and %i Cows"), Score.Bulls, Score.Cows);
    PrintLine(TEXT("Guess again, you have %i lives left"), Lives);

}

bool UBullCowCartridge::IsIsogram(const FString& Word) const
{

   int32 Index = 0;
   int32 Comparison = Index + 1;

   for (; Index < Word.Len(); Index++)
   {
       for (; Comparison < Word.Len(); Comparison++)
       {
           if(Word[Index] == Word[Comparison])
           {
               return false;
           }
       }
   }

    return true;

} 

TArray<FString> UBullCowCartridge::GetValidWords(const TArray<FString>& WordList) const
{

    TArray<FString> ValidWords;

    for (FString Word : WordList)
    {
        if (Word.Len() >= 4 && Word.Len() <= 8 && IsIsogram(Word))
        {
                ValidWords.Emplace(Word);
        }
    }

    return ValidWords;

}

FBullCowCount UBullCowCartridge::GetBullsCows(const FString& Guess) const
{

    FBullCowCount Count;

    for (int32 GuessIndex = 0; GuessIndex < Guess.Len(); GuessIndex++)
    {
        if (Guess[GuessIndex] == HiddenWord[GuessIndex])
        {
            Count.Bulls++;
            continue;
        }

        for (int32 HiddenIndex = 0; HiddenIndex < HiddenWord.Len(); HiddenIndex++)
        {
            if (Guess[GuessIndex] == HiddenWord[HiddenIndex])
            {
                Count.Cows++;
                break;
            }
        }
        
    }

    return Count;

}