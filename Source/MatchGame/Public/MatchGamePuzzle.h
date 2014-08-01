#pragma once

#include "MatchGameCard.h"
#include "GameFramework/Actor.h"
#include "MatchGamePuzzle.generated.h"

/**
 * 
 */
UCLASS()
class MATCHGAME_API AMatchGamePuzzle : public AActor
{
	GENERATED_UCLASS_BODY()

	/** Dummy root component */
	UPROPERTY(Category = Block, VisibleDefaultsOnly, BlueprintReadOnly)
	TSubobjectPtr<class USceneComponent> DummyRoot;
	
	/** This is what the puzzle will look like */
	UPROPERTY(Category = Puzzle, VisibleDefaultsOnly, BlueprintReadOnly)
	TSubobjectPtr<class UStaticMeshComponent> PuzzleMesh;

	/** Match Cards */
	UPROPERTY(Category = Cards, VisibleDefaultsOnly, BlueprintReadOnly)
	TArray<AMatchGameCard*> Cards;

	/** Setup new puzzle */
	UFUNCTION(Category = Puzzle, BlueprintCallable)
	void CreatePuzzle(UStaticMesh* NewPuzzleMesh);
};
