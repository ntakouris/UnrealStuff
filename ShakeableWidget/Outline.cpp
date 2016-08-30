void Tick(FGeometry MyGeometry, float InDeltaTime) {

	Super::Tick(MyGeometry, DeltaTime);

	FVector2D CurrentPosition;

	//make up for lame precision
	if (CurrentPosition == BasePosition && this->Target == BasePosition) {//Near center && target is center
		//reset to base position
	}else if(CurrentPosition == this->Target && this->Target != BasePosition){ //On the edge && target is the edge
		//set to edge
	}
	
	//regrab current position

	//then do normal acceleration stuff
	
	FVector2D Direction = this->Target - CurrentPosition;
	Direction.Normalize();
	this->Speed = this->Speed + Direction * Acceleration;
	FVector2D NewPosition = CurrentPosition + this->Speed * InDeltaTime;
}

void Shake(const FVector2D Direction, uint32 Magnitude, float Acceleration) {
	this->Target = Direction * Magnitude;
	this->Acceleration = Acceleration;
}
