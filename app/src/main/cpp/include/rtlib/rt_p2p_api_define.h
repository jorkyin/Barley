
#ifndef __RT_P2P_API_DEFINE_H__
#define __RT_P2P_API_DEFINE_H__
#include <time.h>
#include "rt_p2p_types.h"


//Message type
#define MSG_TYPE_P2P_STATUS         0x0
#define MSG_TYPE_P2P_MODE           0x1
#define MSG_TYPE_GET_CAMERA_PARAMS  0x2
#define MSG_TYPE_DECODER_CONTROL    0x3
#define MSG_TYPE_GET_PARAMS         0x4
#define MSG_TYPE_SNAPSHOT           0x5
#define MSG_TYPE_CAMERA_CONTROL     0x6
#define MSG_TYPE_SET_NETWORK        0x7
#define MSG_TYPE_REBOOT_DEVICE      0x8
#define MSG_TYPE_RESTORE_FACTORY    0x9
#define MSG_TYPE_SET_USER           0xa
#define MSG_TYPE_SET_WIFI           0xb
#define MSG_TYPE_SET_DATETIME       0xc
#define MSG_TYPE_GET_STATUS         0xd
#define MSG_TYPE_GET_PTZ_PARAMS     0xe
#define MSG_TYPE_SET_DDNS           0xf
#define MSG_TYPE_SET_MAIL           0x10
#define MSG_TYPE_SET_FTP            0x11
#define MSG_TYPE_SET_ALARM          0x12
#define MSG_TYPE_SET_PTZ            0x13
#define MSG_TYPE_WIFI_SCAN          0x14
#define MSG_TYPE_GET_ALARM_LOG      0x15
#define MSG_TYPE_GET_RECORD         0x16
#define MSG_TYPE_GET_RECORD_FILE    0x17
#define MSG_TYPE_SET_PPPOE          0x18
#define MSG_TYPE_SET_UPNP           0x19
#define MSG_TYPE_DEL_RECORD_FILE    0x1a
#define MSG_TYPE_SET_MEDIA          0x1b
#define MSG_TYPE_SET_RECORD_SCH     0x1c
#define MSG_TYPE_CLEAR_ALARM_LOG    0x1d
#define MSG_TYPE_WIFI_PARAMS        0x1f
#define MSG_TYPE_MAIL_PARAMS        0x20
#define MSG_TYPE_FTP_PARAMS         0x21
#define MSG_TYPE_NETWORK_PARAMS     0x22
#define MSG_TYPE_USER_INFO          0x23
#define MSG_TYPE_DDNS_PARAMS        0x24
#define MSG_TYPE_DATETIME_PARAMS    0x25
#define MSG_TYPE_ALARM_PARAMS       0x26
#define MSG_TYPE_SET_DEVNAME        0x27
#define MSG_TYPE_GET_BILL        	0x32
#define MSG_TYPE_SET_BILL        	0x33
#define MSG_TYPE_SET_AP 			0x34
#define MSG_TYPE_GET_AP 			0x35
#define MSG_TYPE_GET_NEW_RECORD_FILE 0x40

#define MSG_TYPE_GET_NETWORK 	    0x41
#define MSG_TYPE_GET_USER_INFO 	    0x42
#define MSG_TYPE_GET_WIFI 	        0x43
#define MSG_TYPE_GET_FTP 	        0x44
#define MSG_TYPE_GET_EMAIL 	        0x45
#define MSG_TYPE_GET_DDNS 	        0x46
#define MSG_TYPE_GET_TIME 	        0x47
#define MSG_TYPE_GET_ALARM_PARAM 	0x48
#define MSG_TYPE_FORMAT_SD 	        0x49
#define MSG_TYPE_GET_P2P_CAPABILITY 0x4a
#define MSG_TYPE_GET_DOWNLOAD_FILE  0x4b
#define MSG_TYPE_GET_SNAP_UPLOAD_FTP  0x4c

#define MSG_TYPE_SET_REC_MODE  		0x50
#define MSG_TYPE_GET_REC_MODE  		0x51
#define MSG_TYPE_SET_MOBILE_TIME  	0x52
#define MSG_TYPE_GET_REC_CALENDAR   0x53

#define MSG_TYPE_UNMOUNT_SD         0x54
#define MSG_TYPE_GET_ALARM_EX       0x55
#define MSG_TYPE_SET_ALARM_EX       0x56
#define MSG_TYPE_GET_SD_REC_EX      0x57
#define MSG_TYPE_SET_SD_REC_EX      0x58
#define MSG_TYPE_FACTORY_RESET      0x59
#define MSG_TYPE_GET_OSD            0x5a
#define MSG_TYPE_SET_OSD            0x5b
#define MSG_TYPE_SET_GEOG           0x5c /*������ͼ���þ�γ����Ϣ*/



//decoder control command
#define CMD_PTZ_UP                      0
#define CMD_PTZ_UP_STOP                 1
#define CMD_PTZ_DOWN                    2
#define CMD_PTZ_DOWN_STOP               3
#define CMD_PTZ_LEFT                    4
#define CMD_PTZ_LEFT_STOP               5
#define CMD_PTZ_RIGHT                   6
#define CMD_PTZ_RIGHT_STOP             	7

#define CMD_PTZ_CENTER                  25
#define CMD_PTZ_UP_DOWN                 26
#define CMD_PTZ_UP_DOWN_STOP            27
#define CMD_PTZ_LEFT_RIGHT              28
#define CMD_PTZ_LEFT_RIGHT_STOP         29


