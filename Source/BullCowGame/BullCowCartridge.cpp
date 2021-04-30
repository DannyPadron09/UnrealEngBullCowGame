// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordList.h"


void UBullCowCartridge::BeginPlay() // When the game starts
{

    Super::BeginPlay();
    
    SetupGame();

    
    PrintLine(TEXT("The HiddenWord is: %s."), *HiddenWord);

}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{

    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else    // Checking Player Guess
    {
        ProcessGuess(Input);
    }

}

void UBullCowCartridge::SetupGame()
{

    // Sets HiddenWord
    HiddenWord = TEXT("cake");
    // Set up lives
    Lives = HiddenWord.Len();
    
    bGameOver = false;

    // Welcomes the player
    PrintLine(TEXT("Welcome to The Bull Cow Game!!")); // TEXT is used so Unreal can encode the string
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives."), Lives);
    PrintLine(TEXT("Enter your guess..."));

}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("\nPress enter to Play Again."));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
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
    PrintLine(TEXT("Guess again, you have %i lives left"), Lives);

}

bool UBullCowCartridge::IsIsogram(FString Word) const
{
    /*  needs to test each letter
        starts at the first letter [0]
        compare it to the next letter
        keep comparing until it reaches (Word.Len() - 1)
        if any  of the letters are the same return 'false'
    */

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