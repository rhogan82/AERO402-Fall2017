// Fill out your copyright notice in the Description page of Project Settings.

#include "NewActorComponent.h"
#include "ROB_Power.h"
#include "../../../../../../../../Program Files/Epic Games/UE_4.16/Engine/Source/Runtime/Engine/Classes/GameFramework/Actor.h"



// Sets default values for this component's properties
UNewActorComponent::UNewActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UNewActorComponent::BeginPlay()
{
	Super::BeginPlay();

	powerlevel = 1200.0;
	// ...
	
}


// Called every frame
void UNewActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	

	Power_Level = new ROB_Power();
	//F = new AActor();
	//A = F->GetVelocity();
	A = F->GetVelocity();
	//B = { 0.,0.,0. };
	//double A = 1;
		if (A == A){
			movement = true;
			x = 0;
		}
		else {
			movement = false;
			x = 1;
		};

	powerlevel = Power_Level->Power_Level(movement, powerlevel, DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("PowerLevel: %f"),powerlevel);


	// ...
}


