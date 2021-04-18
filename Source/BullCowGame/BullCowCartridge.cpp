// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{

    Super::BeginPlay();
    
    SetupGame();

    // Debug Line can turn On/Off as needed
    // PrintLine(FString::Printf(TEXT("The HiddenWord is: %s"), *HiddenWord));
    // PrintLine(TEXT("The HiddenWord is: %s.\nIt is %i characters long"), *HiddenWord, HiddenWord.Len());

    // Welcomes the player
    PrintLine(TEXT("Welcome to The Bull Cow Game!!")); // TEXT is used so Unreal can encode the string
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len()); // Magic Number Remove!
    PrintLine(TEXT("Enter your guess..."));


    // Ask user for guess
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{

    ClearScreen();



    //  Checking User guess

    if(Input == HiddenWord)
    {
        PrintLine(TEXT("You WIN!"));
        // bGameOver = true;
    }
    else
    {
        if(Input.Len() == HiddenWord.Len())
        {
            PrintLine(TEXT("You have the right amount of letters but\nnot correct order"));
        }
        else
        {
            PrintLine(TEXT("Guess Again"));
        }
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
    Lives = 3;

    // bGameOver = false;

}
