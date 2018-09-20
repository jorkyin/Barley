package com.jorkyin.barley.util;

/**
 * Created by yinjian on 2018/2/2.
 */

public class Const {
    public static final String URL = "url";

    /*MainActivity*/
    public static final int MAINACTIVITY_AADACTIVITY_TITLE = 1;//MainActivity 和 AddActivity 跳转标记
    public static final int AADACTIVITY_SEARCHACTIVITY_TITLE = 2;//AddActivity 和 SearchActivity 跳转标记

    // 如果更改数据库模式，则必须增加数据库版本。
    public static final int DATABASE_VERSION = 1;
    public static final String DATABASE_NAME = "camera.db";
    public static final String DATABASE_TABLE_NAME = "param";

    public static final String P2PPARAM = "p2pparam";
    public static final String UID = "uid";
    public static final String IP = "ip";
    public static final String USER = "user";
    public static final String PASSWORD = "password";

    public static final String DATALIST ="dataList";
    public static final String NAME="name";

    /*p2p msgtype*/
    public static final int MSG_NOTIFY_TYPE_PPPP_STATUS     =0;   /* p2p连接状态*/
    public static final int MSG_NOTIFY_TYPE_PPPP_MODE       =1;   /* p2p类型*/
    public static final int MSG_NOTIFY_TYPE_STREAM_TYPE     =2;   //视频流类型
    public static final int MSG_NOTIFY_TYPE_TALK_STATUS     =3;  /*当msgValue的值为PPPP_STATUS_SEND_TALK_DATA时表示可以发送对讲数据*/
    /*p2p连接状态*/
    public static final int PPPP_STATUS_CONNECTING          =0; /* 正在连接 */
    public static final int PPPP_STATUS_INITIALING          =1; /* 启动连接 */
    public static final int PPPP_STATUS_ON_LINE             =2; /* 设备在线 */
    public static final int PPPP_STATUS_CONNECT_FAILED      =3; /* 连接失败 */
    public static final int PPPP_STATUS_DISCONNECT          =4; /* 连接断开*/
    public static final int PPPP_STATUS_INVALID_ID          =5; /* 无效UID*/
    public static final int PPPP_STATUS_DEVICE_NOT_ON_LINE  =6; /*设备不在线*/
    public static final int PPPP_STATUS_CONNECT_TIMEOUT     =7; /* 连接超时 */
    public static final int PPPP_STATUS_INVALID_USER_PWD    =8; /* 用户名或者密码错误 */
    public static final int PPPP_STATUS_MAX_CONNECT_CNT     =9; /*超过设备端的最大连接数*/
    /*p2p类型*/
    public static final int PPPP_MODE_P2P                   =1;//p2p直连
    public static final int PPPP_MODE_RELAY                 =2;//转发
    /*talk status*/
    public static final int PPPP_STATUS_SEND_TALK_DATA     =0; /* user or pwd is invalid */
}
