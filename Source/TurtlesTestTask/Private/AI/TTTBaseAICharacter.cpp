// Turtles Test Task. All rights reserved.

#include "AI/TTTBaseAICharacter.h"
#include "AI/TTTBaseAIController.h"
#include "AI/Components/TTTFXComponent.h"

ATTTBaseAICharacter::ATTTBaseAICharacter(const FObjectInitializer& ObjInit) : Super(ObjInit)
{
    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
    AIControllerClass = ATTTBaseAIController::StaticClass();
}
