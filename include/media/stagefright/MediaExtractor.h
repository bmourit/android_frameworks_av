/*
 * Copyright (C) 2009 The Android Open Source Project
 * Copyright (c) 2012, The Linux Foundation. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MEDIA_EXTRACTOR_H_

#define MEDIA_EXTRACTOR_H_

#include <utils/RefBase.h>
#include <utils/Errors.h>

namespace android {

class DataSource;
class MediaSource;
class MetaData;

class MediaExtractor : public RefBase {
public:
    static sp<MediaExtractor> Create(
            const sp<DataSource> &source, const char *mime = NULL,void* cookie=NULL);

    virtual size_t countTracks() = 0;
    virtual sp<MediaSource> getTrack(size_t index) = 0;

    enum GetTrackMetaDataFlags {
        kIncludeExtensiveMetaData = 1
    };
    virtual sp<MetaData> getTrackMetaData(
            size_t index, uint32_t flags = 0) = 0;

    // Return container specific meta-data. The default implementation
    // returns an empty metadata object.
    virtual sp<MetaData> getMetaData();
    virtual status_t setAudioTrack(int index, int64_t cur_playing_time) { return NO_ERROR; }

    enum Flags {
        CAN_SEEK_BACKWARD  = 1,  // the "seek 10secs back button"
        CAN_SEEK_FORWARD   = 2,  // the "seek 10secs forward button"
        CAN_PAUSE          = 4,
        CAN_SEEK           = 8,  // the "seek bar"
        CAN_SEEK_TO_ZERO   = 16, // the "previous button"
    };

    // If subclasses do _not_ override this, the default is
    // CAN_SEEK_BACKWARD | CAN_SEEK_FORWARD | CAN_SEEK | CAN_PAUSE
    virtual uint32_t flags() const;

    // for DRM
    void setDrmFlag(bool flag) {
        mIsDrm = flag;
    };
    bool getDrmFlag() {
        return mIsDrm;
    }

#ifdef ACT_AUDIO
    virtual void setUsingMidwwareFlag(bool usingMidwareFlag) {
        mIsMidware = usingMidwareFlag;
    };
    virtual bool getUsingMidwwareFlag() {
        return mIsMidware;
    }
#endif

    virtual char* getDrmTrackInfo(size_t trackID, int *len) {
        return NULL;
    }

protected:
    MediaExtractor() : mIsDrm(false) {}
    virtual ~MediaExtractor() {}

private:
    bool mIsDrm;

#ifdef ACT_AUDIO
    bool mIsMidware;
#endif

    MediaExtractor(const MediaExtractor &);
    MediaExtractor &operator=(const MediaExtractor &);
};

}  // namespace android

#endif  // MEDIA_EXTRACTOR_H_
