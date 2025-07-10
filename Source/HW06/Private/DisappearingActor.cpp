#include "HW06/Public/DisappearingActor.h"

ADisappearingActor::ADisappearingActor()
{
	TimeToDisappear = 2.0f;
	TimeToAppear = 2.0f;
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
