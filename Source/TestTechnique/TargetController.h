// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Target.h"
#include "TargetController.generated.h"

UCLASS()
class TESTTECHNIQUE_API ATargetController : public AAIController
{
	GENERATED_BODY()

public:
	ATargetController(FObjectInitializer const& initializer = FObjectInitializer::Get());
	void BeginPlay() override;
	void OnPossess(APawn* const pawn) override;
	
	class UBlackboardComponent* getBlackboard() const;

private:
	class UBehaviorTreeComponent* behaviorTreeComponent;
	class UBehaviorTree* behaviorTree;
	class UBlackboardComponent* blackBoard;
};
