// Turtles Test Task. All rights reserved.

#include "Player/TTTBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"

// Sets default values
ATTTBaseCharacter::ATTTBaseCharacter(const FObjectInitializer& ObjInit) : Super(ObjInit)
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
    CameraComponent->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void ATTTBaseCharacter::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ATTTBaseCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATTTBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    if (!ensure(PlayerInputComponent)) return;

    PlayerInputComponent->BindAxis("MoveForward", this, &ATTTBaseCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ATTTBaseCharacter::MoveRight);
    PlayerInputComponent->BindAxis("LookUp", this, &ATTTBaseCharacter::AddControllerPitchInput);
    PlayerInputComponent->BindAxis("TurnAround", this, &ATTTBaseCharacter::AddControllerYawInput);
}

void ATTTBaseCharacter::MoveForward(float Amount)
{
    if (Amount == 0) return;
    AddMovementInput(GetActorForwardVector(), Amount);
}

void ATTTBaseCharacter::MoveRight(float Amount)
{
    if (Amount == 0) return;
    AddMovementInput(GetActorRightVector(), Amount);
}
