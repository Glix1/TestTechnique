// Fill out your copyright notice in the Description page of Project Settings.


#include "Target_FindPlayer.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"
#include "TargetController.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "bb_keys.h"


UTarget_FindPlayer::UTarget_FindPlayer(FObjectInitializer const& initializer)
{
	NodeName = TEXT("Find Player Location");
}

EBTNodeResult::Type UTarget_FindPlayer::ExecuteTask(UBehaviorTreeComponent& owner, uint8 mem)
{
	//get player character and Target controller
	ACharacter* const player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	auto const control = Cast<ATargetController>(owner.GetAIOwner());
	
	//get player location 
	FVector const player_location = player->GetActorLocation();
	if (search_random)
	{
		FNavLocation loc;

		UNavigationSystemV1* const nav = UNavigationSystemV1::GetCurrent(GetWorld());
		if (nav->GetRandomPointInNavigableRadius(player_location, search_radius, loc, nullptr))
		{
			control->getBlackboard()->SetValueAsVector(bb_keys::target_location, loc.Location);
		}

	}
	else
	{
		control->getBlackboard()->SetValueAsVector(bb_keys::target_location, player_location);
	}

	FinishLatentTask(owner, EBTNodeResult::Succeeded);
	return EBTNodeResult::Type();
}