#define CMD_PTZ_PREFAB_BIT_SET0         30
#define CMD_PTZ_PREFAB_BIT_SET1         32
#define CMD_PTZ_PREFAB_BIT_SET2         34
#define CMD_PTZ_PREFAB_BIT_SET3         36
#define CMD_PTZ_PREFAB_BIT_SET4         38
#define CMD_PTZ_PREFAB_BIT_SET5         40
#define CMD_PTZ_PREFAB_BIT_SET6         42
#define CMD_PTZ_PREFAB_BIT_SET7         44
#define CMD_PTZ_PREFAB_BIT_SET8         46
#define CMD_PTZ_PREFAB_BIT_SET9         48
#define CMD_PTZ_PREFAB_BIT_SETA         50
#define CMD_PTZ_PREFAB_BIT_SETB         52
#define CMD_PTZ_PREFAB_BIT_SETC         54
#define CMD_PTZ_PREFAB_BIT_SETD         56
#define CMD_PTZ_PREFAB_BIT_SETE         58
#define CMD_PTZ_PREFAB_BIT_SETF         60
#define CMD_PTZ_PREFAB_BIT_SET_EXT      70 //����Ԥ����չ,���û��Լ���������ֵ


#define CMD_PTZ_PREFAB_BIT_RUN0         31
#define CMD_PTZ_PREFAB_BIT_RUN1         33
#define CMD_PTZ_PREFAB_BIT_RUN2         35
#define CMD_PTZ_PREFAB_BIT_RUN3         37
#define CMD_PTZ_PREFAB_BIT_RUN4         39
#define CMD_PTZ_PREFAB_BIT_RUN5         41
#define CMD_PTZ_PREFAB_BIT_RUN6         43
#define CMD_PTZ_PREFAB_BIT_RUN7         45
#define CMD_PTZ_PREFAB_BIT_RUN8         47
#define CMD_PTZ_PREFAB_BIT_RUN9         49
#define CMD_PTZ_PREFAB_BIT_RUNA         51
#define CMD_PTZ_PREFAB_BIT_RUNB         53
#define CMD_PTZ_PREFAB_BIT_RUNC         55
#define CMD_PTZ_PREFAB_BIT_RUND         57
#define CMD_PTZ_PREFAB_BIT_RUNE         59
#define CMD_PTZ_PREFAB_BIT_RUNF         61
#define CMD_PTZ_PREFAB_BIT_RUN_EXT      80 //����Ԥ����չ,���û��Լ��������ֵ


#define CMD_PTZ_ZOOM_IN   99
#define CMD_PTZ_ZOOM_OUT  100
#define CMD_PTZ_FOCUS_IN  101
#define CMD_PTZ_FOCUS_OUT 102

/*msgtype*/
#define MSG_NOTIFY_TYPE_PPPP_STATUS (0)   /* pppp status */
#define MSG_NOTIFY_TYPE_PPPP_MODE   (1)   /* device type */
#define MSG_NOTIFY_TYPE_STREAM_TYPE (2)
#define MSG_NOTIFY_TYPE_TALK_STATUS (3)

/*pppp status*/
#define PPPP_STATUS_CONNECTING         (0) /* connecting */
#define PPPP_STATUS_INITIALING         (1) /* initialing */
#define PPPP_STATUS_ON_LINE            (2) /* on line */
#define PPPP_STATUS_CONNECT_FAILED     (3) /* connect failed */
#define PPPP_STATUS_DISCONNECT         (4) /*connect is off*/
#define PPPP_STATUS_INVALID_ID         (5) /* invalid id */
#define PPPP_STATUS_DEVICE_NOT_ON_LINE (6)
#define PPPP_STATUS_CONNECT_TIMEOUT    (7) /* connect timeout */
#define PPPP_STATUS_INVALID_USER_PWD   (8) /* user or pwd is invalid */

/*pppp mode*/
#define PPPP_MODE_P2P   (1)
#define PPPP_MODE_RELAY (2)

/*talk status*/
#define PPPP_STATUS_SEND_TALK_DATA     (0) /* user or pwd is invalid */

#ifndef _DEF_STRU_AV_HEAD
#define _DEF_STRU_AV_HEAD
typedef struct tag_AV_HEAD
{
    RT_APP_UINT32   startcode;	//  0xa815aa55
    RT_APP_UCHAR	type;		//  0->264 idr frame 1->264 p frame
    RT_APP_UCHAR  	streamid;	
    RT_APP_UINT16  	militime;	//  diff time
    RT_APP_UINT32 	sectime;	//  diff time
    RT_APP_UINT32   frameno;	//  frameno
    RT_APP_UINT32	len;		//  data len
    RT_APP_UCHAR	version;	// version
    RT_APP_UCHAR	sessid;		//ssid
    RT_APP_UCHAR	other[2];
    //RT_APP_UCHAR	other1[8];
	RT_APP_ULONG64  timestamp;
}AV_HEAD,*PAV_HEAD;
#endif

