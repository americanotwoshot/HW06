#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawningActor.generated.h"

UCLASS()
class HW06_API ASpawningActor : public AActor
{
	GENERATED_BODY()

public:	
	ASpawningActor();

	UPROPERTY()
	TArray<AActor*> SpawnPoints;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	TArray<TSubclassOf<AActor>> SpawnActors;
	
protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void SpawnActor();
	
	FVector GetRandomSpawnPoint();
	UClass* GetRandomActor();
};
