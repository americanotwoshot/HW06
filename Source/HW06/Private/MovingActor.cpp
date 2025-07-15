#include "HW06/Public/MovingActor.h"

AMovingActor::AMovingActor()
{
	PrimaryActorTick.bCanEverTick = true;

	MoveSpeed = FMath::RandRange(500.0f, 700.0f);
	StartLocation = FVector::ZeroVector;
	MaxRange = FMath::RandRange(700.0f, 1000.0f);
}

void AMovingActor::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	NewLocation.Y += MoveSpeed * DeltaTime;
	SetActorLocation(NewLocation);
	if (FVector::Dist(NewLocation, StartLocation) > MaxRange)
	{
		//StartLocation = NewLocation;
		MoveSpeed *= -1.0f;
	}
}

