#include "HW06/Public/SpawningActor.h"
#include "HW06/Public/ActorToSpawn.h"
#include "Kismet/GameplayStatics.h"

ASpawningActor::ASpawningActor()
{
}

void ASpawningActor::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActorToSpawn::StaticClass(), SpawnPoints);

	SpawnActor();
}

void ASpawningActor::SpawnActor()
{
	const FVector SpawnLocation = GetRandomSpawnPoint();
	
	if (const TSubclassOf<AActor> ActorToSpawn = GetRandomActor())
	{
		if (UWorld* World = GetWorld())
		{
			World->SpawnActor<AActor>(ActorToSpawn, SpawnLocation, FRotator::ZeroRotator);
		}
	}
}

FVector ASpawningActor::GetRandomSpawnPoint()
{
	if (SpawnPoints.IsEmpty()) return FVector::ZeroVector;

	const int32 RandValue = FMath::RandRange(0, SpawnPoints.Num() - 1);
	const FVector SpawnLocation = SpawnPoints[RandValue]->GetActorLocation();

	SpawnPoints.RemoveAt(RandValue);
	
	return SpawnLocation;
}

UClass* ASpawningActor::GetRandomActor()
{
	if (SpawnActors.IsEmpty()) return nullptr;

	const int32 RandValue = FMath::RandRange(0, SpawnActors.Num() - 1);
	return SpawnActors[RandValue];
}
