// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{

    Super::BeginPlay();
    
    SetupGame();

    // Debug Line can turn On/Off as needed
    // PrintLine(FString::Printf(TEXT("The HiddenWord is: %s"), *HiddenWord));
    // PrintLine(TEXT("The HiddenWord is: %s.\nIt is %i characters long"), *HiddenWord, HiddenWord.Len());

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
    

    // Check if word is isogram
    // Check if right number of characters


    // Remove life if wrong guess

    // Check to see if Lives are still left
    // If yes then continue playing
    // If no then game over
    // Prompt user if they want to play again 

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
    PrintLine(TEXT("Press enter to Play Again."));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if(Guess == HiddenWord)
        {
            PrintLine(TEXT("You WIN!"));
            EndGame();
        }
        else
        {
            PrintLine(TEXT("You have lost a life"));
            PrintLine(TEXT("%i"), --Lives);

            if (Lives > 0)
            {
                if (Guess.Len() != HiddenWord.Len())
                {
                    PrintLine(TEXT("Guess Again. \nYou have %i Lives left."), Lives);
                }
            }
            else
            {
                PrintLine(TEXT("You have no lives left!"));
                EndGame();
            }
        }
}