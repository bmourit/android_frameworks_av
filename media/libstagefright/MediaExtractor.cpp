/*
 * Copyright (C) 2009 The Android Open Source Project
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

//#define LOG_NDEBUG 0
#define LOG_TAG "MediaExtractor"
#include <utils/Log.h>
#include "include/ActAudioExtractor.h"
#include "include/ActVideoExtractor.h"
#include "include/AMRExtractor.h"
#include "include/MP3Extractor.h"
#include "include/MPEG4Extractor.h"
#include "include/WAVExtractor.h"
#include "include/OggExtractor.h"
#include "include/PCMExtractor.h"
#include "include/MPEG2PSExtractor.h"
#include "include/MPEG2TSExtractor.h"
#include "include/DRMExtractor.h"
#include "include/WVMExtractor.h"
#include "include/FLACExtractor.h"
#include "include/AACExtractor.h"
#include "include/ExtendedExtractor.h"

#ifdef ACT_AUDIO
#include "include/AwesomePlayer.h"
#include <media/stagefright/foundation/ADebug.h>
#endif

#include "matroska/MatroskaExtractor.h"

#include <media/stagefright/foundation/AMessage.h>
#include <media/stagefright/DataSource.h>
#include <media/stagefright/MediaDefs.h>
#include <media/stagefright/MediaExtractor.h>
#include <media/stagefright/MetaData.h>
#include <utils/String8.h>

#include "include/QCUtils.h"

namespace android {

sp<MetaData> MediaExtractor::getMetaData() {
    return new MetaData;
}

uint32_t MediaExtractor::flags() const {
    return CAN_SEEK_BACKWARD | CAN_SEEK_FORWARD | CAN_PAUSE | CAN_SEEK;
}

// static
sp<MediaExtractor> MediaExtractor::Create(
#ifdef ACT_AUDIO
        const sp<DataSource> &source, const char *mime, void* cookie) {
    // first check if can use android extractor
	sp<AMessage> meta;
	String8 tmp;
	bool usingMidwareFlag = false;
	MediaExtractor *ret = NULL;
	bool isDrm = false;

	int32_t isStreamFlag= 0;
	if (cookie!=NULL) {
		isStreamFlag = ((AwesomePlayer *)cookie)->getStreamingFlag();
	}
	if(mime!=NULL) {
	  ALOGE("cz**********************MediaExtractor creat=%s",mime);
	  if(!strcasecmp(mime, "NuMediaExtractor")) {
	    isStreamFlag = 1;
	    mime=NULL;
	  } 
	}
	char cts_value[PROPERTY_VALUE_MAX];
	int32_t isCTSFlag= 0;
	property_get("ro.build_mode", cts_value, "NORMAL");
	if(!strncmp(cts_value, "CTS",3)) {
	 isCTSFlag=1;
	} else {
	 isCTSFlag=0;   	    
	}
    ALOGE("cts_value=%s isCTSFlag=%d", cts_value,isCTSFlag);
	ALOGE("Create: firstly choose to use android extractor !!! isStreamFlag: %s", (isStreamFlag==true) ? "true" : "false");
    if (mime == NULL) {
        float confidence;
        if (!source->sniff(&tmp, &confidence, &meta)) {
            ALOGE("FAILED to autodetect media content.");
			#ifdef TURN_ON_MIDDLEWARE_FLAG
			goto middleware_extractor;
			#else
			return NULL;
			#endif
        }
        mime = tmp.string();
        ALOGI("Autodetected media content as '%s' with confidence %.2f",
             mime, confidence);
    }
    // bool isDrm = false;
#else
        const sp<DataSource> &source, const char *mime) {
    sp<AMessage> meta;

    String8 tmp;
    if (mime == NULL) {
        float confidence;
        if (!source->sniff(&tmp, &confidence, &meta)) {
            ALOGV("FAILED to autodetect media content.");

            return NULL;
        }

        mime = tmp.string();
        ALOGV("Autodetected media content as '%s' with confidence %.2f",
             mime, confidence);
    }

    bool isDrm = false;
#endif
    // DRM MIME type syntax is "drm+type+original" where
    // type is "es_based" or "container_based" and
    // original is the content's cleartext MIME type
    if (!strncmp(mime, "drm+", 4)) {
        const char *originalMime = strchr(mime+4, '+');
        if (originalMime == NULL) {
            // second + not found
            return NULL;
        }
        ++originalMime;
        if (!strncmp(mime, "drm+es_based+", 13)) {
            // DRMExtractor sets container metadata kKeyIsDRM to 1
            return new DRMExtractor(source, originalMime);
        } else if (!strncmp(mime, "drm+container_based+", 20)) {
            mime = originalMime;
            isDrm = true;
        } else {
            return NULL;
        }
    }

#ifdef ACT_AUDIO
	
	ALOGV("Create: use android extractor !!! mime: %s ", mime);
    if(isCTSFlag==0)
    {
    	if (!strcasecmp(mime, MEDIA_MIMETYPE_CONTAINER_OGG)) {//parser and decoder: both playback and streaming use android's 
    		//isStreamFlag = true;
    		if(isStreamFlag==1)
    		{
    		  ALOGD("use google ogg decoder");   
    		}
    		else
    		{
    		  ALOGD("use actions ogg decoder");      
    		}
    	}
      if (isStreamFlag == 0 || !strcasecmp(mime, MEDIA_MIMETYPE_CONTAINER_MPEG4) ){//parserand decoder: playback use middleware's and streaming use android's 
    			mime = NULL;
    			goto middleware_extractor;
    	}
	}
	else if(isCTSFlag==1)
	{
    	 if (!strcasecmp(mime, MEDIA_MIMETYPE_CONTAINER_OGG)) {//parser and decoder: both playback and streaming use android's     		
    		  ALOGD("use google ogg decoder"); 
    		  isStreamFlag=1;  	
    	}
    	if ((!strcasecmp(mime, MEDIA_MIMETYPE_AUDIO_MPEG)) || (!strcasecmp(mime, MEDIA_MIMETYPE_CONTAINER_MPEG4))) {//parser and decoder: both playback and streaming use android's 
        
        	 // then check if can use middleware extractor
          	off64_t filelen=0;
          	int rt = 0;
          	storage_io_t *storage_io = NULL;
          	const char mime_type[32] = "";   	
        	ALOGV("Create: then choose to use middleware parser mime: %s !!!", mime);
          
        	storage_io = create_storage_io();
        	if (storage_io == NULL)	{
        		return NULL;
        	}
        
        	filelen = init_storage_io(storage_io, source);
        	//if (filelen == 0) {
        	    //ALOGE("unsupport file, because filelen = 0 !!!");	    
        	    //dispose_storage_io(storage_io);
        	    //return NULL;	    
        		
        	//}else {
        		ALOGV("Create: fileLen: %lld", filelen);
        	//}
        	//CHECK(filelen>0);
        	rt = format_check(storage_io, mime_type);
        
        	if (mime_type[0] == '\0' || rt != 0) {
        		dispose_storage_io(storage_io);
        		ALOGE("no media content detected error !!!");
        		return NULL;
        	}
        	
        	dispose_storage_io(storage_io);
        	ALOGV("Create: format mime_type: %s", mime_type);
        	if ((mime_type[0] >= 'a') && (mime_type[0] <= 'z')) {/* video */
        		ALOGE("mp4 is video");
        		if(filelen==504541){
        			isStreamFlag=1;
        			ALOGD("using mp4 for subtitle cts \n");
        		}else{
        			isStreamFlag=0;	
        		}
        		
        	}else if ( (mime_type[0] >= 'A') && (mime_type[0] <= 'Z')) {   	    
        	     ALOGE("audio type: mp3 or mp4");	  
        		 ALOGD("use google mp4 decoder");
        		  isStreamFlag=1;           		  
        	}else {
        		ALOGE("Creat: find extractor meet error!!!");
        	}
    	
    		
    	}
    	
        if (isStreamFlag == 0) {//parserand decoder: playback use middleware's and streaming use android's 
    			mime = NULL;
    			goto middleware_extractor;
    	}
	
    }
    else
    {
      ALOGE("CTS flag erro!!!");         
     }