typedef struct tag_STRU_CAMERA_PARAMS
{
    RT_APP_INT32 resolution;  /*�ֱ���*/
    RT_APP_INT32 brightness;  /*���� 1~255*/
    RT_APP_INT32 contrast;    /*�Աȶ� 1~255*/
    RT_APP_INT32 hue;         /*ɫ�ȣ���֧��*/
    RT_APP_INT32 saturation;  /*ģʽ 0��50hz	1��60hz*/
    RT_APP_INT32 flip;        /*��Ƶ��ת��ʽ 0��ԭʼ   1����ֱ��ת   2��ˮƽ����  3����ֱ��ת + ˮƽ����*/
	RT_APP_INT32 mainFram;    /*������֡��*/
	RT_APP_INT32 subFram;     /*������֡��*/
	RT_APP_INT32 mode;        /*ģʽ 0��50hz	1��60hz*/
	RT_APP_INT32 ircut;	/* ircut��״̬ 0:close   1:auto   2:open*/
	RT_APP_INT32 led; /*led״̬ 0:close 1:open*/
}STRU_CAMERA_PARAMS,*PSTRU_CAMERA_PARAMS;

/*
param	            value
0���ֱ���	    0:VGA 1:QVGA
1������	            1~255
2���Աȶ�	        1~255
3��ģʽ	        0��50hz	1��60hz
5����ת	        0��ԭʼ   1����ֱ��ת   2��ˮƽ����  3����ֱ��ת + ˮƽ����
14:�����       0:close   1:auto   2:open
15:led��        0:close   1:open
*/
typedef struct tag_STRU_CAMERA_CONTROL
{
    RT_APP_INT32 param;
    RT_APP_INT32 value;
}STRU_CAMERA_CONTROL,*PSTRU_CAMERA_CONTROL;


typedef struct tag_STRU_NETWORK_PARAMS
{
    RT_APP_CHAR ipaddr[64];  /*ip��ַ*/
    RT_APP_CHAR netmask[64]; /*��������*/
    RT_APP_CHAR gateway[64]; /*����*/
    RT_APP_CHAR dns1[64];    /*dns������1��Ĭ��8.8.8.8 �ݲ�֧���޸�*/
    RT_APP_CHAR dns2[64];    /*dns������2*/
    RT_APP_INT32 dhcp;         /*�Ƿ���dhcp 1: ���� 0: ������*/
    RT_APP_INT32 port;         /*http�˿�*/
    RT_APP_INT32 rtspport;     /*rtsp�˿ڣ���֧��*/
}STRU_NETWORK_PARAMS,*PSTRU_NETWORK_PARAMS;

typedef struct tag_STRU_USER_INFO
{
    RT_APP_CHAR user1[64];  /*�ι����û���*/
    RT_APP_CHAR pwd1[64];   /*�ι�������*/
    RT_APP_CHAR user2[64];  /*�������û���*/
    RT_APP_CHAR pwd2[64];   /*����������*/
    RT_APP_CHAR user3[64];  /*����Ա�û���*/
    RT_APP_CHAR pwd3[64];   /*����Ա����*/
}STRU_USER_INFO,*PSTRU_USER_INFO;


typedef struct tag_STRU_WIFI_PARAMS
{
    RT_APP_INT32 enable;     /*�Ƿ�����wifi��1: ���� 0: ������*/
    RT_APP_CHAR ssid[128]; /*ssid*/
    RT_APP_INT32 channel;    /*ͨ����*/
    RT_APP_INT32 mode;       /*wifiģʽ����0*/
    RT_APP_INT32 authtype;   /*wifi��֤���� 0: �� 1: WEP 2: WPA-PSK(AES) 2: WPA-PSK(TKIP) 3: WPA2-PSK(AES) 4: WPA2-PSK(TKIP)*/
    RT_APP_INT32 encrypt;    /*��ȫģʽ 0: ����ϵͳ 1: ������Կ*/
    RT_APP_INT32 keyformat;  /*��Կ��ʽ 0: 16������ 1: ASCII��*/
    RT_APP_INT32 defkey;     /*ȱʡʹ����Կ 0~3*/
    RT_APP_CHAR key1[128]; /*��Կ1*/
    RT_APP_CHAR key2[128]; /*��Կ2*/
    RT_APP_CHAR key3[128]; /*��Կ3*/
    RT_APP_CHAR key4[128]; /*��Կ4*/
    RT_APP_INT32 key1_bits;  /*��Կ1�ĳ��� 0: 64bits 1: 128bits*/
    RT_APP_INT32 key2_bits;  /*��Կ2�ĳ��� 0: 64bits 1: 128bits*/
    RT_APP_INT32 key3_bits;  /*��Կ3�ĳ��� 0: 64bits 1: 128bits*/
    RT_APP_INT32 key4_bits;  /*��Կ4�ĳ��� 0: 64bits 1: 128bits*/
    RT_APP_CHAR wpa_psk[128]; /*wpa����*/
}STRU_WIFI_PARAMS,*PSTRU_WIFI_PARAMS;

typedef struct tag_STRU_AP_PARAMS
{
    RT_APP_CHAR ssid[128];
    RT_APP_CHAR pwd[128];
}STRU_AP_PARAMS,*PSTRU_AP_PARAMS;

