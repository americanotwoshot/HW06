#pragma once

#include "CoreMinimal.h"
#include "BaseActor.h"
#include "TeleportingActor.generated.h"

UCLASS()
class HW06_API ATeleportingActor : public ABaseActor
{
	GENERATED_BODY()

public:
	ATeleportingActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Teleporting")
	TArray<FVector> TeleportLocationsFromStartLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Teleporting")
	float TimeToTeleport;

	virtual void BeginPlay() override;

	UFUNCTION()
	void Teleport();

private:
	FTimerHandle TimerHandle;
	FVector StartLocation;

	FVector GetRandomTeleportLocation() const;
};
