#pragma once

#include "CoreMinimal.h"
#include "WeatherDataStruct.generated.h"

/* human readable weather condition */
UENUM(BlueprintType)
enum class EWeatherCondition : uint8
{
	W_Min UMETA(Hidden),
	W_Clear UMETA(DisplayName = "Clear"),
	W_PartlyCloudy UMETA(DisplayName = "Partially Cloudy"),
	W_Overcast UMETA(DisplayName = "Overcast Cloud"),
	W_ThunderStorm UMETA(DisplayName = "Thunder Storm"),
	W_Raining UMETA(DisplayName = "Raining"),
	W_Hail UMETA(DisplayName = "Hail"),
	W_Snowing UMETA(DisplayName = "Snowing"),
	W_Max  UMETA(Hidden)
};

/** Single	Point based weather conditions
 * 
 */
USTRUCT(Blueprintable, BlueprintType)
struct FWeatherDataStruct
{
	 GENERATED_USTRUCT_BODY()
 

	/* Normalized global wind direction */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "WeatherDataPlugin")
	FVector WindDirection;

	/* Wind speed in km/h, (Multiply by 27.7778f  to convert to UE4 cm/s) */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "WeatherDataPlugin")
	float WindSpeed;

	/* Max wind gust speed in Km/h  */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "WeatherDataPlugin")
	float WindGustSpeed;


	/* Normalized global Sun Direction. If Z is less that 0 then sun is bellow horizon */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "WeatherDataPlugin")
	FVector SunDirection;

	/* Air humidity as a percentage, from 0 - 100% */
	UPROPERTY(BlueprintReadWrite, EditAnywhere,meta = (ClampMin = 0, ClampMax = 100, UIMin = 0, UIMax = 100), Category = "WeatherDataPlugin")
	int32 Humidity;

	/*  Air Temperature in celsius at Sealevel */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ClampMin = -100, ClampMax = 150, UIMin = -100, UIMax = 150), Category = "WeatherDataPlugin")
	float SeaLevelTemperature;

	/* Temp at which air can become water saturated, if air temp is at this point and comes in contact with a cooler surface then condensation/dew will form*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ClampMin = -100, ClampMax = 150, UIMin = -100, UIMax = 150), Category = "WeatherDataPlugin")
	float DewPoint;


	/* Rate of Precipitation (rain/snow fall rate) in 0-100 . Probably need a manual override control for it */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ClampMin = 0, ClampMax = 100, UIMin = 0, UIMax = 100), Category = "WeatherDataPlugin")
	float PrecipitationRate;

	/* Air pressure in hpa, Placeholder incase we need it  */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ClampMin = 0, ClampMax = 2000, UIMin = 0, UIMax = 2000), Category = "WeatherDataPlugin")
	float AirPressure;

	/* View distance in KM, relates to air clarity   */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ClampMin = 0, ClampMax = 200, UIMin = 0, UIMax = 200), Category = "WeatherDataPlugin")
	float VisibilityDistance;


	// Fully initialized constructor
	FWeatherDataStruct()
	{
		WindDirection = FVector::ZeroVector;
		WindSpeed = 0.f;
		WindGustSpeed = 0.f;
		SunDirection = FVector::ZeroVector;
		Humidity = 0;
		SeaLevelTemperature = 19.f;
		DewPoint = 9.f;
		PrecipitationRate = 0.f;
		AirPressure = 1000.f;
		VisibilityDistance = 20.f;
	}
};