/*
����now: ��ǰʱ�䣨��1970-1-1 0:0:0��ָ����ʱ������ȥ������������������õ�ǰʱ��ֵ������0
��  tz: ʱ�����ɰ�������ȡֵ��
����39600��(GMT -11:00) ��;��, ��Ħ��Ⱥ��
����36000��(GMT -10:00) ������
����32400��(GMT -09:00) ����˹��
����28800��(GMT -08:00) ̫ƽ��ʱ��(�����ͼ��ô�)
����25200��(GMT -07:00) ɽ��ʱ��(�����ͼ��ô�)
����21600��(GMT -06:00) �в�ʱ��(�����ͼ��ô�), ī�����
����18000��(GMT -05:00) ����ʱ��(�����ͼ��ô�), ����, �����
��  14400��(GMT -04:00) ������ʱ��(���ô�), ʥ���Ǹ�, ����˹
����12600��(GMT -03:30) Ŧ����
����10800>(GMT -03:00) ��������, ����ŵ˹����˹, ���ζ�
����7200>(GMT -02:00) �д�����
����3600>(GMT -01:00) ��ý�Ⱥ��
����0>(GMT) ��������ƽʱ; �׶�, ��˹��, ����������
����-3600��(GMT +01:00) ��³����, ����, ����, ����, �����, ˹����Ħ, ����������, ������
����-7200��GMT +02:00) �ŵ�, Ү·����, ����, �ն�����
����-10800��(GMT +03:00) ���ޱ�, ���ŵ�, Ī˹��
����-12600��(GMT +03:30) �º���
����-14400��(GMT +04:00) �Ϳ�, �ڱ���˹, ��������, ��˹����
����-16200��(GMT +04:30) �Ʋ���
����-18000��(GMT +05:00) ��˹����, ������, ��ɭ��
����-19800��(GMT +05:30) �Ӷ�����, ����, �����˹, �µ���
����-21600��(GMT +06:00) ����ľͼ, ����������, ��˹����, ���
����-25200��(GMT +07:00) ����, ����, �żӴ�
����-28800��(GMT +08:00) ����, �¼���, ̨��
����-32400��(GMT +09:00) �׶�, �ſ�Ŀ�, ����
����-34200��(GMT +09:30) �����
����-36000��(GMT +10:00) �ص�, , ī����, Ϥ��, Ī���ȱȸ�, ��������˹�п�
����-39600��(GMT +11:00) ��ӵ�, ������Ⱥ��, �¿��������
����-43200��(GMT +12:00) �¿���, �����, 쳼�
����ntp_enable: �Ƿ�����ntp���� 1������ 0��������
����ntp_svr: ntp��������ַ
*/
typedef struct tag_STRU_DATETIME_PARAMS
{
    RT_APP_INT32 now;
    RT_APP_INT32 tz;
    RT_APP_INT32 ntp_enable;
	RT_APP_INT32 timeMode;  /*ʱ����ʽ 0:24 1:12*/
    RT_APP_CHAR ntp_svr[64];
}STRU_DATETIME_PARAMS,*PSTRU_DATETIME_PARAMS;


typedef struct tag_STRU_DDNS_PARAMS
{
    RT_APP_INT32 service;
    RT_APP_CHAR user[64];
    RT_APP_CHAR pwd[64];
    RT_APP_CHAR host[64];
    RT_APP_CHAR proxy_svr[64];
    RT_APP_INT32 ddns_mode;
    RT_APP_INT32 proxy_port;
    RT_APP_INT32 ddns_status;
}STRU_DDNS_PARAMS,*PSTRU_DDNS_PARAMS;


typedef struct tag_STRU_FTP_PARAMS
{
    RT_APP_CHAR svr_ftp[64];   /*ftp�������ĵ�ַ*/
    RT_APP_CHAR user[64];      /*ftp��¼�û���*/
    RT_APP_CHAR pwd[64];       /*ftp��¼����*/
    RT_APP_CHAR dir[128];      /*ftp�ϴ�Ŀ¼���� / (����Ŀ¼)*/
    RT_APP_INT32 port;           /*ftp�������˿ڣ�Ĭ��21��*/
    RT_APP_INT32 mode;           /*�ϴ�ģʽ 0: PORT 1: PASV*/
    RT_APP_INT32 upload_interval;/*ftp��ʱ�ϴ���ʱ��������λ�룩 0��ʾ����ʱ�ϴ�*/
}STRU_FTP_PARAMS,*PSTRU_FTP_PARAMS;

typedef struct tag_STRU_MAIL_PARAMS
{
    RT_APP_CHAR svr[64];       /*SMTP��������ַ*/ 
    RT_APP_CHAR user[64];      /*�ʼ��û���*/
    RT_APP_CHAR pwd[64];       /*�ʼ�����*/
    RT_APP_CHAR sender[64];    /*�����������ַ*/
    RT_APP_CHAR receiver1[64]; /*������1�������ַ*/
    RT_APP_CHAR receiver2[64]; /*������2�������ַ*/
    RT_APP_CHAR receiver3[64]; /*������3�������ַ*/
    RT_APP_CHAR receiver4[64]; /*������4�������ַ*/
    RT_APP_INT32 port;           /*SMTP�������Ķ˿�*/
    RT_APP_INT32 ssl;            /*�ʼ����ܷ�ʽ 0: ������ 1: SSL 2: TLS*/
}STRU_MAIL_PARAMS,*PSTRU_MAIL_PARAMS;

