/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ***   To edit the content of this header, modify the corresponding
 ***   source file (e.g. under external/kernel-headers/original/) then
 ***   run bionic/libc/kernel/tools/update_all.py
 ***
 ***   Any manual change here will be lost the next time this script will
 ***   be run. You've been warned!
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef __SOUND_ASOUND_H
#define __SOUND_ASOUND_H
#include <linux/types.h>
#define SNDRV_PROTOCOL_VERSION(major,minor,subminor) (((major) << 16) | ((minor) << 8) | (subminor))
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PROTOCOL_MAJOR(version) (((version) >> 16) & 0xffff)
#define SNDRV_PROTOCOL_MINOR(version) (((version) >> 8) & 0xff)
#define SNDRV_PROTOCOL_MICRO(version) ((version) & 0xff)
#define SNDRV_PROTOCOL_INCOMPATIBLE(kversion,uversion) (SNDRV_PROTOCOL_MAJOR(kversion) != SNDRV_PROTOCOL_MAJOR(uversion) || (SNDRV_PROTOCOL_MAJOR(kversion) == SNDRV_PROTOCOL_MAJOR(uversion) && SNDRV_PROTOCOL_MINOR(kversion) != SNDRV_PROTOCOL_MINOR(uversion)))
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct snd_aes_iec958 {
  unsigned char status[24];
  unsigned char subcode[147];
  unsigned char pad;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned char dig_subframe[4];
};
struct snd_cea_861_aud_if {
  unsigned char db1_ct_cc;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned char db2_sf_ss;
  unsigned char db3;
  unsigned char db4_ca;
  unsigned char db5_dminh_lsv;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define SNDRV_HWDEP_VERSION SNDRV_PROTOCOL_VERSION(1, 0, 1)
enum {
  SNDRV_HWDEP_IFACE_OPL2 = 0,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SNDRV_HWDEP_IFACE_OPL3,
  SNDRV_HWDEP_IFACE_OPL4,
  SNDRV_HWDEP_IFACE_SB16CSP,
  SNDRV_HWDEP_IFACE_EMU10K1,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SNDRV_HWDEP_IFACE_YSS225,
  SNDRV_HWDEP_IFACE_ICS2115,
  SNDRV_HWDEP_IFACE_SSCAPE,
  SNDRV_HWDEP_IFACE_VX,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SNDRV_HWDEP_IFACE_MIXART,
  SNDRV_HWDEP_IFACE_USX2Y,
  SNDRV_HWDEP_IFACE_EMUX_WAVETABLE,
  SNDRV_HWDEP_IFACE_BLUETOOTH,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SNDRV_HWDEP_IFACE_USX2Y_PCM,
  SNDRV_HWDEP_IFACE_PCXHR,
  SNDRV_HWDEP_IFACE_SB_RC,
  SNDRV_HWDEP_IFACE_HDA,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SNDRV_HWDEP_IFACE_USB_STREAM,
  SNDRV_HWDEP_IFACE_FW_DICE,
  SNDRV_HWDEP_IFACE_FW_FIREWORKS,
  SNDRV_HWDEP_IFACE_FW_BEBOB,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SNDRV_HWDEP_IFACE_AUDIO_BE,
  SNDRV_HWDEP_IFACE_AUDIO_CODEC,
  SNDRV_HWDEP_IFACE_LAST = SNDRV_HWDEP_IFACE_AUDIO_CODEC
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct snd_hwdep_info {
  unsigned int device;
  int card;
  unsigned char id[64];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned char name[80];
  int iface;
  unsigned char reserved[64];
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct snd_hwdep_dsp_status {
  unsigned int version;
  unsigned char id[32];
  unsigned int num_dsps;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned int dsp_loaded;
  unsigned int chip_ready;
  unsigned char reserved[16];
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct snd_hwdep_dsp_image {
  unsigned int index;
  unsigned char name[64];
  unsigned char * image;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  size_t length;
  unsigned long driver_data;
};
#define SNDRV_HWDEP_IOCTL_PVERSION _IOR('H', 0x00, int)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_HWDEP_IOCTL_INFO _IOR('H', 0x01, struct snd_hwdep_info)
#define SNDRV_HWDEP_IOCTL_DSP_STATUS _IOR('H', 0x02, struct snd_hwdep_dsp_status)
#define SNDRV_HWDEP_IOCTL_DSP_LOAD _IOW('H', 0x03, struct snd_hwdep_dsp_image)
#define SNDRV_PCM_VERSION SNDRV_PROTOCOL_VERSION(2, 0, 12)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
typedef unsigned long snd_pcm_uframes_t;
typedef signed long snd_pcm_sframes_t;
enum {
  SNDRV_PCM_CLASS_GENERIC = 0,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SNDRV_PCM_CLASS_MULTI,
  SNDRV_PCM_CLASS_MODEM,
  SNDRV_PCM_CLASS_DIGITIZER,
  SNDRV_PCM_CLASS_LAST = SNDRV_PCM_CLASS_DIGITIZER,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum {
  SNDRV_PCM_SUBCLASS_GENERIC_MIX = 0,
  SNDRV_PCM_SUBCLASS_MULTI_MIX,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SNDRV_PCM_SUBCLASS_LAST = SNDRV_PCM_SUBCLASS_MULTI_MIX,
};
enum {
  SNDRV_PCM_STREAM_PLAYBACK = 0,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SNDRV_PCM_STREAM_CAPTURE,
  SNDRV_PCM_STREAM_LAST = SNDRV_PCM_STREAM_CAPTURE,
};
typedef int __bitwise snd_pcm_access_t;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_ACCESS_MMAP_INTERLEAVED ((snd_pcm_access_t) 0)
#define SNDRV_PCM_ACCESS_MMAP_NONINTERLEAVED ((snd_pcm_access_t) 1)
#define SNDRV_PCM_ACCESS_MMAP_COMPLEX ((snd_pcm_access_t) 2)
#define SNDRV_PCM_ACCESS_RW_INTERLEAVED ((snd_pcm_access_t) 3)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_ACCESS_RW_NONINTERLEAVED ((snd_pcm_access_t) 4)
#define SNDRV_PCM_ACCESS_LAST SNDRV_PCM_ACCESS_RW_NONINTERLEAVED
typedef int __bitwise snd_pcm_format_t;
#define SNDRV_PCM_FORMAT_S8 ((snd_pcm_format_t) 0)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_FORMAT_U8 ((snd_pcm_format_t) 1)
#define SNDRV_PCM_FORMAT_S16_LE ((snd_pcm_format_t) 2)
#define SNDRV_PCM_FORMAT_S16_BE ((snd_pcm_format_t) 3)
#define SNDRV_PCM_FORMAT_U16_LE ((snd_pcm_format_t) 4)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_FORMAT_U16_BE ((snd_pcm_format_t) 5)
#define SNDRV_PCM_FORMAT_S24_LE ((snd_pcm_format_t) 6)
#define SNDRV_PCM_FORMAT_S24_BE ((snd_pcm_format_t) 7)
#define SNDRV_PCM_FORMAT_U24_LE ((snd_pcm_format_t) 8)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_FORMAT_U24_BE ((snd_pcm_format_t) 9)
#define SNDRV_PCM_FORMAT_S32_LE ((snd_pcm_format_t) 10)
#define SNDRV_PCM_FORMAT_S32_BE ((snd_pcm_format_t) 11)
#define SNDRV_PCM_FORMAT_U32_LE ((snd_pcm_format_t) 12)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_FORMAT_U32_BE ((snd_pcm_format_t) 13)
#define SNDRV_PCM_FORMAT_FLOAT_LE ((snd_pcm_format_t) 14)
#define SNDRV_PCM_FORMAT_FLOAT_BE ((snd_pcm_format_t) 15)
#define SNDRV_PCM_FORMAT_FLOAT64_LE ((snd_pcm_format_t) 16)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_FORMAT_FLOAT64_BE ((snd_pcm_format_t) 17)
#define SNDRV_PCM_FORMAT_IEC958_SUBFRAME_LE ((snd_pcm_format_t) 18)
#define SNDRV_PCM_FORMAT_IEC958_SUBFRAME_BE ((snd_pcm_format_t) 19)
#define SNDRV_PCM_FORMAT_MU_LAW ((snd_pcm_format_t) 20)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_FORMAT_A_LAW ((snd_pcm_format_t) 21)
#define SNDRV_PCM_FORMAT_IMA_ADPCM ((snd_pcm_format_t) 22)
#define SNDRV_PCM_FORMAT_MPEG ((snd_pcm_format_t) 23)
#define SNDRV_PCM_FORMAT_GSM ((snd_pcm_format_t) 24)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_FORMAT_SPECIAL ((snd_pcm_format_t) 31)
#define SNDRV_PCM_FORMAT_S24_3LE ((snd_pcm_format_t) 32)
#define SNDRV_PCM_FORMAT_S24_3BE ((snd_pcm_format_t) 33)
#define SNDRV_PCM_FORMAT_U24_3LE ((snd_pcm_format_t) 34)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_FORMAT_U24_3BE ((snd_pcm_format_t) 35)
#define SNDRV_PCM_FORMAT_S20_3LE ((snd_pcm_format_t) 36)
#define SNDRV_PCM_FORMAT_S20_3BE ((snd_pcm_format_t) 37)
#define SNDRV_PCM_FORMAT_U20_3LE ((snd_pcm_format_t) 38)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_FORMAT_U20_3BE ((snd_pcm_format_t) 39)
#define SNDRV_PCM_FORMAT_S18_3LE ((snd_pcm_format_t) 40)
#define SNDRV_PCM_FORMAT_S18_3BE ((snd_pcm_format_t) 41)
#define SNDRV_PCM_FORMAT_U18_3LE ((snd_pcm_format_t) 42)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_FORMAT_U18_3BE ((snd_pcm_format_t) 43)
#define SNDRV_PCM_FORMAT_G723_24 ((snd_pcm_format_t) 44)
#define SNDRV_PCM_FORMAT_G723_24_1B ((snd_pcm_format_t) 45)
#define SNDRV_PCM_FORMAT_G723_40 ((snd_pcm_format_t) 46)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_FORMAT_G723_40_1B ((snd_pcm_format_t) 47)
#define SNDRV_PCM_FORMAT_DSD_U8 ((snd_pcm_format_t) 48)
#define SNDRV_PCM_FORMAT_DSD_U16_LE ((snd_pcm_format_t) 49)
#define SNDRV_PCM_FORMAT_DSD_U32_LE ((snd_pcm_format_t) 50)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_FORMAT_DSD_U16_BE ((snd_pcm_format_t) 51)
#define SNDRV_PCM_FORMAT_DSD_U32_BE ((snd_pcm_format_t) 52)
#define SNDRV_PCM_FORMAT_LAST SNDRV_PCM_FORMAT_DSD_U32_BE
#ifdef SNDRV_LITTLE_ENDIAN
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_FORMAT_S16 SNDRV_PCM_FORMAT_S16_LE
#define SNDRV_PCM_FORMAT_U16 SNDRV_PCM_FORMAT_U16_LE
#define SNDRV_PCM_FORMAT_S24 SNDRV_PCM_FORMAT_S24_LE
#define SNDRV_PCM_FORMAT_U24 SNDRV_PCM_FORMAT_U24_LE
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_FORMAT_S32 SNDRV_PCM_FORMAT_S32_LE
#define SNDRV_PCM_FORMAT_U32 SNDRV_PCM_FORMAT_U32_LE
#define SNDRV_PCM_FORMAT_FLOAT SNDRV_PCM_FORMAT_FLOAT_LE
#define SNDRV_PCM_FORMAT_FLOAT64 SNDRV_PCM_FORMAT_FLOAT64_LE
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_FORMAT_IEC958_SUBFRAME SNDRV_PCM_FORMAT_IEC958_SUBFRAME_LE
#endif
#ifdef SNDRV_BIG_ENDIAN
#define SNDRV_PCM_FORMAT_S16 SNDRV_PCM_FORMAT_S16_BE
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_FORMAT_U16 SNDRV_PCM_FORMAT_U16_BE
#define SNDRV_PCM_FORMAT_S24 SNDRV_PCM_FORMAT_S24_BE
#define SNDRV_PCM_FORMAT_U24 SNDRV_PCM_FORMAT_U24_BE
#define SNDRV_PCM_FORMAT_S32 SNDRV_PCM_FORMAT_S32_BE
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_FORMAT_U32 SNDRV_PCM_FORMAT_U32_BE
#define SNDRV_PCM_FORMAT_FLOAT SNDRV_PCM_FORMAT_FLOAT_BE
#define SNDRV_PCM_FORMAT_FLOAT64 SNDRV_PCM_FORMAT_FLOAT64_BE
#define SNDRV_PCM_FORMAT_IEC958_SUBFRAME SNDRV_PCM_FORMAT_IEC958_SUBFRAME_BE
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#endif
typedef int __bitwise snd_pcm_subformat_t;
#define SNDRV_PCM_SUBFORMAT_STD ((snd_pcm_subformat_t) 0)
#define SNDRV_PCM_SUBFORMAT_LAST SNDRV_PCM_SUBFORMAT_STD
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_INFO_MMAP 0x00000001
#define SNDRV_PCM_INFO_MMAP_VALID 0x00000002
#define SNDRV_PCM_INFO_DOUBLE 0x00000004
#define SNDRV_PCM_INFO_BATCH 0x00000010
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_INFO_INTERLEAVED 0x00000100
#define SNDRV_PCM_INFO_NONINTERLEAVED 0x00000200
#define SNDRV_PCM_INFO_COMPLEX 0x00000400
#define SNDRV_PCM_INFO_BLOCK_TRANSFER 0x00010000
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_INFO_OVERRANGE 0x00020000
#define SNDRV_PCM_INFO_RESUME 0x00040000
#define SNDRV_PCM_INFO_PAUSE 0x00080000
#define SNDRV_PCM_INFO_HALF_DUPLEX 0x00100000
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_INFO_JOINT_DUPLEX 0x00200000
#define SNDRV_PCM_INFO_SYNC_START 0x00400000
#define SNDRV_PCM_INFO_NO_PERIOD_WAKEUP 0x00800000
#define SNDRV_PCM_INFO_HAS_WALL_CLOCK 0x01000000
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_INFO_FIFO_IN_FRAMES 0x80000000
typedef int __bitwise snd_pcm_state_t;
#define SNDRV_PCM_STATE_OPEN ((snd_pcm_state_t) 0)
#define SNDRV_PCM_STATE_SETUP ((snd_pcm_state_t) 1)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_STATE_PREPARED ((snd_pcm_state_t) 2)
#define SNDRV_PCM_STATE_RUNNING ((snd_pcm_state_t) 3)
#define SNDRV_PCM_STATE_XRUN ((snd_pcm_state_t) 4)
#define SNDRV_PCM_STATE_DRAINING ((snd_pcm_state_t) 5)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_STATE_PAUSED ((snd_pcm_state_t) 6)
#define SNDRV_PCM_STATE_SUSPENDED ((snd_pcm_state_t) 7)
#define SNDRV_PCM_STATE_DISCONNECTED ((snd_pcm_state_t) 8)
#define SNDRV_PCM_STATE_LAST SNDRV_PCM_STATE_DISCONNECTED
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum {
  SNDRV_PCM_MMAP_OFFSET_DATA = 0x00000000,
  SNDRV_PCM_MMAP_OFFSET_STATUS = 0x80000000,
  SNDRV_PCM_MMAP_OFFSET_CONTROL = 0x81000000,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
union snd_pcm_sync_id {
  unsigned char id[16];
  unsigned short id16[8];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned int id32[4];
};
struct snd_pcm_info {
  unsigned int device;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned int subdevice;
  int stream;
  int card;
  unsigned char id[64];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned char name[80];
  unsigned char subname[32];
  int dev_class;
  int dev_subclass;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned int subdevices_count;
  unsigned int subdevices_avail;
  union snd_pcm_sync_id sync;
  unsigned char reserved[64];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
typedef int snd_pcm_hw_param_t;
#define SNDRV_PCM_HW_PARAM_ACCESS 0
#define SNDRV_PCM_HW_PARAM_FORMAT 1
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_HW_PARAM_SUBFORMAT 2
#define SNDRV_PCM_HW_PARAM_FIRST_MASK SNDRV_PCM_HW_PARAM_ACCESS
#define SNDRV_PCM_HW_PARAM_LAST_MASK SNDRV_PCM_HW_PARAM_SUBFORMAT
#define SNDRV_PCM_HW_PARAM_SAMPLE_BITS 8
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_HW_PARAM_FRAME_BITS 9
#define SNDRV_PCM_HW_PARAM_CHANNELS 10
#define SNDRV_PCM_HW_PARAM_RATE 11
#define SNDRV_PCM_HW_PARAM_PERIOD_TIME 12
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_HW_PARAM_PERIOD_SIZE 13
#define SNDRV_PCM_HW_PARAM_PERIOD_BYTES 14
#define SNDRV_PCM_HW_PARAM_PERIODS 15
#define SNDRV_PCM_HW_PARAM_BUFFER_TIME 16
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_HW_PARAM_BUFFER_SIZE 17
#define SNDRV_PCM_HW_PARAM_BUFFER_BYTES 18
#define SNDRV_PCM_HW_PARAM_TICK_TIME 19
#define SNDRV_PCM_HW_PARAM_FIRST_INTERVAL SNDRV_PCM_HW_PARAM_SAMPLE_BITS
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_HW_PARAM_LAST_INTERVAL SNDRV_PCM_HW_PARAM_TICK_TIME
#define SNDRV_PCM_HW_PARAMS_NORESAMPLE (1 << 0)
#define SNDRV_PCM_HW_PARAMS_EXPORT_BUFFER (1 << 1)
#define SNDRV_PCM_HW_PARAMS_NO_PERIOD_WAKEUP (1 << 2)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct snd_interval {
  unsigned int min, max;
  unsigned int openmin : 1, openmax : 1, integer : 1, empty : 1;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_MASK_MAX 256
struct snd_mask {
  __u32 bits[(SNDRV_MASK_MAX + 31) / 32];
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct snd_pcm_hw_params {
  unsigned int flags;
  struct snd_mask masks[SNDRV_PCM_HW_PARAM_LAST_MASK - SNDRV_PCM_HW_PARAM_FIRST_MASK + 1];
  struct snd_mask mres[5];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  struct snd_interval intervals[SNDRV_PCM_HW_PARAM_LAST_INTERVAL - SNDRV_PCM_HW_PARAM_FIRST_INTERVAL + 1];
  struct snd_interval ires[9];
  unsigned int rmask;
  unsigned int cmask;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned int info;
  unsigned int msbits;
  unsigned int rate_num;
  unsigned int rate_den;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  snd_pcm_uframes_t fifo_size;
  unsigned char reserved[64];
};
enum {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SNDRV_PCM_TSTAMP_NONE = 0,
  SNDRV_PCM_TSTAMP_ENABLE,
  SNDRV_PCM_TSTAMP_LAST = SNDRV_PCM_TSTAMP_ENABLE,
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct snd_pcm_sw_params {
  int tstamp_mode;
  unsigned int period_step;
  unsigned int sleep_min;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  snd_pcm_uframes_t avail_min;
  snd_pcm_uframes_t xfer_align;
  snd_pcm_uframes_t start_threshold;
  snd_pcm_uframes_t stop_threshold;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  snd_pcm_uframes_t silence_threshold;
  snd_pcm_uframes_t silence_size;
  snd_pcm_uframes_t boundary;
  unsigned int proto;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned int tstamp_type;
  unsigned char reserved[56];
};
struct snd_pcm_channel_info {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned int channel;
  __kernel_off_t offset;
  unsigned int first;
  unsigned int step;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct snd_pcm_status {
  snd_pcm_state_t state;
  struct timespec trigger_tstamp;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  struct timespec tstamp;
  snd_pcm_uframes_t appl_ptr;
  snd_pcm_uframes_t hw_ptr;
  snd_pcm_sframes_t delay;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  snd_pcm_uframes_t avail;
  snd_pcm_uframes_t avail_max;
  snd_pcm_uframes_t overrange;
  snd_pcm_state_t suspended_state;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 reserved_alignment;
  struct timespec audio_tstamp;
  unsigned char reserved[56 - sizeof(struct timespec)];
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct snd_pcm_mmap_status {
  snd_pcm_state_t state;
  int pad1;
  snd_pcm_uframes_t hw_ptr;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  struct timespec tstamp;
  snd_pcm_state_t suspended_state;
  struct timespec audio_tstamp;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct snd_pcm_mmap_control {
  snd_pcm_uframes_t appl_ptr;
  snd_pcm_uframes_t avail_min;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_SYNC_PTR_HWSYNC (1 << 0)
#define SNDRV_PCM_SYNC_PTR_APPL (1 << 1)
#define SNDRV_PCM_SYNC_PTR_AVAIL_MIN (1 << 2)
struct snd_pcm_sync_ptr {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned int flags;
  union {
    struct snd_pcm_mmap_status status;
    unsigned char reserved[64];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  } s;
  union {
    struct snd_pcm_mmap_control control;
    unsigned char reserved[64];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  } c;
};
struct snd_xferi {
  snd_pcm_sframes_t result;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  void * buf;
  snd_pcm_uframes_t frames;
};
struct snd_xfern {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  snd_pcm_sframes_t result;
  void * * bufs;
  snd_pcm_uframes_t frames;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum {
  SNDRV_PCM_TSTAMP_TYPE_GETTIMEOFDAY = 0,
  SNDRV_PCM_TSTAMP_TYPE_MONOTONIC,
  SNDRV_PCM_TSTAMP_TYPE_MONOTONIC_RAW,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SNDRV_PCM_TSTAMP_TYPE_LAST = SNDRV_PCM_TSTAMP_TYPE_MONOTONIC_RAW,
};
enum {
  SNDRV_CHMAP_UNKNOWN = 0,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SNDRV_CHMAP_NA,
  SNDRV_CHMAP_MONO,
  SNDRV_CHMAP_FL,
  SNDRV_CHMAP_FR,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SNDRV_CHMAP_RL,
  SNDRV_CHMAP_RR,
  SNDRV_CHMAP_FC,
  SNDRV_CHMAP_LFE,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SNDRV_CHMAP_SL,
  SNDRV_CHMAP_SR,
  SNDRV_CHMAP_RC,
  SNDRV_CHMAP_FLC,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SNDRV_CHMAP_FRC,
  SNDRV_CHMAP_RLC,
  SNDRV_CHMAP_RRC,
  SNDRV_CHMAP_FLW,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SNDRV_CHMAP_FRW,
  SNDRV_CHMAP_FLH,
  SNDRV_CHMAP_FCH,
  SNDRV_CHMAP_FRH,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SNDRV_CHMAP_TC,
  SNDRV_CHMAP_TFL,
  SNDRV_CHMAP_TFR,
  SNDRV_CHMAP_TFC,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SNDRV_CHMAP_TRL,
  SNDRV_CHMAP_TRR,
  SNDRV_CHMAP_TRC,
  SNDRV_CHMAP_TFLC,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SNDRV_CHMAP_TFRC,
  SNDRV_CHMAP_TSL,
  SNDRV_CHMAP_TSR,
  SNDRV_CHMAP_LLFE,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SNDRV_CHMAP_RLFE,
  SNDRV_CHMAP_BC,
  SNDRV_CHMAP_BLC,
  SNDRV_CHMAP_BRC,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SNDRV_CHMAP_LAST = SNDRV_CHMAP_BRC,
};
#define SNDRV_CHMAP_POSITION_MASK 0xffff
#define SNDRV_CHMAP_PHASE_INVERSE (0x01 << 16)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_CHMAP_DRIVER_SPEC (0x02 << 16)
#define SNDRV_PCM_IOCTL_PVERSION _IOR('A', 0x00, int)
#define SNDRV_PCM_IOCTL_INFO _IOR('A', 0x01, struct snd_pcm_info)
#define SNDRV_PCM_IOCTL_TSTAMP _IOW('A', 0x02, int)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_IOCTL_TTSTAMP _IOW('A', 0x03, int)
#define SNDRV_PCM_IOCTL_HW_REFINE _IOWR('A', 0x10, struct snd_pcm_hw_params)
#define SNDRV_PCM_IOCTL_HW_PARAMS _IOWR('A', 0x11, struct snd_pcm_hw_params)
#define SNDRV_PCM_IOCTL_HW_FREE _IO('A', 0x12)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_IOCTL_SW_PARAMS _IOWR('A', 0x13, struct snd_pcm_sw_params)
#define SNDRV_PCM_IOCTL_STATUS _IOR('A', 0x20, struct snd_pcm_status)
#define SNDRV_PCM_IOCTL_DELAY _IOR('A', 0x21, snd_pcm_sframes_t)
#define SNDRV_PCM_IOCTL_HWSYNC _IO('A', 0x22)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_IOCTL_SYNC_PTR _IOWR('A', 0x23, struct snd_pcm_sync_ptr)
#define SNDRV_PCM_IOCTL_CHANNEL_INFO _IOR('A', 0x32, struct snd_pcm_channel_info)
#define SNDRV_PCM_IOCTL_PREPARE _IO('A', 0x40)
#define SNDRV_PCM_IOCTL_RESET _IO('A', 0x41)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_IOCTL_START _IO('A', 0x42)
#define SNDRV_PCM_IOCTL_DROP _IO('A', 0x43)
#define SNDRV_PCM_IOCTL_DRAIN _IO('A', 0x44)
#define SNDRV_PCM_IOCTL_PAUSE _IOW('A', 0x45, int)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_IOCTL_REWIND _IOW('A', 0x46, snd_pcm_uframes_t)
#define SNDRV_PCM_IOCTL_RESUME _IO('A', 0x47)
#define SNDRV_PCM_IOCTL_XRUN _IO('A', 0x48)
#define SNDRV_PCM_IOCTL_FORWARD _IOW('A', 0x49, snd_pcm_uframes_t)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_IOCTL_WRITEI_FRAMES _IOW('A', 0x50, struct snd_xferi)
#define SNDRV_PCM_IOCTL_READI_FRAMES _IOR('A', 0x51, struct snd_xferi)
#define SNDRV_PCM_IOCTL_WRITEN_FRAMES _IOW('A', 0x52, struct snd_xfern)
#define SNDRV_PCM_IOCTL_READN_FRAMES _IOR('A', 0x53, struct snd_xfern)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_PCM_IOCTL_LINK _IOW('A', 0x60, int)
#define SNDRV_PCM_IOCTL_UNLINK _IO('A', 0x61)
#define SNDRV_RAWMIDI_VERSION SNDRV_PROTOCOL_VERSION(2, 0, 0)
enum {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SNDRV_RAWMIDI_STREAM_OUTPUT = 0,
  SNDRV_RAWMIDI_STREAM_INPUT,
  SNDRV_RAWMIDI_STREAM_LAST = SNDRV_RAWMIDI_STREAM_INPUT,
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_RAWMIDI_INFO_OUTPUT 0x00000001
#define SNDRV_RAWMIDI_INFO_INPUT 0x00000002
#define SNDRV_RAWMIDI_INFO_DUPLEX 0x00000004
struct snd_rawmidi_info {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned int device;
  unsigned int subdevice;
  int stream;
  int card;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned int flags;
  unsigned char id[64];
  unsigned char name[80];
  unsigned char subname[32];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned int subdevices_count;
  unsigned int subdevices_avail;
  unsigned char reserved[64];
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct snd_rawmidi_params {
  int stream;
  size_t buffer_size;
  size_t avail_min;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned int no_active_sensing : 1;
  unsigned char reserved[16];
};
struct snd_rawmidi_status {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  int stream;
  struct timespec tstamp;
  size_t avail;
  size_t xruns;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned char reserved[16];
};
#define SNDRV_RAWMIDI_IOCTL_PVERSION _IOR('W', 0x00, int)
#define SNDRV_RAWMIDI_IOCTL_INFO _IOR('W', 0x01, struct snd_rawmidi_info)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_RAWMIDI_IOCTL_PARAMS _IOWR('W', 0x10, struct snd_rawmidi_params)
#define SNDRV_RAWMIDI_IOCTL_STATUS _IOWR('W', 0x20, struct snd_rawmidi_status)
#define SNDRV_RAWMIDI_IOCTL_DROP _IOW('W', 0x30, int)
#define SNDRV_RAWMIDI_IOCTL_DRAIN _IOW('W', 0x31, int)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_TIMER_VERSION SNDRV_PROTOCOL_VERSION(2, 0, 6)
enum {
  SNDRV_TIMER_CLASS_NONE = - 1,
  SNDRV_TIMER_CLASS_SLAVE = 0,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SNDRV_TIMER_CLASS_GLOBAL,
  SNDRV_TIMER_CLASS_CARD,
  SNDRV_TIMER_CLASS_PCM,
  SNDRV_TIMER_CLASS_LAST = SNDRV_TIMER_CLASS_PCM,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum {
  SNDRV_TIMER_SCLASS_NONE = 0,
  SNDRV_TIMER_SCLASS_APPLICATION,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SNDRV_TIMER_SCLASS_SEQUENCER,
  SNDRV_TIMER_SCLASS_OSS_SEQUENCER,
  SNDRV_TIMER_SCLASS_LAST = SNDRV_TIMER_SCLASS_OSS_SEQUENCER,
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_TIMER_GLOBAL_SYSTEM 0
#define SNDRV_TIMER_GLOBAL_RTC 1
#define SNDRV_TIMER_GLOBAL_HPET 2
#define SNDRV_TIMER_GLOBAL_HRTIMER 3
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_TIMER_FLG_SLAVE (1 << 0)
struct snd_timer_id {
  int dev_class;
  int dev_sclass;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  int card;
  int device;
  int subdevice;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct snd_timer_ginfo {
  struct snd_timer_id tid;
  unsigned int flags;
  int card;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned char id[64];
  unsigned char name[80];
  unsigned long reserved0;
  unsigned long resolution;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned long resolution_min;
  unsigned long resolution_max;
  unsigned int clients;
  unsigned char reserved[32];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct snd_timer_gparams {
  struct snd_timer_id tid;
  unsigned long period_num;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned long period_den;
  unsigned char reserved[32];
};
struct snd_timer_gstatus {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  struct snd_timer_id tid;
  unsigned long resolution;
  unsigned long resolution_num;
  unsigned long resolution_den;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned char reserved[32];
};
struct snd_timer_select {
  struct snd_timer_id id;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned char reserved[32];
};
struct snd_timer_info {
  unsigned int flags;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  int card;
  unsigned char id[64];
  unsigned char name[80];
  unsigned long reserved0;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned long resolution;
  unsigned char reserved[64];
};
#define SNDRV_TIMER_PSFLG_AUTO (1 << 0)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_TIMER_PSFLG_EXCLUSIVE (1 << 1)
#define SNDRV_TIMER_PSFLG_EARLY_EVENT (1 << 2)
struct snd_timer_params {
  unsigned int flags;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned int ticks;
  unsigned int queue_size;
  unsigned int reserved0;
  unsigned int filter;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned char reserved[60];
};
struct snd_timer_status {
  struct timespec tstamp;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned int resolution;
  unsigned int lost;
  unsigned int overrun;
  unsigned int queue;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned char reserved[64];
};
#define SNDRV_TIMER_IOCTL_PVERSION _IOR('T', 0x00, int)
#define SNDRV_TIMER_IOCTL_NEXT_DEVICE _IOWR('T', 0x01, struct snd_timer_id)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_TIMER_IOCTL_TREAD _IOW('T', 0x02, int)
#define SNDRV_TIMER_IOCTL_GINFO _IOWR('T', 0x03, struct snd_timer_ginfo)
#define SNDRV_TIMER_IOCTL_GPARAMS _IOW('T', 0x04, struct snd_timer_gparams)
#define SNDRV_TIMER_IOCTL_GSTATUS _IOWR('T', 0x05, struct snd_timer_gstatus)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_TIMER_IOCTL_SELECT _IOW('T', 0x10, struct snd_timer_select)
#define SNDRV_TIMER_IOCTL_INFO _IOR('T', 0x11, struct snd_timer_info)
#define SNDRV_TIMER_IOCTL_PARAMS _IOW('T', 0x12, struct snd_timer_params)
#define SNDRV_TIMER_IOCTL_STATUS _IOR('T', 0x14, struct snd_timer_status)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_TIMER_IOCTL_START _IO('T', 0xa0)
#define SNDRV_TIMER_IOCTL_STOP _IO('T', 0xa1)
#define SNDRV_TIMER_IOCTL_CONTINUE _IO('T', 0xa2)
#define SNDRV_TIMER_IOCTL_PAUSE _IO('T', 0xa3)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct snd_timer_read {
  unsigned int resolution;
  unsigned int ticks;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum {
  SNDRV_TIMER_EVENT_RESOLUTION = 0,
  SNDRV_TIMER_EVENT_TICK,
  SNDRV_TIMER_EVENT_START,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SNDRV_TIMER_EVENT_STOP,
  SNDRV_TIMER_EVENT_CONTINUE,
  SNDRV_TIMER_EVENT_PAUSE,
  SNDRV_TIMER_EVENT_EARLY,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SNDRV_TIMER_EVENT_SUSPEND,
  SNDRV_TIMER_EVENT_RESUME,
  SNDRV_TIMER_EVENT_MSTART = SNDRV_TIMER_EVENT_START + 10,
  SNDRV_TIMER_EVENT_MSTOP = SNDRV_TIMER_EVENT_STOP + 10,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SNDRV_TIMER_EVENT_MCONTINUE = SNDRV_TIMER_EVENT_CONTINUE + 10,
  SNDRV_TIMER_EVENT_MPAUSE = SNDRV_TIMER_EVENT_PAUSE + 10,
  SNDRV_TIMER_EVENT_MSUSPEND = SNDRV_TIMER_EVENT_SUSPEND + 10,
  SNDRV_TIMER_EVENT_MRESUME = SNDRV_TIMER_EVENT_RESUME + 10,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct snd_timer_tread {
  int event;
  struct timespec tstamp;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned int val;
};
#define SNDRV_CTL_VERSION SNDRV_PROTOCOL_VERSION(2, 0, 7)
struct snd_ctl_card_info {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  int card;
  int pad;
  unsigned char id[16];
  unsigned char driver[16];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned char name[32];
  unsigned char longname[80];
  unsigned char reserved_[16];
  unsigned char mixername[80];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned char components[128];
};
typedef int __bitwise snd_ctl_elem_type_t;
#define SNDRV_CTL_ELEM_TYPE_NONE ((snd_ctl_elem_type_t) 0)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_CTL_ELEM_TYPE_BOOLEAN ((snd_ctl_elem_type_t) 1)
#define SNDRV_CTL_ELEM_TYPE_INTEGER ((snd_ctl_elem_type_t) 2)
#define SNDRV_CTL_ELEM_TYPE_ENUMERATED ((snd_ctl_elem_type_t) 3)
#define SNDRV_CTL_ELEM_TYPE_BYTES ((snd_ctl_elem_type_t) 4)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_CTL_ELEM_TYPE_IEC958 ((snd_ctl_elem_type_t) 5)
#define SNDRV_CTL_ELEM_TYPE_INTEGER64 ((snd_ctl_elem_type_t) 6)
#define SNDRV_CTL_ELEM_TYPE_LAST SNDRV_CTL_ELEM_TYPE_INTEGER64
typedef int __bitwise snd_ctl_elem_iface_t;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_CTL_ELEM_IFACE_CARD ((snd_ctl_elem_iface_t) 0)
#define SNDRV_CTL_ELEM_IFACE_HWDEP ((snd_ctl_elem_iface_t) 1)
#define SNDRV_CTL_ELEM_IFACE_MIXER ((snd_ctl_elem_iface_t) 2)
#define SNDRV_CTL_ELEM_IFACE_PCM ((snd_ctl_elem_iface_t) 3)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_CTL_ELEM_IFACE_RAWMIDI ((snd_ctl_elem_iface_t) 4)
#define SNDRV_CTL_ELEM_IFACE_TIMER ((snd_ctl_elem_iface_t) 5)
#define SNDRV_CTL_ELEM_IFACE_SEQUENCER ((snd_ctl_elem_iface_t) 6)
#define SNDRV_CTL_ELEM_IFACE_LAST SNDRV_CTL_ELEM_IFACE_SEQUENCER
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_CTL_ELEM_ACCESS_READ (1 << 0)
#define SNDRV_CTL_ELEM_ACCESS_WRITE (1 << 1)
#define SNDRV_CTL_ELEM_ACCESS_READWRITE (SNDRV_CTL_ELEM_ACCESS_READ | SNDRV_CTL_ELEM_ACCESS_WRITE)
#define SNDRV_CTL_ELEM_ACCESS_VOLATILE (1 << 2)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_CTL_ELEM_ACCESS_TIMESTAMP (1 << 3)
#define SNDRV_CTL_ELEM_ACCESS_TLV_READ (1 << 4)
#define SNDRV_CTL_ELEM_ACCESS_TLV_WRITE (1 << 5)
#define SNDRV_CTL_ELEM_ACCESS_TLV_READWRITE (SNDRV_CTL_ELEM_ACCESS_TLV_READ | SNDRV_CTL_ELEM_ACCESS_TLV_WRITE)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_CTL_ELEM_ACCESS_TLV_COMMAND (1 << 6)
#define SNDRV_CTL_ELEM_ACCESS_INACTIVE (1 << 8)
#define SNDRV_CTL_ELEM_ACCESS_LOCK (1 << 9)
#define SNDRV_CTL_ELEM_ACCESS_OWNER (1 << 10)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_CTL_ELEM_ACCESS_TLV_CALLBACK (1 << 28)
#define SNDRV_CTL_ELEM_ACCESS_USER (1 << 29)
#define SNDRV_CTL_POWER_D0 0x0000
#define SNDRV_CTL_POWER_D1 0x0100
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_CTL_POWER_D2 0x0200
#define SNDRV_CTL_POWER_D3 0x0300
#define SNDRV_CTL_POWER_D3hot (SNDRV_CTL_POWER_D3 | 0x0000)
#define SNDRV_CTL_POWER_D3cold (SNDRV_CTL_POWER_D3 | 0x0001)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_CTL_ELEM_ID_NAME_MAXLEN 44
struct snd_ctl_elem_id {
  unsigned int numid;
  snd_ctl_elem_iface_t iface;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned int device;
  unsigned int subdevice;
  unsigned char name[44];
  unsigned int index;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct snd_ctl_elem_list {
  unsigned int offset;
  unsigned int space;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned int used;
  unsigned int count;
  struct snd_ctl_elem_id * pids;
  unsigned char reserved[50];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct snd_ctl_elem_info {
  struct snd_ctl_elem_id id;
  snd_ctl_elem_type_t type;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned int access;
  unsigned int count;
  __kernel_pid_t owner;
  union {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
    struct {
      long min;
      long max;
      long step;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
    } integer;
    struct {
      long long min;
      long long max;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
      long long step;
    } integer64;
    struct {
      unsigned int items;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
      unsigned int item;
      char name[64];
      __u64 names_ptr;
      unsigned int names_length;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
    } enumerated;
    unsigned char reserved[128];
  } value;
  union {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
    unsigned short d[4];
    unsigned short * d_ptr;
  } dimen;
  unsigned char reserved[64 - 4 * sizeof(unsigned short)];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct snd_ctl_elem_value {
  struct snd_ctl_elem_id id;
  unsigned int indirect : 1;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  union {
    union {
      long value[128];
      long * value_ptr;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
    } integer;
    union {
      long long value[64];
      long long * value_ptr;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
    } integer64;
    union {
      unsigned int item[128];
      unsigned int * item_ptr;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
    } enumerated;
    union {
      unsigned char data[512];
      unsigned char * data_ptr;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
    } bytes;
    struct snd_aes_iec958 iec958;
  } value;
  struct timespec tstamp;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned char reserved[128 - sizeof(struct timespec)];
};
struct snd_ctl_tlv {
  unsigned int numid;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned int length;
  unsigned int tlv[0];
};
#define SNDRV_CTL_IOCTL_PVERSION _IOR('U', 0x00, int)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_CTL_IOCTL_CARD_INFO _IOR('U', 0x01, struct snd_ctl_card_info)
#define SNDRV_CTL_IOCTL_ELEM_LIST _IOWR('U', 0x10, struct snd_ctl_elem_list)
#define SNDRV_CTL_IOCTL_ELEM_INFO _IOWR('U', 0x11, struct snd_ctl_elem_info)
#define SNDRV_CTL_IOCTL_ELEM_READ _IOWR('U', 0x12, struct snd_ctl_elem_value)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_CTL_IOCTL_ELEM_WRITE _IOWR('U', 0x13, struct snd_ctl_elem_value)
#define SNDRV_CTL_IOCTL_ELEM_LOCK _IOW('U', 0x14, struct snd_ctl_elem_id)
#define SNDRV_CTL_IOCTL_ELEM_UNLOCK _IOW('U', 0x15, struct snd_ctl_elem_id)
#define SNDRV_CTL_IOCTL_SUBSCRIBE_EVENTS _IOWR('U', 0x16, int)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_CTL_IOCTL_ELEM_ADD _IOWR('U', 0x17, struct snd_ctl_elem_info)
#define SNDRV_CTL_IOCTL_ELEM_REPLACE _IOWR('U', 0x18, struct snd_ctl_elem_info)
#define SNDRV_CTL_IOCTL_ELEM_REMOVE _IOWR('U', 0x19, struct snd_ctl_elem_id)
#define SNDRV_CTL_IOCTL_TLV_READ _IOWR('U', 0x1a, struct snd_ctl_tlv)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_CTL_IOCTL_TLV_WRITE _IOWR('U', 0x1b, struct snd_ctl_tlv)
#define SNDRV_CTL_IOCTL_TLV_COMMAND _IOWR('U', 0x1c, struct snd_ctl_tlv)
#define SNDRV_CTL_IOCTL_HWDEP_NEXT_DEVICE _IOWR('U', 0x20, int)
#define SNDRV_CTL_IOCTL_HWDEP_INFO _IOR('U', 0x21, struct snd_hwdep_info)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_CTL_IOCTL_PCM_NEXT_DEVICE _IOR('U', 0x30, int)
#define SNDRV_CTL_IOCTL_PCM_INFO _IOWR('U', 0x31, struct snd_pcm_info)
#define SNDRV_CTL_IOCTL_PCM_PREFER_SUBDEVICE _IOW('U', 0x32, int)
#define SNDRV_CTL_IOCTL_RAWMIDI_NEXT_DEVICE _IOWR('U', 0x40, int)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_CTL_IOCTL_RAWMIDI_INFO _IOWR('U', 0x41, struct snd_rawmidi_info)
#define SNDRV_CTL_IOCTL_RAWMIDI_PREFER_SUBDEVICE _IOW('U', 0x42, int)
#define SNDRV_CTL_IOCTL_POWER _IOWR('U', 0xd0, int)
#define SNDRV_CTL_IOCTL_POWER_STATE _IOR('U', 0xd1, int)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum sndrv_ctl_event_type {
  SNDRV_CTL_EVENT_ELEM = 0,
  SNDRV_CTL_EVENT_LAST = SNDRV_CTL_EVENT_ELEM,
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_CTL_EVENT_MASK_VALUE (1 << 0)
#define SNDRV_CTL_EVENT_MASK_INFO (1 << 1)
#define SNDRV_CTL_EVENT_MASK_ADD (1 << 2)
#define SNDRV_CTL_EVENT_MASK_TLV (1 << 3)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_CTL_EVENT_MASK_REMOVE (~0U)
struct snd_ctl_event {
  int type;
  union {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
    struct {
      unsigned int mask;
      struct snd_ctl_elem_id id;
    } elem;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
    unsigned char data8[60];
  } data;
};
#define SNDRV_CTL_NAME_NONE ""
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_CTL_NAME_PLAYBACK "Playback "
#define SNDRV_CTL_NAME_CAPTURE "Capture "
#define SNDRV_CTL_NAME_IEC958_NONE ""
#define SNDRV_CTL_NAME_IEC958_SWITCH "Switch"
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_CTL_NAME_IEC958_VOLUME "Volume"
#define SNDRV_CTL_NAME_IEC958_DEFAULT "Default"
#define SNDRV_CTL_NAME_IEC958_MASK "Mask"
#define SNDRV_CTL_NAME_IEC958_CON_MASK "Con Mask"
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SNDRV_CTL_NAME_IEC958_PRO_MASK "Pro Mask"
#define SNDRV_CTL_NAME_IEC958_PCM_STREAM "PCM Stream"
#define SNDRV_CTL_NAME_IEC958(expl,direction,what) "IEC958 " expl SNDRV_CTL_NAME_ ##direction SNDRV_CTL_NAME_IEC958_ ##what
#endif
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */

