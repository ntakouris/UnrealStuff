#Zark's notes on UE4's [C++ oriented] stuff that are confusing , lack documentation and proper explanation. Tricks included - Must read for beginners

Tip: Don't change versions while developing/learning. Stuff change and stuff WILL break.

Mobile (especially android devices) developers beware! Different devices combined with different OS versions lack 
specific features (AO,SSR,Different OGL Versions). Keep that in mind when trying to use new technologies to achieve
special graphic effects.

Want to package for 32-bit windows and your build crashes? Make sure you have downloaded and using the source version
of the engine.

I like: Making C++ classes, coding all the behavior there. Then creating blueprints that edit defaults only.
​
TIP: Don't let these debug messages and traces get to production , use:
​
```cpp

#include "Engine.h"
...
#if UE_BUILD_DEBUG
     GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "debug msg");
#endif
```

​
Check if actor mesh is of specific type:
​
```cpp
Check if actor mesh is of specific type
for(UActorComponent  i : OtherActor->GetComponentsByClass(UStaticMeshComponent::StaticClass()) {
 
        if(((UStaticMeshComponent*) i)->StaticMesh->GetPathName().Equals("/Game/FirstPerson/Meshes/FirstPersonTemplateCube.FirstPersonTemplateCube"))... // Dont forget continue;
 }
```
​
Don't forget about UGameplayStatics!
​
Vector math support operator overloading.
​
Apply velocity to an actor that `Actor->IsRootComponentMovable && Actor->GetRootComponent()->IsSimulatingPhysics`
`Actor->GetRootPrimitiveComponent()->SetPhysicsLinearVelocity(velocity, false);`
​
The generated header file include should be the last include and the first include needs to be the header file
with the name of your project.
​
In order to add a timer in C++ you need a `FTimerHandle` in order to keep track of it. It is included in `Actor.h`, the syntax is as follows:
​
```cpp
//Declare somewhere - Probably .h file
FTimerHandle TimerHandle;
​
//Somewhere in your .cpp file - NOT IN THE CONSTRUCTOR , BREAKPOINT WILL TRIGGER IF YOU DON'T DO OTHERWISE
GetWorldTimerManager().SetTimer(TimerHandle, this , &Method, DelayBetweenLoops , LoopTheTimer, FirstDelayInSeconds);
```
​
Obviously if `LoopTheTimer` is `false` , `DelayBetweenLoops` is going to be ignored.
​
```cpp
Delay(FirstDelayInSeconds) -> &Method -> If LoopTheTimer == true -> Delay (DelayBetweenLoops) -> &Method -> ... //Till timer is stopped
```
​
You can have timers without a class and method reference:
​
```cpp
GetWorld()->GetTimerManager().SetTimer(TimerHandle, DelayBetweenLoops, LoopTheTimer, FirstDelayInSeconds);
```
​
No use case for `LoopTheTimer == true` :) You just need to check if it is active with `GetWorld()->GetTimerManager().IsTimerActive(TimerHandle)`.
​
How to initialize custom UActorComponents (and maybe UObjects in general) on runtime:
​
```cpp
UActorComponent* comp = ConstructObject<UActorComponent>(UActorComponent::StaticClass(), Owner);
comp->RegisterComponentWithWorld(GetWorld()); //Only for UActorComponents
```
​
How to hotswap custom UActorComponents in runtime:
​
```cpp
//If registered unregister first
//follow instructions on top to initialize :)
```

For multiplayer games: Gamemode is used only on the server. GameState's replicated values suit the needs of game time,
captured points , drop locations etc.

Just use the GameState to track the state of the game (duh!).

A delay of 0 (zero) will cause code to execute next frame.

Don't use default C++ types because their size may vary. Use Unreal's variations instead (e.g. uint32). You can use float though!

Speaking of that, for simplicity reasons, uint8 (Byte) and int32 (Integer) are the only supported int types in blueprints.

Set a rotation of an actor via a forward vector : Use XVector to Rotation
