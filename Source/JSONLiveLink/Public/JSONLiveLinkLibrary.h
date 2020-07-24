
#pragma once

#include "CoreMinimal.h"
#include "ILiveLinkSource.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UObject/ObjectMacros.h"
#include "Interfaces/IPv4/IPv4Endpoint.h"

#include "JSONLiveLinkLibrary.generated.h"

UCLASS()
class JSONLIVELINK_API UJSONLiveLinkLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "Live Link")
	static void ConnectToJSONLiveLink(FLiveLinkSourceHandle &SourceHandle, const FString &InEndPoint = "0.0.0.0:54321");
};