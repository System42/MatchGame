#pragma once

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
	
	UPROPERTY(Category = Puzzle, VisibleDefaultsOnly, BlueprintReadOnly)
	TSubobjectPtr<class UStaticMeshComponent> PuzzleMesh;

	UFUNCTION(Category = Puzzle, BlueprintCallable)
	void CreatePuzzle(UStaticMesh* NewPuzzleMesh);
};
