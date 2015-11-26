#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "ArraySort.generated.h"

/**
 * 
 */
UCLASS()
class BLUHAT_API UArraySort : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public: 

	//Keep elements that are equal compared to the value
	UFUNCTION(BlueprintCallable, Category = "BluHatLibrary")
		static TArray<UObject*> FilterEqual(TArray<UObject*> Array, FName Property, float Value);

	//Keep elements that are different compared to the value
	UFUNCTION(BlueprintCallable, Category = "BluHatLibrary")
		static TArray<UObject*> FilterDifferent(TArray<UObject*> Array, FName Property, float Value);

	//Keep elements that are greater compared to the value
	UFUNCTION(BlueprintCallable, Category = "BluHatLibrary")
		static TArray<UObject*> FilterGreater(TArray<UObject*> Array, FName Property, float Value);

	//Keep elements that are greater or equal compared to the value
	UFUNCTION(BlueprintCallable, Category = "BluHatLibrary")
		static TArray<UObject*> FilterGreaterEqual(TArray<UObject*> Array, FName Property, float Value);

	//Keep elements that are smaller compared to the value
	UFUNCTION(BlueprintCallable, Category = "BluHatLibrary")
		static TArray<UObject*> FilterSmaller(TArray<UObject*> Array, FName Property, float Value);

	//Keep elements that are smaller or equal compared to the value
	UFUNCTION(BlueprintCallable, Category = "BluHatLibrary")
		static TArray<UObject*> FilterSmallerEqual(TArray<UObject*> Array, FName Property, float Value);

	//Sort array based on a property
	UFUNCTION(BlueprintCallable, Category = "BluHatLibrary")
		static void SortWithProperty(TArray<UObject*> Array, FName Property);

	//Get element based on a max property
	UFUNCTION(BlueprintCallable, Category = "BluHatLibrary")
		static UObject* MaxWithProperty(TArray<UObject*> Array, FName Property);

	//Get element based on a min property
	UFUNCTION(BlueprintCallable, Category = "BluHatLibrary")
		static UObject* MinWithProperty(TArray<UObject*> Array, FName Property);

	//Reverse an array
	UFUNCTION(BlueprintCallable, Category = "BluHatLibrary")
		static TArray<UObject*> Reverse(TArray<UObject*> Array);
private:
	//Get property by string, from a UObject. Does not support nesting.
		static UProperty* GetProperty(UObject* Object, FName DesiredProperty);

	//Return Property 1 float value > Property 2 float value
		static bool CompareProperties(UObject* Object1, UProperty* Property1, UObject* Object2, UProperty* Property2);

		static float UPropertyToFloat(UObject* Object ,UProperty* Property);

		//Quicksort stuff
		static void QuickSort(TArray<UObject*>* Array, FName DesiredProperty, uint32 startIndex, uint32 endIndex);

};
