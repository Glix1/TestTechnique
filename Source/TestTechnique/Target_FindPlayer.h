// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "Target_FindPlayer.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class TESTTECHNIQUE_API UTarget_FindPlayer : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UTarget_FindPlayer(FObjectInitializer const& initializer);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& owner, uint8 mem);

protected:
	UPROPERTY(EditAnywhere, Blueprintable, Category = "Search", meta = (AllowedProtectedAccess = "true"))
		bool search_random = false;

	UPROPERTY(EditAnywhere, Blueprintable, Category = "Search", meta = (AllowedProtectedAccess = "true"))
		float search_radius = 150.0f;
};
