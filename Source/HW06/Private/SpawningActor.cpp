#include "HW06/Public/SpawningActor.h"
#include "HW06/Public/ActorToSpawn.h"
#include "Kismet/GameplayStatics.h"

ASpawningActor::ASpawningActor()
	: SpawnCount(1)
{
}

void ASpawningActor::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActorToSpawn::StaticClass(), SpawnPoints);

	for (int32 i = 0; i < SpawnCount; i++)
	{
		SpawnActor();
	}
}

void ASpawningActor::SpawnActor()
{
	const FVector SpawnLocation = GetRandomSpawnPoint();
	
	if (const TSubclassOf<AActor> ActorToSpawn = GetRandomActor())
	{
		if (UWorld* World = GetWorld())
		{
			World->SpawnActor<AActor>(ActorToSpawn, SpawnLocation, FRotator(0.0f, 90.0f, 0.0f));
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
