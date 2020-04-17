// Copyright Matthew Jackson, 2020

#pragma once

#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Grabber.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY() // if not on line 13, it generates error messages that can be ignored


public:	
	// Sets default values for this component's properties
	UGrabber();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


protected:
	virtual void BeginPlay() override;

private:
	float Reach = 100.f;

	void Grab();
	void Release();
	void FindPhysicsHandle();
	void SetupInputComponent();
	FHitResult GetFirstPhysicsBodyInReach() const;
	
	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UPhysicsHandleComponent* GrabComponent = nullptr;
	UInputComponent* InputComponent = nullptr;
};
