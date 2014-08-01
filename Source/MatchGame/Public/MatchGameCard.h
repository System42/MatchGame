

#pragma once

#include "GameFramework/Actor.h"
#include "MatchGameCard.generated.h"

/**
 * 
 */
UCLASS()
class MATCHGAME_API AMatchGameCard : public AActor
{
	GENERATED_UCLASS_BODY()

	/** Dummy root component */
	UPROPERTY(Category = Card, VisibleDefaultsOnly, BlueprintReadOnly)
	TSubobjectPtr<class USceneComponent> DummyRoot;
	
	/** This is what the card looks like */
	UPROPERTY(Category = Card, VisibleDefaultsOnly, BlueprintReadOnly)
	TSubobjectPtr<class UStaticMeshComponent> CardMesh;

	/** Parent Puzzle object */
	UPROPERTY()
	class AMatchGamePuzzle* ParentPuzzle;

	UFUNCTION(BlueprintNativeEvent)
	void OnSelected();

	UFUNCTION()
	void CardClicked(UPrimitiveComponent* ClickedComp);

	UFUNCTION()
	void OnFingerPressedCard(ETouchIndex::Type FingerIndex, UPrimitiveComponent* TouchedComponent);

	/** Pointer to orange material used on active blocks */
	UPROPERTY()
	UMaterialInstance* OrangeMaterial;
};