typedef struct tag_STRU_ALARM_PARAMS
{
    RT_APP_INT32 motion_armed;       /*�ƶ���⿪�� 0: �ر� 1: ��*/
    RT_APP_INT32 motion_sensitivity; /*�ƶ���������� ȡֵ1~10 ��ȡֵԽСԽ������*/
    RT_APP_INT32 input_armed;        /*���뱨������ 0: �ر� 1: ��*/
    RT_APP_INT32 ioin_level;         /*���뱨��������ƽ 0: �͵�ƽ 1: �ߵ�ƽ*/
    RT_APP_INT32 iolinkage;          /*����IO����������� 0: �ر� 1: ��*/
    RT_APP_INT32 ioout_level;        /*���������ƽ 0: �͵�ƽ 1: �ߵ�ƽ*/
    RT_APP_INT32 alarmpresetsit;     /*��������Ԥ��λ ȡֵ 0~16 0��ʾ������Ԥ��λ*/
    RT_APP_INT32 mail;               /*���������ʼ� 0: �ر� 1: ��*/
    RT_APP_INT32 snapshot;           /*����ץͼ 0: �ر� 1: ��  ��Ŀǰ��֧�֣�*/
    RT_APP_INT32 record;             /*����¼�� 0: �ر� 1: ��*/
    RT_APP_INT32 upload_interval;    /*����ftp�ϴ�ʱ����(��λ��) 0��ʾ���ϴ�*/
    RT_APP_INT32 schedule_enable;    /*������������ 0: �ر� 1: �� ��ע�⣺�رղ����������ᴥ���κα�����*/
    RT_APP_INT32 schedule_sun_0;     /*ÿ�찴24Сʱ��ÿСʱ��15���ӻ���Ϊ96������ʱ�Σ�ʹ��3�����α�ʾ��ÿ������32λ�ֱ��ʾ1��ʱ�Σ������λΪ0����ʱ�β�������1����ʱ�β���*/
    RT_APP_INT32 schedule_sun_1;
    RT_APP_INT32 schedule_sun_2;
    RT_APP_INT32 schedule_mon_0;
    RT_APP_INT32 schedule_mon_1;
    RT_APP_INT32 schedule_mon_2;
    RT_APP_INT32 schedule_tue_0;
    RT_APP_INT32 schedule_tue_1;
    RT_APP_INT32 schedule_tue_2;
    RT_APP_INT32 schedule_wed_0;
    RT_APP_INT32 schedule_wed_1;
    RT_APP_INT32 schedule_wed_2;
    RT_APP_INT32 schedule_thu_0;
    RT_APP_INT32 schedule_thu_1;
    RT_APP_INT32 schedule_thu_2;
    RT_APP_INT32 schedule_fri_0;
    RT_APP_INT32 schedule_fri_1;
    RT_APP_INT32 schedule_fri_2;
    RT_APP_INT32 schedule_sat_0;
    RT_APP_INT32 schedule_sat_1;
    RT_APP_INT32 schedule_sat_2;
}STRU_ALARM_PARAMS,*PSTRU_ALARM_PARAMS;

typedef struct tag_STRU_PTZ_PARAMS
{
    RT_APP_INT32 led_mode;             /*ledָʾ��״̬ 0���ر� 1���� ��ĳЩ�汾���ã�*/
    RT_APP_INT32 ptz_center_onstart;   /*����ʱ��̨�Զ����� 0�������� 1������*/
    RT_APP_INT32 ptz_run_times;        /*��̨������Ѳ��������Ѳ��ʱ��Ѳ��Ȧ�� 0����ʾ�����ƣ�����ϵͳ�������ʱ��Ϊ1Сʱ��*/
    RT_APP_INT32 ptz_patrol_rate;      /*��̨����Ѳ��������Ѳ�����ٶȣ�ȡֵ1~10*/
    RT_APP_INT32 ptz_patrol_up_rate;   /*��̨����ת���ٶȣ�ȡֵ1~10*/
    RT_APP_INT32 ptz_patrol_down_rate; /*��̨����ת���ٶȣ�ȡֵ1~10*/
    RT_APP_INT32 ptz_patrol_left_rate; /*��̨����ת���ٶȣ�ȡֵ1~10*/
    RT_APP_INT32 ptz_patrol_right_rate;/*��̨����ת���ٶȣ�ȡֵ1~10*/
    RT_APP_INT32 disable_preset;       /*����Ԥ��λ 0�������� 1�� ����*/
    RT_APP_INT32 ptz_preset;           /*����ʱ����׼Ԥ��λ ȡֵ0~16��0��ʾ����׼Ԥ��λ 1~16�ֱ��ӦԤ��λ1��Ԥ��λ16*/
}STRU_PTZ_PARAMS,*PSTRU_PTZ_PARAMS;

typedef struct tag_STRU_CAMERA_STATUS
{
    RT_APP_CHAR sysver[32];     /*ϵͳ�̼��İ汾��*/
    RT_APP_CHAR devname[96];    /*�豸���ƣ�ʹ��utf-8����*/
    RT_APP_CHAR devid[32];      /*�豸ID*/
    RT_APP_INT32 alarmstatus;     /*����״̬*/
    RT_APP_INT32 sdcardstatus;    /*SD������״̬ 0: δ���� 1: ����*/
    RT_APP_INT32 sdcardtotalsize; /*SD������*/
    RT_APP_INT32 sdcardremainsize;/*SDʣ������*/
    RT_APP_CHAR mac[32];        /*�豸mac*/
    RT_APP_CHAR wifimac[32];    /*wifi mac*/
    RT_APP_INT32 dns_status;      /*dns ״̬ */
    RT_APP_INT32 upnp_status;     /*upnp ״̬*/
	RT_APP_INT32 onlineNum;     /*��������*/
}STRU_CAMERA_STATUS,*PSTRU_CAMERA_STATUS;

