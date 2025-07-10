#include "HW06/Public/TeleportingActor.h"

ATeleportingActor::ATeleportingActor()
{
	TimeToTeleport = 2.0f;
	StartLocation = FVector::ZeroVector;
	TeleportLocationsFromStartLocation.Add(StartLocation);
}

void ATeleportingActor::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ATeleportingActor::Teleport, TimeToTeleport, false);
}

FVector ATeleportingActor::GetRandomTeleportLocation() const
{
	TArray<FVector> ValidLocations;

	for (const FVector& Location : TeleportLocationsFromStartLocation)
	{
		if (!Location.Equals(GetActorLocation() - StartLocation, 0.1f))
		{
			ValidLocations.Add(Location);
		}
	}

	if (ValidLocations.Num() == 0)
	{
		return GetActorLocation();
	}

	const int32 RandValue = FMath::RandRange(0, ValidLocations.Num() - 1);
	return ValidLocations[RandValue];
}

void ATeleportingActor::Teleport()
{
	if (TeleportLocationsFromStartLocation.Num() <= 1) return;

	SetActorLocation(StartLocation + GetRandomTeleportLocation());

	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ATeleportingActor::Teleport, TimeToTeleport, false);
}
