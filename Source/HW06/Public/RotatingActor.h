#pragma once

#include "CoreMinimal.h"
#include "BaseActor.h"
#include "RotatingActor.generated.h"

UCLASS()
class HW06_API ARotatingActor : public ABaseActor
{
	GENERATED_BODY()
	
public:	
	ARotatingActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	float RotationSpeed;
	
protected:
	virtual void Tick(float DeltaTime) override;

};
