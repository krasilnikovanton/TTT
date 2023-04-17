// Turtles Test Task. All rights reserved.

#include "AI/Components/TTTFXComponent.h"
#include "NiagaraFunctionLibrary.h"

// Sets default values for this component's properties
UTTTFXComponent::UTTTFXComponent()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = true;

    // ...
}

void UTTTFXComponent::PlayImpactFX(const FRotator Rotation, const FVector Location)
{
    // niagara
    UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(),  //
        Effect,                                                 //
        Location,                                               //
        Rotation);
}

// Called when the game starts
void UTTTFXComponent::BeginPlay()
{
    Super::BeginPlay();

    // ...
}

// Called every frame
void UTTTFXComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // ...
}