typedef struct tag_STRU_WIFI_SEARCH_RESULT
{
    RT_APP_CHAR ssid[64]; /*�����ssid */
    RT_APP_CHAR mac[64];  /*wifi��mac��ַ */
    RT_APP_INT32 security;  /*���ܷ�ʽ 0: ������ 1: WEP 2: WPA-PSK(AES) 3: WPA-PSK(TKIP) 4: WPA2-PSK(AES) 5: WPA2-PSK(TKIP) */
    RT_APP_CHAR dbm0[32]; /*WIFI�ź�ǿ�� ��100Ϊ��ǿ */
    RT_APP_CHAR  dbm1[32];/*WIFI��׼ֵ ����ʱ���Ըò��� */
    RT_APP_INT32 mode;      /*wifiģʽ */
    RT_APP_INT32 channel;   /*wifiͨ���� */

}STRU_WIFI_SEARCH_RESULT,*PSTRU_WIFI_SEARCH_RESULT;

typedef struct tag_STRU_WIFI_SEARCH_RESULT_LIST
{
    RT_APP_INT32 nResultCount;                 /*nResultCount: WIFIɨ�������� */
    STRU_WIFI_SEARCH_RESULT wifi[50]; /*�洢ɨ����*/
}STRU_WIFI_SEARCH_RESULT_LIST,*PSTRU_WIFI_SEARCH_RESULT_LIST;

typedef struct tag_STRU_SEARCH_SDCARD_RECORD_FILE
{
    RT_APP_CHAR starttime[16]; /*������ʼʱ��(20170818000000)*/
    RT_APP_CHAR endtime[16];   /*��������ʱ��(20170818235959)*/
	RT_APP_INT32 page;         /*��ǰ�����ڼ�ҳ(��ע:���Ϊ0��ʾ����ǰ������¼�񷵻�)*/
	RT_APP_INT32 pageSize;     /*ÿҳ��ʾ������*/
	RT_APP_INT32 fileType;     /*�ļ����� :1-����¼��,2-����¼��,3-����¼��*/
	RT_APP_INT32 showType;     /*�ļ���ʾ���� 0:�ļ��з�ʽ��ʾ 1:ʱ���᷽ʽ��ʾ(�豸ֻ���ļ���ʼ�ͽ���ʱ��)*/
}STRU_SEARCH_SDCARD_RECORD_FILE, *PSTRU_SEARCH_SDCARD_RECORD_FILE;

typedef struct tag_STRU_SDCARD_RECORD_FILE
{
    RT_APP_CHAR szFileName[128]; /*¼���ļ���*/
    RT_APP_INT32 nFileSize;        /*¼���ļ���С*/
	RT_APP_INT32 fileDayStartTime; /*¼��Ŀ�ʼʱ�� HH:MM:SS��ʱ������ܺ�,ex: 18:23:56 ---> 18*3600+23*60+56*/
	RT_APP_INT32 fileDayEndTime;   /*¼��Ľ���ʱ�� HH:MM:SS��ʱ������ܺ�,ex: 18:23:56 ---> 18*3600+23*60+56*/
	RT_APP_INT32 fileTotalTime;    /*¼���ļ�����ʱ��*/
	RT_APP_INT32 currRecordCount;  /*��ǰҳ��¼���ļ�����*/
	RT_APP_INT32 fileTotalCount;   /*��ǰ�豸����ʱ����SD���ļ�����*/
}STRU_SDCARD_RECORD_FILE,*PSTRU_SDCARD_RECORD_FILE;

typedef struct  tag_STRU_SD_RECORD_PARAM
{
    RT_APP_INT32 record_cover_enable;  /*�Ƿ�¼�񸲸�*/
    RT_APP_INT32 record_timer;         /*¼���ʱ��*/
    RT_APP_INT32 record_size;          /*¼���ļ���С*/
    RT_APP_INT32 record_time_enable;   /*��ʱ¼���Ƿ���*/
	RT_APP_INT32 record_sd_status;    /*SD״̬ 0:δ����  1:����  2:����¼��*/
    RT_APP_INT32 sdtotal;              /*SD������*/
    RT_APP_INT32 sdfree;               /*SDʣ���С*/
    RT_APP_INT32 record_schedule_sun_0;
    RT_APP_INT32 record_schedule_sun_1; 
    RT_APP_INT32 record_schedule_sun_2; 
    RT_APP_INT32 record_schedule_mon_0; 
    RT_APP_INT32 record_schedule_mon_1; 
    RT_APP_INT32 record_schedule_mon_2; 
    RT_APP_INT32 record_schedule_tue_0; 
    RT_APP_INT32 record_schedule_tue_1; 
    RT_APP_INT32 record_schedule_tue_2; 
    RT_APP_INT32 record_schedule_wed_0;
    RT_APP_INT32 record_schedule_wed_1; 
    RT_APP_INT32 record_schedule_wed_2; 
    RT_APP_INT32 record_schedule_thu_0; 
    RT_APP_INT32 record_schedule_thu_1; 
    RT_APP_INT32 record_schedule_thu_2; 
    RT_APP_INT32 record_schedule_fri_0; 
    RT_APP_INT32 record_schedule_fri_1; 
    RT_APP_INT32 record_schedule_fri_2; 
    RT_APP_INT32 record_schedule_sat_0; 
    RT_APP_INT32 record_schedule_sat_1; 
    RT_APP_INT32 record_schedule_sat_2;  
}STRU_SD_RECORD_PARAM, *PSTRU_SD_RECORD_PARAM;

typedef struct tag_STRU_BILL_PARAMS
{
    RT_APP_CHAR svr[64];
    RT_APP_CHAR user[64];
    RT_APP_CHAR pwd[64];
    RT_APP_INT32 port;
    RT_APP_INT32 reboottime;
}STRU_BILL_PARAMS,*PSTRU_BILL_PARAMS;

