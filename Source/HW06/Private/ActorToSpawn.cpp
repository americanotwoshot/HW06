#include "HW06/Public/ActorToSpawn.h"

AActorToSpawn::AActorToSpawn()
{
	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(RootComp);

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	MeshComp->SetupAttachment(RootComp);
}

void AActorToSpawn::BeginPlay()
{
	Super::BeginPlay();

	SetActorHiddenInGame(true);
}
