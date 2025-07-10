#pragma once

#include "CoreMinimal.h"
#include "BaseActor.h"
#include "DisappearingActor.generated.h"

/**
 * 
 */
UCLASS()
class HW06_API ADisappearingActor : public ABaseActor
{
	GENERATED_BODY()

public:
	ADisappearingActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time")
	float TimeToDisappear;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time")
	float TimeToAppear;
	
	virtual void BeginPlay() override;

	UFUNCTION()
	void Disappear();
	UFUNCTION()
	void Appear();

private:
	FTimerHandle TimerHandle;
};