/* app���������ṹ��*/
typedef struct tag_STRU_SEARCH_PARAMS
{
	RT_APP_CHAR   szIpAddr[16];  /*�豸IP*/
	RT_APP_CHAR   szMacAddr[32]; /*�豸MAC*/
	RT_APP_CHAR   szDevUID[32];  /*�豸UID*/
	RT_APP_CHAR   szDevName[32]; /*�豸����*/
	RT_APP_UINT16 nPort;         /*�豸�˿�*/
}STRU_SEARCH_PARAMS,*PSTRU_SEARCH_PARAMS;

typedef enum tag_STRU_ALARM_TYPE
{
    MOTION_ALARM     = 0x01,/* �ƶ���ⱨ�� */
    GPIO_ALARM       = 0x02,/* GPIO���� */
    SCHDEULE_ALARM   = 0x03,/* ��������*/
    CONTROL_ALARM    = 0x04,/* ң��������*/ 
    HUMI_ALARM       = 0x05,/* ��ʪ�ȱ���*/
    PM25_ALARM       = 0x06,/* PM25����*/
    SMOKE_ALARM      = 0x07,/* �̸б���*/
    SOUND_ALARM      = 0x08,/* ��������*/
	MOTION_ALARM_EX  = 0x11,/* �ƶ���ⱨ����չ*/
    GPIO_ALARM_EX    = 0x12,/* GPIO������չ*/
}STRU_ALARM_TYPE;

typedef struct tag_STRU_ALARM_EX_INFO
{
	RT_APP_CHAR alarmInfo[128]; //Ŀǰ���������洢�ļ���,Ҳ�����������洢
}STRU_ALARM_EX_INFO,*PSTRU_ALARM_EX_INFO;

/*ý������״̬*/
typedef enum tag_STRU_MEDIA_DATA_STATE
{
	ENUM_MEDIA_DATA_EXIST = 0,  // ý�����ݴ���TF��
	ENUM_MEDIA_DATA_NONENTITY,  // ý�����ݲ�����TF��
	ENUM_MEDIA_DATA_BUTT
}STRU_MEDIA_DATA_STATE;

/*ý����������*/
typedef enum tag_STRU_MEDIA_DATA_TYPE
{
	ENUM_MEDIA_TYPE_VIDEO = 0,
	ENUM_MEDIA_TYPE_PICTURE = 1,
	ENUM_MEDIA_TYPE_BUTT
}STRU_MEDIA_DATA_TYPE;

/* ý���ļ�*/
typedef struct tag_STRU_MEDIA_DATA
{
	RT_APP_INT32 nHandle;
	RT_APP_ULONG64 fileSize;
	RT_APP_CHAR szFileName[128];
	STRU_MEDIA_DATA_STATE dataState;
	STRU_MEDIA_DATA_TYPE mediaType;
}STRU_MEDIA_DATA,*PSTRU_MEDIA_DATA;

/*ץ�����ķֱ���*/
typedef enum _STRU_SNAP_STREAM_VAL
{
	ENUM_SNAP_STREAM_720 = 1,
	ENUM_SNAP_STREAM_VGA,
	ENUM_SNAP_STREAM_BUTT
}STRU_SNAP_STREAM_VAL;

/*��Ƶ��������*/
typedef enum _STRU_AUDIO_TYPE
{
	ENUM_AUDIO_TYPE_PCM = 0,
	ENUM_AUDIO_TYPE_AAC = 1,
	ENUM_AUDIO_TYPE_BUTT
}STRU_AUDIO_TYPE;

/* ץ���ϴ�FTP */
typedef struct _STRU_SNAP_UPLOAD_FTP
{
    STRU_SNAP_STREAM_VAL snapStreamVal;      //��Ҫץ�ĵ�����ֵ
    RT_APP_CHAR ftpPath[128];//ftp�ϴ���·�����ļ���
}STRU_SNAP_UPLOAD_FTP,*PSTRU_SNAP_UPLOAD_FTP;

/* ¼��ģʽѡ�� */
typedef struct tag_STRU_REC_MODE
{
    RT_APP_INT32 timeRecEnable;    /* 0:�ض�ʱ¼�� 1:����ʱ¼�� */
    RT_APP_INT32 motionRecEnable;  /* 0:���ƶ����¼�� 1:���ƶ����¼�� */
}STRU_REC_MODE,*PSTRU_REC_MODE;

/* ʱ������ */
typedef struct tag_STRU_TIME_ATTR
{
    RT_APP_INT32 year;  /* �� */
    RT_APP_INT32 month; /* �� */
	RT_APP_INT32 day;   /* �� */
    RT_APP_INT32 hour;  /* ʱ */
	RT_APP_INT32 min;   /* �� */
    RT_APP_INT32 sec;   /* �� */
	RT_APP_CHAR  timezone[64]; /*ʱ��������,���ո��������·�*/
	                   /*		
						 ʱ������              ʱ��ֵ
						"Etc/GMT-12"            -12
						"Pacific/Apia"          -11
						"Pacific/Honolulu"      -10
						"Pacific/Marquesas"     -9:30
						"America/Anchorage"     -9
						"America/Los_Angeles"   -8
						"America/Denver"        -7
						"America/Mexico_City"   -6
						"America/Bogota"        -5
						"America/Caracas"       -4:30
						"America/Montreal"      -4
						"America/St_Johns"      -3:30
						"America/Sao_Paulo"     -3
						"Atlantic/South_Georgia" -2
						"Atlantic/Cape_Verde"   -1
						"Europe/Dublin"         0
						"Europe/Brussels"       1
						"Europe/Athens"         2
						"Europe/Moscow"         3
						"Asia/Tehran"           3:30
						"Asia/Baku"             4
						"Asia/Kabul"            4:30
						"Asia/Karachi"          5
						"Asia/Calcutta"         5:30
						"Asia/Katmandu"         5:45
						"Asia/Rangoon"          6:30
						"Asia/Almaty"           6
						"Asia/Bangkok"          7
						"Asia/Hong_Kong"        8
						"Asia/Tokyo"            9
						"Australia/Adelaide"    9:30
						"Pacific/Guam"          10
						"Asia/Magadan"          11
						"Pacific/Auckland"      12
						"Pacific/Tongatapu"     13
						"Pacific/Kiritimati"    14
	                   */
}STRU_TIME_ATTR,*PSTRU_TIME_ATTR;

