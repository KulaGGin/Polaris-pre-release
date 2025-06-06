#pragma once
#include "CoreMinimal.h"
#include "Compilation/IMovieSceneTrackTemplateProducer.h"
#include "MovieSceneAkTrack.h"
#include "MovieSceneAkAudioRTPCTrack.generated.h"

UCLASS(MinimalAPI)
class UMovieSceneAkAudioRTPCTrack : public UMovieSceneAkTrack, public IMovieSceneTrackTemplateProducer {
    GENERATED_BODY()
public:
    UMovieSceneAkAudioRTPCTrack();


    // Fix for true pure virtual functions not being implemented
    virtual FMovieSceneEvalTemplatePtr CreateTemplateForSection(const UMovieSceneSection& InSection) const override;
};

