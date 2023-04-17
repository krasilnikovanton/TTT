// Turtles Test Task. All rights reserved.

#include "TTTGameModeBase.h"
#include "Player/TTTBaseCharacter.h"
#include "Player/TTTPlayerController.h"

ATTTGameModeBase::ATTTGameModeBase()
{
    DefaultPawnClass = ATTTBaseCharacter::StaticClass();
    PlayerControllerClass = ATTTPlayerController::StaticClass();
}
