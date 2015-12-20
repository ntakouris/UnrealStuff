#include "BluHat.h"
#include "ArraySort.h"
#include "Engine.h"

TArray<UObject*> UArraySort::FilterEqual(TArray<UObject*> Array, FName Property, float Value)
{
	TArray<UObject*> FilteredArray;

	int32 Length = Array.Num();

	for (int32 Count = 0; Count < Length; Count++){

		UObject* Current = Array[Count];

		if (UPropertyToFloat(Current, GetProperty(Current, Property)) == Value){

			FilteredArray.Add(Current);
		}
	}

	return FilteredArray;
}
TArray<UObject*> UArraySort::FilterDifferent(TArray<UObject*> Array, FName Property, float Value)
{

	TArray<UObject*> FilteredArray;

	int32 Length = Array.Num();

	for (int32 Count = 0; Count < Length; Count++){

		UObject* Current = Array[Count];

		if (UPropertyToFloat(Current, GetProperty(Current, Property)) != Value){

			FilteredArray.Add(Current);
		}
	}

	return FilteredArray;
}
TArray<UObject*> UArraySort::FilterGreater(TArray<UObject*> Array, FName Property, float Value)
{
	TArray<UObject*> FilteredArray;

	int32 Length = Array.Num();

	for (int32 Count = 0; Count < Length; Count++){

		UObject* Current = Array[Count];

		if (UPropertyToFloat(Current, GetProperty(Current, Property)) > Value){

			FilteredArray.Add(Current);
		}
	}

	return FilteredArray;
}
TArray<UObject*> UArraySort::FilterGreaterEqual(TArray<UObject*> Array, FName Property, float Value)
{

	TArray<UObject*> FilteredArray;

	int32 Length = Array.Num();

	for (int32 Count = 0; Count < Length; Count++){

		UObject* Current = Array[Count];

		if (UPropertyToFloat(Current, GetProperty(Current, Property)) >= Value){

			FilteredArray.Add(Current);
		}
	}

	return FilteredArray;
}
TArray<UObject*> UArraySort::FilterSmaller(TArray<UObject*> Array, FName Property, float Value)
{

	TArray<UObject*> FilteredArray;

	int32 Length = Array.Num();

	for (int32 Count = 0; Count < Length; Count++){

		UObject* Current = Array[Count];

		if (UPropertyToFloat(Current, GetProperty(Current, Property)) < Value){

			FilteredArray.Add(Current);
		}
	}

	return FilteredArray;
}
TArray<UObject*> UArraySort::FilterSmallerEqual(TArray<UObject*> Array, FName Property, float Value)
{

	TArray<UObject*> FilteredArray;

	int32 Length = Array.Num();

	for (int32 Count = 0; Count < Length; Count++){

		UObject* Current = Array[Count];

		if (UPropertyToFloat(Current, GetProperty(Current, Property)) <= Value){

			FilteredArray.Add(Current);
		}
	}

	return FilteredArray;
}
void UArraySort::SortWithProperty(TArray<UObject*> Array, FName Property)
{
	uint32 ArraySize = Array.Num();
	QuickSort(Array, Property,0, ArraySize - 1);
}
TArray<UObject*> UArraySort::Reverse(TArray<UObject*> Array)
{
	TArray<UObject*> NewArray;

	int32 Length = Array.Num();

	//Standard reverse for loop
	for (int32 Count = Length - 1; Count >= 0; Count--){
		NewArray.Add(Array[Count]);
	}
	return NewArray;
}
UObject* UArraySort::MaxWithProperty(TArray<UObject*> Array , FName Property)
{

	int32 Length = Array.Num();

	UObject *Dominant = Array[0];

	for (int32 Count = 0; Count < Length; Count++){

		UObject* Current = Array[Count];

		//Compare the properties of every element, keeping the max one
		if (CompareProperties(Current , GetProperty(Current, Property), Dominant , GetProperty(Dominant, Property))){

			Dominant = Current;
		}
	}

	return Dominant;
}
UObject* UArraySort::MinWithProperty(TArray<UObject*> Array, FName Property)
{

	int32 Length = Array.Num();

	UObject* Dominant = Array[0];

	for (int32 Count = 0; Count < Length; Count++){
		UObject* Current = Array[Count];
		
		//Compare the properties of every element, keeping the min one
		if (!CompareProperties(Current , GetProperty(Current, Property) , Dominant , GetProperty(Dominant, Property))){
			Dominant = Current;
		}
	}

	return Dominant;
}
bool UArraySort::CompareProperties(UObject* Object1, UProperty* Property1, UObject* Object2, UProperty* Property2)
{
	UFloatProperty* FloatProperty1 = Cast<UFloatProperty>(Property1);
	UFloatProperty* FloatProperty2 = Cast<UFloatProperty>(Property2);

	float Float1 = FloatProperty1->GetPropertyValue_InContainer(Object1);
	float Float2 = FloatProperty2->GetPropertyValue_InContainer(Object2);

	return Float1 > Float2;
}
UProperty* UArraySort::GetProperty(UObject *Object, FName DesiredProperty){

	//Nesting is too difficult and consumes many resources. Just expose a property on your objects.

	auto Class = Object->GetClass();
	UProperty* Property = Class->FindPropertyByName(DesiredProperty);

	return Property;

	/*//Iterate through all the properties and variables - MANUAL WAY
	for (TFieldIterator<UProperty> PropIt(Class); PropIt; ++PropIt){

		auto Property = *PropIt;
		UE_LOG(LogTemp, Warning, TEXT("Tested %s") , * Property->GetFName().ToString());
		//If it matches the desired name, return it
		if (Property->GetFName() == DesiredProperty){
			return Property;
		}
	}
	return NULL;*/
}
void UArraySort::QuickSort(TArray<UObject*> Array, FName DesiredProperty, uint32 Left, uint32 Right){
	uint32 i = Left, j = Right;
	uint32 PivotIndex = (Left + Right) / 2;
	UObject* Pivot = Array[PivotIndex];

	while (i <= j) {
		while (!CompareProperties(Array[i], GetProperty(Array[i], DesiredProperty), Pivot, GetProperty(Pivot, DesiredProperty)))
			i++;
		while (CompareProperties(Array[j], GetProperty(Array[j], DesiredProperty), Pivot, GetProperty(Pivot, DesiredProperty)))
			j--;
		if (i <= j) {
			/*Temp = arr[i];
			Array[i] = Array[j];
			Array[j] = Temp;*/
			Array.Swap(i, j);
			i++;
			j--;
		}
	};

	if (Left < j)
		QuickSort(Array,DesiredProperty, Left, j);
	if (i < Right)
		QuickSort(Array,DesiredProperty, i, Right);
}
float UArraySort::UPropertyToFloat(UObject* Object , UProperty* Property){

	UFloatProperty* FloatProperty = Cast<UFloatProperty>(Property);
	float FloatValue = FloatProperty->GetPropertyValue_InContainer(Object);
	return FloatValue;

}
