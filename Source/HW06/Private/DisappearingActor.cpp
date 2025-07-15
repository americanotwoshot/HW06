#include "HW06/Public/DisappearingActor.h"

ADisappearingActor::ADisappearingActor()
{
	TimeToDisappear = FMath::FRandRange(1.0f, 3.0f);
	TimeToAppear = FMath::FRandRange(1.0f, 3.0f);
}

void ADisappearingActor::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ADisappearingActor::Disappear, TimeToDisappear, false);
}

void ADisappearingActor::Disappear()
{
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ADisappearingActor::Appear, TimeToAppear, false);
}

void ADisappearingActor::Appear()
{
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ADisappearingActor::Disappear, TimeToDisappear, false);
}
