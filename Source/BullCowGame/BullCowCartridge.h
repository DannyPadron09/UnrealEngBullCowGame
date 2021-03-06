// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

	public:
	virtual void BeginPlay() override;
	virtual void OnInput(const FString& Input) override;
	void SetupGame();
	void EndGame();
	void ProcessGuess(const FString& Guess);
	bool IsIsogram(const FString& Word) const; // const before FString is to pass by reference 
											   // const after is a promise to not change 'Member Variables'
	TArray<FString> GetValidWords(const TArray<FString>& WordList) const;
	FBullCowCount GetBullsCows(const FString& Guess) const; // When using '&' without 'const' means its an out parameter


	// 'Member Variables'
	// Your declarations go below!
	private:
	FString HiddenWord;
	int32 Lives;
	bool bGameOver;
	TArray<FString> Isograms;
};

