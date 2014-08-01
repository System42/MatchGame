
#include "MatchGame.h"
#include "MatchGamePuzzle.h"
#include "Kismet/GameplayStatics.h"


AMatchGamePuzzle::AMatchGamePuzzle(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	PuzzleMesh = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("PuzzleMesh"));

	DummyRoot = PCIP.CreateDefaultSubobject<USceneComponent>(this, TEXT("Dummy0"));
	RootComponent = DummyRoot;

	PuzzleMesh->AttachTo(DummyRoot);
}

void AMatchGamePuzzle::CreatePuzzle(UStaticMesh* NewPuzzleMesh)
{
	if (PuzzleMesh && NewPuzzleMesh) {
		PuzzleMesh->SetStaticMesh(NewPuzzleMesh);

		for (int index = 0; index < PuzzleMesh->GetAllSocketNames().Num(); index++)
		{
			UGameplayStatics::GetPlayerController(this, 0)->ClientMessage(PuzzleMesh->GetAllSocketNames()[index].ToString());
		}
	}
}