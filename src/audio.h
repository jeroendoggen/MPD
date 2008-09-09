/* the Music Player Daemon (MPD)
 * Copyright (C) 2003-2007 by Warren Dukes (warren.dukes@gmail.com)
 * This project's homepage is: http://www.musicpd.org
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef AUDIO_H
#define AUDIO_H

#include "os_compat.h"

#define AUDIO_AO_DRIVER_DEFAULT	"default"

struct audio_format;
struct tag;
struct client;

void getOutputAudioFormat(const struct audio_format *inFormat,
			  struct audio_format *outFormat);

int parseAudioConfig(struct audio_format *audioFormat, char *conf);

/* make sure initPlayerData is called before this function!! */
void initAudioConfig(void);

void finishAudioConfig(void);

void initAudioDriver(void);

void finishAudioDriver(void);

int openAudioDevice(const struct audio_format *audioFormat);

int playAudio(const char *playChunk, size_t size);

void dropBufferedAudio(void);

void closeAudioDevice(void);

int isAudioDeviceOpen(void);

int isCurrentAudioFormat(const struct audio_format *audioFormat);

void sendMetadataToAudioDevice(const struct tag *tag);

/* these functions are called in the main parent process while the child
	process is busy playing to the audio */
int enableAudioDevice(unsigned int device);

int disableAudioDevice(unsigned int device);

void printAudioDevices(struct client *client);

void readAudioDevicesState(FILE *fp);

void saveAudioDevicesState(FILE *fp);

#endif
