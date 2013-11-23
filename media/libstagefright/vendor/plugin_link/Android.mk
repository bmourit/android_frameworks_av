LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

ifeq (true, false)
LOCAL_SRC_FILES:=               \
    link_decoder.c
    
LOCAL_MODULE:= link_decoder
include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SRC_FILES:=               \
    link_parser.c

LOCAL_MODULE:= link_parser
include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SRC_FILES:=               \
    link_encoder.c

LOCAL_MODULE:= link_encoder
include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SRC_FILES:=               \
    link_video_decoder.c

LOCAL_MODULE:= link_video_decoder
include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SRC_FILES:=               \
    link_video_parser.c

LOCAL_MODULE:= link_video_parser
include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)
define build-static-lib
	$(shell echo $(TARGET_OUT_INTERMEDIATES)/STATIC_LIBRARIES/$(1)_intermediates/$(1))
endef
define build-static-lib-dir
	$(shell mkdir -p $(TARGET_OUT_INTERMEDIATES)/STATIC_LIBRARIES/$(1)_intermediates/;echo  $(TARGET_OUT_INTERMEDIATES)/STATIC_LIBRARIES/$(1)_intermediates/)
endef
define find-obj-subdir
	$(shell echo $(TARGET_OUT_INTERMEDIATES)/STATIC_LIBRARIES/$(1)_intermediates/*.o)
endef
MY_LDFLAGS=-EL -r

MY_SRC= $(call find-obj-subdir,link_decoder) 
$(shell $(TARGET_LD) $(MY_SRC) $(MY_LDFLAGS) -o $(LOCAL_PATH)/liblink_decoder.a)
MY_SRC= $(call find-obj-subdir,link_parser) 
$(shell $(TARGET_LD) $(MY_SRC) $(MY_LDFLAGS) -o $(LOCAL_PATH)/liblink_parser.a)
MY_SRC= $(call find-obj-subdir,link_encoder) 
$(shell $(TARGET_LD) $(MY_SRC) $(MY_LDFLAGS) -o $(LOCAL_PATH)/liblink_encoder.a)
MY_SRC= $(call find-obj-subdir,link_video_decoder) 
$(shell $(TARGET_LD) $(MY_SRC) $(MY_LDFLAGS) -o $(LOCAL_PATH)/liblink_video_decoder.a)
MY_SRC= $(call find-obj-subdir,link_video_parser) 
$(shell $(TARGET_LD) $(MY_SRC) $(MY_LDFLAGS) -o $(LOCAL_PATH)/liblink_video_parser.a)
endif

LOCAL_PREBUILT_LIBS := liblink_decoder.a liblink_parser.a liblink_video_decoder.a liblink_video_parser.a liblink_encoder.a
LOCAL_MODULE_TAGS := eng
include $(BUILD_MULTI_PREBUILT)
