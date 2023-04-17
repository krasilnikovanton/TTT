// Turtles Test Task. All rights reserved.

#include "Activity/TTTBaseActivity.h"
#include "Components/SphereComponent.h"
#include "AI/Components/TTTFXComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"

// Sets default values
ATTTBaseActivity::ATTTBaseActivity()
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

// Called when the game starts or when spawned
void ATTTBaseActivity::BeginPlay()
{
    Super::BeginPlay();

    check(FXComponent);
}

// Called every frame
void ATTTBaseActivity::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
void ATTTBaseActivity::NotifyActorBeginOverlap(AActor* OtherActor)
{
    Super::NotifyActorBeginOverlap(OtherActor);
    ATTTBaseCharacter* spawnActivity = Cast<ATTTBaseCharacter>(OtherActor);
    if (spawnActivity != nullptr)
    {
        UE_LOG(LogTemp, Display, TEXT("In"))
        UWorld* World = GetWorld();
        if (World)
        {
            const FTransform ItemTransform = FTransform(FRotator::ZeroRotator, StartSpawn);
            ATTTBaseCharacter* TurtleActor = World->SpawnActor<ATTTBaseCharacter>(CubeClass, ItemTransform);
            TurtleActor->SpawnDefaultController();
            FXComponent->PlayImpactFX(spawnActivity->GetActorRotation(), spawnActivity->GetActorLocation());
            UGameplayStatics::PlaySoundAtLocation(GetWorld(), StartSound, GetActorLocation());
        }
    }
}

void ATTTBaseActivity::NotifyActorEndOverlap(AActor* OtherActor)
{
    Super::NotifyActorEndOverlap(OtherActor);
    ATTTBaseCharacter* spawnActivity = Cast<ATTTBaseCharacter>(OtherActor);
    if (spawnActivity != nullptr)
    {
        UE_LOG(LogTemp, Display, TEXT("Out"))
    }
}
