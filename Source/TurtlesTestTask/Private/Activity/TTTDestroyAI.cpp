// Turtles Test Task. All rights reserved.

#include "Activity/TTTDestroyAI.h"
#include "Components/SphereComponent.h"
#include <TurtlesTestTask/Public/AI/TTTBaseAICharacter.h>
#include "AI/Components/TTTFXComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"

// Sets default values
ATTTDestroyAI::ATTTDestroyAI()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    CollisionComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
    CollisionComponent->InitSphereRadius(50.0f);
    CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
    SetRootComponent(CollisionComponent);    

    FXComponent = CreateDefaultSubobject<UTTTFXComponent>("FXComponent");
}

void ATTTDestroyAI::NotifyActorBeginOverlap(AActor* OtherActor)
{
    Super::NotifyActorBeginOverlap(OtherActor);
    ATTTBaseAICharacter* spawnActivity = Cast<ATTTBaseAICharacter>(OtherActor);
    if (spawnActivity != nullptr)
    {
        FHitResult HitResult;
        spawnActivity->Destroy();
        FXComponent->PlayImpactFX(spawnActivity->GetActorRotation(), spawnActivity->GetActorLocation());
        UGameplayStatics::PlaySoundAtLocation(GetWorld(), DeathSound, GetActorLocation());
    }
}

// Called when the game starts or when spawned
void ATTTDestroyAI::BeginPlay()
{
    Super::BeginPlay();

    check(FXComponent);
}

// Called every frame
void ATTTDestroyAI::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
