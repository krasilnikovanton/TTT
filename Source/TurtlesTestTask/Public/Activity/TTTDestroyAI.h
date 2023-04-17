// Turtles Test Task. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <TurtlesTestTask/Public/Player/TTTBaseCharacter.h>
#include "TTTDestroyAI.generated.h"

class USphereComponent;
class UTTTFXComponent;
class USoundCue;

UCLASS()
class TURTLESTESTTASK_API ATTTDestroyAI : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    ATTTDestroyAI();

protected:
    UPROPERTY(VisibleAnywhere, Category = "Activity")
    USphereComponent* CollisionComponent;

    UPROPERTY(VisibleAnywhere, Category = "VFX")
    UTTTFXComponent* FXComponent;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
    USoundCue* DeathSound;

    UFUNCTION()
    virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;
};
