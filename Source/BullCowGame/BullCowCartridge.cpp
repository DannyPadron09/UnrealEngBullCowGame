// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{

    // Welcomes the player
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to The Bull Cow Game!!")); // TEXT is used so Unreal can encode the string
    PrintLine(TEXT("Guess the 4 letter word!")); // Magic Number Remove!
    PrintLine(TEXT("Press Enter to continue..."));

    // Sets up game
    InitGame();
    

    

    // Ask user for guess
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    
    ClearScreen();

    //  Checking User guess

    if(Input == HiddenWord)
    {
        PrintLine(TEXT("You WIN!"));
    }
    else
    {
        PrintLine(TEXT("You Lose"));
    }

    // Check if word is isogram
    // Check if right number of characters


    // Remove life if wrong guess

    // Check to see if Lives are still left
    // If yes then continue playing
    // If no then game over
    // Prompt user if they want to play again 

}

void UBullCowCartridge::InitGame()
{

    // Sets HiddenWord
    HiddenWord = TEXT("cake");

    // Set up lives


}
