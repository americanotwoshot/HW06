#pragma once

#include "CoreMinimal.h"
#include "BaseActor.h"
#include "MovingActor.generated.h"

UCLASS()
class HW06_API AMovingActor : public ABaseActor
{
	GENERATED_BODY()
	
public:	
	AMovingActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	FVector StartLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MaxRange;
	
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
