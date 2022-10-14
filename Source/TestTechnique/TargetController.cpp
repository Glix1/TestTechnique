// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetController.h"

ATargetController::ATargetController(FObjectInitializer const& initializer)
{
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> obj(TEXT("C:/Users/Glix/Documents/Unreal Projects/TestTechnique/Content/NPC/BTTarget.uasset"));
	if (obj.Succeeded())
	{
		behaviorTree = obj.Object;
	}
	behaviorTreeComponent = initializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("TargetBehavior"));
	blackBoard = initializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("TargetBlackBoard"));
}

void ATargetController::BeginPlay()
{
	Super::BeginPlay();
	RunBehaviorTree(behaviorTree);
	behaviorTreeComponent->StartTree(*behaviorTree);
}

void ATargetController::OnPossess(APawn* const pawn)
{
	Super::OnPossess(pawn);
	if (blackBoard)
	{
		blackBoard->InitializeBlackboard(*behaviorTree->BlackboardAsset);
	}
}

UBlackboardComponent* ATargetController::getBlackboard() const
{
	return blackBoard;
}