#else
    MediaExtractor *ret = NULL;
#endif
    if (!strcasecmp(mime, MEDIA_MIMETYPE_CONTAINER_MPEG4)
            || !strcasecmp(mime, "audio/mp4")) {
        ret = new MPEG4Extractor(source);
    } else if (!strcasecmp(mime, MEDIA_MIMETYPE_AUDIO_MPEG)) {
#ifdef ACT_AUDIO
    	ALOGD("use google mp3 decoder"); 
#endif
        ret = new MP3Extractor(source, meta);
    } else if (!strcasecmp(mime, MEDIA_MIMETYPE_AUDIO_AMR_NB)
            || !strcasecmp(mime, MEDIA_MIMETYPE_AUDIO_AMR_WB)) {
        ret = new AMRExtractor(source);
    } else if (!strcasecmp(mime, MEDIA_MIMETYPE_AUDIO_FLAC)) {
        ret = new FLACExtractor(source);
    } else if (!strcasecmp(mime, MEDIA_MIMETYPE_CONTAINER_WAV)) {
        ret = new WAVExtractor(source);
    } else if (!strcasecmp(mime, MEDIA_MIMETYPE_CONTAINER_OGG)) {
        ret = new OggExtractor(source);
    } else if (!strcasecmp(mime, MEDIA_MIMETYPE_CONTAINER_MATROSKA)) {
        ret = new MatroskaExtractor(source);
    } else if (!strcasecmp(mime, MEDIA_MIMETYPE_CONTAINER_MPEG2TS)) {
        ret = new MPEG2TSExtractor(source);
    } else if (!strcasecmp(mime, MEDIA_MIMETYPE_CONTAINER_WVM)) {
        // Return now.  WVExtractor should not have the DrmFlag set in the block below.
        return new WVMExtractor(source);
    } else if (!strcasecmp(mime, MEDIA_MIMETYPE_AUDIO_AAC_ADTS)) {
        ret = new AACExtractor(source, meta);
    } else if (!strcasecmp(mime, MEDIA_MIMETYPE_CONTAINER_MPEG2PS)) {
        ret = new MPEG2PSExtractor(source);
#ifdef STE_FM
    } else if (!strcasecmp(mime, MEDIA_MIMETYPE_AUDIO_RAW)) {
        ret = new PCMExtractor(source);
#endif
    }

    if (ret != NULL) {
#ifdef ACT_AUDIO
	ret->setUsingMidwwareFlag(false);
#endif
       if (isDrm) {
           ret->setDrmFlag(true);
       } else {
           ret->setDrmFlag(false);
       }
#ifdef ACT_AUDIO
      return ret;
    }

