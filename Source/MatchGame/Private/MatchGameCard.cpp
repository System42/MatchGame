

#include "MatchGame.h"
#include "MatchGameCard.h"


AMatchGameCard::AMatchGameCard(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	UE_LOG(LogTemp, Warning, TEXT("In AMatchGameCard Cons"));
	// Structure to hold one-time initialization
	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinderOptional<UStaticMesh> PlaneMesh;
		ConstructorHelpers::FObjectFinderOptional<UMaterialInstance> BlueMaterial;
		ConstructorHelpers::FObjectFinderOptional<UMaterialInstance> OrangeMaterial;
		FConstructorStatics()
			: PlaneMesh(TEXT("/Game/Meshes/TemplateCube_Rounded.TemplateCube_Rounded"))
			, BlueMaterial(TEXT("/Engine/TemplateResources/MI_Template_BaseBlue.MI_Template_BaseBlue"))
			, OrangeMaterial(TEXT("/Engine/TemplateResources/MI_Template_BaseOrange.MI_Template_BaseOrange"))
		{
		}
	};
	static FConstructorStatics ConstructorStatics;

	DummyRoot = PCIP.CreateDefaultSubobject<USceneComponent>(this, TEXT("Dummy0"));
	RootComponent = DummyRoot;

	CardMesh = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("CardMesh"));
	//CardMesh->SetStaticMesh(ConstructorStatics.PlaneMesh.Get());
	//CardMesh->SetMaterial(0, ConstructorStatics.BlueMaterial.Get());
	CardMesh->AttachTo(DummyRoot);
	CardMesh->OnClicked.AddDynamic(this, &AMatchGameCard::CardClicked);
	CardMesh->OnInputTouchBegin.AddDynamic(this, &AMatchGameCard::OnFingerPressedCard);

	//OrangeMaterial = ConstructorStatics.OrangeMaterial.Get();
}

void AMatchGameCard::CardClicked(UPrimitiveComponent* ClickedComp)
{
	OnSelected();
}

void AMatchGameCard::OnSelected_Implementation()
{
	// No default implementation
}

void AMatchGameCard::OnFingerPressedCard(ETouchIndex::Type FingerIndex, UPrimitiveComponent* TouchedComponent)
{
	CardClicked(TouchedComponent);
}

