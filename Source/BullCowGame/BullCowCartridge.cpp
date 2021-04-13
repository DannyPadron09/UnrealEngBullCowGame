// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to The Bull Cow Game!!")); // TEXT is used so Unreal can encode the string
    PrintLine(TEXT("Input something and press Enter to clear screen"));
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    FString HiddenWord = TEXT("cake");
    if(Input == HiddenWord)
    {
        PrintLine(TEXT("You WIN!"));
    }
    else
    {
        PrintLine(TEXT("You Lose"));
    }

    // PrintLine(Input);
}