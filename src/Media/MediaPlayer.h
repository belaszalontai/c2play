/*
*
* Copyright (C) 2016 OtherCrashOverride@users.noreply.github.com.
* All rights reserved.
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 2, as
* published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
* more details.
*
*/

#pragma once

#include "MediaSourceElement.h"
#include "AlsaAudioSink.h"
#include "AmlVideoSink.h"
#include "AudioCodec.h"
#include "SubtitleCodecElement.h"
//#include "Egl.h"
#include "Compositor.h"

#include <string>



class MediaPlayer
{
	std::string url;
	std::string avOptions;
	MediaSourceElementSPTR source;
	AmlVideoSinkElementSPTR videoSink;
	AudioCodecElementSPTR audioCodec;
	AlsaAudioSinkElementSPTR audioSink;
	SubtitleDecoderElementSPTR subtitleCodec;
	SubtitleRenderElementSPTR subtitleRender;

	MediaState state = MediaState::Pause;
	//EGLDisplay eglDisplay = nullptr;
	//EGLSurface surface = nullptr;
	//EGLContext context = nullptr;
	CompositorSPTR compositor;

	OutPinSPTR sourceVideoPin;
	OutPinSPTR sourceAudioPin;
	OutPinSPTR sourceSubtitlePin;
	

public:

	double Position() const;
	
	double Duration() const;

	MediaState GetState() const;
	void SetState(MediaState value);

	bool IsEndOfStream();

	const ChapterListSPTR Chapters() const;

	MediaPlayer(std::string url, std::string avOptions, CompositorSPTR compositor, int videoStream, int audioStream, int subtitleStream);
	~MediaPlayer();

	void Seek(double timeStamp);
};

typedef std::shared_ptr<MediaPlayer> MediaPlayerSPTR;