/*�����ж�������¼��*/
typedef struct tag_STRU_REC_CALENDAR
{
	RT_APP_UINT32 calendar; /*���뵼������ ����:Ҫ���Ǹ��� ����:ÿbit��ʾһ��,1:�� 0:��*/
	RT_APP_UINT32 count; /*����������ж�������¼���ļ�*/
}STRU_REC_CALENDAR,*PSTRU_REC_CALENDAR;

typedef struct tag_STRU_ALARM_PARAMS_EX
{
	RT_APP_INT32 mdSensitive; /*�ƶ���������� 0:�ر� 1:�� 2:�� 3:�� 4:���*/
	RT_APP_INT32 mdInterval;  /*�ƶ���ⱨ�����ʱ��(��λs)*/
	RT_APP_INT32 mdEmailSnap; /*�ƶ�����ʼ�ץ��*/
	RT_APP_INT32 mdFtpSnap;   /*�ƶ����ftpץ��*/
	RT_APP_INT32 mdFtpRec;    /*�ƶ����ftp¼��*/
	RT_APP_INT32 ioEnable;    /*io�澯���� 0-������1-���أ�2-�ر�*/
	RT_APP_INT32 ioInterval;  /*io�澯�������ʱ��(��λs)*/
	RT_APP_INT32 ioEmailSnap; /*io�澯�ʼ�ץ��*/
	RT_APP_INT32 ioFtpSnap;   /*io�澯ftpץ��*/
	RT_APP_INT32 ioFtpRec;    /*io�澯ftp¼��*/
}STRU_ALARM_PARAMS_EX,*PSTRU_ALARM_PARAMS_EX;

typedef struct tag_STRU_SD_RECORD_EX
{
	RT_APP_INT32 sdRecMode;     /*sd��¼��ģʽ 0:��¼�� 1:ȫʱ¼�� 2:����¼��*/
	RT_APP_INT32 fullRecTime;   /*ȫʱ¼����ʱ��(��λ��)*/
	RT_APP_INT32 alarmRecTime;  /*�澯¼����ʱ��(��λ��)*/
	RT_APP_INT32 timelapseRecEnable;/*��ʱ¼�񿪹� 0:�� 1:��*/
	RT_APP_INT32 timelapseRecTime;  /*��ʱ¼����ʱ��(��λСʱ)*/
	RT_APP_INT32 timePlanEnable;    /*��ʱ¼��ƻ����� 1:�� 0:�ر� (��ע�رյĻ�Ĭ��Ϊ��7*24Сʱ¼��)*/
	RT_APP_INT32 timePlanStartTime; /*��ʱ¼��ƻ���ʼʱ�� (ʱ�侫��Ϊ15���� ����03:30  3*(60/15)+30/15=14) ��ע:���*/
	RT_APP_INT32 timePlanEndTime;   /*��ʱ¼��ƻ�����ʱ�� (ʱ�侫��Ϊ15���� ����20:45  20*(60/15)+45/15=83)*/
	RT_APP_INT32 loopRecEnable;     /*ѭ��¼�� 1:ѭ��¼�� 0:��ѭ��¼��*/
	RT_APP_INT32 audioRecEnable;    /*¼���Ƿ�¼������ 1:¼������ 0:��¼������*/
	RT_APP_INT32 resolutionRec;     /*¼��ķֱ��� 0:������ 1:������*/
	
}STRU_SD_RECORD_EX,*PSTRU_SD_RECORD_EX;

typedef struct tag_STRU_OSD_ATTRS
{
	RT_APP_INT32 osdEnable; /*osd 0:�� 1:��*/ 
	RT_APP_CHAR  osdName[64]; /*osd������*/
}STRU_OSD_ATTRS,*PSTRU_OSD_ATTRS;

/*Ŀǰ��Ҫ��������ͼ�������豸,��Ƴ�buf����Ϊ�ײ����ݽ�����֧�ָ���������*/
typedef struct tag_STRU_GEOG_ATTRS
{
	RT_APP_CHAR longitude[16]; /*����*/
	RT_APP_CHAR latitude[16];  /*γ��*/
	RT_APP_INT32 isRefresh;    /*�Ƿ���Ҫ����ˢ��������Ϣ 0:��ˢ��(Ĭ��) 1:ˢ��*/
}STRU_GEOG_ATTRS,*PSTRU_GEOG_ATTRS;

/*��̨���ƽṹ��*/
typedef struct tag_STRU_PTZ_CONTROL
{
	RT_APP_UINT32 command;  /*����ֵ*/
	RT_APP_UINT32 extParam; /*��չ����*/
}STRU_PTZ_CONTROL,*PSTRU_PTZ_CONTROL;

#endif //__RT_P2P_API_DEFINE_H__