middleware_extractor:
	
	// then check if can use middleware extractor
  	off64_t filelen=0;
  	int rt = 0;
  	storage_io_t *storage_io = NULL;
  	const char mime_type[32] = "";   	
	ALOGV("Create: then choose to use middleware parser mime: %s !!!", mime);
  	if (mime != NULL) {
		ALOGE("Create: fail to load %s", mime);
		return NULL;
	}

	storage_io = create_storage_io();
	if (storage_io == NULL)	{
		return NULL;
	}

	filelen = init_storage_io(storage_io, source);
	//if (filelen == 0) {
	    //ALOGE("unsupport file, because filelen = 0 !!!");	    
	    //dispose_storage_io(storage_io);
	    //return NULL;	    
		
	//}else {
		ALOGV("Create: fileLen: %lld", filelen);
	//}
	//CHECK(filelen>0);
	rt = format_check(storage_io, mime_type);

	if (mime_type[0] == '\0' || rt != 0) {
		dispose_storage_io(storage_io);
		ALOGE("no media content detected error !!!");
		return NULL;
	}
	
	dispose_storage_io(storage_io);
	ALOGV("Create: format mime_type: %s", mime_type);
	if ((mime_type[0] >= 'a') && (mime_type[0] <= 'z')) {/* video */
		ALOGV("Create()->new ActVideoExtractor!!!");
		ret = new ActVideoExtractor(source, mime_type, cookie);
	}else if ( (mime_type[0] >= 'A') && (mime_type[0] <= 'Z')) {
		ret = new ActAudioExtractor(source, mime_type);
	}else {
		ALOGE("Creat: find extractor meet error!!!");
		ret = NULL;
	}
	
	if (ret != NULL) {
		isDrm ? ret->setDrmFlag(true) : ret->setDrmFlag(false);
		ret->setUsingMidwwareFlag(true);
		return ret;
	}
    return NULL;
#else
    }
#endif
    return QCUtils::MediaExtractor_CreateIfNeeded(ret, source, mime);
}

}  // namespace android
