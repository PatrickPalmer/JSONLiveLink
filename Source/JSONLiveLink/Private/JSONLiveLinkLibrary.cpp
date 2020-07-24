
#include "JSONLiveLinkLibrary.h"

#include "Features/IModularFeatures.h"
#include "ILiveLinkClient.h"
#include "Interfaces/IPv4/IPv4Endpoint.h"
#include "JSONLiveLinkSource.h"

void UJSONLiveLinkLibrary::ConnectToJSONLiveLink(FLiveLinkSourceHandle& SourceHandle, const FString& InEndPoint)
{
	FIPv4Endpoint DeviceEndPoint;

	if (!FIPv4Endpoint::Parse(InEndPoint, DeviceEndPoint))
	{
		DeviceEndPoint.Address = FIPv4Address::Any;
		DeviceEndPoint.Port = 54321;
	}

	IModularFeatures& ModularFeatures = IModularFeatures::Get();

	if (ModularFeatures.IsModularFeatureAvailable(ILiveLinkClient::ModularFeatureName))
	{
		ILiveLinkClient* LiveLinkClient = &ModularFeatures.GetModularFeature<ILiveLinkClient>(ILiveLinkClient::ModularFeatureName);

		TSharedPtr<ILiveLinkSource> NewSource = MakeShared<FJSONLiveLinkSource>(DeviceEndPoint);
		LiveLinkClient->AddSource(NewSource);
		SourceHandle.SetSourcePointer(NewSource);
	}
	else
	{
		SourceHandle.SetSourcePointer(nullptr);
	}
}
