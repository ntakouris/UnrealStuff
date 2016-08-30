#include "Runtime/Core/Public/Math/Vector2D.h"
//Dependent modules: "UMG", "Slate", "SlateCore"
public:
	virtual void Tick(FGeometry MyGeometry, float InDeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = Miscellaneous)
	void Shake(const FVector2D Direction , int32 Magnitude, float Acceleration);
	
private:
	FVector2D BasePosition;
	FVector2D Target;
	FVector2D Speed;
	float Acceleration;
