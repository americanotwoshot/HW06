#include "HW06/Public/MovingActor.h"

AMovingActor::AMovingActor()
{
	PrimaryActorTick.bCanEverTick = true;

	MoveSpeed = 500.0f;
	StartLocation = FVector::ZeroVector;
	MaxRange = 1000.0f;
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
	NewLocation.X += MoveSpeed * DeltaTime;
	SetActorLocation(NewLocation);
	if (FVector::Dist(NewLocation, StartLocation) > MaxRange)
	{
		StartLocation = NewLocation;
		MoveSpeed *= -1.0f;
	}
}

