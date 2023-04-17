// Turtles Test Task. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <TurtlesTestTask/Public/Player/TTTBaseCharacter.h>
#include "TTTBaseActivity.generated.h"

class USphereComponent;
class UTTTFXComponent;
class USoundCue;

UCLASS()
class TURTLESTESTTASK_API ATTTBaseActivity : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    ATTTBaseActivity();

protected:
    UPROPERTY(VisibleAnywhere, Category = "Activity")
    USphereComponent* CollisionComponent;
    UPROPERTY(EditAnywhere)
    TSubclassOf<ATTTBaseCharacter> CubeClass;

    UPROPERTY(VisibleAnywhere, Category = "VFX")
    UTTTFXComponent* FXComponent;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
    USoundCue* StartSound;

    UPROPERTY(EditAnywhere)
    FVector StartSpawn;
    UFUNCTION()
    virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
    UFUNCTION()
    virtual void NotifyActorEndOverlap(AActor* OtherActor) override;
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;
};
